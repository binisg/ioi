#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<int> factor(ll n) {
    vector<int> ret;
    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1) ret.push_back(n);
    return ret;
}

int num(int n) {
    int counter = 0, curr_num = 1;

    while (n - curr_num >= 0) {
        n -= curr_num;
        curr_num++;
        counter++;
    }

    return counter;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> vec = factor(n);

    vector<int> final; int sum = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[i-1]) sum++;
        else {
            final.push_back(sum);
            sum = 1;
        }
    }

    if (sum != 0) final.push_back(sum);

    int result = 0;
    for (int i = 0; i < final.size(); i++) {
        result += num(final[i]);
    }

    cout << result << '\n';

    return 0;
}