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

priority_queue<int,vector<int>,greater<int>> pq;

int main()
{		
	int n;
	scanf("%d", &n);
	int val;
	for (int i = 0; i < n*n; i++) {
		scanf("%d", &val);
		if (pq.size() < n) {
			pq.push(val);
		}
		else {
			//pq안에 가장 작은값보다 크면 pop하고 val 넣기
			if (val > pq.top()) {
				pq.pop();
				pq.push(val);
			}
		}
	}
	printf("%d\n", pq.top());
	return 0;
}