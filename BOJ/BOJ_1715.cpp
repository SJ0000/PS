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

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{		
	int n;
	scanf("%d", &n);
	int card;
	for (int i = 0; i < n; i++) {
		scanf("%d", &card);
		pq.push(card);
	}
	int total = 0;
	int x, y;
	while (!pq.empty()) {
		x = pq.top(); pq.pop();
		if (pq.empty()) {
			
		}
		else {
			y = pq.top(); pq.pop();
			total += (x + y);
			pq.push(x + y);
		}
	}	
	printf("%d", total);
	return 0;
}