#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, A, B;
int a[10], b[10];
vector<pair<int, int>> k;
bool rec_check[1001];
pair<int,int> using_rec[10], using_rep[10]; // first : num, second : time;
vector<int> reception[10] , repair[10];
queue<pair<int,int>> recq,repq; // first : num ,second : time
int repair_count,reception_count;

void init() {
	for (int i = 0; i < 10; i++) {
		reception[i].clear();
		repair[i].clear();
	}
	k.clear();
	for (int i = 0; i < 10; i++) {
		using_rec[i].first = 0; using_rec[i].second = -1;
		using_rep[i].first = 0; using_rep[i].second = -1;
	}
	memset(rec_check, false, sizeof(rec_check));
	repair_count = 0;
	reception_count = 0;
}
void simulation() {
	bool isRepFull,isRecFull;
	//시간에 따른 변화
	for (int time = 0; time <= 25000; time++) {	
		//시간처리
		for (int i = 1; i <= N; i++) {
			if (using_rec[i].second > 0) using_rec[i].second--;
			if (using_rec[i].second == 0) {
				using_rec[i].second = -1;
				repq.push(make_pair(using_rec[i].first, time));
			}
		}
		for (int i = 1; i <= M; i++) {
			if (using_rep[i].second > 0) using_rep[i].second--;
			if (using_rep[i].second == 0) {
				using_rep[i].second = -1;
			}
		}
		//모든 사람이 repair를 완료한 경우.
		if (repair_count == K) break;

		//reception 처리 , 시간이 되면 큐에 넣는다.
		for (int i = 0; i < K; i++) {
			if (reception_count == K) break;
			if (rec_check[k[i].first]) continue;
			if (k[i].second == time) {
				recq.push(make_pair(k[i].first, k[i].second));
			}
		}

		while(true){
			//큐가 비어있거나 reception이 모두 차있으면 못들어감.
			isRecFull = true;
			for (int i = 1; i <= N; i++) {
				if (using_rec[i].second == -1) {
					isRecFull = false;
				}
			}
			if (isRecFull) break;

			if (!recq.empty()) {
				for (int i = 1; i <= N; i++) {
					if (using_rec[i].second == -1) {
						reception[i].push_back(recq.front().first);
						using_rec[i].first = recq.front().first;
						using_rec[i].second = a[i] ;
						recq.pop();
						reception_count++;
						break;
					}
				}
			}
			else {
				break;
			}
		}
		//repair 처리
		while (true) {
			isRepFull = true;
			for (int i = 1; i <= M; i++) {
				if (using_rep[i].second == -1) {
					isRepFull = false;
				}
			}
			if (isRepFull) break;
			if (!repq.empty()) {
				for (int i = 1; i <= M; i++) {
					if (using_rep[i].second == -1) {
						repair[i].push_back(repq.front().first);
						using_rep[i].first = repq.front().first;
						using_rep[i].second = b[i];
						repq.pop();
						repair_count++;
						break;
					}
				}
			}
			else {
				break;
			}
		}
		
	}	
}

int main(void) {
	int T;
	scanf("%d", &T);
	int val,ans;
	for(int t_case = 1; t_case <= T; t_case++) {
		init();
		ans = 0;
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= M; i++) {
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= K; i++) {
			scanf("%d", &val);
			k.push_back(make_pair(i, val));
		}

		simulation();		
		
		for (int x : reception[A]) {
			for (int y : repair[B]) {
				if (x == y) {
					ans += x;
				}
			}
		}
		if (ans == 0) {
			ans = -1;
		}
		printf("#%d %d\n", t_case, ans);
	}
	return 0;
}