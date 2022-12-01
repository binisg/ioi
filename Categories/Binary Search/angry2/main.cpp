// didnt work
// find another way for f(x) to work

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

bool f(int r) {
    if (r == 5) {
        r++;
        r--;
    }
    int counter = 1, mid = (vec.back()+vec[0])/2;
    int i = 1;
    for (i = 1; i < vec.size(); i++) {
        if (vec[i] > mid) break;
        if (vec[i]-vec[i-1] > r) return false;
        if (vec[i]-vec[i-1] <= counter) counter++;
        else counter = vec[i]-vec[i-1];
        if (counter > r) return false;
    }

    counter = r-1;
    if (vec[i] - vec[i-1] > r*2) return false;
    else if (vec[i]-vec[i-1] <= r && i < vec.size()-1) {
        if (vec[i+1]-vec[i] > r) return false;
    } 
    i++;

    for (i; i < vec.size(); i++) {
        if (vec[i]-vec[i-1] > r) return false;
        if (vec[i]-vec[i-1] <= counter) counter--;
        else counter = vec[i]-vec[i-1];
        if (counter < 0) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int N; cin >> N; vec.resize(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    int l = 0, h = 1e9;
    while (l < h) {
        int mid = (l+h)/2;
        if (f(mid)) h = mid;
        else l = mid+1;
    }

    double result = (double)l;
    cout.precision(1);
    cout << fixed << result << '\n';

    return 0;
}