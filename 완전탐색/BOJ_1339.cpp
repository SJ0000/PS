#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;

string sumStr[10];
bool usedChar[27];
map<char, int> mymap;

int str_to_int(vector<int> perm) {
	int ret = 0;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp = 0;
		string s = sumStr[i];
		for (int j = 0; j < s.size(); j++) {
			tmp += perm[mymap[s[j]]]; tmp *= 10;
		}
		tmp /= 10;
		ret += tmp;
	}
	return ret;
}
int getAns() {
	//완탐
	int ret = 0;
	vector<int> perm;
	for (int i = 10 - mymap.size(); i <= 9; i++) {
		perm.push_back(i);
	}
	do {
		ret = max(ret, str_to_int(perm));
	} while (next_permutation(perm.begin(), perm.end()));

	return ret;
}
int main()
{
	scanf("%d", &N);
	string s;
	for (int i = 0; i < 7; i++) {
		sumStr[i] = "";
	}
	memset(usedChar, false, sizeof(usedChar));
	int idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		sumStr[i] = s;
		//map에 쓴거 index 저장.
		for (int j = 0; j < s.size(); j++) {
			if (!usedChar[s[j] - 'A']) {
				mymap.insert(make_pair(s[j], idx++));
				usedChar[s[j] - 'A'] = true;
			}
		}
	}	

	int ans = getAns();
	printf("%d\n", ans);
	return 0;
}