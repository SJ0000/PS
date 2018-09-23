#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

vector<int> li;
vector<int> psum;

int getMaxIndex(vector<int> v,int st) {
	int now = st;
	for (int i = st; i < v.size(); i++) {
		if (v[i] > v[now]) {
			now = i;
		}
	}
	return now;
}
int main()
{	
	int t;
	scanf("%d", &t);
	long long ans;
	long long money = 0;
	int ea = 0;
	int n,val;
	int maxIdx;
	for (int T = 1; T <= t; T++) {
		ans = 0;
		li.clear();
		psum.clear();
		maxIdx = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &val);
			li.push_back(val);
		}
		psum.push_back(li[0]);
		for (int i = 1; i < n; i++) {
			psum.push_back(psum[i - 1] + li[i]);
		}
		int before = 0;
		while (true) {
			if (before == n) {
				break;
			}
			money = ea = 0;			
			maxIdx = getMaxIndex(li, before);
			if (before == maxIdx) {
				before++;
				maxIdx++;
				continue;
			}			
			ea = maxIdx - before;
			money = (before == 0) ? (psum[maxIdx - 1]) : (psum[maxIdx - 1] - psum[before - 1]);
			ans += (li[maxIdx] * ea) - money;
			before = maxIdx+1;
			if (before == n) {
				break;
			}
		}		
		printf("#%d %lld\n", T, ans);
	}
	return 0;
}