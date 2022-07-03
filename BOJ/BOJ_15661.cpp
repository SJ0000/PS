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

int n, ret;
int s[21][21];
vector<int> teamA, teamB;

int getAbilDiff()
{
    //teamA와 teamB의 능력치 차이.
    int abilA = 0;
    int abilB = 0;
    for (int i = 0; i < teamA.size(); i++)
    {
        for (int j = 0; j < teamA.size(); j++)
        {
            abilA += s[teamA[i]][teamA[j]];
        }
    }
    for (int i = 0; i < teamB.size(); i++)
    {
        for (int j = 0; j < teamB.size(); j++)
        {
            abilB += s[teamB[i]][teamB[j]];
        }
    }
    return abs(abilA - abilB);
}
int main()
{
    scanf("%d", &n);
    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }
    //bitmask, 1<<n 이 1이면 1팀, 0이면 2팀
    for (int mask = 0; mask <= (1 << (n + 1)) - 1; mask++)
    {
        teamA.clear();
        teamB.clear();
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                teamA.push_back(i);
            }
            else
            {
                teamB.push_back(i);
            }
        }
        ret = min(ret, getAbilDiff());
    }
    printf("%d",ret);

    return 0;
}