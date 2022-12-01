// postponed_to_be_solved_from_beggining

// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <map>
// #include <stack>
// #include <unordered_map>

// using namespace std;

// #define MAX_N 100005

// void assign (stack<int> s, unordered_map<int, int> &add, int &counter) {
//     if (counter == 0) return;
//     while (!s.empty()) {
//         add[s.top()] += counter;
//         s.pop();
//     }
// }

// int my_upper_bound (map<int, int> &m, int &x) {
//     if (!m.count(x)) m[x] = -1;
//     map<int, int>::iterator it = m.find(x);
//     if (m[x] == -1 && x != 0) it--;
//     pair<int, int> p = *it;
//     if (m[x] == -1) m.erase(x);
//     return p.second;
// }

// int main() {
//     FILE *in = fopen("snowboots.in", "r");
//     FILE *out = fopen("snowboots.out", "w");

//     int N, Q;
//     fscanf(in, "%d%d", &N, &Q);

//     vector<int> vec(N);
//     for (int i = 0; i < N; i++) fscanf(in, "%d", &vec[i]);

//     map<int, int> m; m[1000000000] = 0;
//     stack<int> s; s.push(0);
//     unordered_map<int, int> add;

//     for (int i = 1; i < N; i++) {
//         int counter = 0;
//         while (!s.empty() && s.top() >= vec[i]) {
//             m[s.top()] = max(m[s.top()], counter+add[s.top()]);
//             add[s.top()] = 0;
//             s.pop();
//             counter++;
//         }
//         assign(s, add, counter);
//         s.push(vec[i]);
//     }

//     for (auto i: m) {
//         cout << i.first << " " << i.second << endl;
//     }

//     for (auto i = m.rbegin(); i != m.rend(); i++) {
//         if (i != m.rbegin()) m[i->first] = max(i->second, prev(i)->second);
//     }

//     cout << endl;

//     for (auto i: m) {
//         cout << i.first << " " << i.second << endl;
//     }

//     vector<int> result(Q);

//     for (int i = 0; i < Q; i++) {
//         int x, y;
//         fscanf(in, "%d%d", &x, &y);
//         int val = my_upper_bound(m, x);
//         // cout << x << " " << y << " " << val << " ";
//         if (y > val) result[i] = 1;
//         else result[i] = 0;
//         // cout << result[i] << '\n';
//     }

//     for (int i = 0; i < Q; i++) {
//         fprintf(out, "%d\n", result[i]);
//     }

//     return 0;
// }