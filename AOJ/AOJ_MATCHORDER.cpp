#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;


vector<int> russia;
vector<int> korea;
int n;
int getGreed() {
	int ret=0;
	//match
	int kidx = 0;
	bool canWin;
	for (int i = 0; i < n; i++) {
		canWin = false;
		for (int j = 0; j < n; j++) {
			//써먹은 선수는 0으로해서 다음탐색에 무시.
			if (korea[j] == 0) continue;
			if (russia[i] <= korea[j]) {
				korea[j] = 0;
				ret++;
				canWin = true;
				break;
			}
		}
		//다돌았는데 못이길경우 제일 약한선수랑 붙인다
		if (!canWin) {
			for (int j = 0; j < n; j++) {
				if (korea[j] == 0) continue;
				korea[j] = 0;
				break;
			}
		}
	}
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int val;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &val);
			russia.push_back(val);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &val);
			korea.push_back(val);
		}
		sort(russia.begin(), russia.end());
		sort(korea.begin(), korea.end());
		int ans = getGreed();
		printf("%d\n", ans);
		russia.clear(); korea.clear();
	}
	return 0;
}