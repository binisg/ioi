#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#

using namespace std;

bool search (vector<char> &c, char &x) {
    for (char k: c) {
        if (k == x) return true;
    }
    return false;
}

int main() {

    ifstream in("cownomics.in");
    ofstream out("cownomics.out");

    int N, M;
    in >> N >> M;

    vector<string> genes1(N);
    vector<string> genes2(N);

    in.ignore();

    for (int i = 0; i < N; i++) {
        getline(in, genes1[i]);
    }

    for (int i = 0; i < N; i++) {
        getline(in, genes2[i]);
    }

    int result = 0;

    for (int i = 0; i < M; i++) {
        vector<char> s;
        for (int j = 0; j < N; j++) {
            if (!search(s, genes1[j][i])) s.push_back(genes1[j][i]); 
        }
        bool foreign = true;
        for (int j = 0; j < N; j++) {
            if (search(s, genes2[j][i])) {
                foreign = false;
                break;
            }
        }
        if (foreign) {
            result++;
        }
    }

    out << result;

    return 0;

}