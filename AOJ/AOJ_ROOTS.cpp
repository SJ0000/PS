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

// 두 극점 사이에는 하나의 근 만이 존재한다.

//다항식 계수 p가 주어질 때 미분한 결과인 p'의 계수를 반환한다.
vector<double> differentiate(const vector<double>& poly);
// 방정식을 푼다
vector<double> solveNaive(const vector<double>& poly);
// 다항식 f(x)의 계수 poly가 주어질 때, f(x0)을 반환한다.
double evaluate(const vector<double>& poly, double x0);

vector<double> solve(const vector<double>& poly);
//방정식 해의 절대 값은 L 이하여야 한다.
const double L = 25;
int main()
{
	int t;
	scanf("%d", &t);
	vector<double> p;
	int n;
	double val;
	while (t--) {
		scanf("%d", &n);
		p.clear();
		for (int i = 0; i <= n; i++) {
			scanf("%lf", &val);
			p.push_back(val);
		}
		vector<double> ans = solve(p);
		cout << fixed << setprecision(12);
		for (double d : ans) {
			cout << d << " ";
		}
		printf("\n");
	}
	return 0;
}

vector<double> differentiate(const vector<double>& poly) {
	vector<double> ret;
	int n = poly.size() - 1;
	for (int i = 0; i < n; i++) {
		ret.push_back(poly[i] * (n - i));
	}
	return ret;
}

double evaluate(const vector<double>& poly, double x0) {
	double ret = 0;
	int n = poly.size() - 1;
	double x;
	for (int i = 0; i < poly.size(); i++) {
		x = 1;
		for (int j = 0; j < n - i; j++) {
			x *= x0;
		}
		ret += x * poly[i];
	}
	return ret;
}
vector<double> solveNaive(const vector<double>& poly) {
	vector<double> ret;
	int n = poly.size() - 1;
	if (n == 1) {
		ret.push_back((-1 * poly[1]) / poly[0]);
	}
	else {
		//근의공식
		double a = poly[0], b = poly[1], c = poly[2];
		ret.push_back((-b + sqrt((b*b) - (4 * a*c))) / (2 * a));
		ret.push_back((-b - sqrt((b*b) - (4 * a*c))) / (2 * a));
	}
	sort(ret.begin(), ret.end());
	return ret;
}

vector<double> solve(const vector<double>& poly) {

	int n = poly.size() - 1;
	//2차 이하 방정식은 풀 수 있다.
	if (n <= 2) return solveNaive(poly);

	//방정식을 미분해서 n-1차 방정식을 얻는다.
	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);

	//이 극점들 사이를 하나하나 검사하며 근이 있나 확인한다.
	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);

	vector<double> ret;
	for (int i = 0; i < sols.size() - 1; i++) {

		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		//f(x1)과 f(x2)의 부호가 같으면 답은 없다. 
		if (y1*y2 > 0) continue;
		//불변조건 f(x1) <= 0 < f(x2)
		if (y1 > y2) {
			swap(y1, y2); swap(x1, x2);
		}
		//이분법
		for (int iter = 0; iter < 100; iter++) {
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);
			if (y1*my > 0) {
				y1 = my;
				x1 = mx;
			}
			else {
				y2 = my;
				x2 = mx;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());
	return ret;
}