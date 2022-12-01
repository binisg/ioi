#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pi;
#define x first
#define y second 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pi> vec;
    for (int i = 0; i < N; i++) {
        pi a, b;
        cin >> a.x >> b.x;
        a.y = 1; b.y = 0;
        vec.push_back(a);
        vec.push_back(b);
    }

    sort(vec.begin(), vec.end());

    int max_num = 0, curr_num = 0;
    for (int i = 0; i < vec.size(); i++) {
            if (vec[i].y) {
                curr_num++;
                max_num = max(max_num, curr_num);
            } else curr_num--;
    }

    cout << max_num << '\n';

    return 0;
}