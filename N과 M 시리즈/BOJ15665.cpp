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
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		picked.push_back(numli[i]);
		dfs();
		picked.pop_back();
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
	return 0;
}