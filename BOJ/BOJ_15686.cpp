#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

vector<int> home;
vector<int> chicken;
vector<int> idx;
const int MAX = 987654321;

int getLength(int h, int c) {
	int hx = h / 100;
	int hy = h % 100;
	int cx = c / 100;
	int cy = c % 100;

	return abs(hx - cx) + abs(hy - cy);
}

int getChickenLength(vector<int> l) {
	int ret = 0;
	int length;
	for (int h : home) {
		length = MAX;
		for (int c = 0; c < l.size();c++) {
			if (l[c] == 0) continue;
			length = min(length, getLength(h, chicken[c]));
		}
		ret += length;
	}
	return ret;
}

int main()
{		
	int n, m;
	scanf("%d %d", &n, &m);
	int val;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &val);
			if (val == 0) continue;
			if (val == 1) {
				home.push_back((i * 100) + j);
				continue;
			}
			if (val == 2) {
				chicken.push_back((i * 100) + j);
				continue;
			}
		}
	}
	int minLength = MAX;
	//1개고름 ~ m개고름
	for (int i = 1; i <= m; i++) {
		idx.clear();
		//0이 chicken.size - i개 , 1이 i개
		for (int j = 0; j < chicken.size()-i; j++) {
			idx.push_back(0);
		}
		for (int j = 0; j < i; j++) {
			idx.push_back(1);
		}		
		do{	
			minLength= min(getChickenLength(idx),minLength);

		} while (next_permutation(idx.begin(), idx.end()));
	}
	printf("%d\n", minLength);
	return 0;
}