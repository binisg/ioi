#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        string s; cin >> s;
        vector<int> vec(N);

        for (int i = 0; i < N; i++) {
            vec[i] = (int)s[i] - 48;
        }

        vector<ll> pre(N+1);
        for (int i = 0; i < N; i++) {
            pre[i+1] = pre[i] + vec[i];
        }

        map<ll, ll> m; m[0] = 1;
        ll result = 0;

        for (int i = 1; i <= N; i++) {
            if (m.count(pre[i]-i)) result += m[pre[i]-i];
            m[pre[i]-i]++;
        }

        cout << result << '\n';
    }

    return 0;
}