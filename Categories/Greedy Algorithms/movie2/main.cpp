// postponed_after_boredom

#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second  

bool mysort(pi &a, pi &b) {
    return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;

    multiset<pair<int, int>> s;

    for (int i = 0; i < N; i++) {
        pi p;
        cin >> p.y >> p.x;
        s.insert(p);
    }

    int size = s.size();
    for (int i = 0; i < K; i++) {
        auto it = s.begin();
        while (it != s.end()) {
            pi p = *it;
            s.erase(s.find(*it));
            it = s.upper_bound(p);
        }
    }

    cout << size-s.size() << '\n';
    
    return 0;
}