#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector < vector<int >> adj;
vector<bool> check;
vector<int> order;
void dfs(int now) {
	check[now] = true;
	for (int next = 0; next < adj.size(); next++) {
		if (adj[now][next] == 1 && !check[next]) {
			dfs(next);
		}
	}
	order.push_back(now);
}
void dictionary(const vector<string>& s) {
	bool invalid = false;
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	//단어 비교해서 dag 만듬
	for (int i = 0; i < s.size()-1; i++) {
		string s1 = s[i];
		string s2 = s[i + 1];
		int length = min(s1.size(), s2.size());
		for (int j = 0; j < length; j++) {
			if (s1[j] == s2[j]) continue;
			else {
				int a = s1[j] - 'a';
				int b = s2[j] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
	check = vector<bool>(26, false);
	order.clear();

	for (int i = 0; i < check.size(); i++) {
		if (!check[i]) {
			dfs(i);
		}
	}
	//역방향 간선 유무 check;
	reverse(order.begin(), order.end());
	for (int i = 0; i < adj.size(); i++) {
		for (int j = i + 1; j < adj.size(); j++) {
			if (adj[order[j]][order[i]]) {
				invalid = true;
				break;
			}
		}
	}
	if (invalid) {
		printf("INVALID HYPOTHESIS\n");
	}
	else {
		for (int i = 0; i < order.size(); i++) {
			cout << (char)(order[i]+'a');
		}
		cout << endl;
	}
}
int main() {	
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		vector<string> dic;
		int n;
		scanf("%d", &n);
		string s;
		while (n-- > 0) {
			cin >> s;
			dic.push_back(s);
		}
		dictionary(dic);
	}	
}