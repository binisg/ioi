#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<pi> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].x >> vec[i].y;
    }
    sort(vec.begin(), vec.end());

    ll time = 0, result = 0;
    for (int i = 0; i < N; i++) {
        time += vec[i].x;
        result += (vec[i].y - time);
    }

    cout << result << '\n';

    return 0;
}