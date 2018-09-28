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
	string s;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		int x = s[s.size() - 1] - '0';
		if (x % 2 == 0) {
			cout << "#" << t << " " << "Even" << endl;
		}
		else {
			cout << "#" << t << " " << "Odd" << endl;
		}
	}
	return 0;
}