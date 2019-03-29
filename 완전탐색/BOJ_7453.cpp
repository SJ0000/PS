#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

typedef long long ll;

int n;
vector<int> a, b, c, d; // 누적합 기록
vector<int> al, bl; // a+b = x , c+d = y

void init() {
	scanf("%d", &n);
	int v1, v2, v3, v4;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &v1, &v2, &v3, &v4);
		a.push_back(v1);
		b.push_back(v2);
		c.push_back(v3);
		d.push_back(v4);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			al.push_back(a[i] + b[j]);
			bl.push_back(c[i] + d[j]);
		}
	}
	sort(al.begin(), al.end());
	sort(bl.begin(), bl.end());
}

//debug
void printv(vector<int> pr) {

	for (int i = 0; i < pr.size(); i++) {
		printf("%d ", pr[i]);
	}
	printf("\n");
}


ll calc() {
	ll ret = 0;
	int l = 0;
	int r = al.size() - 1;
	int lcnt, rcnt;

	//	printv(al);
	//	printv(bl);

	while (l < al.size() && r >= 0) {
		//		printf("l,r,al[l],bl[r] : %d %d %lld %lld \n", l, r, al[l], bl[r]);
		if (al[l] + bl[r] == 0) {
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
			//			printf("lcnt rcnt : %lld %lld \n", lcnt, rcnt);
			ret += ((ll)lcnt*(ll)rcnt);
			l += lcnt;
			r -= rcnt;
		}
		else if (al[l] + bl[r] > 0) {
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