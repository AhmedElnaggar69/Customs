#include <stdexcept>
#include<memory>
#include<iostream>
template<typename type>
class MyVec {
private:
    int size_m = 0;
    int capacity_m = 1;
    std::unique_ptr<type[]>start_m;
public:
    MyVec() :start_m{ std::make_unique<type[]>(capacity_m) } {}

    void push_back(const type& val) {
        if (size_m >= capacity_m) {
            capacity_m *= 2;
            std::unique_ptr<type[]>new_start_m = std::make_unique<type[]>(capacity_m);
            for (int i = 0; i < size_m; i++) {
                new_start_m[i] = std::move(start_m[i]);
            }


            start_m = std::move(new_start_m);
        }



        start_m[size_m] = val;
        size_m++;
    }

    void print() {
        for (int i = 0; i < size_m; i++) {
            std::cout << start_m[i] << " ";
        }
        std::cout << std::endl;
    }
    const type& operator[](int index)const {
        if (index < 0 || index >= size_m) {
            throw std::out_of_range("no bueno");
        }
        return start_m[index];
    }

    type& operator[](int index) {
        if (index < 0 || index >= size_m) {
            throw std::out_of_range("no bueno");
        }
        return start_m[index];
    }

    MyVec(const MyVec&) = delete;
    MyVec& operator=(const MyVec&) = delete;
};
int main()
{
    MyVec<float>vec;
    float num;
    for (int i = 0; i < 15; i++) {
        vec.push_back(i);
    }
    vec.print();

    while (true) {


        std::cout << "enter an index!!";
        int i;
        std::cin >> i;
        std::cout << "here it is " << vec[i] << std::endl;


        int t;
        int y;
        std::cout << "write into an index!!" << std::endl;
        std::cout << "index :";
        std::cin >> t;
        std::cout << "value :";
        std::cin >> y;
        vec[t] = y;
        vec.print();
    }


}