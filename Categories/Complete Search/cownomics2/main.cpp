#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int a, b, c, i;
vector<string> spotty, not_spotty;

int sort_str (string &one, string &two) {
    if (one[a] > two[a]) return 0;
    else if (one[a] < two[a]) return 1;
    else {
        if (one[b] > two[b]) return 0;
        else if (one[b] < two[b]) return 1;
        else {
            if (one[c] > two[c]) return 0;
            else if (one[c] < two[c]) return 1;
        }
    }
    return 0;
}

bool binary_search() {
    int start = 0, end = not_spotty.size()-1;
    int k;

    while (start <= end) {
        k = (start+end)/2;
        if (not_spotty[k][a] == spotty[i][a] && not_spotty[k][b] == spotty[i][b] && not_spotty[k][c] == spotty[i][c]) return true;
        else if (not_spotty[k][a] == spotty[i][a] && not_spotty[k][b] > spotty[i][b]) end = k-1;
        else if (not_spotty[k][a] == spotty[i][a] && not_spotty[k][b] < spotty[i][b]) start = k+1;
        else if (not_spotty[k][a] == spotty[i][a] && not_spotty[k][b] == spotty[i][b] && not_spotty[k][c] > spotty[i][c]) end = k-1;
        else if (not_spotty[k][a] == spotty[i][a] && not_spotty[k][b] == spotty[i][b] && not_spotty[k][c] < spotty[i][c]) start = k+1;
        else if (not_spotty[k][a] > spotty[i][a]) end = k-1;
        else if (not_spotty[k][a] < spotty[i][a]) start = k+1;
    }

    if (k < not_spotty.size() && not_spotty[k][a] == spotty[i][a] && not_spotty[k][b] == spotty[i][b] && not_spotty[k][c] == spotty[i][c]) return true;
    return false;
}

int main() {
    ifstream in("cownomics.in");
    ofstream out("cownomics.out");

    int N, M;
    in >> N >> M;

    spotty.resize(N);
    not_spotty.resize(N);

    in.ignore();

    for (int j = 0; j < N; j++) {
        getline(in, spotty[j]);
    }

    for (int j = 0; j < N; j++) {
        getline(in, not_spotty[j]);
    }

    int result = 0;

    for (a = 0; a < M-2; a++) {
        for (b = a+1; b < M-1; b++) {
            for (c = b+1; c < M; c++) {
                sort(not_spotty.begin(), not_spotty.end(), sort_str);
                for (i = 0; i < N; i++) {
                    if (binary_search()) goto end;
                }
                result++;
                end:
                continue;
            }
        }
    }

    out << result << endl;

    return 0;
}