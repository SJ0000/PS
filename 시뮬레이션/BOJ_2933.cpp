#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

char a[101][101];
bool check[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int R, C, N;
int mh[101]; // (min_height)i번째 colomn의 최소 높이.

vector<pair<int, int>> down(vector<pair<int, int>> old) {
	vector<pair<int, int>> new_;
	int x, y;
	memset(mh, -1, sizeof(mh));
	//x가 큰거부터 내려야 중간에 사라지지 않음.
	sort(old.begin(), old.end());
	for (int i = old.size() - 1; i >= 0; i--) {
		//한칸 내림
		x = old[i].first; y = old[i].second;
		a[x][y] = '.';
		a[x + 1][y] = 'x';
		new_.push_back({ x + 1,y });
		mh[y] = max(mh[y], x + 1);
	}
	return new_;
}


void bfs(int stx, int sty) {

	queue<pair<int, int>> q;
	vector<pair<int, int>> root;
	q.push({ stx,sty });

	int x, y, ax, ay;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		root.push_back({ x,y });
		check[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			ax = x + dx[i];
			ay = y + dy[i];
			if (0 <= ax && ax < R && 0 <= ay && ay < C) {
				if (!check[ax][ay]) {
					check[ax][ay] = true;
					q.push({ ax,ay });
				}
			}
		}
	}
	//덩어리 탐색이 다 끝나고.
	// case 1 : 바닥과 닿은 클러스터
	for (auto p : root) {
		if (p.first == R - 1) {
			return;
		}
	}
	// case 2 : 바닥에 닿지 않은 클러스터 	
	while (true) {
		//한칸 내리기
		root = down(root);
		//검사
		for (int i = 0; i < C; i++) {
			if (mh[i] == -1) continue;
			//해당 클러스터의 맨 밑칸의 한칸밑에 자리가 차있을경우
			//더 내려갈 수 없음.
			if (mh[i] == R - 1) return;
			if (a[mh[i] + 1][i] == 'x') return;
		}
	}
}

void update() {
	memset(check, false, sizeof(check));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (a[i][j] == '.') {
				check[i][j] = true;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!check[i][j]) {
				bfs(i, j);
			}
		}
	}
}

void shoot(int lr, int height) {
	//lr = 0 이면 --->  /  1이면  <===
	if (lr == 0) {
		// shoot=========>
		for (int i = 0; i < C; i++) {
			if (a[height][i] == 'x') {
				a[height][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = C - 1; i >= 0; i--) {
			if (a[height][i] == 'x') {
				a[height][i] = '.';
				break;
			}
		}

	}
}


int main()
{
	scanf("%d %d", &R, &C);
	string tmp;
	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			a[i][j] = tmp[j];
		}
	}
	scanf("%d", &N);
	int height;
	for (int i = 0; i < N; i++) {
		scanf("%d", &height);
		shoot(i % 2, R - height);
		update();
	}
	//getAns
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%1c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}