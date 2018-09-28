#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

string s[5];
char ch[5][15];
int main()
{	
	int T;	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(ch, ' ', sizeof(ch));
		for (int i = 0; i < 5; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < s[i].size(); j++) {
				ch[i][j] = s[i][j];
			}
		}
		printf("#%d ", t);
		for (int j = 0; j < 15; j++) {
			for (int i = 0; i < 5; i++) {
				if (ch[i][j] == ' ') {
					continue;
				}
				else {
					printf("%c", ch[i][j]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}