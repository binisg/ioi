#include <iostream>
#include <map>

using namespace std;

bool f(int &x, string &abc, int &num) {
    int counter = 0;
    map<char, int> m;

    int a = 0, b = x;
    string s;

    for (int i = a; i < b; i++) {
        char c = abc[i];
        s += c;
        m[c]++;
        if (m[c] == 1) counter++;
    }

    if (counter == num) return true;

    while (b < abc.size()) {
        m[abc[a]]--;
        if (m[abc[a]] == 0) counter--;
        a++;
        m[abc[b]]++;
        if (m[abc[b]] == 1) counter++;
        b++;
        if (counter == num) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    string s; cin >> s;

    int counter = 0;
    map<char, int> seen;

    for (auto c: s) {
        if (seen[c] == 0) {
            seen[c] = 1;
            counter++;
        }
    } 

    int a = 1, b = N, mid;
    while (a < b) {
        mid = (a+b)/2;
        if (f(mid, s, counter)) {
            b = mid;
        } else {
            a = mid+1;
        }
    }

    cout << b << '\n';

    return 0;
}