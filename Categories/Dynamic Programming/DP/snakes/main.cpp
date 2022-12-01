#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;

    vector<int> vals(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> vals[i];
    }

    vector<vector<int>> dp(N+1, vector<int> (K+1));

    int max_num = 0, sum = 0;
    for (int i = 1; i <= N; i++) {
        max_num = max(max_num, vals[i]);
        dp[i][0] = max_num * i;

        for (int j = 1; j <= K; j++) {
            dp[i][j] = INT32_MAX;
            int num = vals[i];
            for (int k = i-1; k >= 0; k--) {
                dp[i][j] = min(dp[i][j], dp[k][j-1] + num * (i-k));
                num = max(num, vals[k]);
            }
        }

        sum += vals[i];
    }

    cout << dp[N][K] - sum << '\n';

    return 0;
}