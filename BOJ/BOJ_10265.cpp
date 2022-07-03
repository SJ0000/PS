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

bool check[10001];
vector<int> g[10001];
vector<int> r[10001]; //reverse
stack<int> st;
vector<int> scc[10001];
vector<vector<int>> sccList;
void dfs1(int now){
    if(check[now]) return;
    
    check[now] = true;
    for(int i=0;i<g[now].size();i++){
        dfs1(g[now][i]);
    }
    st.push(now);
}

void dfs2(int start, int now){
    if(check[now]) return;
    check[now] = true;
    for(int i=0;i<r[now].size();i++){
        dfs2(start,r[now][i]);
    }
    scc[start].push_back(now);
}

bool comp(vector<int> x, vector<int> y){
    return x[0]<y[0];
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    printf("-1\n");
}

int main()
{
    int v,e;
    scanf("%d %d",&v,&e);
    int a,b;
    for(int i=0;i<e;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        r[b].push_back(a);
    }
    //정방향 dfs
    for(int i=1;i<=v;i++){
        dfs1(i);
    }
    //stack 순서대로 역방향 dfs
    memset(check,0,sizeof(check));
    while(!st.empty()){
        dfs2(st.top(),st.top());
        st.pop();
    }

    for(int i=1;i<=v;i++){
        if(scc[i].size()){
            sort(scc[i].begin(),scc[i].end());
            sccList.push_back(scc[i]);
        }
    }
    sort(sccList.begin(),sccList.end(),comp);
    printf("%d\n",sccList.size());
    for(int i=0;i<sccList.size();i++){
        printVector(sccList[i]);
    }
    
    return 0;
}