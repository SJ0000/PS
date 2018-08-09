#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> coords;
//
bool isDominated(int x, int y) {
	//x보다 오른쪽에 있는 점 중 가장왼쪽에 있는 점을 찾는다.
	map<int, int>::iterator it = coords.lower_bound(x);
	//그런점이없으면 (x,y)는 지배당하지않음
	if (it == coords.end()) return false;

	return y < it->second;
}
void removeDominated(int x, int y) {
	auto it = coords.lower_bound(x);
	//x보다 왼쪽에 있는 점이 없을 경우
	if (it == coords.begin()) return;
	it--;
	while (true) {
		if (it->second > y) {
			break;
		}
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else { 
			//이전 점으로 iterator를 하나 옮겨놓고 it를 지운다.
			auto jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}		
	}
}
int registered(int x, int y) {
	if (isDominated(x, y)) return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}
int main() {	
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		while (n-- > 0) {
			int x, y;
			scanf("%d %d", &x, &y);
			ans += registered(x, y);
		}
		printf("%d\n", ans);
		coords.clear();
	}	
}