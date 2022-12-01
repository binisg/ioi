#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long 

int result = 0;
vector<int> is(1e5+5, 0), ret, factors;

vector<int> find_factors(int &num) {
    ret = {};

    int limit = sqrt(num);
    for (int i = 1; i <= limit; i++) {
        if (num % i == 0) {
            ret.push_back(i);
        }
    }

    return ret;
}

void solve(int &num) {
    factors = find_factors(num);
    for (auto &i: factors) {
        if (i != num/i) {
            if (is[i] && is[num/i]) 
                result += is[i] * is[num/i];
        } else {
            if (is[i] > 1) 
                result += (is[i]*(is[i]-1))/2;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, k; cin >> N >> k;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        is[vec[i]]++;
    }

    sort(vec.begin(), vec.end());
    ll max_num = (vec.size() > 1) ? vec[vec.size()-1] * vec[vec.size()-2] : vec[0] * vec[0];

    vector<int> el = {1};

    for (int i = 2; ; i++) {
        ll p = pow(i, k);
        if (p > max_num) break;
        else el.push_back(p);
    }        

    for (auto &i: el) {
        solve(i);
    }

    cout << result << '\n';

    return 0;
}