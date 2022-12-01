#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
#define x first 
#define y second

int main() {
    int n, x;
    scanf("%d%d", &n, &x);

    vector<pi> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].x);
        arr[i].y = i+1;
    }

    sort(arr.begin(), arr.end());

    vector<int> result(3);

    for (int m = 1; m < n-1; m++) {
        int i = 0, j = n-1;
        while (i != j) {
            if (i == m) {
                i++;
                continue;
            } else if (j == m) {
                j--;
                continue;
            }
            int temp = arr[i].x + arr[m].x + arr[j].x;
            if (temp == x) {
                result = {arr[i].y, arr[m].y, arr[j].y};
                goto end;
            }
            else if (temp > x) j--;
            else i++;
        }
    }

    end:
    sort(result.begin(), result.end());
    if (result[2] == 0) cout << "IMPOSSIBLE\n";
    else printf("%d %d %d\n", result[0], result[1], result[2]);
    
    return 0;
}