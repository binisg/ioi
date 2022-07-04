#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int find_pairs(string &str, char &c) {

    int start = 0, end = 0, result = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == c) {
            start = i;
            break;
        }
    }

    for (int i = start+1; i < str.size(); i++) {
        if (str[i] == c) {
            end = i;
            break;
        }
    }

    unordered_map<char, bool> ones;
    for (int i = start; i <= end; i++) {
        if (ones.count(str[i])) {
            ones[str[i]] = false;
        } else {
            ones[str[i]] = true;
        }
    }

    for (auto p: ones) {
        if (p.second == true) result++;
    }

    return result;

}

int main() {
    ifstream in("circlecross.in");
    ofstream out("circlecross.out");

    string str;
    getline(in, str);

    vector<char> abc = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int result = 0;
    for (char c: abc) {
        result += find_pairs(str, c);
    }

    result /= 2;

    out << result << endl;

    return 0;
}