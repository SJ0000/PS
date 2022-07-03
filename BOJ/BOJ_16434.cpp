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
		if (t[i] == 1) {	//����
			enemyatk = a[i];
			enemyhp = h[i];
			//��밡 ���� ���ϼ� �ִ� ����Ƚ��
			long long enemyatk_n = (nowhp / enemyatk) + (nowhp%enemyatk == 0 ? 0 : 1);
			//���� ��븦 ���� �� �ִ� ����Ƚ��
			long long nowatk_n = enemyhp / nowatk + (enemyhp%nowatk == 0 ? 0 : 1);
			//������ ���� ħ,�� Ƚ���� ���ų� ������ ���� �̱�
			if (enemyatk_n >= nowatk_n) {
				//���� �����Ѱ�� ���� ���� ���� �� �ִ� Ƚ�� - 1ȸ �´´�
				nowhp -= ((nowatk_n)-1)*enemyatk;
			}
			else {
				return false;
			}
		}
		else {	//����
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
	//n���� ���� ���� ��Ƴ������
	//	printf("LIVE!! \n");
	return true;
}

void calc() {
	long long lo = 0, hi = LLONG_MAX / 2;
	//�׻� lo �Ұ���, hi ����
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		bool isPossible = simulate(mid); // �ʱ�ü���� mid�϶� ��������
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