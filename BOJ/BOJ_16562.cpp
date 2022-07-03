#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>


using namespace std;

int parent[10001];
int fm[10001]; //친구비

int n, m, k;

int find(int n) {
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	//root에는 해당 묶음의 최소 가격이 저장됨.
	fm[parent[n]] = min(fm[n], fm[parent[n]]);
	return parent[n];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	//root에는 해당 묶음의 최소 가격이 저장됨.
	fm[a] = min(fm[a], fm[b]);
	parent[b] = a;
}
int main()
{		
	// 문제는 1~N이지만 0~N-1로 바꿔서 풀이.	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &fm[i]);
		parent[i] = -1;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	//친구비 지급
	int spend = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == -1) { 
			spend += fm[i];
		}
	}
	if (k >= spend) {
		printf("%d\n", spend);
	}
	else {
		printf("Oh no\n");
	}	
	return 0;
}