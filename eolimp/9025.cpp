//
// Created by Volodymyr Avvakumov on 11.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
int* sort(int* lst, vector<int>& vec, int size,int j = 0){
    int minNum = vec[0];
    int minInd = 0;
    int i;
    if (vec.size() == 0){
        return lst;
    }
    for(i = 1; i < vec.size(); i++){
        if (vec[i] < minNum){
            minNum = vec[i];
            minInd = i;
        }
    }
    lst[j] = minNum;
    vec.erase(vec.begin() + minInd);
    j += 1;
    return sort(lst, vec, size, j);
}

int main(){
    int size, index;
    cin >> size >> index;
    int lst[size];
    vector<int> vec;
    for (int i = 0; i < size; i++){
        int value;
        cin >> value;
        vec.push_back(value);
    }
    int* sortedLst = new int[size];
    sortedLst = sort(sortedLst, vec, size);
    cout << sortedLst[index - 1] << endl;

    delete[] sortedLst;
    return 0;

}