#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int status[21][21];
int diff = 987654321;
int getDiff(const vector<int>& a, const vector<int>& b) {
	int scoreA = 0;
	int scoreB = 0;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			scoreA += status[a[i]][a[j]];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			scoreB += status[b[i]][b[j]];
		}
	}
	return abs(scoreA - scoreB);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			scanf("%d", &status[i][j]);
		}
	}
	vector<int> bit(t, 0);
	vector<int> teamA, teamB;
	for (int i = t/2; i < t; i++) {
		bit[i] = 1;
	}
	//순열로 완전탐색
	do {
		//bit[i] 가 0이면 i는 teamA, 1이면 teamB
		for (int i = 0; i < t; i++) {
			if (bit[i] == 0) {
				teamA.push_back(i);
			}
			else {
				teamB.push_back(i);
			}
		}
		int temp = getDiff(teamA, teamB);
		diff = min(diff, temp);
		teamA.clear(); teamB.clear();
	} while (next_permutation(bit.begin(), bit.end()));

	printf("%d\n", diff);

	return 0;
}