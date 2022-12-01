#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long 

vector<int> vec; int N, sum = 0;

bool f(int x) {
    vector<ll> p(vec.size()+1), m(vec.size()+1); p[0] = 0; m[0] = 0; 

    for (int i = 1; i <= vec.size(); i++) {
        p[i] = p[i-1]+(vec[i]-x);
    }

    for (int i = 1; i <= vec.size(); i++) {
        m[i] = min(p[i], m[i-1]);
    }

    for (int i = 1; i <= vec.size(); i++) {
        if (p[i] >= m[i-1]) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);

    cin >> N; vec.resize(N-2);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (i != 0 && i != N-1) {
            vec[i-1] = x;
        }   
        sum += x;
    }

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (f(mid)) {
            l = mid;
        } else r = mid-1;
    }

    cout << l << '\n';

    return 0;
}