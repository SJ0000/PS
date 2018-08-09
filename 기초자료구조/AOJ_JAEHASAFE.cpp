#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> getPi(const string& N) {
	//KMP알고리즘을 이용해서 PI(부분일치테이블)를 구한다.
	int n = N.size();
	vector<int> pi(n, 0);
	int begin = 1;
	int matched = 0;
	while (begin + matched < n) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPi(N);
	int matched = 0;
	for (int i = 0; i < n; i++) {
		//matched번 글자와 짚더미의 해당 글자가 불일치 할 경우
		// 현재 대응된 글자의 수를 pi[matched-1]로 줄인다.
		while (matched > 0 && H[i] != N[matched]) {
			matched = pi[matched - 1];
		}
		//대응될 경우
		if (H[i] == N[matched]) {
			matched++;
			if (matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
//original에서 shift를 몇번 해야 target이 되는지 검사
int shifts(const string& original, const string& target) {
	return kmpSearch(original + original, target)[0];
}
int main() {	
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		string start;
		cin >> start;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			string target;
			cin >> target;
			if (i % 2 == 1) {
				ans += shifts(start, target);
			}
			else {
				ans += shifts(target, start);
			}
			start=target;	
		}
		printf("%d\n", ans);
	}	
}