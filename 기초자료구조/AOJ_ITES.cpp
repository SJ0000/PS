#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct RNG {
	//unsigned 자료형을 이용해서 2^32로 나누는 나머지 연산을
	//하지 않아도 되게 함.
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		//시드 값을 다음걸로 바꿔줌.
		unsigned ret = seed;
		seed = (seed * 214013u) + 2531011u;
		return ret % 10000 + 1;
	}	
};

int countRanges(int k, int n) {
	
	RNG rng;
	queue<int> range;
	int ret = 0; int sum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		sum += newSignal;
		range.push(newSignal);

		//합이 k보다 커질 경우 큐에서 빼줌
		while (sum > k) {
			sum -= range.front();
			range.pop();
		}

		if (sum == k) ret++;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n",countRanges(n,k));
	}
}