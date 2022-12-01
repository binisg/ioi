#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_N 2000000000

int mymax(int a, int b) {
    if (a >= 0) {
        if (b >= 0) {
            return max(a, b) - min(a, b);
        } else {
            return a + abs(b);
        }
    } else {
        if (b >= 0) {
            return abs(a) + b;
        } else {
            return max(-a, -b) - min(-a, -b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    set<int> s;
    for (int i = 0; i < M; i++) {
        int x; cin >> x; s.insert(x);
    }

    vector<int> dif(N, MAX_N);
    for (int i = 0; i < N; i++) {
        auto it = s.lower_bound(vec[i]);
        if (it == s.end()) it--;
        dif[i] = min(dif[i], mymax(vec[i], *it));
        if (it != s.begin() && *it > vec[i]) {
            it--;
            dif[i] = min(dif[i], mymax(vec[i], *it));
        }
    }

    int max_dif = 0;
    for (int i = 0; i < N; i++) {
        max_dif = max(max_dif, dif[i]);
    }

    cout << max_dif << '\n';

    return 0;
}