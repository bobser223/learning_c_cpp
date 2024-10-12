//
// Created by Volodymyr Avvakumov on 11.10.2024.
//
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <cmath>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int pollards_rho(int n) {
    if (n % 2 == 0) return 2;

    int x = rand() % (n - 2) + 2;
    int y = x;
    int c = rand() % (n - 1) + 1;
    int d = 1;

    while (d == 1) {
        x = (int)((long long)x * x + c) % n;
        y = (int)((long long)y * y + c) % n;
        y = (int)((long long)y * y + c) % n;
        d = gcd(abs(x - y), n);

        if (d == n) return pollards_rho(n);
    }
    return d;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

std::vector<int> factorize_pollard(int n) {
    std::vector<int> factors;
    if (is_prime(n)) {
        factors.push_back(n);
        return factors;
    }

    while (n > 1) {
        if (is_prime(n)) {
            factors.push_back(n);
            break;
        }
        int divisor = pollards_rho(n);
        std::vector<int> sub_factors = factorize_pollard(divisor);
        factors.insert(factors.end(), sub_factors.begin(), sub_factors.end());
        n /= divisor;
    }

    return factors;
}

std::map<int, int> make_pow_element_dict(const std::vector<int>& elements) {
    std::map<int, int> pow_element_dict;
    for (int element : elements) {
        if (pow_element_dict.find(element) == pow_element_dict.end()) {
            pow_element_dict[element] = 1;
        } else {
            pow_element_dict[element]++;
        }
    }
    return pow_element_dict;
}

int pow_sum(const std::vector<int>& elements) {
    std::map<int, int> pow_element_dict = make_pow_element_dict(elements);
    int suma = 0;
    for (const auto& [element, power] : pow_element_dict) {
        suma += pow(element, power);
    }
    return suma;
}

bool is_there_element_order_k(int k, int n) {
    std::vector<int> factors = factorize_pollard(k);
    std::map<int, int> pow_element_dict = make_pow_element_dict(factors);

    int suma = 0;
    for (const auto& [element, power] : pow_element_dict) {
        suma += pow(element, power);
        if (suma > n) return false;
    }
    return true;
}

int main() {
    int n = 100;
    for (int k = 1; k <= std::tgamma(n + 1); ++k) {
        if (is_there_element_order_k(k, n)) {
            std::cout << k << std::endl;
        }
    }

    return 0;
}
