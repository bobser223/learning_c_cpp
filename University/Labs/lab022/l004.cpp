//
// Created by Volodymyr Avvakumov on 22.11.2024.
//

#include <ctime>
#include <iostream>
#include <list>

using namespace std;

clock_t clockGenerator() {
    return clock();
}

template <class cont>
void print(const cont&c){
    cout << "[";
    for (const auto& item: c){
        cout << item << ", ";
    }
    cout << "\b\b]" << endl; // \b - delete last char
}

int main(){
//    time_t currentTime = time(nullptr);
//    cout << ctime(&currentTime) << endl;
//    cout << clockGenerator() << endl;

    list<clock_t> clockList;
    generate_n(back_inserter(clockList), 10, clockGenerator);

    print(clockList);


    clockList.sort();
    clockList.unique();

    copy(clockList.begin(), clockList.end(), ostream_iterator<clock_t>(cout, " "));
}
