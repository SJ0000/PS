#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

//����Ž�� = O(4^50) -> �Ұ���
//�� �ڸ����� ���� ���� �����°� ����.

// a t g c , 0 1 2 3

string dna[1001];
int n, m;
void calc() {
	vector<char> ans[1001];
	int a, t, g, c;
	//���η� Ž��
	for (int i = 0; i < m; i++) {
		a = t = g = c = 0;
		for (int j = 0; j < n; j++) {
			if (dna[j][i] == 'A') a++;
			if (dna[j][i] == 'T') t++;
			if (dna[j][i] == 'G') g++;
			if (dna[j][i] == 'C') c++;
		}
		//����
		int _max = max(a, max(t, max(g, c)));
		//���������� �߰��ؼ� �˾Ƽ� ������ �� ������
		if (a == _max) ans[i].push_back('A');
		if (c == _max) ans[i].push_back('C');
		if (g == _max) ans[i].push_back('G');
		if (t == _max) ans[i].push_back('T');
	}
	string ansDNA = "";
	for (int i = 0; i < m; i++) {
		ansDNA += ans[i][0];
	}
	//�عְŸ�
	int hd = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ansDNA[j] != dna[i][j]) {
				hd++;
			}
		}
	}
	cout << ansDNA << endl;
	cout << hd << endl;

}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> dna[i];
	}
	calc();
	return 0;
}