#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>

using namespace std;

// G킬로그램 : 현재 몸무게 제곱 - 기억하고 있던 몸무게 제곱
// G가 주어졌을 때 현재 몸무게로 가능한 것.

int main()
{	
	int g;
	scanf("%d", &g);

	int a = 1, b = 1;
	bool impossible = true;
	while (true) {
		int now = (b*b) - (a*a);
		//종료조건 : a랑b가 1차이밖에 안나는데, now가 g보다 큰 경우.
		if (b - a == 1 && now > g) {
			break;
		}
		if (now == g) {
			impossible = false;
			printf("%d\n", b);
			b++;
		}
		else if (now > g) {
			a++;
		}
		else {
			b++;
		}		
	}
	if (impossible) printf("-1\n");
	return 0;
}