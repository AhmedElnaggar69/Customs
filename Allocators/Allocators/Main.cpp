#include<iostream>
#include<vector>

#include<limits>

#include<string>

template<typename type>
struct CusAlloc {
	using value_type = type;

	CusAlloc() = default;
	

	template<typename U>
	CusAlloc(const CusAlloc<U>&) noexcept {}


	type* allocate(size_t n) {
		std::cout << "allocating size of -> " << n << " elements" << std::endl;
		return static_cast<type*>(::operator new (sizeof(type) * n));
	}

	void deallocate(type* p, size_t n) {
		std::cout << "deallocating " << n << " elements" << std::endl;
	    ::operator delete(p);
	}

	// now we need to construct the type from raw bytes
	/*
	* Args is a list of types
	construct(p, 1);          
	construct(p, 1, 2.5);     
	construct(p, "hi", 5); 
	*/

	/*
	Args&&... args (forward ref for Ival and Rval)
	int x = 5;
	construct(p, x, 10);  args = {int&, int}
	construct(p, 5, 10);  args = {int&&, int&&}
	*/
	template<typename... Args>
	void construct(type* p, Args&&... args) {
		// p is return from alloc
		new (p) type(std::forward<Args>(args)...);  
	}


	void destroy(type* p) {
		p->~type();
	}
};

struct dummy
{
	std::string name{};
	int age{};
	dummy() {
		std::cout << "A dummy was constucted " << std::endl;
	}
	dummy(std::string name, int age) :name{ name }, age{ age } { std::cout << "A dummy was constucted " << std::endl; }

	~dummy() {
		std::cout << " deconstructing the dummy " << std::endl;

	}
};
int main() {
	/*
	std::vector<int, CusAlloc<int> >vec;
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(69);
	*/


	std::vector < dummy, CusAlloc<dummy> >dummyBucket;
	dummyBucket.reserve(3);

	dummyBucket.push_back(dummy("man", 69));
	dummyBucket.push_back(dummy("noman", 69));
	dummyBucket.push_back(dummy("charmask", 69));
}