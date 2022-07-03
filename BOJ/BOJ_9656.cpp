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

int d[1001][2];//d[i][j] : 돌 i개 남았을때 j차례일때 이기는 사람 
// 0이면 SK 1은 CY

int main()
{
    int n;
    scanf("%d",&n);
    memset(d,0,sizeof(d));
    d[0][1] = 1;
    d[1][0] = 1;
    d[2][1] = 1;

    for(int i=3;i<=n;i++){
        //1개먹었을때랑 3개먹었을때 중 이기는거 고름
        d[i][0] = min(d[i-1][1],d[i-3][1]);
        d[i][1] = max(d[i-1][0],d[i-3][0]); 
    }
    string ret;
    d[n][0]==0 ? ret = "SK" : ret = "CY";
    cout << ret;

    return 0;
}