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

int d[50001];

int go(int x){
    if(x==0) return 0;
    if(d[x]>0) return d[x];
    int y = (int) sqrt((double)x);
    int ret = 987654321;
    for(int i=y;i>=1;i--){
        ret = min(ret,1+go(x-i*i));
    }
    d[x] = ret;
    return d[x];
}

int main()
{
    for(int i=1;i<=223;i++){
        d[i*i] = 1;
    }
    int x;
    scanf("%d",&x);
    printf("%d",go(x));
    return 0;
}