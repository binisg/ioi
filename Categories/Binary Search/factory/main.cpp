#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long 

vector<int> vec;

bool f(ll x, int T) {
    ll sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > x) return false;
        sum += ((ll)x/(ll)vec[i]);
        if (sum >= T) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, T; cin >> N >> T;
    vec.resize(N);

    for (int i = 0; i < N; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    ll l = 0, r = 1e9*1e9;
    while (l < r) {
        ll mid = (l+r)/2;
        if (f(mid, T)) r = mid;
        else l = mid+1;
    }

    cout << l << '\n';

    return 0;
}