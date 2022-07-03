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
ll d[65][10]; //d[i][j] : i자리에 맨오른쪽자리가j인 줄어들지 않는 수
ll ans[65];
int main()
{
    memset(d,0,sizeof(d));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<10;i++){
        d[1][i] = 1;
    }
    ans[1] = 10;
    for(int i=2;i<64;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=j;k++){
                d[i][j] += d[i-1][k];
            }
            ans[i] += d[i][j];
        }
    }
    int TC;
    scanf("%d",&TC);
    int n;
    while(TC--){
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}