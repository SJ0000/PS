#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int n;
string s;
string ans[30];

/*		pos
	 --      1
	l  l	2 3
	l  l
	 --      4
	l  l	5  6
	l  l
	 --		 7
*/

void printLine(char ch, int pos) {
	string block, space;
	for (int i = 0; i < n; i++) {
		block += ch;
		space += ' ';
	}
	if (pos == 1) {
		ans[0] += (' ' + block + ' ');
	}
	else if (pos == 2) {
		for (int i = 1; i <= n; i++) {
			ans[i] += (ch + space);
		}
	}
	else if (pos == 3) {
		for (int i = 1; i <= n; i++) {
			ans[i] += ch;
		}
	}
	else if (pos == 4) {
		ans[n + 1] += (' ' + block + ' ');
	}
	else if (pos == 5) {
		for (int i = n + 2; i <= 2 * n + 1; i++) {
			ans[i] += (ch + space);
		}
	}
	else if (pos == 6) {
		for (int i = n + 2; i <= 2 * n + 1; i++) {
			ans[i] += ch;
		}
	}
	else if (pos == 7) {
		ans[2 * n + 2] += (' ' + block + ' ');
	}
}
void assemble_num(char c1, char c2, char c3, char c4, char c5, char c6, char c7) {
	printLine(c1, 2);
	printLine(c2, 5);
	printLine(c3, 1);
	printLine(c4, 4);
	printLine(c5, 7);
	printLine(c6, 3);
	printLine(c7, 6);
}
void printN(int now) {
	if (now == 0) {
		assemble_num('|', '|', '-', ' ', '-', '|', '|');
	}
	else if (now == 1) {
		assemble_num(' ', ' ', ' ', ' ', ' ', '|', '|');
	}
	else if (now == 2) {
		assemble_num(' ', '|', '-', '-', '-', '|', ' ');
	}
	else if (now == 3) {
		assemble_num(' ', ' ', '-', '-', '-', '|', '|');
	}
	else if (now == 4) {
		assemble_num('|', ' ', ' ', '-', ' ', '|', '|');
	}
	else if (now == 5) {
		assemble_num('|', ' ', '-', '-', '-', ' ', '|');
	}
	else if (now == 6) {
		assemble_num('|', '|', '-', '-', '-', ' ', '|');
	}
	else if (now == 7) {
		assemble_num(' ', ' ', '-', ' ', ' ', '|', '|');
	}
	else if (now == 8) {
		assemble_num('|', '|', '-', '-', '-', '|', '|');
	}
	else if (now == 9) {
		assemble_num('|', ' ', '-', '-', '-', '|', '|');
	}
}
void printStr(string s) {
	for (int i = 0; i < s.size() - 1; i++) {
		int now = s[i] - '0';
		//조립순서에 유의
		printN(now);
		//각 숫자사이에 공백한칸
		for (int i = 0; i <= 2 * n + 2; i++) {
			ans[i] += ' ';
		}
	}
	printN(s[s.size() - 1] - '0');
}
int main(void) {
	cin >> n >> s;
	printStr(s);
	for (int i = 0; i <= 2 * n + 2; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}