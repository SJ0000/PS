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

pair<int, int> len[1003][1003];
int d[1003][1003];
int a[1003][1003];
int n, m;

int main()
{
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    scanf("%d %d", &n, &m);
    string s;
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = d[i][j] = s[j - 1] - '0';
            if (a[i][j] == 1)
            {
                //len계산
                len[i][j].first = len[i][j - 1].first + 1;
                len[i][j].second = len[i - 1][j].second + 1;
                //정사각형 늘릴 수 있는지 여부 검사.
                /*
                if (a[i - 1][j - 1] == 1)
                {
                    if (len[i][j - 1].first >= d[i - 1][j - 1] && len[i - 1][j].second >= d[i - 1][j - 1])
                    {
                        d[i][j] = d[i - 1][j - 1] + 1;
                    }
                }
                */
                d[i][j] = min(min(d[i-1][j-1]+1,len[i][j].first),len[i][j].second);
                ret = max(ret,d[i][j]);
            }
        }
    }
    printf("%d",ret*ret);
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d,%d ",len[i][j].first,len[i][j].second);
        }
        printf("\n");
    }
    return 0;
}