#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

typedef long long ll;

ll T;
int n, m;
vector<ll> a, b; // 누적합 기록
vector<ll> al, bl;

void init() {

	ll val;
	scanf("%lld", &T);
	scanf("%d", &n);
	a.push_back(0);
	b.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &val);
		a.push_back(a[i - 1] + val);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &val);
		b.push_back(b[i - 1] + val);
	}

	//정답 리스트 (i~j의 합 = a[j]-a[i-1])
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			al.push_back(a[j] - a[i - 1]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			bl.push_back(b[j] - b[i - 1]);
		}
	}
	sort(al.begin(), al.end());
	sort(bl.begin(), bl.end());
}

ll calc() {
	ll ret = 0;
	int l = 0;
	int r = bl.size() - 1;
	ll lcnt, rcnt;
	while (l < al.size() && r >= 0) {
		//	printf("l,r,al[l],bl[r] : %d %d %lld %lld \n", l, r, al[l], bl[r]);
		if (al[l] + bl[r] == T) {
			lcnt = 0;
			rcnt = 0;
			for (int i = l; i < al.size(); i++) {
				if (al[i] == al[l]) {
					lcnt++;
				}
				else {
					break;
				}
			}
			for (int i = r; i >= 0; i--) {
				if (bl[i] == bl[r]) {
					rcnt++;
				}
				else {
					break;
				}
			}

			ret += (lcnt*rcnt);
			l += lcnt;
			r -= rcnt;
		}
		else if (al[l] + bl[r] > T) {
			r--;
		}
		else {
			l++;
		}
	}
	return ret;
}

int main()
{
	init();
	printf("%lld", calc());
}