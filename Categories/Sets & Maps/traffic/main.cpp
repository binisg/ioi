#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    multiset<int> s;
    s.insert(0); s.insert(x);

    multiset<int> dist;
    dist.insert(x-0);

    int result[n];
    for (int i = 0; i < n; i++) {
        int ent; cin >> ent;
        s.insert(ent);
        auto f = s.find(ent);
        int to_erase = *(++f);
        f--;
        to_erase -= *(--f);
        f++;
        dist.erase(dist.find(to_erase));
        dist.insert(*f - *(--f));
        f++;
        dist.insert(*(++f) - *(--f));
        auto place = dist.end();
        result[i] = *(--place);
    }

    for (int i = 0; i < n; i++) cout << result[i] << ' ';
    cout << '\n';
    
    return 0;
}