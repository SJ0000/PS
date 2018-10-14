#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> myset;
vector<int> picked;
vector<int> numli;
bool check[10];
int n, m;
void dfs() {
	if (picked.size() == (unsigned)m) {
		string s = "";
		//10
		int st = picked[0];
		for (int i = 1; i < m; i++) {
			if (st > picked[i]) {
				return;
			}
			else {
				st = picked[i];
			}
		}
		for (int i = 0; i < m - 1; i++) {
			s.append(to_string(picked[i]));
			s.append(" ");
		}
		s.append(to_string(picked[m - 1]));

		if (myset.find(s) != myset.end()) {
			return;
		}
		else {
			myset.insert(s);
			for (int x : picked) {
				printf("%d ", x);
			}
			printf("\n");
		}
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			picked.push_back(numli[i]);
			check[i] = true;
			dfs();
			picked.pop_back();
			check[i] = false;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	int val;
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		numli.push_back(val);
	}
	sort(numli.begin(), numli.end());
	dfs();
	/*
	for (auto it = myset.begin(); it != myset.end(); it++) {
	cout << *it << endl;
	}
	*/
	return 0;
}