#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
string common;
vector<string> vars;
vector<int> space;

void calc() {
	string var, var_t, var_n; // 형식,이름
	int tp;
	for (string var : vars) {
		tp = -1;
		var = var.substr(0, var.size() - 1);
		for (int j = 0; j < var.size(); j++) {
			if (!(('a' <= var[j] && var[j] <= 'z') || ('A' <= var[j] && var[j] <= 'Z'))) {
				tp = j;
				break;
			}
		}
		if (tp > 0) {
			var_n = var.substr(0, tp);
			var_t = var.substr(tp);
			reverse(var_t.begin(), var_t.end());
			cout << common << var_t << " " << var_n << ";" << endl;
		}
		else {
			cout << common << " " << var << ";" << endl;
		}

	}
}

int main()
{
	cin >> common;
	//선처리
	string tmp;
	while (true) {
		cin >> tmp;

		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == '[') tmp[i] = ']';
			else if (tmp[i] == ']') tmp[i] = '[';
		}

		vars.push_back(tmp);
		if (tmp[tmp.size() - 1] == ';') {
			break;
		}
	}
	calc();
	return 0;
}