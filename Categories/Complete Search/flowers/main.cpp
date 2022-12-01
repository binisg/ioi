#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> vec;

int ok(int size, int sum, unordered_set<int> &s) {
    double d = (double)sum/(double)size;
    int can = d;
    if ((double)d != (double)can) return false;
    else return s.count(can);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    vec.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    vector<int> pre(N+1);
    for (int i = 0; i < N; i++) {
        pre[i+1] = pre[i] + vec[i];
    }
    
    int counter = N; 
    for (int i = 0; i < N; i++) {
        unordered_set<int> s;
        s.insert(vec[i]);
        for (int j = i+1; j < N; j++) {
            s.insert(vec[j]);
            if (ok(j-i+1, pre[j+1]-pre[i], s)) counter++;
        }
    }

    cout << counter << '\n';

    return 0;
}