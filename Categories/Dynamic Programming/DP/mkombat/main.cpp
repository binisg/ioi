#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9+5

int solve(vector<int> &vec, int &n) {
    vector<int> res1(n+1, INF);
    vector<int> res2(n+1, INF);

    res2[0] = 0; res1[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            res1[i] = min(res1[i], res2[i-1]);
            if (i != n) res1[i+1] = min(res1[i+1], res2[i-1]);
        }

        int val, val2;
        if (vec[i-1] == 1) val = 1;
        else val = 0;

        res2[i] = min(res2[i], res1[i-1]+val);

        if (i != n) {
            if (vec[i] == 1) val2 = 1;
            else val2 = 0;

            res2[i+1] = min(res2[i+1], res1[i-1]+val+val2);
        }
    }

    return min(res1[n], res2[n]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        cout << solve(vec, n) << '\n';
    }

    return 0;
}