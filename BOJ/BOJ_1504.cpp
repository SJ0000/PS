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


//1������ n������ �̵��� �� �־��� �� ������ �ݵ�� ��ġ�鼭 �̵�.
//Ư���� �� ������ ������ �ִܰ��.

using namespace std;

const int MAXN = 801;
const int MAXW = 987654321;
int N, E, X, Y; // X1,X2�� Ư���� �� ����.
vector<pair<long long,int>> g[MAXN]; // pair<�Ÿ�,����>
bool check[MAXN];
long long w[MAXN];

void dijkstra(int st) {
	priority_queue < pair <long long, int >, vector<pair<long long, int>>, greater<pair<long long, int>> > pq;
	//�ʿ��� 6���� ���� , �������� f,x,y���� �� �� �ִ�.
	
	//1���� �ּҰ��
	fill_n(w, MAXN, MAXW);
	fill_n(check, MAXN, false);
	w[st] = 0;
	pq.push(make_pair(0, st));
	int nowv, noww, nextv, nextw,nextDist;
	while (!pq.empty()) {
		nowv = pq.top().second;
		noww = pq.top().first;
		pq.pop();
		if (check[nowv]) continue;
		check[nowv] = true;
		sort(g[nowv].begin(), g[nowv].end());
		for (pair<int, int> next : g[nowv]) {
			nextv = next.second;
			nextw = next.first;
			nextDist = noww + nextw;
			//����
			if (w[nextv] > nextDist) {
				w[nextv] = nextDist;
				pq.push(make_pair(w[nextv], nextv));
			}
		}
	}	
}

int main()
{	
	scanf("%d %d", &N, &E);
	int a, b; long long c;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		g[a].push_back(make_pair(c,b));
		g[b].push_back(make_pair(c,a));
	}
	scanf("%d %d", &X, &Y);
	long long ftox, ftoy, xtoy, xton, ytox, yton;

	dijkstra(1);
	ftox = w[X]; ftoy = w[Y];
	dijkstra(X); 
	xtoy = w[Y]; xton = w[N];
	dijkstra(Y); 
	ytox = w[X]; yton = w[N];

	//��δ� 2�� : 1-x-y-n / 1-y-x-n
	long long path = min(ftox + xtoy + yton, ftoy + ytox + xton);
	printf("%lld\n", path >= MAXW ? -1 : path);
	
	return 0;
}