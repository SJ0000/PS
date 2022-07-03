#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> getPi(const string& N) {
	//KMP�˰����� �̿��ؼ� PI(�κ���ġ���̺�)�� ���Ѵ�.
	int n = N.size();
	vector<int> pi(n, 0);
	int begin = 1;
	int matched = 0;
	while (begin + matched < n) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPi(N);
	int matched = 0;
	for (int i = 0; i < n; i++) {
		//matched�� ���ڿ� ¤������ �ش� ���ڰ� ����ġ �� ���
		// ���� ������ ������ ���� pi[matched-1]�� ���δ�.
		while (matched > 0 && H[i] != N[matched]) {
			matched = pi[matched - 1];
		}
		//������ ���
		if (H[i] == N[matched]) {
			matched++;
			if (matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
//original���� shift�� ��� �ؾ� target�� �Ǵ��� �˻�
int shifts(const string& original, const string& target) {
	return kmpSearch(original + original, target)[0];
}
int main() {	
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		string start;
		cin >> start;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			string target;
			cin >> target;
			if (i % 2 == 1) {
				ans += shifts(start, target);
			}
			else {
				ans += shifts(target, start);
			}
			start=target;	
		}
		printf("%d\n", ans);
	}	
}