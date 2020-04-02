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
int d[1001][1001]; // d[i][j] = i,j를 맨 오른쪽 아래칸으로 하는 정사각형의 길이
int a[1001][1001];
int calc(int n, int m){
    int ret = 0;
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(d));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            d[i][j] = a[i][j];
            ret = max(ret,d[i][j]);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]==0) continue;
            d[i][j] = min(d[i-1][j-1],min(d[i-1][j],d[i][j-1]))+1;
            ret = max(ret,d[i][j]);
        }
    }
    return ret;
}


int main()
{
    int a,b;
    while(true){
        scanf("%d %d",&a,&b);
        if(a==0 && b==0) break;
        printf("%d\n",calc(a,b));
    }
    return 0;
}