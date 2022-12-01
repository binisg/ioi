#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void setIO(string s) {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N, M, C;

bool ok(int x, vector<int> &vec) {
    queue<int> q;
    for (int i: vec) q.push(i);
    int mcounter = 0, ccounter = 0;
    while (!q.empty() && mcounter < M) {
        int num = q.front(); q.pop(); ccounter = 1;
        while (!q.empty() && q.front() - num <= x && ccounter < C) {
            q.pop();
            ccounter++;
        }
        mcounter++;
        ccounter = 0;
    }
    if (mcounter > M || !q.empty()) return false;
    return true;
}   

int main() {
    setIO("convention");

    cin >> N >> M >> C;
    vector<int> vec(N);

    for (int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    int z = vec[vec.size()-1] - vec[0], x = -1;
    for (int i = z; i >= 1; i /= 2) {
        while (!ok(x+i, vec)) x += i;
    }
    int k = x+1;

    cout << k << '\n';

    return 0;
}