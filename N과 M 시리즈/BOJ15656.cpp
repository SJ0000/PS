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
vector<int> li;
bool check[10];
void search() {
	if (picked.size() == M) {
		for (int x : picked) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		picked.push_back(li[i]);
		search();
		picked.pop_back();
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	int val;
	memset(check, false, sizeof(check));
	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		li.push_back(val);
	}
	sort(li.begin(), li.end());
	search();
	return 0;
}