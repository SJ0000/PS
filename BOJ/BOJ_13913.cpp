#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int n, k;
queue<pair<int, int>> q; // <pos,sec>
pair<int, int> route[100001]; //<parent,sec>
vector<int> chaseV;

bool inRange(int x) {
	if (0 <= x && x <= 100000) {
		return true;
	}
	else {
		return false;
	}
}

void chaseParent(int now) {
	chaseV.push_back(now);
	if (now == n) return;
	chaseParent(route[now].first);
}

void solve() {
	bool getAnswer = false;
	int answerTime = 0;
	q.push(make_pair(n, 0));

	pair<int, int> now;
	int nowp, nows;
	while (!q.empty()) {
		if (getAnswer) break;
		int qs = q.size();
		while (qs--) {
			now = q.front(); q.pop();
			nowp = now.first; nows = now.second;

			if (nowp == k) {
				answerTime = nows;
				getAnswer = true;
				break;
			}

			if (inRange(nowp - 1)) {
				if (route[nowp - 1].second > nows + 1) {
					q.push(make_pair(nowp - 1, nows + 1));
					route[nowp - 1] = make_pair(nowp, nows + 1);
				}
			}
			if (inRange(nowp + 1)) {
				if (route[nowp + 1].second > nows + 1) {
					q.push(make_pair(nowp + 1, nows + 1));
					route[nowp + 1] = make_pair(nowp, nows + 1);
				}
			}
			if (inRange(nowp * 2)) {
				if (route[nowp * 2].second > nows + 1) {
					q.push(make_pair(nowp * 2, nows + 1));
					route[nowp * 2] = make_pair(nowp, nows + 1);
				}
			}
		}
	}

	printf("%d\n", answerTime);
	chaseParent(k);
	for (int i = chaseV.size() - 1; i >= 0; i--) {
		printf("%d ", chaseV[i]);
	}

}
void init() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 100001; i++) {
		route[i] = make_pair(-1, 987654321);
	}
}

int main()
{
	init();
	solve();
	return 0;
}