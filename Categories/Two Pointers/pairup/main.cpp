#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

typedef pair<int, int> pi;
#define x first 
#define y second 

int main() {
    setIO("pairup");

    int N; cin >> N; deque<pi> d;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        d.push_back({y, x});
    }

    sort(d.begin(), d.end());

    int max_num = 0;
    while (!d.empty()) {
        max_num = max(max_num, d.front().x + d.back().x);
        if (d.front().y < d.back().y) {
            d.back().y -= d.front().y;
            d.front().y = 0;
        } else {
            d.front().y -= d.back().y;
            d.back().y = 0;
        }
        if (d.front().y == 0) d.pop_front();
        if (!d.empty()) {
            if (d.back().y == 0) d.pop_back();
        }
    }

    cout << max_num << '\n';

    return 0;
}