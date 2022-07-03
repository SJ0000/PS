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

const int MAXN = 501;

bool g[MAXN][MAXN];
int last[MAXN];
int indegree[MAXN];
queue<int> q;
vector<int> ret;
vector<pair<int,int>> swaps;
bool isImpossible;
void init(){
    memset(g,0,sizeof(g));
    memset(last,0,sizeof(last));
    memset(indegree,0,sizeof(indegree));
    ret.clear();
    while(!q.empty()){
        q.pop();
    }
    isImpossible = false;
}
int main()
{
    int TC;
    scanf("%d",&TC);
    int n,m,a,b,now;
    while(TC--){
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&last[i]);
        }
        scanf("%d",&m);
        for(int i=1;i<=n;i++){
            a = last[i];
            for(int j=i+1;j<=n;j++){
                b = last[j];
                g[a][b] = true;
                indegree[b]++;
            }
        }
        while(m--){
            //역방향 간선으로 변경            
            scanf("%d %d",&a,&b);
            if(g[a][b]==true){
                g[b][a] = true;
                g[a][b] = false;
                indegree[a]++;
                indegree[b]--;
            }else{
                g[a][b] = true;
                g[b][a] = false;
                indegree[b]++;
                indegree[a]--;
            }
        }
        //위상정렬
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(q.empty()){
                printf("IMPOSSIBLE\n");
                break;
            }else if(q.size()>1){
                printf("?\n");
                break;
            }
            now = q.front();
            q.pop();
            ret.push_back(now);
            //간선 삭제
            for(int next=1;next<=n;next++){
                if(g[now][next]){
                    g[now][next] = false;
                    if(--indegree[next]==0){
                        q.push(next);
                    }
                }
            }            
        }
        if(ret.size()==n){
            for(int i=0;i<n;i++){
                printf("%d ",ret[i]);
            }
            printf("\n");
        }
    }
    return 0;
}