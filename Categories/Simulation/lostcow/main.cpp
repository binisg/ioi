#include <iostream>

using namespace std;

int one (int x, int y) {
    int num = 1, result = 0, loc = x; bool f = false;

    while (loc < y) {
        if (!f) {
            result += (num/2) + num;
            loc += ((num/2) + num);
            f = true;
        } else {
            result += (num/2) + num;
            loc -= ((num/2) + num);
            f = false;
        }
        num *= 2;
    }

    result -= (loc - y);
    return result;
}

int two (int x, int y) {
    int num = 1, result = 0, loc = x; bool f = false;

    while (loc > y) {
        if (!f) {
            result += ((num/2) + num);
            loc += ((num/2) + num);
            f = true;
        } else {
            result += ((num/2) + num);
            loc -= ((num/2) + num);
            f = false;
        }
        num *= 2;
    }

    result -= (y - loc);
    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y; cin >> x >> y;

    if (x < y) cout << one(x, y) << '\n';
    else cout << two(x, y) << '\n';

    return 0;
}