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
	//전역변수 초기화
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
//euler circuit or trail 계산
void getEulerCircuit(int now, vector<int>& circuit) {
	for (int next = 0; next < adj.size(); next++) {
		//간선이 있을 경우
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
		//들어오는 간선이 하나 많을 경우, 즉 오일러트레일일때
		//시작점을 찾는다
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}		
	}
	//트레일이 아니면 서킷이니까 아무데서나 시작해도됨
	for (int i = 0; i < 26; i++) {
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	//둘다 아니면 답이없음 - 빈 벡터 출력
	return circuit;
}
bool checkEuler() {
	//오일러 서킷 : 모든 정점에서 나가는 간선의 수와 들어오는 간선의 수가 같아야 함
	//오일러 트레일 : 나가는 간선이 하나 많은 시작점이 하나, 들어오는 간선이 하나 많은 끝점이 하나 있어야함.

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