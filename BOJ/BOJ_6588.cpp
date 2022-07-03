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

int main()
{
	era();
	int val;
	bool goldbach;
	while (true) {
		scanf("%d", &val);
		if (val == 0) break;
		int a, b;
		//°ËÁõ
		goldbach = false;

		for (int i = 0; i < p.size(); i++) {
			if (val - p[i] >= 0) {
				if (prime[val - p[i]]) {
					goldbach = true;
					a = p[i];
					b = val - p[i];
					break;
				}
			}
		}
		if (goldbach) {
			printf("%d = %d + %d\n", val, a, b);
		}
		else {
			cout << "Goldbach's conjecture is wrong." << endl;
		}
	}
	return 0;
}