// to_be_solved

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    FILE *in = fopen("paintbarn.in", "r");
    FILE *out = fopen("paintbarn.out", "w");

    int N, K;
    fscanf(in, "%d%d", &N, &K);

    vector<vector<int>> arr(202, vector<int>(202, 0));

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fscanf(in, "%d%d%d%d", &x1, &y1, &x2, &y2);
        arr[y1][x1]++;
        arr[y2][x2]++;
        arr[y2][x1]--;
        arr[y1][x2]--;
    }

    for (int i = 200; i >= 0; i--) {
        for (int j = 200; j >= 0; j--) {
            arr[i][j] += ((arr[i+1][j]) + (arr[i][j+1]) - (arr[i+1][j+1]));
        }
    }

    // O(n)

    // for (int i = 9; i >= 0; i--) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}