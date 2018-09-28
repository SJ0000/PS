#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;


int search(string s) {
	int st = 0;
	int ed = s.size() - 1;
	while (st < ed) {
		if (s[st] != s[ed]) {
			return 0;
		}
		st++; ed--;
	}
	return 1;
}

int main()
{	
	int T;
	cin >> T;
	string palindrome;
	for (int t = 1; t <= T; t++) {
		cin >> palindrome;
		printf("#%d %d\n", t, search(palindrome));
	}
	return 0;
}