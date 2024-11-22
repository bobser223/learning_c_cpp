//
// Created by Volodymyr Avvakumov on 18.11.2024.
//
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

class segment{
public:
    float x;
    float y;

    segment(float a, float b):x(a), y(b) {};

    const float len() const{
        return sqrt(pow(x, 2)+ pow(y, 2));
    }

    void print(std::ostream& out = std::cout) const{
        out<< "(" << x << "," << y << ")";
    }

    friend std::ostream& operator <<(std::ostream& out,const segment& p){
        p.print(out);
        return out;
    }
};

vector<segment> read_points(const char* filename) {
    vector<segment> segments;
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Cannot open file.");
    }

    string line;
    while (getline(file, line)) {
        regex pattern(R"(\(([-+]?\d*\.?\d+),([-+]?\d*\.?\d+)\))");
        smatch match;

        while (regex_search(line, match, pattern)) {
            int a = stof(match[1]);
            int b = stof(match[2]);
            segment p(a, b);
            segments.push_back(p);
            line = match.suffix();
        }
    }
    return segments;
}

vector<segment> sort_segments(const char* filename) {
    vector<segment> segments = read_points(filename);

    sort(segments.begin(), segments.end(), [](const segment& a, const segment& b) {
        return a.len() > b.len();
    });

    return segments;
}





int main(){
    vector<segment> segments = sort_segments("input03.txt");
    for (const auto& seg : segments) {
        cout << seg << " -> Length: " << seg.len() << endl;
    }

}