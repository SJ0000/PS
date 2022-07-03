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

// i -> x , x-> 
// ���� - �ܹ���.

int n, m, x;
const int maxn = 1001;
const int maxv = 987654321;
vector<pair<int, int>> road[maxn];
int mRoute[maxn]; // ���ͽ�Ʈ�� ����.
int itox[maxn], xtoi[maxn]; // �ִܰŸ� �����.

bool check[maxn];

void dijkstra(int st) {

	priority_queue<pair<int, int>> pq;
	fill_n(mRoute, maxn, maxv);
	fill_n(check, maxn, false);

	pq.push(make_pair(0, st));
	mRoute[st] = 0;

	int nowi, noww, nexti, nextw; // i : index , w : weight
	while (!pq.empty()) {
		noww = -1 * pq.top().first;
		nowi = pq.top().second;
		pq.pop();

		if (check[nowi]) continue;
		check[nowi] = true;

		for (pair<int, int> next : road[nowi]) {
			//�ִܰŸ��ϰ��
			nexti = next.second;
			nextw = -1 * next.first;
			//���� -> ���� �� �������� ���� �ּҰŸ����� ���� ��� ����.
			if (mRoute[nexti] > mRoute[nowi] + nextw) {
				mRoute[nexti] = mRoute[nowi] + nextw;
				pq.push(make_pair(-1 * mRoute[nexti], nexti));
			}
		}
	}

	//����
	if (st == x) {
		for (int i = 0; i < maxn; i++) {
			xtoi[i] = mRoute[i];
		}
	}
	else {
		itox[st] = mRoute[x];
	}
}


int main()
{
	scanf("%d %d %d", &n, &m, &x);
	int a, b, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		road[a].push_back(make_pair(-1 * w, b));
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}

	int ans = -1;

	for (int i = 1; i <= n; i++) {
		ans = max(ans, xtoi[i] + itox[i]);
	}

	printf("%d\n", ans);

	return 0;
}