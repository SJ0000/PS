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

//1달에 m원씩 내서 갚을 수 있으면 true 못값으면 false
bool simulate(double m) {

	double debt = N;
	double perMonth = 1 + (P / 1200);
	//M달동안 갚는다.
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

	//이자가 먼저 불어나고 돈을 갚아야 하니까
	//x2는 이자를 포함한 값이어야 한다.
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