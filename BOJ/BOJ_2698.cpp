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

// d[n][k][0 or 1] : n개자리, 인접한 비트 개수 k이고 [0 or 1]로 끝나는 갯수
ll d[101][101][2];
int n,k;

void calc(){
    memset(d,0,sizeof(d));
    //0,1
    d[1][0][0] = 1;
    d[1][0][1] = 1;
    for(int i=2;i<=100;i++){
        for(int j=0;j<=i-1;j++){
            d[i][j][0] += d[i-1][j][0]+d[i-1][j][1];
            d[i][j][1] += d[i-1][j][0]+d[i-1][j-1][1];
        }
    }
}

int main()
{
    calc();
    int TC;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d %d",&n,&k);
        printf("%lld\n",d[n][k][0]+d[n][k][1]);
    }  
    
    return 0;
}