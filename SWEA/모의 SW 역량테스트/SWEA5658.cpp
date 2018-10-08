#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, K;
string s;
set<int> myset;
vector<int> v;
int simpleExp(int a, int b) {
	//aÀÇ bÁ¦°ö
	if (b == 0) return 1;
	int ret = 1;
	for (int i = 0; i < b; i++) {
		ret *= a;
	}
	return ret;
}
int hexToDec(string hex){
	int ret = 0;
	string rev = hex;
	for (int i = 0; i < hex.size(); i++) {
		rev[hex.size() - 1 - i] = hex[i];
	}
	int a;
	for (int i = 0; i < rev.size(); i++) {
		if ('0' <= rev[i] && rev[i] <= '9') {
			a = rev[i] - '0';
		}
		else {
			a = rev[i] - '7';
		}
		ret += a*simpleExp(16, i);
	}
	return ret;
}
void getAns(int st) {
	int sz = N / 4;
	string hex = "";
	for (int i = st; i < st + s.size() / 2; i++) {
		hex += s[i];
		if (hex.size() == sz) {
			myset.insert(hexToDec(hex));			
			hex = "";
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d %d", &N, &K);		
		cin >> s;
		s += s;
		v.clear(); myset.clear();
		for (int i = 0; i < N/4; i++) {
			getAns(i);
		}		
		for (auto it = myset.begin(); it != myset.end(); it++) {
			v.push_back(*it);
		}
		sort(v.begin(), v.end());
		printf("#%d %d\n", t_case, v[v.size() - K]);
	}
	return 0;
}