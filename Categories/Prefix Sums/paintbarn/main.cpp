#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    FILE *in = fopen("paintbarn.in", "r");
    FILE *out = fopen("paintbarn.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);

    vector<vector<int>> vec(1001, vector<int>(1001, 0));
    vector<vector<int>> sub(1001, vector<int>(1001, 0));

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fscanf(in, "%d%d%d%d", &x1, &y1, &x2, &y2);
        vec[y1][x2]++;
        vec[y1-1][x1-1]++;
        sub[y1-1][x2]++;
        sub[y2][x1-1]++;
    }

    int result = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (vec[i][j] > 0) result += (vec[i][j] * ((i+1) * (j+1)));
            if (sub[i][j] > 0) result -= (vec[i][j] * ((i+1) * (j+1)));
        }
    }

    cout << result << endl;

    return 0;
}