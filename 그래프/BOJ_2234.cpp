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

//방의 정보 : 0~15 : 이진수 bit 0,1,2,3 : 서북동남
//dx,dy도 서북동남으로 맞춰주면 편할거같음
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int a[51][51];
pair<int,int> d[51][51]; // <roomIndex,roomSize>
int check[51][51];
int n,m;

bool possible(int info, int move){
    return (info & (1<<move)) == 0;
}

//x,y가 속한 방의 넓이를 반환
int bfs(int x,int y,int roomIndex){
    //d[i][j] = i,j가 속한 방의 크기
    vector<pair<int,int>> group;
    queue<pair<int,int>> q;
    //TODO
    q.push(make_pair(x,y));
    group.push_back(make_pair(x,y));
    check[x][y] = true;
    int nowx,nowy,nextx,nexty;
    //printf("**** Start ****\n");
    while(!q.empty()){
        nowx = q.front().first;
        nowy = q.front().second;
        q.pop();
        //printf("now : (%d,%d)\n",nowx,nowy);
        for(int i=0;i<4;i++){
            if(possible(a[nowx][nowy],i)){
                //printf("Open %d,%d's %d Position\n",nowx,nowy,i);
                nextx = nowx+dx[i];
                nexty = nowy+dy[i];
                if(!(0<=nextx && nextx < m && 0<= nexty && nexty <n)) continue;
                if(!check[nextx][nexty]){
                    check[nextx][nexty]=true;
                    q.push(make_pair(nextx,nexty));
                    group.push_back(make_pair(nextx,nexty));
                }
            }
        }
    }
    int sz = group.size();
    for(int i=0;i<sz;i++){
        nowx = group[i].first;
        nowy = group[i].second;
        d[nowx][nowy] = make_pair(roomIndex,sz);
    }

    return d[x][y].second;
}

int main()
{   
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    memset(check,0,sizeof(check));
    //1이랑 2는 bfs or dfs 한번으로 구할 수 있음.
    int ans1,ans2,ans3;
    ans1 = ans2 = ans3 = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!check[i][j]){
                // printf("%d,%d / ans1 : %d \n",i,j,ans1);
                ans1++;
                ans2 = max(ans2,bfs(i,j,ans1));
            }
        }
    }

    //TODO
    //3은 각 방의 인덱스랑 크기를 따로 저장해놓고
    /*
    ex) pair<int,int> <인덱스,방 크키>
    1,3 1,3 1,3 2,7 2,7
    2,7 2,7 2,7 2,7 2,7
    과같이 해놓고 한칸당 벽 1개씩 뿌시면서 최대값 찾기. 
    */
    
    //가로벽 부셔보고 세로벽 부셔보면 됨
    //가로벽
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            if(d[i][j].first!=d[i][j+1].first){
                ans3 = max(ans3,d[i][j].second+d[i][j+1].second);
            }
        }
    }
    //세로벽
    // 0,0 1,0 2,0 3,0 m-2,0
    // ... 0,0
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(d[j][i].first!=d[j+1][i].first){
                ans3 = max(ans3,d[j][i].second+d[j+1][i].second);
            }
        }
    }
    printf("%d\n%d\n%d",ans1,ans2,ans3);
    
    return 0;
}