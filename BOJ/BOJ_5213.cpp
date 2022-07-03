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

typedef pair<int,int> pii;

const int MAXN = 250000;
pii a[MAXN]; // i번째 타일조각의 값 ( <left,right> )
vector<int> g[MAXN]; // graph
int l[MAXN]; //1에서 i까지 최단거리, 없으면 0
bool check[MAXN];
int n;
//x의 오른쪽조각이랑 y의 왼쪽조각이 연결되었는지 확인
void connect(int x, int y){
    if(a[x].second==a[y].first){
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
//1->i로 최단거리 계산
void bfs(){
    memset(check,0,sizeof(check));
    memset(l,0,sizeof(l));
    check[1] = true;
    l[1] = 1;
    queue<int> q;
    q.push(1);
    int now,next,maxj,sz;
    while(!q.empty()){
        sz = q.size();
        for(int i=0;i<sz;i++){
            now = q.front();
            q.pop();
            maxj = g[now].size();
            for(int j=0;j<maxj;j++){
                next = g[now][j];
                if(!check[next]){
                    check[next] = true;
                    q.push(next);
                    l[next] = l[now]+1;
                }
            }
        }
    }
}
//x->1로 가는 길 계산
void go(int x){
    deque<int> ret;
    ret.push_front(x);
    int nowLen = l[x];
    int now,next;
    now = x;
    int sz;
    while(now!=1){
        sz = g[now].size();
        for(int j=0;j<sz;j++){
            next = g[now][j];
            if(l[next]==nowLen-1){
                ret.push_front(next);
                now = next;
                nowLen--;
                break;
            }
        }
    }
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();i++){
        printf("%d ",ret[i]);
    }
}
// 1 -> X로 가는 최단거리
int main()
{
    scanf("%d",&n);
    int now = 0;
    int maxj;
    int x,y;
    for(int i=0;i<n;i++){
        if(i%2==0){
            maxj = n;
        }else{
            maxj = n-1;
        }
        for(int j=0;j<maxj;j++){
            now++;
            scanf("%d %d",&x,&y);
            a[now] = make_pair(x,y);
            //graph 만들기
            // 1) 자기 바로 앞에꺼랑 연결여부 확인(j!=0일때)
            if(j!=0){
                connect(now-1,now);
            }
            // 2) 자기 위에 2개랑 연결 여부 확인(now-n이랑 now-n+1)
            if(i!=0){
                //i가 홀수줄일경우 위에꺼 2개 다 연결확인
                if(i%2==1){
                    connect(now-n,now);
                    connect(now,now-n+1);
                }else{
                    if(j==0){
                        //위에서 오른쪽꺼만 확인
                        connect(now,now-n+1);
                    }else if(j==maxj-1){
                        //위에서 왼쪽꺼랑만 확인
                        connect(now-n,now);
                    }else{
                        connect(now-n,now);
                        connect(now,now-n+1);
                    }
                }
            }
        }
    }
    // 1에서 출발하는 모든 경로의 최단거리 구하기
    bfs();
    // 정답 구하기
    for(int i=n*n-1;i>=1;i--){
        if(l[i]){
            go(i);
            break;
        }
    }
    return 0;
}