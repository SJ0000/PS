#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct BC {
	int cover;
	int perf;
	int x;
	int y;
};
int a[10][10];
int go_a[101], go_b[101];
int M, A;
//0 1 2 3 4 / x,상,우,하,좌
int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };
vector<BC> bc;

int getMaxPower(vector<int> a, vector<int> b) {
	int ret = 0;
	//a,b둘 중 하나가 아무데도 안들어갈경우.
	if (a.size() == 0) {
		for (int x : b) {
			ret = max(ret, bc[x].perf);
		}
		return ret;
	}
	if (b.size() == 0) {
		for (int x : a) {
			ret = max(ret, bc[x].perf);
		}
		return ret;
	}	
	for (int x : a) {
		for (int y : b) {
			if (x == y) {
				ret = max(ret, bc[x].perf);
			}
			else {
				ret = max(ret, bc[x].perf + bc[y].perf);
			}
		}
	}
	return ret;
}
int calc() {
	//0초부터 a,b의 move에 따른 최대충전량.	
	int ret = 0;
	int ax = 0, ay = 0, bx = 9, by = 9;
	vector<int> use_a, use_b;
	for (int i = 0; i <= M; i++) {
		use_a.clear(); use_b.clear();
		ax += dx[go_a[i]]; ay += dy[go_a[i]];
		bx += dx[go_b[i]]; by += dy[go_b[i]];
		
	//	printf("time : %d \n", i);
	//	printf("ax ay bx by  %d %d %d %d \n", ax, ay, bx, by);
		for (int j = 0; j < bc.size(); j++) {
			//a와 bat의 거리가 bat범위에 들어올경우.
			BC bat = bc[j];
			int alen = abs(bat.x - ax) + abs(bat.y - ay);
			int blen = abs(bat.x - bx) + abs(bat.y - by);
			if (alen <= bat.cover) use_a.push_back(j);
			if (blen <= bat.cover) use_b.push_back(j);
			
	//		printf("alen : %d  blen : %d  cover : %d \n", alen, blen, bat.cover);
		}		
		//getMaxPower
		ret += getMaxPower(use_a, use_b);
	//	printf("maxPower : %d \n", getMaxPower(use_a, use_b));
	}
	return ret;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d %d", &M, &A);
		bc.clear();
		
		go_a[0] = 0; go_b[0] = 0;
		for (int i = 1; i <= M; i++) {
			scanf("%d", &go_a[i]);
		}
		for (int i = 1; i <= M; i++) {
			scanf("%d", &go_b[i]);
		}
		int cover, power, bcx, bcy;
		for (int i = 0; i < A; i++) {
			scanf("%d %d %d %d", &bcx, &bcy, &cover, &power);
			bc.push_back(BC{ cover,power,bcy - 1,bcx - 1 });
		}
		int ans = calc();
		printf("#%d %d\n", t_case, ans);
	}
	return 0;
}