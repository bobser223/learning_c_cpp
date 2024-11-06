//
// Created by Volodymyr Avvakumov on 04.11.2024.
//
#include <iostream>
#include <stack>
namespace my {
    template<class T>
    struct Node {
        T item;
        Node<T>* next;
    };

    template<class T>
    class stack{
    private:
        Node<T>* _top;
    public:
        stack(): _top(nullptr) {};

        ~stack(){
            while (!empty()){
                pop();
            }

        }


        bool empty() {return _top == nullptr;}

        T top(){
            if(empty()) throw std::logic_error("method 'top' applied to empty container");
            return _top -> item;
        };

        void push(T value){
            Node<T>* node =  new Node<T>;
            node -> item = value;
            node -> next = _top;
            _top = node;

        }

        T pop(){
            if(empty()) throw std::logic_error("method 'top' applied to empty container");
            Node<T>* node = _top;
            _top = _top -> next;
            T item = node -> item;
            delete node;
            return item;
        }

    };

}

int main() {
    std::stack<int> std_stack;

    for (int i = 0; i < 6; i++) {
        std_stack.push(i);
    }

    while (!std_stack.empty()) {
        std::cout << std_stack.top() << " ";
        std_stack.pop();
    }
    std::cout << std::endl;

    my::stack<int> my_stack;

    for (int i = 0; i < 6; i++) {
        my_stack.push(i);
    }

    while (!my_stack.empty()) {
        std::cout << my_stack.top() << " ";
        my_stack.pop();
    }
    std::cout << std::endl;

    return 0;
}
