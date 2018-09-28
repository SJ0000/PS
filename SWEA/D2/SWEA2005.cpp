#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;
int pas[10][10];

void printPas(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", pas[i][j]);
		}
		printf("\n");
	}
}
int main()
{	
	int T;
	cin >> T;
	pas[0][0] = 1;
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || (j==i)) {
				pas[i][j] = 1;
				continue;
			}
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}
	int n;
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		printf("#%d\n", t);
		printPas(n);
	}
	return 0;
}