#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int N, K;
const int MOD = 20091101;

// i ~ j ������ ����, psum[j]-psum[i-1]=0 �϶� K���� ��̿���
// ��� ������ ������ �� �� �ִ�.

int getAns1(const vector<int>& psum) {
	int ret = 0;
	vector<long long> count(K, 0);
	for (int i = 0; i < psum.size(); i++) {
		count[psum[i]]++;
	}
	// n>2 �϶�, nC2
	for (int i = 0; i < K; i++) {
		if (count[i] >= 2) {
			ret += ((count[i] * ((count[i] - 1)) / 2)) % MOD;
		}
	}
	return ret % MOD;
}

int getAns2(const vector<int>& psum) {
	// ret[i] : ù��° ���ں��� i��° ���ڱ��� ������� ��
	// �� �� �ִ� �ִ� Ƚ��.
	vector<int> ret(N + 1, 0);

	//prev[s] : psum[] �� s���� ������ ��ġ
	vector<int> prev(K, -1);

	for (int i = 0; i <= N; i++) {

		if (i > 0) {
			ret[i] = ret[i - 1];
		}
		else {
			ret[i] = 0;
		}

		int loc = prev[psum[i]]; //psum[i]�� ���������� �� ��ġ
		if (loc != -1) {
			ret[i] = max(ret[i], ret[loc] + 1);
		}
		prev[psum[i]] = i;
	}
	return ret[N];
}


void solve() {
	vector<int> psum(N + 1, 0);
	int val;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &val);
		psum[i] = (psum[i - 1] + val) % K;
	}

	int ans1 = getAns1(psum);
	int ans2 = getAns2(psum);

	cout << ans1 << " " << ans2 << endl;

}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc-- > 0) {
		scanf("%d %d", &N, &K);
		solve();
	}
	return 0;
}