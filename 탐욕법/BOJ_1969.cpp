#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

//완전탐색 = O(4^50) -> 불가능
//각 자리별로 가장 많이 나오는거 선택.

// a t g c , 0 1 2 3

string dna[1001];
int n, m;
void calc() {
	vector<char> ans[1001];
	int a, t, g, c;
	//세로로 탐색
	for (int i = 0; i < m; i++) {
		a = t = g = c = 0;
		for (int j = 0; j < n; j++) {
			if (dna[j][i] == 'A') a++;
			if (dna[j][i] == 'T') t++;
			if (dna[j][i] == 'G') g++;
			if (dna[j][i] == 'C') c++;
		}
		//결정
		int _max = max(a, max(t, max(g, c)));
		//사전순으로 추가해서 알아서 사전순 답 나오게
		if (a == _max) ans[i].push_back('A');
		if (c == _max) ans[i].push_back('C');
		if (g == _max) ans[i].push_back('G');
		if (t == _max) ans[i].push_back('T');
	}
	string ansDNA = "";
	for (int i = 0; i < m; i++) {
		ansDNA += ans[i][0];
	}
	//해밍거리
	int hd = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ansDNA[j] != dna[i][j]) {
				hd++;
			}
		}
	}
	cout << ansDNA << endl;
	cout << hd << endl;

}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> dna[i];
	}
	calc();
	return 0;
}