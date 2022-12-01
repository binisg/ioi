#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int N, K; cin >> N >> K;
    vector<int> vec(N);

    for (int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    int l = 0, r = 0, result = 0;
    for (l; l < N; l++) {
        while (vec[r]-vec[l] <= K && r < N-1 && vec[r+1]-vec[l] <= K) {
            r++;
        }
        result = max(result, r-l+1);
    }

    cout << result << '\n';

    return 0;
}