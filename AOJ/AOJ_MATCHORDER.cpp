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
			//����� ������ 0�����ؼ� ����Ž���� ����.
			if (korea[j] == 0) continue;
			if (russia[i] <= korea[j]) {
				korea[j] = 0;
				ret++;
				canWin = true;
				break;
			}
		}
		//�ٵ��Ҵµ� ���̱��� ���� ���Ѽ����� ���δ�
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