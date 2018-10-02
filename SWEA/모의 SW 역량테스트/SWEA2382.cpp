#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

//해야할것 : 어떤 자료형으로 어떻게 담아서 어떻게 처리할지.
// 합쳐지는 경우를 주의해서 풀어야 할듯 싶다.

typedef struct micro {
	int m_x;
	int m_y;
	int m_amount;
	int m_dir;
	micro(int x, int y, int amount, int dir)
		: m_x(x), m_y(y), m_amount(amount), m_dir(dir) {}
};
int n, time_, k;
int ans;
vector<pair<int,int>> area[101][101];
int direction[5];
//상하좌우 1 2 3 4;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

vector<micro> v;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			area[i][j].clear();
		}
	}	
}
//동서남북 1234
void update() {
	int max_amount, total_amount;
	for (micro m : v) {
		int x = m.m_x;
		int y = m.m_y;
		int amount = m.m_amount;
		int dir = m.m_dir;
		int ax = x + dx[dir];
		int ay = y + dy[dir];
		//미생물에 닿았을 경우.
		if (ax == 0 || ax == n - 1 || ay == 0 || ay == n - 1) {
			amount /= 2;
			if (dir % 2 == 0) {
				dir--;
			}
			else {
				dir++;
			}
		}
		area[ax][ay].push_back(make_pair(amount, dir));
	}
	v.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j].size() == 0) {
				continue;
			}else if (area[i][j].size() == 1) {
				v.emplace_back(micro(i, j, area[i][j][0].first, area[i][j][0].second));
			}
			else {
				//size==2이상, 즉 여러개의 군집이 만나는경우.
				// direction[1..4]에 얼마나 만나는지 저장.
				max_amount = total_amount = 0;
				for (int g = 1; g <= 4; g++) { direction[g] = 0; }
				for (pair<int, int> p : area[i][j]) {
					direction[p.second] += p.first;
					total_amount += p.first;
				}
				for (int g = 1; g <= 4; g++) {
					max_amount = max(max_amount, direction[g]);
				}
				for (int g = 1; g <= 4; g++) {
					if (max_amount == direction[g]) {
						v.emplace_back(micro(i, j, total_amount, g));
						break;
					}
				}
			}			
		}
	}
	init();
}

int main(void) {
	int T;
	scanf("%d", &T);	
	int x, y, amount, dir;
	for(int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		scanf("%d %d %d", &n, &time_, &k);
		init();
		v.clear();
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d %d", &x, &y, &amount, &dir);
			v.emplace_back(micro(x, y, amount, dir));
		}
		for (int i = 0; i < time_; i++) {
			update();
			//test
			/*
			printf("***** PHASE %d *****\n", i + 1);
			printf("SIZE : %d\n", v.size());
			for (micro m : v) {
				printf("%d %d %d %d \n", m.m_x, m.m_y, m.m_amount, m.m_dir);
			}
			*/
		}
		for (micro m : v) {
			ans += m.m_amount;
		}
		printf("#%d %d\n", t_case, ans);
	}
	return 0;
}