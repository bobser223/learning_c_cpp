#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm> // Include this header for std::find

using namespace std;

// Function to check if n is a "self-replicating" number (the last digits of n^2 are equal to n)
bool is_in(int n) {
    string sq = to_string(n * n);
    string str_n = to_string(n);

    // Add a check to prevent out-of-range errors
    if (sq.length() >= str_n.length()) {
        if (str_n == sq.substr(sq.length() - str_n.length())) {
            return true;
        }
    }
    return false;
}

vector<int> lst = {5, 6};

void foo(int n) {
    if (n < 5) {
        cout << 1 << endl;
        return;
    } else if (n == 5) {
        cout << 5 << endl;
        return;
    } else if (n == 6) {
        cout << 6 << endl;
        return;
    }

    int b = lst.back();
    int a = lst[lst.size() - 2];
    int i = 10;
    int first = 1;

    while (lst.back() <= n) {
        if (first == 1) {
            a += i;
            b += i;
            first = 0;
        }
        if (find(lst.begin(), lst.end(), a) == lst.end()) {
            a += i;
        }
        if (find(lst.begin(), lst.end(), b) == lst.end()) {
            b += i;
        }
        if (is_in(a) && find(lst.begin(), lst.end(), a) == lst.end()) {
            lst.push_back(a);
        }
        if (is_in(b) && find(lst.begin(), lst.end(), b) == lst.end()) {
            lst.push_back(b);
        }

        if (find(lst.begin(), lst.end(), a) != lst.end() && find(lst.begin(), lst.end(), b) != lst.end()) {
            i *= 10;
            b = lst.back();
            a = lst[lst.size() - 2];
            first = 1;
        }
    }
    cout << lst[lst.size() - 2] << endl;
}

int main() {
    int a;
    cin >> a;
    foo(a);
    return 0;
}
