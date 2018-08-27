#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
using namespace std;
string S, W;
int cache[101][101];
vector<string> answer;
bool matchMemoized(int w, int s) {
	//memoization
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	//W와 S를 탐색한다.
	// *을 만나거나 s,w가 끝에 도달하면 끝남.
	while (s < S.size() && w < W.size() && 
		(W[w] == '?' || W[w] == S[s])) {
		w++;
		s++;
	}
	//W끝에 도달함 : 패턴에 *가 없는 경우, 즉 패턴과 문자열의 길이가 같아야함.
	if (w == W.size()) {
		return ret = (s == S.size());
	}
	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); skip++) {
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
		}
	}
	return ret = 0;
}
int main()
{	//helpp outofrange
	int t;
	cin >> t;
	while (t-- > 0) {
		cin >> W;
		int n; cin >> n;
		while (n-- > 0) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (matchMemoized(0,0)) {
				answer.push_back(S);
			}
		}		
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}		
		answer.clear();
	}
	return 0;
}