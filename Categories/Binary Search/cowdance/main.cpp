#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void setIO(string s) {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N, T;
bool canT(int k, queue<int> q) {
    priority_queue<int> pq;
    int time = 0;
    while (time <= T) {
        while (pq.size() < k && q.size() > 0) {
            pq.push(-(time+q.front()));
            q.pop();
        }
        if (pq.size() == 0) break;
        int val = -pq.top();
        time = val;
        pq.pop();
        while (pq.size() > 0 && pq.top() == -val) pq.pop();
    }
    if (time > T) return false;
    return true;
}

int main() {
    setIO("cowdance");
    cin >> N >> T;

    queue<int> q;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; q.push(x);
    }

    int x = -1;
    for (int b = T+1; b >= 1; b /= 2) {
        while (!canT(x+b, q)) x += b;
    }
    int k = x+1;

    cout << k << '\n';
    
    return 0;
}