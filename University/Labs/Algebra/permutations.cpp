//
// Created by Volodymyr Avvakumov on 01.10.2024.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath> // Для функцій pow, log, exp, lgamma
#include <numeric>
#include <chrono>

using namespace std;

// Функція для обчислення НСД (найбільшого спільного дільника)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Функція для обчислення НСК (найменшого спільного кратного)
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Функція для обчислення НСК списку чисел
int lcm_list(const vector<int>& lst) {
    if (lst.size() == 1)
        return lst[0];
    int lcm_1 = lcm(lst[0], lst[1]);
    for (size_t i = 2; i < lst.size(); ++i) {
        lcm_1 = lcm(lcm_1, lst[i]);
    }
    return lcm_1;
}

// Функція для перетворення списку в словник з підрахунком частот елементів
map<int, int> list_to_dict(const vector<int>& lst) {
    map<int, int> dict;
    for (size_t i = 0; i < lst.size(); ++i) {
        ++dict[lst[i]];
    }
    return dict;
}

// Функція для обчислення кількості перестановок заданого типу циклів
double permutations_count(const vector<int>& lst, int n) {
    map<int, int> perm_dict = list_to_dict(lst);
    double log_a = lgamma(n + 1); // log(n!)
    double log_b = 0.0;
    for (auto& kv : perm_dict) {
        int key = kv.first;
        int value = kv.second;
        log_b += value * log(key) + lgamma(value + 1); // value*log(key) + log(value!)
    }
    return exp(log_a - log_b);
}

// Рекурсивна функція для генерації всіх розбиттів числа n
void foo(int n, int l, vector<int>& current, vector<vector<int>>& results) {
    if (n == 0) {
        results.push_back(current);
        return;
    }
    for (int i = 1; i <= min(l, n); ++i) {
        current.push_back(i);
        foo(n - i, i, current, results);
        current.pop_back();
    }
}

int main() {
    int n;
    cout << "Введіть число n: ";
    cin >> n;
    auto start = std::chrono::high_resolution_clock::now();
    vector<vector<int>> sums;
    vector<int> current;
    foo(n, n, current, sums);

    map<int, double> ord_dict;

    for (auto& s : sums) {
        int lcm_val = lcm_list(s);
        double count = permutations_count(s, n);
        ord_dict[lcm_val] += count;
    }

    cout << "{";
    bool first = true;
    for (auto& kv : ord_dict) {
        if (!first)
            cout << ", ";
        cout << kv.first << ": " << kv.second;
        first = false;
    }
    cout << "}" << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Час виконання: " << elapsed.count() << " секунд" << std::endl;

    return 0;
    return 0;
}
