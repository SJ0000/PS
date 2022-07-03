#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct RNG {
	//unsigned �ڷ����� �̿��ؼ� 2^32�� ������ ������ ������
	//���� �ʾƵ� �ǰ� ��.
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		//�õ� ���� �����ɷ� �ٲ���.
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

		//���� k���� Ŀ�� ��� ť���� ����
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