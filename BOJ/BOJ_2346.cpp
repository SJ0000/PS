#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <list>

using namespace std;

vector<pair<int, int>> v;
const int pass = 0;
int n;


int main()
{
	int val;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
		v.push_back(make_pair(i, val));
	}
	
	while (true) {
		printf("%d ", v.front().first); // ù��°�� ����
		int balloon = v.front().second; // �̵��Ҹ�ŭ
		v.erase(v.begin());

		if (v.empty()) break; // �� ��Ʈ������ Ż��

		if (balloon < 0) {
			for (int i = 0; i < (-1*balloon); i++) {
				//�ڿ����� ������ �ű�
				//vector.insert(index,value);
				v.insert(v.begin(), v.back());
				v.erase(--v.end()); // v.end()�� ���������� ���� ����� ����Ŵ.
				// erase�� end�� ������� v.erase(--v.end()) �ؾ���.
			}
		}
		else {
			for (int i = 0; i < balloon - 1; i++) {
				//�տ����� �ڷ� �̵�
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
	}
	return 0;
}