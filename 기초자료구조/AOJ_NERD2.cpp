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
	//x���� �����ʿ� �ִ� �� �� ������ʿ� �ִ� ���� ã�´�.
	map<int, int>::iterator it = coords.lower_bound(x);
	//�׷����̾����� (x,y)�� �������������
	if (it == coords.end()) return false;

	return y < it->second;
}
void removeDominated(int x, int y) {
	auto it = coords.lower_bound(x);
	//x���� ���ʿ� �ִ� ���� ���� ���
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
			//���� ������ iterator�� �ϳ� �Űܳ��� it�� �����.
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