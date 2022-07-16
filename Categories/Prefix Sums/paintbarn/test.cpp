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
    vector<vector<int>> sum(1001, vector<int>(1001, 0));

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fscanf(in, "%d%d%d%d", &x1, &y1, &x2, &y2);
        vec[y1][x2]++;
        vec[y2+1][x1-1]++;
        vec[y2+1][x2]--;
        vec[y1][x1-1]--;
    }

    for (int i = 8; i >= 0; i--) {
        cout << "[ ";
        for (int j = 0; j < 9; j++) {
            if (vec[i][j] != -1) cout << vec[i][j] << " ";
            else cout << "- ";
        }
        cout << "]\n";
    }

    cout << endl;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 999; j >= 1; j--) {
            sum[i][j] = ((sum[i-1][j]) + (sum[i][j+1]) + (vec[i][j])) - (sum[i-1][j+1]);
        }
    }

    for (int i = 8; i >= 0; i--) {
        cout << "[ ";
        for (int j = 0; j < 9; j++) {
            cout << sum[i][j] << " ";
        }
        cout << "]\n";
    }

    int result = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (sum[i][j] == K) result++;
        }
    }

    cout << result << endl;

    return 0;
}