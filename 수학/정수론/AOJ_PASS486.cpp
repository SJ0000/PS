#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

const int N = 10000000;

bool isPrime[N + 1];
int pNum[N + 1];
vector<int> pList;
void era() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= (int)sqrt(N); i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) pList.push_back(i);
	}
}

// n의 가장 작은 소인수가 p이고, 이 소인수가 a번 출현한다면
// n의 약수는 ( n/p 의 약수의 개수 )* (a+1)/a 로 구할 수 있다.
void preCalc() {
	pNum[1] = 1;
	int p, a, n;
	for (int i = 2; i <= N; i++) {

		if (isPrime[i]) {
			pNum[i] = 2; // 1과 자기 자신. 
			continue;
		}

		for (int x : pList) {
			if (i%x == 0) {
				p = x;
				break;
			}
		}
		a = 0;
		n = i;
		while (n%p == 0) {
			n /= p;
			a++;
		}
		pNum[i] = pNum[i / p] * (a + 1) / a;
	}
}

int calc(int n, int lo, int hi) {

	int ret = 0;

	for (int i = lo; i <= hi; i++) {
		if (pNum[i] == n) ret++;
	}
	return ret;
}


int main()
{
	int t;
	scanf("%d", &t);
	int n, lo, hi;
	era(); preCalc();
	while (t--) {
		scanf("%d %d %d", &n, &lo, &hi);
		cout << calc(n, lo, hi) << endl;
	}
	return 0;
}