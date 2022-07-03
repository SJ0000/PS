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

int maxlen[6];
int nowlen[6];
bool isBefore[6];
void check(int x)
{
    if (isBefore[x])
    {
        nowlen[x]++;
        maxlen[x] = max(maxlen[x],nowlen[x]);
    }
    else
    {
        nowlen[x] = 1;
        maxlen[x] = max(maxlen[x],nowlen[x]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    scanf("%d %d", &a, &b);
    isBefore[a] = isBefore[b] = true;
    nowlen[a] = nowlen[b] = maxlen[a] = maxlen[b] = 1;

    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        if (a == b)
        {
            check(a);
        }
        else
        {
            check(a);
            check(b);
        }
        memset(isBefore,0,sizeof(isBefore));
        isBefore[a] = isBefore[b] = true;
    }

    int m = 0;
    for(int i=1;i<=5;i++){
        m = max(m,maxlen[i]);
    }
    for(int i=1;i<=5;i++){
        if(m==maxlen[i]){
            printf("%d %d",m,i);
            break;
        }
    }
    return 0;
}