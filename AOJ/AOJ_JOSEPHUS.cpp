#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;
void josephus(int n, int k) {
	list<int> li;
	for (int i = 1; i <= n; i++) {
		li.push_back(i);
	}
	list<int>::iterator kill = li.begin();
	while (n > 2) {
		kill = li.erase(kill);
		if (kill == li.end()) {
			kill = li.begin();
		}
		n--;
		for (int i = 0; i < k - 1; i++) {
			kill++;
			if (kill == li.end()) {
				kill = li.begin();
			}
		}
	}
	printf("%d %d\n", li.front(), li.back());
}
int main() {
	int t;
	int n, k;
	scanf_s("%d", &t);
	while (t-- > 0) {
		scanf_s("%d %d", &n, &k);
		josephus(n, k);
	}	
}