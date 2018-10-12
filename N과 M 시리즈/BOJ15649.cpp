#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>
using namespace std;

//1���� n���� �ߺ����� m��
int N, M;
bool check[10];
vector<int> picked;
void search() {
	if (picked.size() == M) {
		//���
		for (int x : picked) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			picked.push_back(i);
			check[i] = true;
			search();
			check[i] = false;
			picked.pop_back();
		}
	}
}

int main(void) {

	scanf("%d %d", &N, &M);	
	memset(check, false, sizeof(check));
	search();
	return 0;
}