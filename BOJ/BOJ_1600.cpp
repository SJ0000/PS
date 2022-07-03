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
//말 무빙
int hx[8] = {-1,-2,-2,-1,1,2, 2, 1};
int hy[8] = {-2,-1, 1, 2,2,1,-1,-2};
//기본 무빙
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool check[201][201][31];
int d[201][201][31];
int a[201][201];
int w,h,k;

// 0,0 -> h-1,w-1
void init(){
    memset(check,0,sizeof(check));
    memset(d,0,sizeof(d));
}

int bfs(){
    init();
    queue<pair<pii,int>> q;
    q.push(make_pair(make_pair(0,0),k));
    check[0][0][k] = true;
    int nowx,nowy,nextx,nexty,nowk,qs;
    int moveCount = 0;
    while(!q.empty()){
        qs = q.size();
        moveCount++;
        for(int t=0;t<qs;t++){
            nowx = q.front().first.first;
            nowy = q.front().first.second;
            nowk = q.front().second;
            q.pop();

            printf("now : (%d,%d) k : %d\n",nowx,nowy,nowk);

            //말 무빙
            if(nowk>0){
                for(int i=0;i<8;i++){
                    nextx = nowx+hx[i];
                    nexty = nowy+hy[i];
                    if(0<=nextx && nextx < h && 0<= nexty && nexty <w){
                        if(a[nextx][nexty]==0 && !check[nextx][nexty][nowk-1]){
                            check[nextx][nexty][nowk-1] = true;
                            q.push(make_pair(make_pair(nextx,nexty),nowk-1));
                            d[nextx][nexty][nowk-1] = moveCount;
                        }
                    }                
                }
            }
            //기본 무빙
            for(int i=0;i<4;i++){
                nextx = nowx+dx[i];
                nexty = nowy+dy[i];
                if(0<=nextx && nextx < h && 0<= nexty && nexty < w){
                    if(a[nextx][nexty]==0 && !check[nextx][nexty][nowk]){
                        check[nextx][nexty][nowk]=true;
                        q.push(make_pair(make_pair(nextx,nexty),nowk));
                        d[nextx][nexty][nowk] = moveCount;
                    }
                }
            }
        }
    }
    int ret = 987654321;
    for(int i=0;i<31;i++){
        if(d[h-1][w-1][i]>0){
            ret = min(ret,d[h-1][w-1][i]);
        }
    }
    if(ret==987654321){
        return -1;
    }
    return ret;
}

int main()
{   
    //d[x][y][k] : x,y를 말카운트x번 남은 상태로 이동한 경우
    //어제푼거랑 비슷할듯
    scanf("%d %d %d",&k,&w,&h);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d",bfs());
    

    return 0;
}