#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <list>
using namespace std;

//p에는 1번계단과의 거리, 2번계단과의 거리를 pair형태로 저장.
//f는 계단의 정보를 <위치,길이> 형태로 저장. 위치는 i*100+j;

//해야할것 : 시간에 따른 변화 처리.
vector<pair<int, int>> f,p;

int a[11][11];
int min_time;
vector<int> f_elv, s_elv;
int  elv1[3]; int elv2[3]; // -1이면 비어있음.
int elv1_sz , elv2_sz;
bool allCleared;
void dfs(int toPick, vector<int> picked) {	
	if (toPick == 0) {
		//시간 처리.
		int f_last = 0; //엘리베이터 마지막 인덱스
		int s_last = 0;
		elv1_sz = elv2_sz = 0;
		int now = 0;
		memset(elv1, -1, sizeof(elv1));
		memset(elv2, -1, sizeof(elv2));
		f_elv.clear(); s_elv.clear();
		for (int i = 0; i < picked.size(); i++) {
			if (picked[i] == 0) {
				f_elv.push_back(p[i].first);
			}
			else {
				s_elv.push_back(p[i].second);
			}
		}
		sort(f_elv.begin(), f_elv.end());
		sort(s_elv.begin(), s_elv.end());
		while (true) {
			//test
			/*
			printf("TIME : %d\n", now);
			printf("f_last = %d , f_elv STATE : ", f_last);
			for (int i = 0; i < f_elv.size(); i++) {
				printf("%d ", f_elv[i]);
			}
			printf("\n");

			printf("s_last = %d , s_elv STATE : ", s_last);
			for (int i = 0; i < s_elv.size(); i++) {
				printf("%d ", s_elv[i]);
			}
			printf("\n");

			printf("ELV1 STATE : ");
			for (int i = 0; i < 3; i++) {
				printf("%d ", elv1[i]);
			}
			printf("\n");
			printf("ELV2 STATE : ");
			for (int i = 0; i < 3; i++) {
				printf("%d ", elv2[i]);
			}
			printf("\n");
			*/
			//test-end

			//가지치기
			if (now >= min_time) {
				return;
			}
			//전부다 나간경우 break;
			allCleared = true;
			if (f_last == f_elv.size() && s_last == s_elv.size()) {				
				for (int i = 0; i < 3; i++) {
					if (elv1[i] != -1 || elv2[i]!=-1) {
						allCleared = false;
						break;
					}
				}
				if (allCleared) {
					min_time = min(now, min_time);
					break;
				}
			}

			//시간에 따른 변화.
			now++;
			for (int i = f_last; i < f_elv.size(); i++) {
				//도착했고, 엘리베이터에 탈 수 있을 경우.
				if (f_elv[i] == -1 && elv1_sz < 3) {
					f_last++;
					for (int j = 0; j < 3; j++) {
						if (elv1[j] == -1) {
							elv1[j] = f[0].second;
							elv1_sz++;
							break;
						}
					}
				}
				//도착은 한 경우
				if (f_elv[i] == -1) continue;
				//도착 못한 경우
				f_elv[i]--;
			}	
			for (int i = 0; i < 3; i++) {
				if (elv1[i] == -1) continue;
				elv1[i]--;
				if (elv1[i] == 0) {
					elv1[i]--;
					elv1_sz--;
				}
			}
			for (int i = s_last; i < s_elv.size(); i++) {
				//도착했고, 엘리베이터에 탈 수 있을 경우.
				if (s_elv[i] == -1 && elv2_sz < 3) {
					s_last++;
					for (int j = 0; j < 3; j++) {
						if (elv2[j] == -1) {
							elv2[j] = f[1].second;
							elv2_sz++;
							break;
						}
					}
				}
				//도착은 한 경우
				if (s_elv[i] == -1) continue;
				//도착 못한 경우
				s_elv[i]--;
			}
			for (int i = 0; i < 3; i++) {
				if (elv2[i] == -1) continue;
				elv2[i]--;
				if (elv2[i] == 0) {
					elv2[i]--;
					elv2_sz--;
				}
			}			
		}
		return;
	}
	//picked[i] 가 0이면 1번계단, 1이면 2번계단을 선택한 것.
	picked.push_back(0);
	dfs(toPick -1 , picked);
	picked.pop_back();

	picked.push_back(1);
	dfs(toPick -1, picked);
	picked.pop_back();
}


int main(void) {
	int T;
	scanf("%d", &T);
	
	int n,val;
	int tx1, ty1,tx2,ty2,dist1,dist2;
	for(int t_case = 1; t_case <= T; t_case++) {
		min_time = 987654321;
		f.clear(); p.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				if (a[i][j] >= 2) {
					f.push_back(make_pair(i * 100 + j, a[i][j]));
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) {
					continue;
				}
				else if (a[i][j] == 1) {
					tx1 = f[0].first / 100;
					ty1 = f[0].first % 100;
					tx2 = f[1].first / 100;
					ty2 = f[1].first % 100;
					dist1 = abs(tx1 - i) + abs(ty1 - j);
					dist2 = abs(tx2 - i) + abs(ty2 - j);
					p.push_back(make_pair(dist1, dist2));
				}
			}
		}
		vector<int> base;
		dfs(p.size(), base);
		printf("#%d %d\n", t_case, min_time);
	}
	return 0;
}