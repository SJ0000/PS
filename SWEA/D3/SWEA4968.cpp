#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

vector<int> p;

void getPrime() {
	const int N = 1000001;
	bool prime[N];
	memset(prime, true, sizeof(prime));

	for (int i = 2; i*i < N; i++) {
		if (prime[i]) {
			for (int j = i * i; j < N; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = 2; i < N; i++) {
		if (prime[i]) p.push_back(i);
	}
}

int main()
{
	int T;
	cin >> T;
	string s;
	getPrime();
	int d, a, b;
	int ans;

	for (int t = 1; t <= T; t++) {
		ans = 0;
		scanf("%d %d %d", &d, &a, &b);
		for (int i = 0; i < p.size(); i++) {
			if (p[i] < a) continue;
			if (p[i] > b) break;

			s = to_string(p[i]);
			for (int j = 0; j < s.size(); j++) {
				if (s[j] - '0' == d) {
					ans++;
					break;
				}
			}
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}