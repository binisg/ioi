#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second 

bool mypisort(pi &a, pi &b) {
    if (a.x < b.x) return true;
    else if (a.x > b.x) return false;
    else return a.y > b.y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int N; cin >> N;
    
    vector<pi> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].x >> vec[i].y;
    }

    sort(vec.begin(), vec.end(), mypisort);

    vector<int> dif; bool zero = false;
    int sum = 0, far = 0;

    for (int i = 0; i < vec.size(); i++) {
        int add = 0;
        if (vec[i].y > far) {
            if (vec[i].x < far) {
                add = vec[i].y - far;
                if (dif.size() != 0) dif.back() -= vec[i-1].y - vec[i].x;
            } else add = vec[i].y - vec[i].x;
            sum += add;
            far = vec[i].y;
        }
        if (add == 0) zero = true;
        else dif.push_back(add);
    }

    int min_dif = 1e9;
    for (auto i: dif) min_dif = min(min_dif, i);
    if (zero) min_dif = 0;

    cout << sum - min_dif << '\n';

    return 0;
}