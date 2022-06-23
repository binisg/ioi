#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream in ("blocks.in");
    ofstream out ("blocks.out");

    int N;
    in >> N;

    vector<string> words;
    string s;
    getline(in, s);

    for (int i = 0; i < N; i++) {
        char c = 's';
        string str;
        in >> str;
        words.push_back(str);
        in >> str;
        words.push_back(str);
        getline (in, str);
    }

    vector<vector<int>> times(words.size(), vector<int>(26, 0));
    for (int i = 0; i < words.size(); i++) {
        string str = words[i];
        for (char o: str) {
            times[i][(int)o-97]++;
        }
    }

    int arr[26] = {};

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < times.size()-1; j += 2) {
            arr[i] += max(times[j][i], times[j+1][i]);
        }
    }

    for (int i = 0; i < 26; i++) {
        out << arr[i] << "\n";
    }

    return 0;
}