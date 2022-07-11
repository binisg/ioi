#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>

using namespace std;

#define MAX_N 1000000005

int main() {
    ifstream in("notlast.in");
    ofstream out("notlast.out");

    int N;
    in >> N;
    in.ignore();

    unordered_map<string, int> cows;

    while (N--) {
        string s; int val;
        in >> s >> val;
        cows[s] += val;
        in.ignore();
    }

    pair<string, int> min_p_1 {"", MAX_N}, min_p_2 = {"", MAX_N};

    for (auto p: cows) {
        if (p.second < min_p_1.second) {
            min_p_1 = p;
        }
    }

    for (auto p: cows) {
        if (p.second < min_p_2.second && p.second != min_p_1.second) {
            min_p_2.second = p.second;
            min_p_2.first = p.first;
        }
    }

    if (min_p_2.first != "") out << min_p_2.first << "\n";
    else {
        if (cows.size() == 1) out << min_p_1.first << "\n";
        else out << "Tie\n";
    }

    return 0;
}