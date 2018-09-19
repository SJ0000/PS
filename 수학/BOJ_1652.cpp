#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int main()
{		
	int n;
	string s[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans1 = 0;
	int ans2 = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '.') {
				count++;
			}
			else {
				if (count >= 2) {
					ans1++;
				}
				count = 0;
			}
		}
		if (count >= 2) {
			ans1++;
		}
		count = 0;
	}
	count = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			
			if (s[i][j] == '.') {
				count++;
			}
			else {
				if (count >= 2) {
					ans2++;
				}
				count = 0;
			}
		}
		if (count >= 2) {
			ans2++;
		}
		count = 0;
	}
	
	printf("%d %d", ans1, ans2);
	return 0;
}