#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


void printAns(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '3' || str[i] == '6' || str[i] == '9') {
			count++;
		}
	}
	string clap = "";
	for (int i = 0; i < count; i++) {
		clap += "-";
	}
	if (count == 0) {
		cout << str;
	}
	else {
		cout << clap;
	}
}
int main()
{
	int n;
	string s;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		s = to_string(i);
		printAns(s);
		cout << " ";
	}
	cout << endl;
	return 0;
}