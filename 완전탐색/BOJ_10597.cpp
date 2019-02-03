#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool check[51];

int maxn;
string s;
bool getAns = false;
void dfs(int index, vector<int> li) {

	//BASE 1 : 이미 답을 구한 경우
	if (getAns) return;

	//BASE 2 : list 다채운경우
	if (index >= s.size()) {
		for (int x : li) {
			printf("%d ", x);
		}
		getAns = true;
		return;
	}

	// x는 해당인덱스에서 1자리, y는 해당인덱스~2자리
	int x, y;
	if (index < s.size() - 1) {//2자리 가능
		x = s[index] - '0';
		y = x * 10 + (s[index + 1] - '0');
	}
	else {
		x = s[index] - '0';
		y = 987654321;		
	}

	//1자리수가 가능한경우
	if (x <= maxn && x!=0) {
		if (!check[x]) {
			li.push_back(x);
			check[x] = true;
			dfs(index + 1, li);
			check[x] = false;
			li.pop_back();
		}
	}
	//2자리수가 가능한 경우
	if (y <= maxn && y>9) {
		if (!check[y]) {
			li.push_back(y);
			check[y] = true;
			dfs(index + 2, li);
			check[y] = false;
			li.pop_back();
		}
	}
}


int getN(int sz) {	
	if (sz < 10) { // 1자리수
		return sz;
	}
	else { //2자리수
		return ((sz - 9) / 2) +9 ;   // 1~9 9개 +  2자리수의 개수
	}
}

int main()
{	
	cin >> s;
	maxn = getN(s.size());
	vector<int> v;

	dfs(0, v);

	return 0;
}