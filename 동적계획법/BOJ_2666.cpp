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

int n,t,o1,o2;
int d[22][22][22]; // d[x][i][j] : x번째에서 상태 i,j일때 비용
int a[22];

int go(int x,int i,int j){
    // i가 작고,j가 큰걸로 통일
    if(i>j) return go(x,j,i);
    int &ret = d[x][i][j];
    if(ret!=-1) return ret;
    //printf("%d %d %d called\n",x,i,j);
    //edge node
    if(x==t){
        return 0;
    }
    ret = min(go(x+1,a[x+1],i)+abs(a[x+1]-j),go(x+1,a[x+1],j)+abs(a[x+1]-i));
    //printf("%d,%d,%d : %d\n",x,i,j,ret);
    return ret;
}

int main()
{
    memset(d,-1,sizeof(d));
    scanf("%d %d %d",&n,&o1,&o2);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&a[i]);
    }
    int ans = go(0,o1,o2);
    printf("%d",ans);

    return 0;
}