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

priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>>pq;
// <값,부호> // -면 0, +면 1; // minHeap이기 때문
int main()
{		
	int n;
	scanf("%d", &n);
	long val;
	for (int i = 0; i < n; i++) {
		scanf("%ld", &val);

		if (val == 0) {
			pair<long, int> now;
			if (pq.size() != 0) {
				now = pq.top();
				pq.pop();
			}
			else {
				now = make_pair(0, 0);
			}
			if (now.second == 1) {
				printf("%ld\n", now.first);
			}
			else {
				printf("%ld\n", -now.first);
			}
		}
		else {
			if (val < 0) {
				pq.push(make_pair(-val, 0));
			}
			else {
				pq.push(make_pair(val, 1));
			}		
		}
	}	
	return 0;
}