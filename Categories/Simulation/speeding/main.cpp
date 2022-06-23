#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	FILE *in = fopen("speeding.in", "r");
	FILE *out = fopen("speeding.out", "w");
	int N, M;
	fscanf(in, "%d%d", &N, &M);
	int arr_N[100], arr_M[100];
	int i = 0, j = 0;

	while (N--) {
		int point, limit;
		fscanf(in, "%d%d", &point, &limit);
        point += i;
		for (i; i < point; i++) {
			arr_N[i] = limit;
		}
	}

	while (M--) {
		int point, limit;
		fscanf(in, "%d%d", &point, &limit);
        point += j;
		for (j; j < point; j++) {
			arr_M[j] = limit;
		}
    }

	int counter = 0;

    for (int i = 0; i < 100; i++) {
        if (arr_M[i] - arr_N[i] > counter) counter = arr_M[i] - arr_N[i];
    }

	fprintf(out, "%d", counter);

	fclose(in);
	fclose(out);

	return 0;
}