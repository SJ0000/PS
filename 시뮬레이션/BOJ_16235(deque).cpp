#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int N, M, K;

deque<int> tr[11][11];
int now_energy[11][11];
int fill_energy[11][11];
int dead_energy[11][11];
vector<int> live_t;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,1,-1,0,1,-1 };

void simulate() {
	//봄
	int now;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int deqsz = tr[i][j].size();
			for (int tsz = 0; tsz < deqsz; tsz++) {
				//먹을게잇는경우
				now = tr[i][j].front(); tr[i][j].pop_front();
				if (now_energy[i][j] >= now) {
					now_energy[i][j] -= now;
					tr[i][j].push_back(now + 1);
				}
				else {
					//여름 (update는 겨울에 같이)
					dead_energy[i][j] += (now / 2);
				}
			}
		}
	}
	//가을
	int ax, ay;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int tsz = 0; tsz < tr[i][j].size(); tsz++) {
				if (tr[i][j][tsz] % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						ax = i + dx[k];
						ay = j + dy[k];
						if (0 <= ax && ax < N && 0 <= ay && ay < N) {
							tr[ax][ay].push_front(1);
						}
					}
				}
			}
		}
	}
	//겨울
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			now_energy[i][j] += (fill_energy[i][j] + dead_energy[i][j]);
			dead_energy[i][j] = 0;
		}
	}
}

int getAns() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += tr[i][j].size();
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &fill_energy[i][j]);
			now_energy[i][j] = 5;
			dead_energy[i][j] = 0;
		}
	}
	int x, y, age;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &age);
		tr[x - 1][y - 1].push_back(age);
	}
	for (int i = 0; i < K; i++) {
		simulate();
	}
	printf("%d\n", getAns());
	return 0;
}