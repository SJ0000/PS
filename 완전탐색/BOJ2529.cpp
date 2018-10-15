#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;
vector<int> checker; // 0 : < , 1 : > 

bool valid(vector<int>& v) {
	int x, y;
	for (int i = 0; i < N; i++) {
		x = v[i]; y = v[i + 1];
		if (checker[i]) {
			if (x < y) return false;
		}
		else {
			if (x > y) return false;
		}
	}
	return true;
}

vector<int> getMax() {

	vector<int> perm;

	for (int i = 9; i >= 9 - N; i--) {
		perm.push_back(i);
	}
	do {
		if (valid(perm)) return perm;
	} while (prev_permutation(perm.begin(), perm.end()));

	return perm;
}

vector<int> getMin() {
	vector<int> perm;

	for (int i = 0; i <= N; i++) {
		perm.push_back(i);
	}

	do {
		if (valid(perm)) return perm;
	} while (next_permutation(perm.begin(), perm.end()));

	return perm;
}


int main()
{
	scanf("%d", &N);
	char c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == '<') {
			checker.push_back(0);
		}
		else {
			checker.push_back(1);
		}
	}

	vector<int> mymax = getMax();
	vector<int> mymin = getMin();
	for (int x : mymax) {
		printf("%d", x);
	}
	printf("\n");
	for (int x : mymin) {
		printf("%d", x);
	}
	printf("\n");

	return 0;
}