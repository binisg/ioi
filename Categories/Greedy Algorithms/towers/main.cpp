#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    multiset<int> s;
    for (int i = 0; i < N; i++) { 
        int x; cin >> x;
        if (s.empty()) s.insert(x);
        else {
            auto it = s.upper_bound(x);
            if (it == s.end()) it--;
            if (x < *it) {
                s.erase(s.find(*it));
                s.insert(x);
            } else s.insert(x);
        }
    }

    cout << s.size() << '\n';

    return 0;
}