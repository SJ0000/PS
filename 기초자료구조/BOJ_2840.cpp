#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <list>

using namespace std;

int n, k;
vector<char> v;
bool alphabetChecker[26];
//마지막 회전의 인덱스부터 시계방향으로 출력
void printCircle(int index) {
	for (int i = index; i >= 0; i--) {
		printf("%c", v[i]);
	}
	for (int i = n - 1; i > index; i--) {
		printf("%c", v[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%d %d", &n, &k);
	v.assign(n,'?');
	int go;
	char letter;
	bool isNoAnswer = false;
	int index = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d %c", &go, &letter);
		index+=go;
		if (index >= n) {
			index %= n;
		}	
		if (v[index] == '?' || v[index] == letter) {
			v[index] = letter;
		}
		else {
			isNoAnswer = true;
			break;
		}
	}

	//중복문자 체크
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] == v[j] && v[i]!='?') isNoAnswer = true;
		}
	}
	if (isNoAnswer) {
		printf("!");
	}
	else {
		printCircle(index);
	}
	return 0;
}