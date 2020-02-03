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

int n,m,k;
const int MAXN = 1001;
string a[MAXN];
int d[MAXN][MAXN][11];
int check[MAXN][MAXN][11]; // x,y,breakCount
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
//0,0 ~ n-1,m-1 까지
int bfs(){
    memset(d,0,sizeof(d));
    memset(check,0,sizeof(check));
    queue<pair<pii,int>> q; // x,y,breakCount
    q.push(make_pair(make_pair(0,0),k));
    check[0][0][k] = true;
    pair<pii,int> now;
    int nowx,nowy,nextx,nexty,breakCount;
    int qs;
    int len=0;
    while(!q.empty()){
        //부실 수 있는 벽은 부시면서 진행
        qs = q.size();
        len++;
        for(int i=0;i<qs;i++){
            now = q.front();
            nowx = q.front().first.first;
            nowy = q.front().first.second;
            breakCount = q.front().second;
            q.pop();
            d[nowx][nowy][breakCount] = len;
            //printf("now = (%d,%d) breakCount : %d, len : %d \n",nowx,nowy,breakCount,len);
            //문제점 : 똑같은 점에 도착했는데 breakCount개수가 다를수도잇음
            // 도착점 앞에 무조건 1번 부셔야되는데, 중간에서 breakCount가 0인데 check하면 안됨

            for(int j=0;j<4;j++){
                nextx = nowx+dx[j];
                nexty = nowy+dy[j];
                if(0<=nextx && nextx<n && 0<=nexty && nexty < m){
                    if(a[nextx][nexty]=='0'){
                        if(!check[nextx][nexty][breakCount]){
                            check[nextx][nexty][breakCount] = true;
                            q.push(make_pair(make_pair(nextx,nexty),breakCount));
                        }                        
                    }
                    //부실 수 있는 경우
                    if(a[nextx][nexty]=='1' && breakCount>=1){
                        if(!check[nextx][nexty][breakCount-1]){
                            check[nextx][nexty][breakCount-1] = true;
                            q.push(make_pair(make_pair(nextx,nexty),breakCount-1));
                        }
                    }
                }
            }
        }
    }
    int ret = 987654321;
    for(int i=0;i<11;i++){
        if(d[n-1][m-1][i]>0){
            ret = min(ret,d[n-1][m-1][i]);
        }
    }
    if(ret!=987654321){
        return ret;
    }else{
        return -1;
    }
}
int main()
{   
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    printf("%d",bfs());
    return 0;
}