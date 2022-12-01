#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<array<int, 3>> prefix_counts{{}};
	string s;
	cin >> s;
	for (char c : s) {
		prefix_counts.push_back(prefix_counts.back());
		if (c == 'C') ++prefix_counts.back()[0];
		if (c == 'O') ++prefix_counts.back()[1];
		if (c == 'W') ++prefix_counts.back()[2];
	}
	int Q;
	cin >> Q;
	string ans;
	while (Q--) {
		int l, r;
		cin >> l >> r;
		array<int, 3> query_counts;
		for (int i = 0; i < 3; ++i) {
			query_counts[i] = prefix_counts[r][i] - prefix_counts[l - 1][i];
		}
		ans += ((query_counts[1] + query_counts[2]) % 2 == 0 &&
		        (query_counts[0] + query_counts[1]) % 2 == 1)
		           ? 'Y'
		           : 'N';
	}
	cout << ans << "\n";
}