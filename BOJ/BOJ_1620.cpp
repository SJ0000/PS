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

bool isChar(char c) {
	if ('A' <= c && c <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	map<string, int> strToInt; // 이름
	vector<string> intToStr(n); // 번호순
	char str[21];
	string s;
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		s = str;
		intToStr[i] = s;
		strToInt.insert(make_pair(s, i + 1));
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", str);
		if (isChar(str[0])) {
			printf("%d\n", strToInt[str]);
		}
		else {
			cout << intToStr[atoi(str) - 1] << "\n";
		}
	}
	return 0;
}