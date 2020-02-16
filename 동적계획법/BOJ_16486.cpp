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

const int MAXN = 1500001;

int dp[MAXN][2];
int t[MAXN];
int p[MAXN];
int n;

int dfs(int now,int ok){
    if(now>=n) return 0;
    if(dp[now][ok]!=-1) return dp[now][ok];
    if(ok==0){
        dp[now][ok] = max(dfs(now+1,0),dfs(now+1,1));
        return dp[now][ok];
    }else{
        //i골랐는데 너무 길어서 상담을 못하는 경우
        if(now+t[now]>n){
            return 0;
        }else{
            dp[now][ok] = p[now]+max(dfs(now+t[now],0),dfs(now+t[now],1));
            return dp[now][ok];
        }
    }
}

int main()
{
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        t[i] = x;
        p[i] = y;
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    dfs(0,0);
    dfs(0,1);
    printf("%d",max(dp[0][0],dp[0][1]));
    return 0;
}