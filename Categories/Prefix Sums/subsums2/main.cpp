#include <iostream>
#include <map>

using namespace std;

#define ll long long

int main() {
    int N, x; cin >> N >> x;

    map<ll, int> m; m[0] = 1;
    ll result = 0, sum = 0;

    while (N--) {
        int num; cin >> num;
        sum += num;
        if (m.count(sum-x)) result += m[sum-x];
        m[sum]++;
    }

    cout << result << '\n';

    return 0;
}