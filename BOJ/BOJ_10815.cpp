#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
using namespace std;

vector<int> a;
int m;
bool search(int n) {
	int l = 0;
	int r = m - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == n) {
			return true;
		}
		else if(a[mid] < n) {
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return false;
}

int main()
{	
	scanf("%d", &m);
	int n;
	for (int i = 0; i < m; i++) {
		scanf("%d", &n);
		a.push_back(n);
	}
	sort(a.begin(), a.end());
	int t, num;
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &num);
		if (search(num)) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
	return 0;
}