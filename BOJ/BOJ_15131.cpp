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

//정확히 n의 파워로 만들 수 있는 최대 숫자
//p[i] = 숫자i를 만들때 드는 힘
int d[1000001];

int go(int x){
    if(x<0) return 0;
    int &ret = d[x];
    if(ret!=-1) return ret;
    
    for(int i=2;i<=4;i++){
        ret = max(ret,d[i]+go(x-i));
    }
    return ret;    
}


int main()
{
    memset(d,-1,sizeof(d));
    d[0] = d[1] = 0;
    d[2] = 1; d[3] = 7; d[4] = 4;
    int n;
    scanf("%d",&n);
    printf("%d",go(n));
    return 0;
}