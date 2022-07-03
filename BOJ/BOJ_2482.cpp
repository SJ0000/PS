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

typedef long long ll;

int n,k;
ll d[1001][1001][2];
const ll MOD = 1000000003;
//d[i][j] = i가 j번째로 선택된 경우의 수
ll go(int now,int count, int isLastSelected){
    ll ret = 0;
    if(d[now][count][isLastSelected]!=-1){
        // printf("CALLED %d %d : %lld \n",now,count,d[now][count]);
        return d[now][count][isLastSelected];
    }
    if(now==0 && isLastSelected) return 0;    
    //now가 선택된 경우, now-1 은 선택할 수 없음
    int st;
    isLastSelected ? st = 1 : st = 0;
    for(int i=st;i<=now-2;i++){
        ret += go(i,count-1,isLastSelected);
        // printf("ret : %lld\n",ret);
        ret %= MOD;
    }
    d[now][count][isLastSelected] = ret;
    // printf("case %d : %d %d = %lld\n",isLastSelected,now,count,ret);
    return ret;
}

int main()
{
    scanf("%d %d",&n,&k);
    memset(d,-1,sizeof(d));
    for(int i=0;i<1000;i++){
        d[i][0][0] = 0;
        d[i][0][1] = 0;
        d[i][1][0] = 1;
        d[i][1][1] = 1;
    }
    ll ans = 0;
    for(int i=0;i<n-1;i++){
        ans += go(i,k,false);
        ans%=MOD;
    }
    ans += go(n-1,k,true);
    ans%=MOD;
    printf("%lld",ans);
    return 0;
}