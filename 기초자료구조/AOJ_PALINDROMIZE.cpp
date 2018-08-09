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
int solve (const string& N, const string& M) {
	int n = N.size(), m = M.size();
	vector<int> pi = getPi(M);
	int begin = 0, matched = 0;
	while (begin < n) {
		if (matched < m && N[begin + matched] == M[matched]) {
			matched++;
			if (begin + matched == n) {
				return matched;
			}
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
	return 0;
}
int main() {	
	int t;
	cin >> t;
	while (t-- > 0) {
		string s;
		cin >> s;
		string rev(s);
		reverse(rev.begin(), rev.end());
		printf("%d\n", s.size()*2 - solve(s,rev));
	}	
}