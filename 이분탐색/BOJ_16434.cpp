#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
using namespace std;

const int maxn = 123457;
int n, atk;
int t[maxn], a[maxn], h[maxn];

bool simulate(long long maxhp) {
	//
	//	printf("simulate MaxHP : %lld\n", maxhp);

	long long nowhp = maxhp;
	long long nowatk = atk;
	long long enemyhp, enemyatk;
	for (int i = 0; i < n; i++) {
		if (t[i] == 1) {	//몬스터
			enemyatk = a[i];
			enemyhp = h[i];
			//상대가 나를 죽일수 있는 공격횟수
			long long enemyatk_n = (nowhp / enemyatk) + (nowhp%enemyatk == 0 ? 0 : 1);
			//내가 상대를 죽일 수 있는 공격횟수
			long long nowatk_n = enemyhp / nowatk + (enemyhp%nowatk == 0 ? 0 : 1);
			//선공은 내가 침,즉 횟수가 같거나 작으면 내가 이김
			if (enemyatk_n >= nowatk_n) {
				//내가 생존한경우 나는 적을 죽일 수 있는 횟수 - 1회 맞는다
				nowhp -= ((nowatk_n)-1)*enemyatk;
			}
			else {
				return false;
			}
		}
		else {	//포션
			nowatk += a[i];
			if (nowhp + h[i] > maxhp) {
				nowhp = maxhp;
			}
			else {
				nowhp += h[i];
			}
			//		printf("potion phase , atk : %lld, hp : %lld \n", nowatk, nowhp);
		}
	}
	//n개의 방을 지나 살아남은경우
	//	printf("LIVE!! \n");
	return true;
}

void calc() {
	long long lo = 0, hi = LLONG_MAX / 2;
	//항상 lo 불가능, hi 가능
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		bool isPossible = simulate(mid); // 초기체력이 mid일때 생존여부
		if (isPossible) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	printf("%lld\n", hi);
}

int main()
{
	scanf("%d %d", &n, &atk);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &t[i], &a[i], &h[i]);
	}
	calc();
	return 0;
}