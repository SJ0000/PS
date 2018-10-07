#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[101][101];
int n, k;

bool search_row(int st) {
	bool c[100] = { 0, };
	int now = a[st][0];
	//�˻�
	for (int i = 0; i < n; i++) {
		if (now == a[st][i]) continue;
		if (abs(now - a[st][i]) > 1) {
			return false;
		}
		//��������
		if (now - a[st][i] == 1) {
			//��ܸ��� ���� ������ �˻�.
			if (i + k - 1 >= n) return false;
			//�ٸ� ����� �ִ���,��ܱ��̸�ŭ�� ���̰� ������������ �˻�
			int tmp = a[st][i];
			for (int j = i; j < i + k; j++) {
				if (c[j]) return false;
				if (tmp != a[st][j]) return false;
				c[j] = true;
			}
			//���������� ��������� now--; i+k���� �ٽ� �˻�
			now--;
			i += k-1;
		}
		//��������
		if (now - a[st][i] == -1) {		
			if (i - k < 0) return false;
			int tmp = a[st][i - k];
			for (int j = i - k; j <= i - 1; j++) {
				if (c[j]) return false;
				if (tmp != a[st][j])return false;
				c[j] = true;
			}
			//���������� �ö����� now++;
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