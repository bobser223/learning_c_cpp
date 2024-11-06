//
// Created by Volodymyr Avvakumov on 04.11.2024.
//
#include <iostream>

namespace my {
    namespace my2{
        int my2 = 2;
        namespace my3{
            int my3 = 3;
        }
    }
    template<class T>
    class cl{
        T var;
    public:
        cl(T var): var(var) {};
        T get_var(){
            return var;
        }
    };
}

int main(){
    my::cl<int> cla(9);
    std::cout << cla.get_var() << std::endl;
    std::cout << my::my2::my2 << std::endl;
    std::cout << my::my2::my3::my3 << std::endl;
}


