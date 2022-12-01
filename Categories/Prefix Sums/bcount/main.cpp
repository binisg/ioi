#include <iostream>
#include <vector>

using namespace std;

struct cows {
    int one = 0, two = 0, three = 0;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int N, Q; cin >> N >> Q;
    
    vector<cows> vec = {{}};
    for (int i = 0; i < N; i++) {
        vec.push_back(vec[vec.size()-1]);
        int x; cin >> x;
        if (x == 1) vec[i+1].one++;
        else if (x == 2) vec[i+1].two++;
        else vec[i+1].three++;
    }

    vector<cows> result(Q);
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        result[i].one = vec[b].one - vec[a-1].one;
        result[i].two = vec[b].two - vec[a-1].two;
        result[i].three = vec[b].three - vec[a-1].three;
    }

    for (auto i: result) {
        cout << i.one << ' ' << i.two << ' ' << i.three << '\n';
    }
    
    return 0;
}