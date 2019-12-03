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

vector<int> v[1001];
bool check[1001];
bool finished[1001];
stack<int> ret;

//역방향 간선을 찾는 법 : Visited되었지만 아직 끝나지 않은 정점을 dfs호출 중 보게 된다면
//이는 역방향간선이다.

void dfs(int now){
    if(check[now] && !finished[now]){
        check[0] = true; // check[0]을 사이클 유무로 사용
        return;
    }
    if(check[now]) return;
    check[now] = true;
    for(int i=0;i<v[now].size();i++){
        dfs(v[now][i]);
    }
    finished[now] = true;
    ret.push(now);
}

int main()
{
    int n,m,t,st,ed;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        for(int j=0;j<t;j++){
            if(j==0){
                scanf("%d",&st);
            }else{
                scanf("%d",&ed);
                v[st].push_back(ed);
                st = ed;
            }
        }
    }
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    if(check[0]){
        printf("0\n");
    }else{
        int x;
        while(!ret.empty()){
            x = ret.top();
            printf("%d\n",x);
            ret.pop();
        }
    }
    return 0;
}