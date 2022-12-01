#include <iostream>
#include <cstdio>
#include <vector> 
#include <algorithm>
#include <set>

using namespace std;

int main() {
    FILE *in = fopen("cardgame.in", "r");
    FILE *out = fopen("cardgame.out", "w");

    int N; fscanf(in, "%d", &N);

    set<int> op1, op2;
    for (int i = 0; i < N; i++) {
        int x;
        fscanf(in, "%d", &x);
        if (i < N/2) op1.insert(x);
        else op2.insert(x);
    }

    vector<int> v;
    set<int> me1, me2;
    int index = 1;
    while (v.size() != N) {
        if (!op1.count(index) && !op2.count(index)) {
            v.push_back(index);
        }
        index++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        if (i < N/2) me1.insert(v[i]);
        else me2.insert(v[i]);
    }

    int counter = 0;

    auto a = op1.begin();    
    while (me2.size() != 0) {
        while (me2.size() != 0 && *a > *me2.begin()) {
            me2.erase(*me2.begin());
        }
        if (me2.size() > 0) {
            counter++;
            me2.erase(*me2.begin());
        }
        a++;
    }

    auto a2 = op2.rbegin();
    while (me1.size() > 0) {
        while (me1.size() != 0 && *a2 < *me1.rbegin()) {
            me1.erase(*me1.rbegin());
        } 
        if (me1.size() > 0) {
            counter++;
            me1.erase(*me1.rbegin());
        }
        a2++;
    }

    fprintf(out, "%d\n", counter);

    return 0;
}