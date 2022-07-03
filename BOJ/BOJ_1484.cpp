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

// Gų�α׷� : ���� ������ ���� - ����ϰ� �ִ� ������ ����
// G�� �־����� �� ���� �����Է� ������ ��.

int main()
{	
	int g;
	scanf("%d", &g);

	int a = 1, b = 1;
	bool impossible = true;
	while (true) {
		int now = (b*b) - (a*a);
		//�������� : a��b�� 1���̹ۿ� �ȳ��µ�, now�� g���� ū ���.
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