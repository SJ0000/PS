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
const ll MOD = 1000000009;
ll d[100001][4];

int main()
{
    memset(d,0,sizeof(d));
    d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;
    
    for(int i=4;i<=100000;i++){
        d[i][1] = (d[i-1][2]%MOD+d[i-1][3]%MOD)%MOD;
        d[i][2] = (d[i-2][1]%MOD+d[i-2][3]%MOD)%MOD;
        d[i][3] = (d[i-3][1]%MOD+d[i-3][2]%MOD)%MOD;
    }
    int n,x;
    ll ret;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        ret = (d[x][1]%MOD+d[x][2]%MOD+d[x][3]%MOD)%MOD;
        printf("%lld\n",ret);
    }
    return 0;
}