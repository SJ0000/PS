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

int parent[100001];
int fn[100001]; //친구 수
int mapIndex;
map<string, int> searchId;

int find(int n) {
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	//루트에 묶음의 개수 저장.
	parent[b] = a;
	fn[a] += fn[b];
}
void init() {
	for (int i = 0; i < 100001; i++) {
		parent[i] = -1;
		fn[i] = 1;
	}
	searchId.clear();
	mapIndex = 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	string a, b;
	int aidx, bidx;
	int n;

	while (tc-- > 0) {
		init();
		cin >> n;
		while (n-- > 0) {

			cin >> a >> b;

			if (searchId.find(a) == searchId.end()) {
				searchId.insert(make_pair(a, mapIndex++));
			}
			if (searchId.find(b) == searchId.end()) {
				searchId.insert(make_pair(b, mapIndex++));
			}
			aidx = searchId[a];
			bidx = searchId[b];
			merge(aidx, bidx);
			cout << fn[find(aidx)] << "\n";
		}
	}
	return 0;
}