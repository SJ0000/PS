#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

int M;
double N, P;

//1�޿� m���� ���� ���� �� ������ true �������� false
bool simulate(double m) {

	double debt = N;
	double perMonth = 1 + (P / 1200);
	//M�޵��� ���´�.
	for (int i = 0; i < M; i++) {
		debt *= perMonth;
		debt -= m;
	}
	if (debt <= 0) {
		return true;
	}
	else {
		return false;
	}
}

double getAns() {

	//���ڰ� ���� �Ҿ�� ���� ���ƾ� �ϴϱ�
	//x2�� ���ڸ� ������ ���̾�� �Ѵ�.
	double x1 = 0, x2 = N * (1 + (P / 1200));

	for (int iter = 0; iter < 110; iter++) {
		double m = (x1 + x2) / 2;
		if (simulate(m)) {
			x2 = m;
		}
		else {
			x1 = m;
		}
	}

	return (x1 + x2) / 2;
}


int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lf %d %lf", &N, &M, &P);

		cout << fixed << setprecision(10);

		cout << getAns() << endl;
	}
	return 0;
}