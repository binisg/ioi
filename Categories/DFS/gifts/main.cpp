// to_be_solved

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<vector<int>> arr(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    unordered_map<int, bool> memo;
    int res[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!memo.count(arr[i][j])) {
                res[i] = arr[i][j];
                memo[arr[i][j]] = true;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}