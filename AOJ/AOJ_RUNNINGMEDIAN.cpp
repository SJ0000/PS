#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {};
	int next() {
		int ret = seed;
		seed = ((seed* (long long)a) + b) % 20090711;
		return ret;
	}
};

int runningMedian(int n, RNG rng) {
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0;
	for (int cnt = 1; cnt <= n; cnt++) {
		if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(rng.next());
		}
		else {
			minHeap.push(rng.next());
		}
		//maxheap의 최대값이 minheap의 최소값보다 작을 때
		// maxheap의 최대값이 중간값이다.(짝수일 경우 작은것이 중간값이기 때문)
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b); minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret;
}

int main() {	
	int t;
	scanf("%d", &t);
	int x, y, z;
	while (t-- > 0) {
		scanf("%d %d %d", &x, &y, &z);
		RNG rng(y, z);
		int ans = runningMedian(x, rng);
		printf("%d\n", ans);
	}	
}