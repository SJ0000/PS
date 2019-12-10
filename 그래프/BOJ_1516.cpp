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

const int MAXN = 500;
vector<int> v[MAXN+1];
int cost[MAXN+1];
int ret[MAXN+1];
int inDegree[MAXN+1];
queue<int> q;

//from -> to 일 때
// ret[to] = max(ret[to],ret[from]+cost[to]); 이다
// 걸리는 시간은 이전에 지어지는 건물들 중 최대 시간에 의존적임

int main()
{
    int n,m,req;
    req = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", &cost[i]);
        while(true){
            scanf("%d",&req);
            if(req==-1) break;
            inDegree[i]++;
            v[req].push_back(i);
        }
        if(inDegree[i]==0){
            ret[i] = cost[i];
            q.push(i);
        }
    }
    
    //위상정렬
    /*
    1) indegree가 0인 정점을 모두 Queue에 넣는다.
    2) 정점의 개수만큼
      -> Queue의 Front원소를 빼서 그 정점에서 나가는 간선을 모두 삭제.
      -> 이때 삭제하면서 indegree가 0이 된 새로운 정점이 생기면, 그것들도 큐에 넣음.
      위 행동을 반복
    3) 이 때 Queue에서 빼는 정점 순서가 위상정렬 결과임.
    */
    for(int i=1;i<=n;i++){
        int from = q.front();
        q.pop();
        int sz = v[from].size();
        for(int idx = 0;idx<sz;idx++){
            int to = v[from][idx];
            ret[to] = max(ret[to],ret[from]+cost[to]);
            inDegree[to]--;
            if(inDegree[to]==0){
                q.push(to);
            }
        }        
    }

    for(int i=1;i<=n;i++){
        printf("%d\n",ret[i]);
    }
    return 0;
}