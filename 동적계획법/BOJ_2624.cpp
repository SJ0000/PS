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

int t,k;

typedef long long ll;
int p[101]; // price
int a[101]; // amount
ll d[10001][101]; // d[i][j] = j번째까지 동전으로 i원 만드는 경우의 수

ll go(int price,int now){
    if(price<0 || now<0) return 0;
    ll &ret = d[price][now];    
    if(ret!=-1) return ret;
    ret = 0;
    //현재 있는 동전 갯수만큼 반복
    for(int j=0;j<now;j++){
        for(int i=1;i<=a[now];i++){
            if(price-p[now]*i<0) break;
            ret += go(price-p[now]*i,j);
        }
    }
    // printf("%d,%d : %d\n",price,now,ret);
    return ret;
}

int main()
{
    memset(d,-1,sizeof(d));
    memset(p,0,sizeof(p));
    memset(a,0,sizeof(a));
    scanf("%d %d",&t,&k);
    for(int i=0;i<k;i++){
        scanf("%d %d",&p[i],&a[i]);
    }
    
    //0번째
    for(int i=0;i<=a[0];i++){
        if(p[0]*i<=t) d[p[0]*i][0] = 1;
    }
    ll ans = 0;
    for(int i=0;i<k;i++){
        ans += go(t,i); //모든 t원 만드는 경우
    }
    printf("%lld",ans);
    return 0;
}