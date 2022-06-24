#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 8;

    int start = 0, end = vec.size(), k;

    while (start <= end) {
        k = (start+end)/2;
        if (vec[k] == x) break;
        else if (vec[k] < x) start = k+1;
        else end = k-1;
    }

    if (vec[k] == x) cout << "found\n";
    else cout << "not found\n";

    return 0;
}