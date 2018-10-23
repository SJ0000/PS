#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <set>
using namespace std;

string f[50];
int N;
string go() {
	string ret = "";
	bool getit;
	for (int i = 0; i < f[0].size(); i++) {
		getit = false;
		char st = f[0][i];
		for (int j = 1; j < N; j++) {
			if (f[j][i] != st) {
				getit = true;
				ret += '?';
				break;
			}
		}
		if (!getit) {
			ret += st;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> f[i];
	}
	cout << go() << endl;
	return 0;
}