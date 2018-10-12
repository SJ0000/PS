#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>
using namespace std;
struct atom {
	int x;
	int y;
	int dir;
	int energy;
};
int N;
vector<atom> v;
bool collision[1000]; // i,j 가 충돌하면 true;
bool used[1000];
double coltime[1000][1000];// i랑 j랑 언제박을 수 있는지 check (가능성)
set<double> coltimer;
vector<double> coltimer2;
int simulate() {
	atom at1, at2;
	int dx, dy;
	int total_energy = 0;
	vector<pair<double, int>> vcol;
	for (int i = 0; i < N; i++) {
		at1 = v[i];
		vcol.clear();
		for (int j = i + 1; j < N; j++) {
			at2 = v[j];
			//만날 수 있는 거리가 아닌 경우.
			dx = abs(at1.x - at2.x);
			dy = abs(at1.y - at2.y);
			if (dx > 0 && dy > 0 && dx != dy) {
				continue;
			}
			//만날 수 있는 방향이 아닌 경우.
			if (dy == 0) {
				//x축으로 움직일때
				if (at1.x < at2.x) {
					if (!(at1.dir == 3 && at2.dir == 2)) continue;
				}
				else {
					if (!(at1.dir == 2 && at2.dir == 3)) continue;
				}
			}
			if (dx == 0) {
				if (at1.y < at2.y) {
					if (!(at1.dir == 0 && at2.dir == 1)) continue;
				}
				else {
					if (!(at1.dir == 1 && at2.dir == 0)) continue;
				}
			}
			//at1를 0,0이라 치고 at2가 1사분면일 때 부터 1,2,3,4
			//1사분면
			if (at1.x < at2.x && at1.y < at2.y) {
				if (!((at1.dir == 0 && at2.dir == 2) || (at1.dir == 3 && at2.dir == 1))) {
					continue;
				}
			}
			//2사분면
			if (at1.x > at2.x && at1.y < at2.y) {
				if (!((at1.dir == 2 && at2.dir == 1) || (at1.dir == 0 && at2.dir == 3))) {
					continue;
				}
			}
			//3사분면
			if (at1.x > at2.x && at1.y > at2.y) {
				if (!((at1.dir == 2 && at2.dir == 0) || (at1.dir == 1 && at2.dir == 3))) {
					continue;
				}
			}
			//4사분면
			if (at1.x <at2.x && at1.y > at2.y) {
				if (!((at1.dir == 3 && at2.dir == 0) || (at1.dir == 1 && at2.dir == 2))) {
					continue;
				}
			}
			//충돌가능한것중 만나는 시간. pair<시간,번호>
			if (dx == 0) {
				vcol.push_back(make_pair((double)dy / (double)2, j));
			}
			else if (dy == 0) {
				vcol.push_back(make_pair((double)dx / (double)2, j));
			}
			else {
				vcol.push_back(make_pair(dx, j));
			}
		}
		//i와 충돌가능한것중 가장짧은시간에 만나는것.
		//coltime update;
		for (pair<double, int> p : vcol) {
			coltime[i][p.second] = p.first;
			coltimer.insert(p.first);
		}
	}
	vector<int> collist;
	for (auto iter = coltimer.begin(); iter != coltimer.end(); iter++) {
		coltimer2.push_back(*iter);
	}
	sort(coltimer2.begin(), coltimer2.end());
	for (double timer : coltimer2) {
		collist.clear();
		for (int i = 0; i < N; i++) {
			if (used[i]) continue;
			for (int j = i + 1; j < N; j++) {
				if (coltime[i][j] == 0.0) continue;
				if (used[j]) continue;
				if (coltime[i][j] == timer) {
					collision[i] = true;
					collision[j] = true;
					collist.push_back(i);
					collist.push_back(j);
				}
			}
		}
		for (int x : collist) {
			used[x] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		if (collision[i]) {
			total_energy += v[i].energy;
		}
	}
	return total_energy;
}

void init() {
	memset(collision, false, sizeof(collision));
	memset(used, false, sizeof(used));
	memset(coltime, 0.0, sizeof(coltime));
	coltimer.clear();
	coltimer2.clear();
	v.clear();
}

int main(void) {
	int T;
	scanf("%d", &T);
	int a_x, a_y, a_dir, a_en;
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		init();
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &a_x, &a_y, &a_dir, &a_en);
			v.emplace_back(atom{ a_x + 1000,a_y + 1000,a_dir,a_en });
		}
		printf("#%d %d\n", tc, simulate());
	}
	return 0;
}