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

int c,n;
int cost[101]; // i를 지불했을 때 얻을 수 있는 고객수.
int d[1101]; // i명을 얻기 위한 최소비용
int main()
{
    scanf("%d %d",&c,&n);
    memset(cost,-1,sizeof(cost));
    int a,b;
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        cost[a] = max(cost[a],b);
    }
    d[0] = 0;
    for(int i=1;i<1101;i++){
        d[i] = 987654321;
        for(int j=0;j<101;j++){
            if(cost[j]==-1) continue;            
            if(i-cost[j]<0) continue;
            d[i] = min(d[i],d[i-cost[j]]+j);
        }
    }
    //최소 c명
    int ret = 987654321;
    for(int i=c;i<1101;i++){
        ret = min(ret,d[i]);
    }
    printf("%d",ret);

    return 0;
}