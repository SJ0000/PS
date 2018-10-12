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
void search(int st) {
	if (picked.size() == M) {
		//출력
		for (int x : picked) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	for (int i = st; i <= N; i++) {
		picked.push_back(i);
		search(i + 1);
		picked.pop_back();
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	search(1);
	return 0;
}