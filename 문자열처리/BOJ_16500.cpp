#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

string A[101], S;
int n, answer;
bool getAnswer;
void dfs(int idx) {
	//�̹� ���� ���Ѱ��.
	if (getAnswer) return;

	bool match;
	for (int i = 0; i < n; i++) {
		match = true;
		if (idx + A[i].size() > S.size()) continue;

		for (int j = 0; j < A[i].size(); j++) {
			if (S[idx + j] != A[i][j]) {
				match = false;
				break;
			}
		}
		//A[i]�� match�� ���.
		// 1) S�� ���� ������ ���.
		if (match) {
			if (idx + A[i].size() == S.size()) {
				getAnswer = true;
				answer = 1;
				return;
			}
			else {
				//2) �������� ���� ���.
				dfs(idx + A[i].size());
			}
		}
	}
}

int main()
{
	cin >> S;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	answer = 0;
	dfs(0);
	printf("%d\n", answer);
	return 0;
}