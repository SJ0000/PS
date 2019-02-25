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
ll n, m, k;
const ll mod = 1000000007;
const int maxn = 1000000;
ll seg[4 * maxn];

// pos : 리프노드 번호 , node : 트리의 노드 번호

ll update(ll pos, ll val, ll node, ll x, ll y) { // x~y 까지
	if (pos < x || y < pos) {
		return seg[node];
	}
	if (x == y) {
		return seg[node] = val;
	}
	ll mid = (x + y) / 2;
	return seg[node] = (update(pos, val, node * 2, x, mid)*update(pos, val, node * 2 + 1, mid + 1, y)) % mod;

}

ll query(ll lo, ll hi, ll node, ll x, ll y) {
	//x~y에서 벗어난 경우
	if (y < lo || hi < x) {
		return 1;
	}
	// lo~hi가 x~y내부에 있는 경우
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	ll mid = (x + y) / 2;
	return (query(lo, hi, node * 2, x, mid)*query(lo, hi, node * 2 + 1, mid + 1, y)) % mod;
}


int main()
{		
	ll t;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &t);
		update(i, t, 1, 1, n);
	}
	ll x, y, z;
	for (ll i = 0; i < m + k; i++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		if (x == 1) {
			update(y, z, 1, 1, n);
		}
		else {
			printf("%lld\n", query(y, z, 1, 1, n));
		}
	}
	return 0;
}