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

ll d[11][2001]; //i번째에 j를 고른 경우의 수

void calc(){
    memset(d,0,sizeof(d));
    //첫번재
    for(int i=1;i<=2000;i++){
         d[0][i] = 1;
    }
    //2~10번째
    for(int i=1;i<10;i++){
        for(int now=1;now<=2000;now++){
            //before는 1~now/2 까지이다.
            for(int before=1; before<=now/2;before++){
                d[i][now] += d[i-1][before];
            }
        }
    }
}
ll getAns(int n,int m){
    ll ret = 0;  
    for(int i=1;i<=m;i++){
        ret += d[n-1][i];
    } 
    return ret;
}

int main()
{
    int TC;
    scanf("%d",&TC);
    int n,m;
    calc();
    while(TC--){
        scanf("%d %d",&n,&m);
        printf("%lld\n",getAns(n,m));
    }    
    
    return 0;
}