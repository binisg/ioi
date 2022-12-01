#include <iostream>
#include <set>
#include <vector>

using namespace std;

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;

    multiset<int> s;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; s.insert(x);
    }

    cin.ignore();
    vector<int> vec(M);
    for (int i = 0; i < M; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < M; i++) {
        if (s.empty()) {
            cout << -1 << '\n';
            continue;
        }
        auto it = s.lower_bound(vec[i]);
        if (it == s.end()) it--;
        else if (*it > vec[i]) {
            if (it == s.begin()) {
                cout << -1 << '\n';
                continue;
            } else it--;
        } 
        cout << *it << '\n';
        s.erase(s.find(*it));
    }

    return 0;
}