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

int n,m;
string a[11];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

//red를 빼내야함.
int solve(int r, int b){
    queue<pair<pii,int>> q;
    q.push(make_pair(make_pair(r,b),0));
    //1이 red, 2가 blue
    int x1,y1,x2,y2,ax1,ay1,ax2,ay2,times;
    pii now;
    int ret = -1;
    //red,blue가 특정지점에 이미 도달한 경우를 check;
    bool check[100][100];
    memset(check,0,sizeof(check));
    bool getAnswer = false;
    bool reverse;
    while(!q.empty()){
        now = q.front().first;
        x1 = now.first/10; y1 = now.first%10;
        x2 = now.second/10; y2 = now.second%10;
        times = q.front().second;
        q.pop();
        check[now.first][now.second] = true;
        // printf("now red : (%d,%d) blue : (%d,%d)\n",x1,y1,x2,y2);
        //move
        for(int i=0;i<4;i++){
            reverse = false;
            ax1 = x1; ay1 = y1; ax2 = x2; ay2 = y2;
            //한칸 가는게 아니라 쭉 미는거임
            //뭐부터 밀지 결정 , default = red->blue 이고
            //꼭 blue -> red여야 하는 경우만 분리
            if(x1==x2){
              if((i==0 && y1<y2) || (i==1 && y2<y1)){
                  reverse = true;
              }
            }else if(y1==y2){
                if((i==2 && x1<x2)||(i==3 && x2<x1)){
                    reverse = true;
                }
            }
            //밀기
            if(!reverse){
                while(a[ax1][ay1]=='.'){
                    ax1+=dx[i];
                    ay1+=dy[i];
                }
                if(a[ax1][ay1]=='#'){
                    ax1-=dx[i];
                    ay1-=dy[i];                    
                }
                while(a[ax2][ay2]=='.' && !(ax1==ax2 && ay1==ay2)){
                    ax2+=dx[i];
                    ay2+=dy[i];
                }
                if(a[ax2][ay2]=='#' || (ax1==ax2 && ay1==ay2)){
                    ax2-=dx[i];
                    ay2-=dy[i];
                }
            }else{
                while(a[ax2][ay2]=='.'){
                    ax2+=dx[i];
                    ay2+=dy[i];
                }
                if(a[ax2][ay2]=='#'){
                    ax2-=dx[i];
                    ay2-=dy[i];
                }
                while(a[ax1][ay1]=='.' && !(ax1==ax2 && ay1==ay2)){
                    ax1+=dx[i];
                    ay1+=dy[i];
                }
                if(a[ax1][ay1]=='#' || (ax1==ax2 && ay1==ay2)){
                    ax1-=dx[i];
                    ay1-=dy[i];                    
                }
            }
            // printf("    move red : (%d,%d) blue : (%d,%d) \n",ax1,ay1,ax2,ay2);

            //가장자리는 항상 벽이기때문에 배열의 범위를 넘어가지 않는 것은 보장이 된다.

            // 1) red만 구멍에 들어간 경우
            if(a[ax1][ay1]=='O' && a[ax2][ay2]!='O'){
                ret = times+1;
                getAnswer = true;
                break;
            }
            // 2) blue가 구멍에 들어갔을 때
            if(a[ax2][ay2]=='O') continue;
            // 다음 칸 queue 삽입
            if(!check[ax1*10+ay1][ax2*10+ay2]){
                // printf("**Push** %d,%d  %d,%d \n",ax1,ay1,ax2,ay2);
                q.push(make_pair(make_pair(ax1*10+ay1,ax2*10+ay2),times+1));
            }
        }
        if(getAnswer) break;
    }
    return ret;
}


int main()
{
    scanf("%d %d",&n,&m);
    int red,blue;
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;j<m;j++){
            if(a[i][j]=='R'){
                red = i*10+j;
                a[i][j] = '.';
            }
            if(a[i][j]=='B'){
                blue = i*10+j;
                a[i][j] = '.';
            }           
        }
    }
    printf("%d",solve(red,blue));
    return 0;
}