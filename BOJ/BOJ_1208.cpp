#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

//���̵� �ȶ��ö� ����Ǯ����.
// ���� �� Ǭ��. �ð��� ���̷��� [���] �� �ʿ��ϴ�.

// 1Ʈ : sort�� 2�� for�� ����ġ�� 
// 2Ʈ : asum�� �������� bsum �̺�Ž��
// 3Ʈ : �������� ����

int n;
long long s;
vector<long long> a, b;
vector<long long> asum, bsum;

//x+y=s�� y�� ������ ���� ��ȯ.
long long bsearch(long long x) {
	long long y = s - x;
	int l = 0;
	int r = bsum.size() - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		//	printf("bSearch / mid = %d , bsum[mid] = %d , l = %d , r = %d \n", mid, bsum[mid],l,r);

		if (bsum[mid] == y) {
			//�������� ����
			long long ret = 1;
			//������
			for (int i = mid + 1; i < bsum.size(); i++) {
				if (bsum[i] == y) {
					ret++;
				}
				else {
					break;
				}
			}
			for (int i = mid - 1; i >= 0; i--) {
				if (bsum[i] == y) {
					ret++;
				}
				else {
					break;
				}
			}
			return ret;
		}
		else if (bsum[mid] > y) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	//���°��
	return 0;
}

//long long �� ����
//�־��� ��� - 40���� �� 0�̰� s�� 0�̸� 2^20 * 2^20 -1 �� �����ε� int�ʰ���

long long solve() {
	long long ret = 0;
	long long sum;
	for (int i = 0; i < (1 << a.size()); i++) {
		sum = 0;
		for (int j = 0; j < a.size(); j++) {
			if (i&(1 << j)) sum += a[j];
		}
		asum.push_back(sum);
	}

	for (int i = 0; i < (1 << b.size()); i++) {
		sum = 0;
		for (int j = 0; j < b.size(); j++) {
			if (i&(1 << j)) sum += b[j];
		}
		bsum.push_back(sum);
	}

	sort(asum.begin(), asum.end());
	sort(bsum.begin(), bsum.end());
	/*
	for (int x : asum) {
		printf("%d ",x);
	}
	printf("\n");
	for (int x : bsum) {
		printf("%d ", x);
	}
	printf("\n");
	*/
	/*
	for (int i = 0; i < asum.size(); i++) {
		ret += bsearch(asum[i]);
	//	printf("%d %d \n", asum[i], ret);
	}
	*/

	//printf("size : %d %d \n", asum.size(), bsum.size());

	//��������
	long long l = 0;
	long long r = bsum.size() - 1;
	while (l < asum.size() && r >= 0) {
		//	printf("l r : %lld %lld \n", l, r);
		if (asum[l] + bsum[r] == s) {
			//	printf("l r : %lld %lld / %lld %lld \n", l, r, asum[l], bsum[r]);
				//��������
			long long lcnt = 0;
			long long rcnt = 0;
			for (int i = l; i < asum.size(); i++) {
				if (asum[i] == asum[l]) {
					lcnt++;
				}
				else {
					break;
				}
			}
			for (int i = r; i >= 0; i--) {
				if (bsum[i] == bsum[r]) {
					rcnt++;
				}
				else {
					break;
				}
			}
			l += lcnt;
			r -= rcnt;
			ret += (lcnt * rcnt);
		}
		else if (asum[l] + bsum[r] > s) {
			r--;
		}
		else {
			l++;
		}
	}
	return ret;
}

int main()
{
	scanf("%d %lld", &n, &s);
	long long val;
	int l = n / 2;
	int r = n - l;
	for (int i = 0; i < l; i++) {
		scanf("%lld", &val);
		a.push_back(val);
	}
	for (int i = 0; i < r; i++) {
		scanf("%lld", &val);
		b.push_back(val);
	}
	long long ans = solve();
	if (s == 0) ans--;
	printf("%lld", ans);
	return 0;
}