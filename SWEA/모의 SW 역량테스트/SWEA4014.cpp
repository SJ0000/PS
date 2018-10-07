#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[101][101];
int n, k;

bool search_row(int st) {
	bool c[100] = { 0, };
	int now = a[st][0];
	//검사
	for (int i = 0; i < n; i++) {
		if (now == a[st][i]) continue;
		if (abs(now - a[st][i]) > 1) {
			return false;
		}
		//내리막길
		if (now - a[st][i] == 1) {
			//계단만들 공간 나오나 검사.
			if (i + k - 1 >= n) return false;
			//다른 계단이 있는지,계단길이만큼의 길이가 같은높이인지 검사
			int tmp = a[st][i];
			for (int j = i; j < i + k; j++) {
				if (c[j]) return false;
				if (tmp != a[st][j]) return false;
				c[j] = true;
			}
			//내리막길을 만들었으니 now--; i+k부터 다시 검사
			now--;
			i += k-1;
		}
		//오르막길
		if (now - a[st][i] == -1) {		
			if (i - k < 0) return false;
			int tmp = a[st][i - k];
			for (int j = i - k; j <= i - 1; j++) {
				if (c[j]) return false;
				if (tmp != a[st][j])return false;
				c[j] = true;
			}
			//오르막길을 올랐으니 now++;
			now++;
		}
	}
	return true;
}
bool search_col(int st) {
	bool c[100] = { 0, };
	int now = a[0][st];
	for (int i = 0; i < n; i++) {
		if (now == a[i][st]) continue;
		if (abs(now - a[i][st]) > 1) {
			return false;
		}
		if (now - a[i][st] == 1) {
			if (i + k - 1 >= n) return false;
			int tmp = a[i][st];
			for (int j = i; j < i + k; j++) {
				if (c[j]) return false;
				if (tmp != a[j][st]) return false;
				c[j] = true;
			}
			now--;
			i += k-1;
		}
		if (now - a[i][st] == -1) {
			if (i - k < 0) return false;
			int tmp = a[i-k][st];
			for (int j = i - k; j <= i - 1; j++) {
				if (c[j]) return false;
				if (tmp != a[j][st])return false;
				c[j] = true;
			}
			now++;
		}
	}
	return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t_case = 1 ; t_case<=T;t_case++){
       scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (search_row(i)) {
			ret++;
		}
		if (search_col(i)) {
			ret++;
		}
	}
	printf("#%d %d\n",t_case, ret);
    }    
	return 0;
}