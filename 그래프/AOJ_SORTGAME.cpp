#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<vector<int>, int> toSort;
//[1,2,..n]으로 선처리
void precalc(int n) {
	vector<int> perm(n);
	for (int i = 0; i < n; i++) {
		perm[i] = i;
	}
	queue<vector<int>> q;
	q.push(perm);
	toSort[perm] = 0;
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int cost = toSort[here];
		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j <= n; j++) {
				//2개,3개...n개씩 뒤집어서 q에 저장
				reverse(here.begin() + i, here.begin() + j);
				if (toSort.count(here) == 0) {
					toSort[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}
int solve(const vector<int>& perm) {
	int n = perm.size();
	vector<int> fixed(n);
	for (int i = 0; i < n; i++) {
		int smaller = 0;
		for (int j = 0; j < n; j++) {
			if (perm[j] < perm[i]) {
				smaller++;
			}			
		}
		fixed[i] = smaller;
	}
	return toSort[fixed];
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= 8; i++) {
		precalc(i);
	}
	while (t-- > 0) {
		int n;
		int num;
		scanf("%d", &n);
		vector<int> v;
		for (int i = 0; i < n; i++) {			
			scanf("%d", &num);
			v.push_back(num);
		}		
		printf("%d\n",solve(v));
	}
	return 0;
}