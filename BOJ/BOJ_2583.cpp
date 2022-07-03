#include cstdio
#include iostream
#include algorithm
#include string
#include vector
#include queue
#include map
#include string.h
using namespace std;

int a[101][101];
bool check[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int m, n;
int sz = 0;
void set(int x1, int y1, int x2, int y2) {
	for (int i = y1; i  y2; i++) {
		for (int j = x1; j  x2; j++) {
			a[i][j] = 1;
			check[i][j] = true;
		}
	}
}
void dfs(int x, int y) {
	sz++;
	check[x][y] = true;
	int ax, ay;
	for (int i = 0; i  4; i++) {
		ax = x + dx[i]; ay = y + dy[i];
		if (0 = ax && ax  m && 0 = ay && ay  n && !check[ax][ay]) {
			dfs(ax, ay);
		}
	}
}
int main()
{	
	memset(a, 0, sizeof(a));
	memset(check, false, sizeof(check));
	int t;
	scanf(%d %d %d, &m, &n, &t);
	int x1, x2, y1, y2;
	while (t--  0) {
		scanf(%d %d %d %d, &x1, &y1, &x2, &y2);
		set(x1, y1, x2, y2);
	}	
	vectorint ret;
	for (int i = 0; i  m; i++) {
		for (int j = 0; j  n; j++) {
			if (check[i][j] == true) {
				continue;
			}
			dfs(i, j);
			ret.push_back(sz);
			sz = 0;
		}
	}
	sort(ret.begin(), ret.end());
	
	printf(%dn, ret.size());
	for (int i  ret) {
		printf(%d , i);
	}
	return 0;
}