#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;

    vector<int> vals(N); 
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }

    vector<int> dp(N, -1);

    for (int i = 0; i < N; i++) {
        int num = vals[i];
        for (int j = i; i-j+1 <= K && j >= 0; j--) {
            num = max(num, vals[j]);
            if (j > 0) dp[i] = max(dp[i], dp[j-1] + (num * (i-j+1)));
            else dp[i] = max(dp[i], num * (i-j+1));
        }
    }

    cout << dp[N-1] << '\n';

    return 0;
}