#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    vector<int> Ns(T);
    vector<int> max_nums(T);
    vector<vector<int>> vecs(T);

    for (int i = 0; i < T; i++) {
        int N, max_num = 0;
        scanf("%d", &N);
        vector<int> to_add (N);
        Ns[i] = N;
        for (int j = 0; j < N; j++) {
            scanf("%d", &to_add[j]);
            if (to_add[j] > max_num) max_num = to_add[j];
        }
        vecs[i] = to_add;
        max_nums[i] = max_num;
    }

    for (int l = 0; l < T; l++) {
        int N = Ns[l];

        vector<int> vec = vecs[l];
        int max_num = max_nums[l];

        int sum = 0, index = 0, counter = -1;
        for (index = 0; index < vec.size(); index++) {
            sum += vec[index];
            counter++;
            if (sum >= max_num) break;
        }

        int result = 0, curr_counter = -1, to_add = 0;

        if (index == vec.size()-1) {
            result = vec.size()-1;
            printf("%d\n", result);
            goto final;
        }

        for (int i = index+1; i < vec.size(); i++) {
            int curr_sum = 0;
            for (int j = i; j < vec.size(); j++) {
                i++;
                curr_sum += vec[j];
                if (curr_sum < sum && j != vec.size()-1) {
                    curr_counter++;
                    continue;
                } else if (curr_sum == sum) {
                    curr_counter++;
                    to_add += curr_counter;
                    curr_sum = 0;
                    curr_counter = -1;
                    continue;
                } else {
                    curr_counter = -1;
                    to_add = 0;
                    index++;
                    sum += vec[index];
                    counter++;
                    if (index == vec.size()-1) {
                        result = vec.size()-1;
                        printf("%d\n", result);
                        goto final;
                    }
                    i = index;
                    goto end;
                }
            }
            end:
            continue;
        }
        counter += to_add;
        printf("%d\n", counter);
        final:
        continue;
    }

    return 0;
}