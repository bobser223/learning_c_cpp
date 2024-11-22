//
// Created by Volodymyr Avvakumov on 22.11.2024.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void sort_vector(vector<string>& vec) {
    sort(vec.begin(), vec.end());
}

void print_vector(const vector<string>& vec) {
    for (const auto& var : vec) {
        cout << var << " ";
    }
    cout << "\n";
}

void read_file(const string& filename, vector<string>& V0, vector<vector<string>>& VN) {
    ifstream file(filename, ios::binary);


    if (!file.is_open()) {
        cerr << "can't open file" << filename << endl;
        return;
    }

    string line;
    if (getline(file, line, '\n')){
        istringstream ss(line);

        string word;
        while (ss >> word) {
            V0.push_back(word);
        }
    } else {
        cerr << "can't read V0" << endl;
    }


    int N;
    if(getline(file, line, '\n')){
        N = stoi(line);
        VN.resize(N);
    } else {
        cerr << "can't read N" << endl;
    }

    for (int i = 0; i < N; i++){
        if (getline(file, line, '\n')) {
            istringstream ss(line);

            string word;
            while (ss >> word) {
                VN[i].push_back(word);
            }
        } else {
            cerr << "problem with V" << i << endl;
        }
    }

    file.close();
}

void print_includes(const string& filename) {
    vector<string> V0;
    vector<vector<string>> VN;

    read_file(filename, V0, VN);

    cout << "includings: " << endl;

    sort_vector(V0);
    for (auto& Vi : VN) {
        sort_vector(Vi);
        if (includes(V0.begin(), V0.end(), Vi.begin(), Vi.end())) {
            print_vector(Vi);
        }
    }
}

void write_test_data(const string& filename) {
    std::ofstream file(filename, std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису: " << filename << std::endl;
        return;
    }

    std::vector<std::string> V0 = {"apple", "orange", "banana"};
    for (const auto& word : V0) {
        file << word << ' ';
    }
    file << '\n';


    int N = 3;
    file << N << '\n';


    std::vector<std::vector<std::string>> VN = {
            {"apple", "banana"},
            {"orange", "banana", "kiwi"},
            {"peach", "apple"}
    };

    for (const auto& vec : VN) {
        for (const auto& word : vec) {
            file << word << ' ';
        }
        file << '\n';
    }

    file.close();
    std::cout << "Дані записані у файл: " << filename << std::endl;
}

int main() {
    write_test_data("input09.pipka");
    print_includes("input09.pipka");
    return 0;
}
