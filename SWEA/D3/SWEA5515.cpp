#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;
int days[366]; //day[0] = 1¿ù1ÀÏ ~
int month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

int main()
{	
	int T;	
	cin >> T;
	int m, d;
	int week = 4;
	int day;
	for (int i = 0; i <= 365; i++) {
		days[i] = week++;
		week%=7;
	}
	int pSum[13]; pSum[0] = pSum[1] = 0;
	for (int i = 2; i <= 12; i++) {
		pSum[i] = pSum[i - 1] + month[i-1];
	}
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &m, &d);
		day = pSum[m] + d - 1;
		printf("#%d %d\n", t, days[day]);
	}
	return 0;
}