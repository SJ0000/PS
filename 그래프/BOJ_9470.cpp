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

/*
 strahler 순서
 1) Indegree가 0인 node는 순서가 1
 2) 나머지는 해당 node로 들어오는 순서 중 가장 큰 값이 i일 때
    들어오는 모든 node의 순서가 i인 강이 1개이면, i, 2개 이상이면 i+1
*/

//TODO 1211 : 처리부분 다시짜기

int T,TC;
int k,m,p;
queue<int> Q;
vector<int> v[1001];
int indegree[1001];
pair<int,int> s[1001]; // <inner MAX, MAX's count >

void init(){
    TC++;
    while(!Q.empty()){
        Q.pop();
    }
    for(int i=0;i<1001;i++){
        v[i].clear();
        indegree[i] = 0;
        s[i] = make_pair(0,0);
    }
}

int main()
{
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d %d %d",&k,&m,&p);
        int a,b;
        for(int i=0;i<p;i++){
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            indegree[b]++;
        }
        for(int i=1;i<=m;i++){
            if(indegree[i]==0){
                Q.push(i);
             s[i] = make_pair(1,1);
            }
        }
        //위상정렬
        int now,next,sz;
        for(int i=1;i<=m;i++){
            now = Q.front();
            Q.pop();
            if(s[now].second>=2) s[now].first++;
            sz = v[now].size();
            for(int idx=0;idx<sz;idx++){
                next = v[now][idx];
                //처리
                if(s[now].first > s[next].first){
                    s[next] = make_pair(s[now].first,1);
                }else if(s[now].first==s[next].first){
                    s[next].second++;
                }
                if(--indegree[next]==0){
                    Q.push(next);
                }
            }
        }
        printf("%d %d\n",TC,s[m].first);
    }
    return 0;
}