#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> adj;
vector<string> graph[26][26];

vector<int> indegree, outdegree;
void makeGraph(const vector<string>& words) {
	//�������� �ʱ�ȭ
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			graph[i][j].clear();
		}
	}
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	for (int i = 0; i < words.size(); i++) {
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}
//euler circuit or trail ���
void getEulerCircuit(int now, vector<int>& circuit) {
	for (int next = 0; next < adj.size(); next++) {
		//������ ���� ���
		while (adj[now][next] > 0) {			
			adj[now][next]--;
			getEulerCircuit(next, circuit);
		}		
	}
	circuit.push_back(now);
}

vector<int> getEulerCircuitOrTrail() {
	vector<int> circuit;
	for (int i = 0; i < 26; i++) {
		//������ ������ �ϳ� ���� ���, �� ���Ϸ�Ʈ�����϶�
		//�������� ã�´�
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}		
	}
	//Ʈ������ �ƴϸ� ��Ŷ�̴ϱ� �ƹ������� �����ص���
	for (int i = 0; i < 26; i++) {
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	//�Ѵ� �ƴϸ� ���̾��� - �� ���� ���
	return circuit;
}
bool checkEuler() {
	//���Ϸ� ��Ŷ : ��� �������� ������ ������ ���� ������ ������ ���� ���ƾ� ��
	//���Ϸ� Ʈ���� : ������ ������ �ϳ� ���� �������� �ϳ�, ������ ������ �ϳ� ���� ������ �ϳ� �־����.

	int p1=0, m1=0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || delta > 1) return false;
		if (delta == 1) p1++;
		if (delta == -1) m1++;
	}
	return (p1 == 1 && m1 == 1) || (p1 == 0 && m1 == 0);
}
string solve(const vector<string>& words) {
	makeGraph(words);
	if (!checkEuler()) {
		return "IMPOSSIBLE";
	}
	vector<int> circuit = getEulerCircuitOrTrail();

	if (circuit.size() != words.size() + 1) {
		return "IMPOSSIBLE";
	}
	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 1; i < circuit.size(); i++) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}
int main() {	
	int t;
	cin >> t;
	vector<string> words;
	while (t-- > 0) {
		int n;
		cin >> n;
		string s;
		while (n-- > 0) {
			cin >> s;
			words.push_back(s);
		}
		cout << solve(words) << endl;
		words.clear();
	}	
}