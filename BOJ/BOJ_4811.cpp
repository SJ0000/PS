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

ll dp[31][31];

ll dfs(int w,int h){
    if(w<0 || h<0) return 0;
    //이미 구한 경우
    if(dp[w][h]!=0){
        return dp[w][h];
    }
    //한조각 다뽑은경우, 뒤에는 H밖에 못옴
    if(w==0){
        dp[w][h] = 1;
        return dp[w][h];
    }
    //한조각밖에 없는 경우
    if(w==h){
        dp[w][h] = dfs(w-1,h);
        return dp[w][h];
    }
    dp[w][h] = dfs(w-1,h)+dfs(w,h-1);
    return dp[w][h];
}
int main()
{
    memset(dp,0,sizeof(dp));
    dfs(30,30);
    int x;
    while(true){
        scanf("%d",&x);
        if(x==0) break;
        printf("%lld\n",dp[x][x]);
    }    
    return 0;
}