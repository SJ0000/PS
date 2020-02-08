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
//check -> spread -> check -> spread ...
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int r,c;
string a[1501];
int check[1501][1501]; // 1,2로 백조 방문 구분
bool nextCheck[1501][1501];
queue<pii> q;
queue<pii> sq[3]; // sq[0]은 다음번 step에 동작 할 값을 저장하는 임시 queue임
vector<pii> sted; // start end
bool getAnswer = false;

void spreadWater(){
    int x,y,ax,ay;
    int qs = q.size();
    //spread() 실행 시점에 queue에 들어있던 좌표들만 퍼지게 한다
    while(qs--){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            ax = x+dx[i];
            ay = y+dy[i];
            if(0<=ax && ax < r && 0<= ay && ay< c){
                if(a[ax][ay]=='X'){
                    a[ax][ay] = '.';
                    q.push(make_pair(ax,ay));
                }
            }
        }
    }    
}

void spreadSwan(int idx){
    //퍼지는걸 끝까지 퍼지게 해아함.
    int x,y,ax,ay;
    int qs = sq[idx].size();
    while(!sq[idx].empty()){
        x = sq[idx].front().first;
        y = sq[idx].front().second;
        sq[idx].pop();
        for(int i=0;i<4;i++){
            ax = x+dx[i];
            ay = y+dy[i];
            if(0<= ax && ax < r && 0<= ay && ay < c){
                if(a[ax][ay]=='X'){
                    if(!nextCheck[ax][ay]){
                        nextCheck[ax][ay] = true;
                        sq[0].push(make_pair(ax,ay));
                    }
                    continue;
                }
                if(check[ax][ay]==0){
                    check[ax][ay] = idx;
                    sq[idx].push(make_pair(ax,ay));
                }else if(check[ax][ay]!=idx){
                    getAnswer = true;
                    return;
                }
            }
        }
    }
    while(!sq[0].empty()){
        sq[idx].push(sq[0].front());
        sq[0].pop();
    }
}
void dfs(int x,int y,int idx){
    check[x][y] = idx;
    sq[idx].push(make_pair(x,y));
    int ax,ay;
    for(int i=0;i<4;i++){
        ax = x+dx[i];
        ay = y+dy[i];
        if(0<= ax && ax < r && 0<= ay && ay < c){
            if(check[ax][ay]==0 && a[ax][ay]=='.'){
                dfs(ax,ay,idx);
            }
            if(check[ax][ay]!=0 && check[ax][ay]!=idx){
                getAnswer = true;
                return;
            }
        }
    }
}

int main()
{   
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        cin >> a[i];
        for(int j=0;j<c;j++){
            if(a[i][j]=='.'){
                q.push(make_pair(i,j));
            }
            if(a[i][j]=='L'){
                q.push(make_pair(i,j));
                sted.push_back(make_pair(i,j));
                a[i][j] = '.'; // 다른거 구현할때 복잡해져서
            }
        }
    }
    memset(check,0,sizeof(check));
    memset(nextCheck,0,sizeof(nextCheck));
    dfs(sted[0].first,sted[0].second,1);
    dfs(sted[1].first,sted[1].second,2);

    int day = 0;
    
    while(true){
        if(getAnswer){
            printf("%d",day);
            break;
        }
        spreadWater();
        spreadSwan(1);
        spreadSwan(2);
        day++;        
    }
    return 0;
}