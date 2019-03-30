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
pair<int, int> route[100001]; //<count,sec>
bool chk[100001];

bool inRange(int x) {
	if (0 <= x && x <= 100000) {
		return true;
	}
	else {
		return false;
	}
}

void solve() {
	bool getAnswer = false;
	int answerTime = 987654321;
	int answerCount = 0;
	q.push(make_pair(n, 0));
	pair<int, int> now;
	int nowp, nows;
	while (!q.empty()) {
		if (getAnswer) break;
		int qs = q.size();
		while (qs--) {
			now = q.front(); q.pop();
			nowp = now.first; nows = now.second;
			chk[nowp] = true;
			if (nows == answerTime + 1) {
				getAnswer = true;
				break;
			}

			if (nowp == k) {
				answerTime = nows;
				answerCount++;
			}

			if (inRange(nowp - 1)) {
				if (!chk[nowp - 1]) {
					q.push(make_pair(nowp - 1, nows + 1));
				}
			}
			if (inRange(nowp + 1)) {
				if (!chk[nowp + 1]) {
					q.push(make_pair(nowp + 1, nows + 1));
				}
			}
			if (inRange(nowp * 2)) {
				if (!chk[nowp * 2]) {
					q.push(make_pair(nowp * 2, nows + 1));
				}
			}
		}
	}

	printf("%d\n", answerTime);
	printf("%d\n", answerCount);

}

int main()
{
	scanf("%d %d", &n, &k);
	solve();
	return 0;
}