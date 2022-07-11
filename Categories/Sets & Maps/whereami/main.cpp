#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ifstream in("whereami.in");
    ofstream out("whereami.out");

    int N;
    in >> N;
    in.ignore();

    string s;
    getline(in, s);

    int result = -1;

    for (int i = 1; i < N; i++) {
        unordered_set<string> board;
        for (int j = 0; j < N-i+1; j++) {
            string sub = s.substr(j, i);
            if (board.count(sub)) goto end;
            else board.insert(sub);
        }
        result = i;
        break;
        end:
        continue;
    }

    out << result << "\n";

    return 0;
}