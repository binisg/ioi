#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using pi = pair<string, string>;
#define push_back pb

bool valid (vector<pi> &rules, vector<string> &names) {
    for (int i = 0; i < names.size(); i++) {
        for (int j = 0; j < rules.size(); j++) {
            if (rules[j].first == names[i]) {
                if (j > 0 && names[j-1] == rules[j].second) continue;
                else if (j < names.size()-1 && names[j+1] == rules[j].second) continue;
                else return false;
            } else if (rules[j].second == names[i]) {
                if (j > 0 && names[j-1] == rules[j].first) continue;
                else if (j < names.size()-1 && names[j+1] == rules[j].first) continue;
                else return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream in("lineup.in");
    ofstream out("lineup.out");

    vector<string> names = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    int N; in >> N; in.ignore();
    vector<pi> rules(N);

    for (int i = 0; i < N; i++) {
        pi p;
        in >> p.first;
        for (int i = 0; i < 4; i++) {
            string temp; in >> temp;
        }
        in >> p.second;
        rules[i] = p;
    }

    do {
        for (pi v: rules) {
            cout << v.first << " " << v.second << endl;
        }
        cout << endl;
        for (string s: names) {
            cout << s << endl;
        }
        cout << endl;
        if (valid(rules, names)) {
            for (string s: names) {
                cout << s << "\n";
            }
            return 0;
        }
    } while (next_permutation(names.begin(), names.end()));

    return 0;
}