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
		printf("%d ", v.front().first); // 첫번째꺼 지움
		int balloon = v.front().second; // 이동할만큼
		v.erase(v.begin());

		if (v.empty()) break; // 다 터트렸으면 탈출

		if (balloon < 0) {
			for (int i = 0; i < (-1*balloon); i++) {
				//뒤에꺼를 앞으로 옮김
				//vector.insert(index,value);
				v.insert(v.begin(), v.back());
				v.erase(--v.end()); // v.end()는 마지막원소 뒤의 허공을 가리킴.
				// erase로 end를 지우려면 v.erase(--v.end()) 해야함.
			}
		}
		else {
			for (int i = 0; i < balloon - 1; i++) {
				//앞에꺼를 뒤로 이동
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
	}
	return 0;
}