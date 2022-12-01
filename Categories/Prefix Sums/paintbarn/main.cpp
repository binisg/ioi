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

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fscanf(in, "%d%d%d%d", &x1, &y1, &x2, &y2);
        x1++; y1++; x2++; y2++;
        vec[x1][y1]++;
        vec[x2][y2]++;
        vec[x1][y2]--;
        vec[x2][y1]--;
    }

    // 2 3 4 5

                 // 0 - 0 1 0
    // 0 0 - 0 1 // 0 0 0 0 0
    // 0 0 0 0 0 // 0 1 0 - 0
    // 0 0 1 0 - // 0 0 0 0 0
    // 0 0 0 0 0 // 0 0 0 0 0 

    for (int i = 8; i >= 0; i--) {
        cout << "[ ";
        for (int j = 0; j < 9; j++) {
            if (vec[i][j] != -1) cout << vec[i][j] << " ";
            else cout << "- ";
        }
        cout << "]\n";
    }

    cout << endl;

    int result = 0;
    for (int i = 1; i < 1000; i++) {
        for (int j = 1; j < 1000; j++) {
            vec[i][j] += ((vec[i-1][j]) + (vec[i][j-1]) - (vec[i-1][j-1]));
            if (vec[i][j] == K) result++;
        }
    }

    for (int i = 8; i >= 0; i--) {
        cout << "[ ";
        for (int j = 0; j < 9; j++) {
            if (vec[i][j] != -1) cout << vec[i][j] << " ";
            else cout << "- ";
        }
        cout << "]\n";
    }

    fprintf(out, "%d\n", result);

    return 0;
}