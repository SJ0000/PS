#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int a[10000];
int cache[10000];
const int MAX = 9999999;
string s;

int getScore(int start, int end)

{
	string part = s.substr(start, end - start + 1);
	if (part == string(part.size(), part[0]))
		return 1;
	
	bool progressive = true;
	for (int i = 0; i < part.size() - 1; i++)
		if (part[i + 1] - part[i] != part[1] - part[0])
			progressive = false;

	if (progressive && abs(part[1] - part[0]) == 1)
		return 2;
	bool alternate = true;

	for (int i = 0; i < part.size(); i++)
		if (part[i] != part[i % 2])
			alternate = false;

	if (alternate)
		return 4;

	if (progressive)
		return 5; 

	return 10;
}

int go(int begin) {

	if (begin == s.size()) {
		return 0;
	}
	int& ret = cache[begin];
	if (ret != -1) return ret;

	ret = MAX;
	for (int L = 3; L <= 5; L++) {
		if (begin + L <= s.size()) {			
			ret = min(ret, go(begin + L) + getScore(begin, begin + L -1));
		}
	}
	return ret;
}

int main()
{		
	int t;
	cin >> t;
	int ans;
	while (t-- > 0) {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			a[i] = s[i] - '0';
		}
		memset(cache, -1, sizeof(cache));
		go(0);	
		cout << cache[0] << endl;
	}	
	return 0;
}