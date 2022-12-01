#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, sum; cin >> N >> sum;
    vector<int> vec(N);
    
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    
    vector<pair<bool, int>> dp(sum+1, {false, -1});
    
    dp[0] = {true, 0};
    for (int i = 0; i < sum; i++) {
        if (dp[i].first == false) continue;
        for (int j = 0; j < N; j++) {
            int num = i+vec[j];
            if (num <= sum) {
                if (dp[num].first == false) {
                    dp[num] = {true, dp[i].second + 1};
                } else {
                    dp[num].second = min(dp[num].second, dp[i].second + 1);
                }
            }
        }
    }
    
    cout << dp[sum].second << '\n';

    return 0;
}
