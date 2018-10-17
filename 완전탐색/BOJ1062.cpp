#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int N, K;
bool apb[26] = { false , };
string str[51];
string tmp[51];
vector<int> pick;
set<char> myset;
vector<char> li;
int ans = -1;
void dfs(int cnt, int start) {
	// antic �����ϰ� K-5�� ����ų� �� ���� ������
	if (cnt == K - 5 || start == li.size()) {
		//� �������� ���ϰ� ����.
		int tmp = 0;
		bool valid;
		for (int i = 0; i < N; i++) {
			valid = true;
			for (int j = 0; j < str[i].size(); j++) {
				if (!apb[str[i][j] - 'a']) {
					valid = false;
					break;
				}
			}
			if (valid) tmp++;
		}
		ans = max(ans, tmp);
		return;
	}
	//����
	for (int i = start; i < li.size(); i++) {
		char ch = li[i];
		if (apb[ch - 'a'] == false) {
			apb[ch - 'a'] = true;
			dfs(cnt + 1, i + 1);
			apb[ch - 'a'] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	// antic�� �ʼ�
	apb['a' - 'a'] = apb['n' - 'a'] = apb['t' - 'a'] = apb['i' - 'a'] = apb['c' - 'a'] = true;

	for (int i = 0; i < N; i++) {
		cin >> tmp[i];
	}
	//�ĺ��� ����ġ��
	bool word[26];
	for (int i = 0; i < N; i++) {
		memset(word, false, sizeof(word));
		word['a' - 'a'] = word['n' - 'a'] = word['t' - 'a'] = word['i' - 'a'] = word['c' - 'a'] = true;
		for (int j = 4; j < (int)tmp[i].size() - 4; j++) {
			if (!word[tmp[i][j] - 'a']) {
				word[tmp[i][j]] = true;
				str[i] += tmp[i][j];
				myset.insert(tmp[i][j]);
			}
		}
	}
	//set�� �ִ°� ������ vector�� ����.
	for (auto iter = myset.begin(); iter != myset.end(); iter++) {
		li.push_back(*iter);
	}
	if (K < 5) {
		printf("0\n");
	}
	else {
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}