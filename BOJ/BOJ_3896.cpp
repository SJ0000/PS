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
const ll maxn = 1300000;
bool prime[maxn + 1];
vector<ll> p;
void era() {
	memset(prime, true, sizeof(prime));
	for (ll i = 2; i <= maxn; i++) {
		if (prime[i]) {
			p.push_back(i);
			for (ll j = i * i; j <= maxn; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main()
{
	era();
	int t;
	scanf("%d", &t);
	ll val;
	while (t--) {
		scanf("%lld", &val);
		ll a, b;
		for (int i = 0; i < p.size(); i++) {
			if (val < p[i]) {
				b = p[i];
				a = i == 0 ? 1 : p[i - 1];
				break;
			}
		}
		printf("%lld\n", prime[val] ? 0 : b - a);
	}
	return 0;
}