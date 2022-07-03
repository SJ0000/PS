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
#include <set>
using namespace std;

int d[101][101][2];
//x,y개 남은 상태에서 turn 차례
int go(int x, int y, int turn){

    if(x<y) return go(y,x,turn);

    // printf("%d %d %d\n",x,y,turn);
    
    int &ret = d[x][y][turn];
    int next = (turn+1)%2;

    if(ret!=-1) return ret;

    if(x==1 && y==1){
        ret = next;
        return ret;
    }
    //x를 비우는 경우
    for(int i=1;i<y;i++){
        if(ret==-1) ret = next;
        if(turn==0){
            ret = min(ret,go(i,y-i,1));
        }else{
            ret = max(ret,go(i,y-i,0));
        }
    }
    //y를 비우는 경우
    for(int i=1;i<x;i++){
        if(ret==-1) ret = next;
        if(turn==0){
            ret = min(ret,go(i,x-i,1));
        }else{
            ret = max(ret,go(i,x-i,0));
        }
    }
    return ret;
}

int main()
{
    memset(d,-1,sizeof(d));
    int a,b;
    scanf("%d %d",&a,&b);
    if(go(a,b,0)==0){
        printf("A");
    }else{
        printf("B");
    }
    return 0;
}