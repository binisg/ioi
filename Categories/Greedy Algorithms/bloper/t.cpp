#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {-13, -3, -5, 5, 1, 11, -7, 3, -1, 9, -9, 1, -3, 7, 5, 15};
    sort (vec.begin(), vec.end());
    for (int i: vec) cout << i << " ";
    cout << endl;
    return 0;
}