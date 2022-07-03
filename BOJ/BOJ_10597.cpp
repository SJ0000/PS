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

	//BASE 1 : �̹� ���� ���� ���
	if (getAns) return;

	//BASE 2 : list ��ä����
	if (index >= s.size()) {
		for (int x : li) {
			printf("%d ", x);
		}
		getAns = true;
		return;
	}

	// x�� �ش��ε������� 1�ڸ�, y�� �ش��ε���~2�ڸ�
	int x, y;
	if (index < s.size() - 1) {//2�ڸ� ����
		x = s[index] - '0';
		y = x * 10 + (s[index + 1] - '0');
	}
	else {
		x = s[index] - '0';
		y = 987654321;		
	}

	//1�ڸ����� �����Ѱ��
	if (x <= maxn && x!=0) {
		if (!check[x]) {
			li.push_back(x);
			check[x] = true;
			dfs(index + 1, li);
			check[x] = false;
			li.pop_back();
		}
	}
	//2�ڸ����� ������ ���
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
	if (sz < 10) { // 1�ڸ���
		return sz;
	}
	else { //2�ڸ���
		return ((sz - 9) / 2) +9 ;   // 1~9 9�� +  2�ڸ����� ����
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