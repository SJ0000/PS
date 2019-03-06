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
// 주의 - 단방향.

int n, m, x;
const int maxn = 1001;
const int maxv = 987654321;
vector<pair<int, int>> road[maxn];
int mRoute[maxn]; // 다익스트라 계산용.
int itox[maxn], xtoi[maxn]; // 최단거리 저장용.

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
			//최단거리일경우
			nexti = next.second;
			nextw = -1 * next.first;
			//현재 -> 다음 이 이전까지 계산된 최소거리보다 작은 경우 갱신.
			if (mRoute[nexti] > mRoute[nowi] + nextw) {
				mRoute[nexti] = mRoute[nowi] + nextw;
				pq.push(make_pair(-1 * mRoute[nexti], nexti));
			}
		}
	}

	//저장
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