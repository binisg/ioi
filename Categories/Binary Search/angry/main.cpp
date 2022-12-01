#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

void setIO (string s) {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool ok (int x, int K) {
    int start = vec[0], cows = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] <= start + 2*x) continue;
        else {
            start = vec[i];
            cows++;
        }
    }
    if (cows <= K) return true;
    return false;
}

int main() {
    setIO("angry");
    
    int N, K; cin >> N >> K;
    vec.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int z = vec[vec.size()-1], x = -1;
    for (int i = z; i >= 1; i /= 2) {
        while (!ok(i+x, K)) x += i;
    }
    int k = x+1;

    cout << k << '\n';

    return 0;
}