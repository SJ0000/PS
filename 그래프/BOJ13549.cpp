#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
bool check[100001];
queue<int> now_q, next_q;
int getAns() {
	int timer = 0;
	int now;
	while (true) {
		//fq에서 0초 처리.
		while (!now_q.empty()) {
			now = now_q.front(); now_q.pop();

			if (now == M) return timer;
			if (!(0 <= now && now <= 100000)) continue;
			if (check[now]) continue;

			check[now] = true;
			next_q.push(now - 1); next_q.push(now + 1);
			now_q.push(now * 2);
		}
		// next_q -> now_q
		while (!next_q.empty()) {
			now = next_q.front(); next_q.pop();
			now_q.push(now);
		}
		timer++;
	}
}
int main()
{
	int s;
	scanf("%d %d", &N, &M);
	now_q.push(N);
	printf("%d\n", getAns());

	return 0;
}