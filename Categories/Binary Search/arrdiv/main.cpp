#include <iostream>
#include <vector>

using namespace std;

#define ll long long 

vector<int> vec;

bool f(ll x, int K) {
    ll sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        if (sum > x) return false;
        if (i != vec.size()-1 && vec[i+1]+sum > x) {
            sum = 0;
            K--;
        }
        if (i == vec.size()-1) K--;
        if (K < 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;
    vec.resize(N);

    for (int i = 0; i < N; i++) cin >> vec[i];

    long long l = 0, r = 1e9*vec.size();
    while (l < r) {
        ll mid = (l+r)/(long long)2;
        if (f(mid, K)) r = mid;
        else l = mid+1;
    }

    cout << l << '\n';

    return 0;
}