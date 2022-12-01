#include <iostream>
#include <vector>

using namespace std;

#define MAX_T 1000

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0);

    int N, M, C; cin >> N >> M >> C;

    vector<int> earn(N);
    for (int i = 0; i < N; i++) cin >> earn[i];

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
    }

    vector<vector<int>> vec(MAX_T+1, vector<int>(N, -1));
    vec[0][0] = 0;
    
    int result = 0;
    for (int i = 0; i < MAX_T; i++) {
        for (int j = 0; j < N; j++) {
            if (vec[i][j] != -1) {
                for (auto x: adj[j]) {
                    vec[i+1][x] = max(vec[i+1][x], vec[i][j] + earn[x]);
                }
            }
        }
        result = max(result, vec[i][0] - C * i * i);
    }

    cout << result << '\n';

    return 0;
}