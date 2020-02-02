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
// o양 v늑대

int r,c;
string a[251];
bool check[251][251];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int totalO,totalV;

void bfs(int x, int y){
    queue<pii> q;
    q.push(make_pair(x,y));
    int nowO = 0;
    int nowV = 0;
    int nowx,nowy,nextx,nexty;
    while(!q.empty()){
        nowx = q.front().first;
        nowy = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            nextx = nowx+dx[i];
            nexty = nowy+dy[i];
            if(0<=nextx && nextx <r && 0<=nexty && nexty <c){
                if(!check[nextx][nexty]){
                    check[nextx][nexty] = true;
                    if(a[nextx][nexty]=='o') nowO++;
                    if(a[nextx][nexty]=='v') nowV++;
                    q.push(make_pair(nextx,nexty));
                }
            }
        }
    }
    if(nowO<=nowV){
        nowO = 0;
    }else{
        nowV = 0;
    }
    totalO += nowO;
    totalV += nowV;
}

int main()
{
    scanf("%d %d",&r,&c);
    memset(check,0,sizeof(check));
    for(int i=0;i<r;i++){
        cin >> a[i];
        for(int j=0;j<c;j++){
            if(a[i][j]=='#'){
                check[i][j] = true;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(check[i][j]){
                bfs(i,j);
            }
        }
    }
    
    printf("%d %d",totalO, totalV);

    return 0;
}