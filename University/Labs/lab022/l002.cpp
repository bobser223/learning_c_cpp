//
// Created by Volodymyr Avvakumov on 22.11.2024.
//

#include <vector>
#include <iostream>
#include <algorithm>

class BoolVector{
private:
    std::vector<bool> vec;
public:
    BoolVector(){
        vec = {1, 0, 1, 0, 0,1};
    };
    BoolVector AND(const BoolVector& other){
        BoolVector bl;
        bl.vec = this ->vec;
        std::transform(this->vec.begin(), this->vec.end(), other.vec.begin(), bl.vec.begin(),[](bool x, bool y){return x&&y;} );
        return bl;
    }

    BoolVector OR(const BoolVector& other){
        BoolVector bl;
        bl.vec = this ->vec;
        std::transform(this->vec.begin(), this->vec.end(), other.vec.begin(), bl.vec.begin(),[](bool x, bool y){return x||y;} );
        return bl;
    }

    BoolVector operator!(){
        BoolVector bl;
        bl.vec = this ->vec;
    std::transform(bl.vec.begin(), bl.vec.end(), bl.vec.begin(),[](bool x){return !x;} );
    return bl;
    }

    void print(){
        for (auto i: this ->vec){
            std::cout << i << " ";

        }
        std::cout << '\n';
    }

};


int main(){
    BoolVector vec;
    vec.print();
    (!vec).print();
    (vec.AND(vec)).print();
}