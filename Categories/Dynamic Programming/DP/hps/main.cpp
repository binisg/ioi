#include <iostream>
#include <vector>

using namespace std;


int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0);


    int N, K; cin >> N >> K;
    vector<char> letters(N);

    for (int i = 0; i < N; i++) {
        cin >> letters[i];
    }

    vector<vector<int>> dp(K+1, vector<int> (3, 0));
    char letter; int num;

    for (int i = 0; i < N; i++) {
        letter = letters[i];
        if (letter == 'P') num = 0;
        else if (letter == 'H') num = 1;
        else num = 2;

        for (int j = 0; j <= K; j++) {
            dp[j][num]++;
            if (j != 0) {
                for (int k = 0; k < 3; k++) {
                    if (k == num) continue;
                    dp[j-1][num] = max(dp[j-1][num], dp[j][k]+1);
                }
            }
        }
    }

    int result = 0;
    for (int j = 0; j <= K; j++) {
        result = max(result, dp[j][0]);
        result = max(result, dp[j][1]);
        result = max(result, dp[j][2]);
    }

    cout << result << '\n';

    return 0;
}