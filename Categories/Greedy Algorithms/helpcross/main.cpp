#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pi; 
#define x first 
#define y second 

void setIO(string s) {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool mysort(pi &a, pi &b) {
    return a.y < b.y;
}

int main() {
    setIO("helpcross");

    int C, N;
    cin >> C >> N;

    multiset<int> ch; vector<pi> cows(N);
    for (int i = 0; i < C; i++) {
        int x; cin >> x; ch.insert(x);
    }
    for (int i = 0; i < N; i++) cin >> cows[i].x >> cows[i].y;

    sort(cows.begin(), cows.end(), mysort);

    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (ch.size() == 0) break;
        auto it = ch.lower_bound(cows[i].x);
        if (*it >= cows[i].x && *it <= cows[i].y) {
            ch.erase(ch.find(*it));
            counter++;
        }
    }

    cout << counter << '\n';

    return 0;
}