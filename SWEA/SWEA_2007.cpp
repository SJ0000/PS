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
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;
		int ans = 0;
		string tmp;
		bool getAns;
		for (int i = 1; i <= 10; i++) {
			getAns = true;
			tmp = "";			
			for (int j = 0; j < i; j++) {
				tmp += s[j];
			}
			for (int j = tmp.size(); j < s.size(); j++) {
				if (tmp[j%i] != s[j]) {
					getAns = false;
				}
			}
			if (getAns) {
				ans = i;
				break;
			}
		}
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}