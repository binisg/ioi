#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
vector<unordered_map<int, bool>> adj;
vector<int> vec;
set<int> notv;

void dfs(int &i, int &c) {
    vec[i] = c;

    auto it = notv.begin();
    while (it != notv.end()) {
        if (!adj[i].count(*it)) {
            int num = *it;
            notv.erase(it);
            dfs(num, c);
            it = notv.upper_bound(num);
        } else {
            it++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    adj.resize(N); vec.resize(N); 
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a-1][b-1] = true;
        adj[b-1][a-1] = true;
    }

    for (int i = 0; i < N; i++) {
        notv.insert(i);
    }

    int c = -1;
    for (int i = 0; i < N; i++) {
        auto it = notv.find(i);
        if (it != notv.end()) {
            dfs(i, ++c);
        }
    }

    vector<int> final(c+1);
    for (int i = 0; i < N; i++) {
        final[vec[i]]++;
    }

    sort(final.begin(), final.end());

    cout << final.size() << '\n';
    for (int i = 0; i <= c; i++) {
        cout << final[i] << ' ';
    }
    cout << '\n';

    return 0;
}