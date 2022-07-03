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
using namespace std;

int n,m;

bool bad[201][201];

int main()
{
    scanf("%d %d",&n,&m);
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        bad[x][y] = true;
        bad[y][x] = true;
    }
    int ret = 0;
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(bad[i][j]) continue;
            for(int k=j+1;k<=n;k++){
                if(bad[i][k]) continue;
                if(bad[j][k]) continue;
                ret++;
            }
        }
    }
    printf("%d",ret);
    return 0;
}