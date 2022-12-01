#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi; 
#define x first 
#define y second

vector<pi> vec;

bool f(int t, int N) {
    int index = 0, num = vec[0].x;
    while (N > 0 && index < vec.size()) {
        if (vec[index].x > num) num = vec[index].x;
        while (vec[index].y >= num) {
            num += t;
            N--;
        }
        index++;
    }
    return N <= 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int N, M; cin >> N >> M;
    vec.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> vec[i].x >> vec[i].y;
    }    

    sort(vec.begin(), vec.end());

    int a = 0, b = 1e9;
    while (a < b) {
        int mid = a + (b-a+1) / 2;
        if (f(mid, N)) {
            a = mid;
        } else {
            b = mid-1;
        }
    }

    cout << a << '\n';

    return 0;
}