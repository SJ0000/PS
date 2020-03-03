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

typedef unsigned long long ull;
ull d[1000001]; // 높이 i인 탑을 1까지 쪼갰을 때 얻을 수 있는 최대 즐거움

ull go(int x){
    if(x<=1) return 0;
    ull l = x/2;
    ull r = x/2+x%2;
    if(x>1000000){
        return l*r + go(l)+go(r);
    }
    if(d[x]!=0) return d[x];
    d[x] = l*r + go(l) + go(r);
    return d[x];
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(d,0,sizeof(d));
    cout << go(n);
    return 0;
}