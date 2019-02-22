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
int fm[10001]; //ģ����

int n, m, k;

int find(int n) {
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	//root���� �ش� ������ �ּ� ������ �����.
	fm[parent[n]] = min(fm[n], fm[parent[n]]);
	return parent[n];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	//root���� �ش� ������ �ּ� ������ �����.
	fm[a] = min(fm[a], fm[b]);
	parent[b] = a;
}
int main()
{		
	// ������ 1~N������ 0~N-1�� �ٲ㼭 Ǯ��.	
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
	//ģ���� ����
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