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
using namespace std;

bool g[26][26];
int in[26];
bool used[26];
queue<int> q;
vector<string> s;
vector<int> ret;
bool check[26];

void dfs(int x){
    if(check[x]) return;
    check[x] = true;
    for(int i=0;i<26;i++){
        if(g[x][i]){
            dfs(i);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    string str;
    int st,ed;
    for(int i=0;i<n;i++){
        cin >> str;
        s.push_back(str);
        for(int j=0;j<str.size();j++){
            used[str[j]-'a'] = true;
        }
    }
    bool hasAns = false;
    int idx=0;
    //견고하게
    //aab,aa랑 aa,aab랑 다르다.
    for(int i=0;i<n-1;i++){
        idx = 0;
        while(s[i][idx]==s[i+1][idx]){
            idx++;
            if(idx >= s[i].size() || idx >= s[i+1].size()){
                idx = -1;
                if(s[i].size()>s[i+1].size()){
                    hasAns = true;
                    printf("!");
                }
                break;
            }           
        }
        if(idx==-1) continue;
        st = s[i][idx]-'a';
        ed = s[i+1][idx]-'a';
        if(!g[st][ed]){
            g[st][ed]=true;
            in[ed]++;
            //loop Check
            memset(check,0,sizeof(check));
            dfs(ed);
            if(check[st]){
                hasAns = true;
                printf("!");
                break;
            }
            //end loop Check
        }
        // printf("%d : %c => %c ok \n",i,st+'a',ed+'a');
    }
    //위상정렬
    int elementSize = 0;
    for(int i=0;i<26;i++){
        if(used[i]&&in[i]==0) q.push(i);
        if(used[i]) elementSize++;
    }
    int now;
    for(int i=0;i<elementSize;i++){
        if(hasAns) break;
        if(q.empty()){
            hasAns = true;
            printf("!");
            break;
        }else if(q.size()>=2){
            hasAns = true;
            printf("?");
            break;
        }
        now = q.front();
        q.pop();
        ret.push_back(now);
        //dd
        // printf("%c ",now+'a');
        for(int next = 0;next<26;next++){
            if(g[now][next]){
                g[now][next] = false;
                if(--in[next]==0){
                    q.push(next);
                }
            }
        }
    }
    if(!hasAns && ret.size()==elementSize){
        for(int i=0;i<ret.size();i++){
            printf("%c",ret[i]+'a');
        }
    }
    return 0;
}