#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

string a[4];

void calc() {

	int sum = 0;
	int ax, ay, bx, by;
	for (int i = 0; i < 16; i++) {
		if (a[i / 4][i % 4] == '.') continue;
		ax = i / 4;
		ay = i % 4;
		bx = (a[i / 4][i % 4] - 'A') / 4;
		by = (a[i / 4][i % 4] - 'A') % 4;
		//		printf("%c / %d %d / %d %d\n", a[i / 4][i % 4], ax, ay, bx, by);
		sum += (abs(ax - bx) + abs(ay - by));
	}
	printf("%d", sum);
}

int main()
{
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	calc();
	return 0;
}