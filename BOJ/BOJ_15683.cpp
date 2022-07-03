#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int h, w;
int result;
int a[8][8];
int tmp[8][8];
int cctv_size;

struct info {
	int x, y, dir, type;
};
// 0 1 2 3 : r d l u
void go_r(int x,int y) {
	for (int j = y; j < w; j++) {
		if (tmp[x][j] == 6) break;
		if (tmp[x][j] == 0) tmp[x][j] = -1;
	}
}
void go_d(int x, int y) {
	for (int i = x; i < h; i++) {
		if (tmp[i][y] == 6) break;
		if (tmp[i][y] == 0) tmp[i][y] = -1;
	}
}
void go_l(int x, int y) {
	for (int j = y; j >=0; j--) {
		if (tmp[x][j] == 6) break;
		if (tmp[x][j] == 0) tmp[x][j] = -1;
	}
}
void go_u(int x, int y) {
	for (int i = x; i >=0; i--) {
		if (tmp[i][y] == 6) break;
		if (tmp[i][y] == 0) tmp[i][y] = -1;
	}
}
void do_test(vector<info> &cctv) {

	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			tmp[i][j] = a[i][j];
		}
	}

	for (int k = 0; k<cctv.size(); k++) {

		if (cctv[k].type == 1) {
			if (cctv[k].dir == 0) go_r(cctv[k].x, cctv[k].y);
			if (cctv[k].dir == 1) go_d(cctv[k].x, cctv[k].y);
			if (cctv[k].dir == 2) go_l(cctv[k].x, cctv[k].y);
			if (cctv[k].dir == 3) go_u(cctv[k].x, cctv[k].y);
		}

		if (cctv[k].type == 2) {

			if (cctv[k].dir == 0 || cctv[k].dir == 2) {
				go_r(cctv[k].x, cctv[k].y);
				go_l(cctv[k].x, cctv[k].y);
			}

			if (cctv[k].dir == 1 || cctv[k].dir == 3) {
				go_d(cctv[k].x, cctv[k].y);
				go_u(cctv[k].x, cctv[k].y);
			}
		}

		if (cctv[k].type == 3) {

			if (cctv[k].dir == 0) {
				go_l(cctv[k].x, cctv[k].y);
				go_u(cctv[k].x, cctv[k].y);
			}

			if (cctv[k].dir == 1) {
				go_r(cctv[k].x, cctv[k].y);
				go_u(cctv[k].x, cctv[k].y);
			}

			if (cctv[k].dir == 2) {
				go_r(cctv[k].x, cctv[k].y);
				go_d(cctv[k].x, cctv[k].y);
			}

			if (cctv[k].dir == 3) {
				go_d(cctv[k].x, cctv[k].y);
				go_l(cctv[k].x, cctv[k].y);
			}
		}

		if (cctv[k].type == 4) {

			if (cctv[k].dir == 0) {
				go_r(cctv[k].x, cctv[k].y);
				go_d(cctv[k].x, cctv[k].y);
				go_l(cctv[k].x, cctv[k].y);
			}

			if (cctv[k].dir == 1) {
				go_d(cctv[k].x, cctv[k].y);
				go_l(cctv[k].x, cctv[k].y);
				go_u(cctv[k].x, cctv[k].y);
			}

			if (cctv[k].dir == 2) {
				go_r(cctv[k].x, cctv[k].y);
				go_l(cctv[k].x, cctv[k].y);
				go_u(cctv[k].x, cctv[k].y);
			}

			if (cctv[k].dir == 3) {
				go_r(cctv[k].x, cctv[k].y);
				go_d(cctv[k].x, cctv[k].y);
				go_u(cctv[k].x, cctv[k].y);
			}
		}
		if (cctv[k].type == 5) {
			go_r(cctv[k].x, cctv[k].y);
			go_d(cctv[k].x, cctv[k].y);
			go_l(cctv[k].x, cctv[k].y);
			go_u(cctv[k].x, cctv[k].y);
		}
	}
	int cnt = 0;
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			if (tmp[i][j] == 0) cnt++;
		}
	}
	result = min(result, cnt);
}
void go(int index, vector<info> &cctv) {

	if (index == cctv_size) {
		do_test(cctv);
		return;
	}
	cctv[index].dir = 0;
	go(index + 1, cctv);

	cctv[index].dir = 1;
	go(index + 1, cctv);

	cctv[index].dir = 2;
	go(index + 1, cctv);

	cctv[index].dir = 3;
	go(index + 1, cctv);

}

int main()
{		
	result = 99999999;
	cin >> h >> w;

	vector<info> cctv;

	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0 && a[i][j] != 6) {
				cctv.push_back({ i, j, 0, a[i][j] });
			}
		}
	}

	cctv_size = cctv.size();
	go(0, cctv);

	cout << result << endl;
	
	return 0;
}