#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second

struct event {
    int num, a, b;
};

pi solve(vector<event> &vec) {
    int d = 0, u = 1e9;
    
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].num == 0) {
            d = max(d, vec[i].a);
            u = min(u, vec[i].b);
        } else if (vec[i].num == 1) {
            u += max(vec[i].a, vec[i].b);
            d += min(vec[i].a, vec[i].b);
        } else {
            d -= min(max(vec[i].a, vec[i].b), d);
            u -= min(min(vec[i].a, vec[i].b), u);
        }
    }

    return {d, u};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int N; cin >> N;
    vector<event> vec(N);

    for (int i = 0; i < N; i++) {
        string s; cin >> s;

        if (s == "none") vec[i].num = 0;
        else if (s == "on") vec[i].num = 1;
        else vec[i].num = 2;

        cin >> vec[i].a >> vec[i].b;
    }

    pi last, first;
    last = solve(vec);

    reverse(vec.begin(), vec.end());
    for (int i = 0; i < N; i++) {
        if (vec[i].num == 1) vec[i].num = 2;
        else if (vec[i].num == 2) vec[i].num = 1;
    }

    first = solve(vec);

    cout << first.x << ' ' << first.y << '\n';
    cout << last.x << ' ' << last.y << '\n';

    return 0;
}