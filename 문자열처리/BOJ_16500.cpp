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
	//이미 답을 구한경우.
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
		//A[i]가 match인 경우.
		// 1) S의 끝에 도달한 경우.
		if (match) {
			if (idx + A[i].size() == S.size()) {
				getAnswer = true;
				answer = 1;
				return;
			}
			else {
				//2) 도달하지 못한 경우.
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