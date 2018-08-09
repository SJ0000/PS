#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

bool isMatch(const string& formula) {
	const string opening("({["), closing(")}]");
	stack<char> st;
	for (int i = 0; i < formula.size(); i++) {
		char c = formula[i];
		if (opening.find(c) != -1) {
			st.push(c);
		}
		else {
			if (st.empty()) return false;
			if (opening.find(st.top()) != closing.find(c)) return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		string s;
		cin >> s;
		if (isMatch(s)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}