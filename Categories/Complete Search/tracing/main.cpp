#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
#define MAX_K 100000005

struct greet {
    int time, x, y;
};

int sorting(greet a, greet b) {
    if (a.time > b.time) return 0;
    return 1;
}

pi findk(int &N, int &e, vector<greet> &vec, string &final_str) {
    bool uno = false, limit = false;
    pi to_return = {MAX_K, -1};
    for (int i = 0; i < max((int)vec.size(), N); i++) {
        if (limit) break;
        string s;
        for (int i = 0; i < N; i++) s.push_back('0');
        s[e] = '1';
        vector<int> times(N, i);
        for (int j = 0; j < vec.size(); j++) {
            uno = false;
            int a = vec[j].x-1, b = vec[j].y-1;
            if (s[a] == '1' && s[b] == '0') {
                if (times[a] > 0) {
                    times[a]--;
                    s[b] = '1';
                }
            } else if (s[a] == '0' && s[b] == '1') {
                if (times[b] > 0) {
                    times[b]--;
                    s[a] = '1';
                }
            } else if (s[a] == '1' && s[b] == '1') {
                if (times[a] > 0) times[a]--;
                if (times[b] > 0) times[b]--;
            }
        }
        for (int i = 0; i < times.size(); i++) {
            if (times[i] == 0) goto skip;
        }
        limit = true;
        skip:
        if (s != final_str) continue;
        else {
            if (to_return.first == MAX_K) to_return.first = i;
            if (i > to_return.second) to_return.second = i;
            uno = true;
        }
    }
    if (uno) to_return.second = -1;
    return to_return;
}

int main() {
    ifstream in ("tracing.in");
    ofstream out ("tracing.out");

    int N, T;
    in >> N >> T;
    in.ignore();

    string final_str;
    getline(in, final_str);

    vector<greet> vec (T);
    
    for (int i = 0; i < T; i++) {
        in >> vec[i].time >> vec[i].x >> vec[i].y;
    }

    sort(vec.begin(), vec.end(), sorting);

    int K = 0, min_k = MAX_K, max_k = -1;

    for (int i = 0; i < N; i++) {
        if (final_str[i] != '1') continue;
        pi p = findk(N, i, vec, final_str);
        if (p.first != MAX_K) K++;
        if (p.first < min_k) min_k = p.first;
        if (p.second > max_k) max_k = p.second;
    }

    out << K << " ";

    if (min_k == MAX_K) out << "Infinity ";
    else out << min_k << " ";

    if (max_k == -1) out << "Infinity\n";
    else out << max_k << "\n";

    return 0;
}