#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool check[2001][2001];
int S;
int getAns() {
	int ret = 0;
	int len, clip;
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q; // <value,clip>
	q.push(make_pair(1, 0));
	while (!q.empty()) {
		int qs = q.size();
		// ret�ʿ� �� �� �ִ� �ϵ�.
		for (int i = 0; i < qs; i++) {
			len = q.front().first; clip = q.front().second;
			q.pop();
			//�迭���� check
			if (!(0 <= len && len < 2001 && 0 <= clip && clip < 2001)) continue;

			if (len == S) return ret;

			if (check[len][clip]) continue;
			check[len][clip] = true;
			//1.����.
			q.push(make_pair(len, len));
			//2. �����ֱ�
			q.push(make_pair(len + clip, clip));
			//3. ����
			q.push(make_pair(len - 1, clip));
		}
		ret++;
	}
	return ret;
}
int main()
{
	int s;
	scanf("%d", &S);
	printf("%d\n", getAns());

	return 0;
}