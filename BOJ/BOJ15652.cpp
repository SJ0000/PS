#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>
using namespace std;

//1부터 n까지 중복없이 m개
int N, M;
vector<int> picked;
void search() {
	if (picked.size() == M) {
		//출력
		int st = picked[0];
		for (int x : picked) {
			if (x < st) {
				return;
			}
			else {
				st = x;
			}
		}
		for (int x : picked) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		picked.push_back(i);
		search();
		picked.pop_back();
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	search();
	return 0;
}