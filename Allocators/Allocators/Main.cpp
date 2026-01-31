#include<iostream>
#include<vector>

#include<limits>

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


};
int main() {
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

	for (const auto& i : vec) {
		std::cout << i << " ";
	}
}