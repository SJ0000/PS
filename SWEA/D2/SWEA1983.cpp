#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int n, k;
vector<pair<double, int>> student;

string getGrade(int x) {
	int g = 0;
	for (int i = 0; i < n; i++) {
		if (student[i].second == x) {
			g = n - i;
			break;
		}
	}	
	int level = ceil((double)g / (n / 10)) - 1;
	if (level == 0) {
		return "A+";
	}
	else if(level==1) {
		return "A0";
	}
	else if (level == 2) {
		return "A-";
	}
	else if (level == 3) {
		return "B+";
	}
	else if (level == 4) {
		return "B0";
	}
	else if (level == 5) {
		return "B-";
	}
	else if (level == 6) {
		return "C+";
	}
	else if (level == 7) {
		return "C0";
	}
	else if (level == 8) {
		return "C-";
	}
	else {
		return "D0";
	}
}
int main()
{	
	int T;
	cin >> T;
	int mid, fin, rep;
	double point;
	for (int t = 1; t <= T; t++) {
		student.clear();
		scanf("%d %d",&n,&k);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &mid, &fin, &rep);
			point = mid * 0.35 + fin * 0.45 + rep * 0.2;
			student.push_back(make_pair(point,i));
		}
		sort(student.begin(), student.end());
		cout << "#" << t << " " << getGrade(k) << endl;
	}
	return 0;
}