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

/*
	dist[a][b] �� -1�̸� a�� b���� ����,
	dist[a][b] �� 1�̸� a�� b���� ���߿�.
*/

const int maxn = 401;
int n, m;
int dist[maxn][maxn];

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//i,k / k,j �� 0�� �ƴϸ鼭 ������� 
				// ���� �Ͼ ������, ���߿� �Ͼ ������ i-k-j�� ���� ������� �̾���.
				if (dist[i][k] == dist[k][j] && dist[i][k] != 0) {
					dist[i][j] = dist[i][k];
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		dist[a][b] = -1;
		dist[b][a] = 1;
	}

	floyd();

	int t;
	scanf("%d", &t);
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	*/
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		printf("%d\n", dist[a][b]);
	}
	return 0;
}