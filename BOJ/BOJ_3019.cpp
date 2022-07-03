#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int a[101];
vector<string> block[7];
int C, P;

void init() {
	block[0].push_back("0000");
	block[0].push_back("0");

	block[1].push_back("00");

	block[2].push_back("110");
	block[2].push_back("01");

	block[3].push_back("011");
	block[3].push_back("10");

	block[4].push_back("000");
	block[4].push_back("10");
	block[4].push_back("01");
	block[4].push_back("010");

	block[5].push_back("000");
	block[5].push_back("02");
	block[5].push_back("100");
	block[5].push_back("00");

	block[6].push_back("000");
	block[6].push_back("20");
	block[6].push_back("001");
	block[6].push_back("00");
}


int simulate(int p) {

	int ret = 0;
	int height, depth, checker;
	bool possible;
	for (string s : block[p]) {
		//	cout << "STRING : " << s << endl;
		for (int st = 0; st <= C - s.size(); st++) {
			checker = s[0] - '0' + a[st];
			possible = true;
			//		printf("ST : %d  Checker : %d \n", st,checker);
			for (int i = 0; i < s.size(); i++) {
				depth = s[i] - '0';
				//				printf("depth : %d , a[st+%d] + depth : %d \n", depth,i,a[st + i] + depth);
				if (a[st + i] + depth != checker) {
					possible = false;
					break;
				}
			}
			if (possible) ret++;
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &C, &P);
	for (int i = 0; i < C; i++) {
		scanf("%d", &a[i]);
	}
	init();

	int ans = simulate(P - 1);

	printf("%d\n", ans);

	return 0;
}