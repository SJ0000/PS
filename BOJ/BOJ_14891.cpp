#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int gear[4][8];
bool check[4] = { 0,0,0,0 };
// idx[i][0] = 왼쪽 , idx[i][1] = 오른쪽
int idx[4][2] = { {6,2},{ 6,2 },{ 6,2 },{ 6,2 } }; 
string s;

void setGear(int n, int go) {
	//시계방향 -- 반시계방향 ++
	if (check[n] == true) {
		return;
	}
	check[n] = true;
	if (n - 1 >= 0) {
		if (gear[n - 1][idx[n - 1][1]] != gear[n][idx[n][0]]) {
			setGear(n - 1, -go);
		}
	}
	//오른쪽바퀴
	if (n + 1 < 4) {
		if (gear[n + 1][idx[n + 1][0]] != gear[n][idx[n][1]]) {
			setGear(n + 1, -go);
		}
	}
	if (go == 1) {
		idx[n][0]--;
		idx[n][1]--;
	}
	else {
		idx[n][0]++;
		idx[n][1]++;
	}
	//범위오류 조정
	for (int i = 0; i < 2; i++) {
		if (idx[n][i] == 8) {
			idx[n][i] = 0;
		}
		else if (idx[n][i] == -1) {
			idx[n][i] = 7;
		}
	}
}
int main()
{	
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = s[j] - '0';
		}
	}
	int t,n,go;
	cin >> t;
	while (t-- > 0) {
		cin >> n >> go;
		setGear(n - 1, go);
		for (int i = 0; i < 4; i++) {
			check[i] = false;
		}
	}
	//score 구하기
	int score = 0;
	if (gear[0][(idx[0][0] + 2) % 8] == 1) {
		score += 1;
	}
	if (gear[1][(idx[1][0] + 2) % 8] == 1) {
		score += 2;
	}
	if (gear[2][(idx[2][0] + 2) % 8] == 1) {
		score += 4;
	}
	if (gear[3][(idx[3][0] + 2) % 8] == 1) {
		score += 8;
	}
	cout << score;
	return 0;
}