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
int main() {
	string a,b;
	cin >> a >> b;
	string s = a + b;
	vector<int> pi = getPi(s);
	stack<int> ret;
	int n = s.size();
	while (n > 0) {
		ret.push(n);
		n = pi[n - 1];
	}
	while (!ret.empty()) {
		printf("%d ", ret.top());
		ret.pop();
	}
	system("pause");
}