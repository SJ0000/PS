#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool a[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

string drgcurb[11];

void getcurb() {
	drgcurb[0] = "fx";
	for (int i = 1; i <= 10; i++) {
		string s = drgcurb[i - 1];
		int sz = s.size();
		for (int i = 0; i < sz; i++) {
			if (s[i] == 'x') {
				s.replace(i, 1, "x+yf");
				sz = s.size();
				i += 3;
			}
			if (s[i] == 'y') {
				s.replace(i, 1, "fx-y");
				sz = s.size();
				i += 3;
			}
		}
		drgcurb[i] = s;
	}
}

int turn(int now, char d) {
	int ret = now;
	if (d == '+') {
		ret++;
		if (ret == 4) {
			ret = 0;
		}
		return ret;
	}
	else {
		ret--;
		if (ret == -1) {
			ret = 3;
		}
		return ret;
	}
}
void update(int stx, int sty, int dir, int gen) {
	int ax = stx;
	int ay = sty;
	int ndir = dir;

	string drg = drgcurb[gen];
	a[ax][ay] = true;

	for (int i = 0; i < drg.size(); i++) {
		char di = drg[i];
		if (di == 'x' || di == 'y') continue;
		if (di == 'f') {
			ax += dx[ndir]; ay += dy[ndir];
			a[ax][ay] = true;
		}
		else {
			ndir = turn(ndir, di);
		}
	}
}

int getAns() {
	int ret = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
				ret++;
			}
		}
	}
	return ret;
}


int main(void) {

	getcurb(); // 잘동작함

	int N;
	scanf("%d", &N);
	int x, y, d, g;
	memset(a, false, sizeof(a));
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		update(x, y, d, g);
	}

	printf("%d\n", getAns());

	return 0;
}