#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct event {
    int time;
    int num;
    bool start;
};

bool mysort(event &a, event &b) {
    return a.time < b.time;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int N; cin >> N;
    vector<event> vec;

    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        vec.push_back({a, c, true});
        vec.push_back({b, c, false});
    }

    sort(vec.begin(), vec.end(), mysort);

    int result = 0, buckets = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].start) {
            if (vec[i].num > buckets) {
                result += (vec[i].num - buckets);
                buckets = 0;
            } else {
                buckets -= vec[i].num;
            }
        } else {
            buckets += vec[i].num;
        }
    }

    cout << result << '\n';

    return 0;
}
