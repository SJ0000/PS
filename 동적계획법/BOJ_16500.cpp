#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string.h>
#include <queue>
#include <deque>
#include <set>
using namespace std;

string s;
int n;
int ok[101];
vector<string> w;
bool getAns = false;
//s의 st부터랑 word랑 일치하는지, 일치하면 true 반환
bool check(int st,int idx){
    string word = w[idx];
    if(st+word.length()>s.size()) return false;
    int len = word.length();
    for(int i=0;i<len;i++){
        if(s[st+i]!=word[i]) return false;
    }
    return true;
}

bool go(int st){
    bool ret = false;
    if(ok[st]!=-1){
        ok[st]==0 ? ret = false : ret = true;
        return ret;
    }
    if(st==s.size()) return true;

    for(int i=0;i<n;i++){
        if(check(st,i)){
            ret |= go(st+w[i].size());
        }
    }
    ret ? ok[st] = 1 : ok[st] = 0;
    return ret;
}

int main()
{
    cin >> s;
    scanf("%d",&n);
    string str;
    memset(ok,-1,sizeof(ok));
    for(int i=0;i<n;i++){
        cin >> str;
        w.push_back(str);
    }
    int ret;
    go(0) ? ret = 1 : ret = 0;
    cout << ret;
	return 0;
}