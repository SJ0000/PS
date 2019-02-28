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

typedef long long ll;
const ll maxn = 1000000;
bool prime[maxn + 1];
vector<int> p;
vector<int> sgNum; // 상근수
void era() {
	memset(prime, true, sizeof(prime));
	for (ll i = 2; i <= maxn; i++) {
		if (prime[i]) {
			p.push_back((int)i);
			for (ll j = i * i; j <= maxn; j += i) {
				prime[j] = false;
			}
		}
	}
}

int sg(int x) {
	int ret = 0;
	int val = x;
	int now;
	while (true) {
		now = val % 10;
		ret += (now*now);
		val /= 10;
		if (val == 0) break;
	}
	return ret;
}

void getsg() {
	set<int> checker;
	int now;
	for (int i = 0; i < p.size(); i++) {
		checker.clear();
		now = p[i];
		while (true) {
			//		printf("p[i] = %d , now : %d \n",p[i], now);
			checker.insert(now);
			now = sg(now);
			//계속 반복해서 도는 경우
			if (checker.find(now) != checker.end()) {
				break;
			}
			//상근수인경우
			if (now == 1) {
				sgNum.push_back(p[i]);
				break;
			}
		}
	}
}


int main()
{
	era();
	getsg();
	int N;
	scanf("%d", &N);
	for (int i = 0; i < sgNum.size(); i++) {
		if (sgNum[i] <= N) {
			printf("%d\n", sgNum[i]);
		}
		else {
			break;
		}
	}
	return 0;
}