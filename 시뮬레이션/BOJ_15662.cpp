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

int gear[1001][8];
int n, m;
int turnList[1001];

void turn(int idx, int dir)
{
    int tmp[8];
    for (int i = 0; i < 8; i++)
    {
        tmp[i] = gear[idx][i];
    }
    if (dir == 1)
    {
        for (int i = 0; i < 7; i++)
        {
            gear[idx][i + 1] = tmp[i];
        }
        gear[idx][0] = tmp[7];
    }
    else
    {
        for (int i = 7; i >= 1; i--)
        {
            gear[idx][i - 1] = tmp[i];
        }
        gear[idx][7] = tmp[0];
    }
}
//n번 바퀴를 dir방향으로 돌림 (1 시계 -1 반시계)
void act(int idx, int dir)
{
    memset(turnList,0,sizeof(turnList));
    turnList[idx] = dir;
    //맞닿은 극이 다르면 반대방향으로 회전
    if (idx != 1)
    {
        //왼
        for (int i = idx - 1; i >= 0; i--)
        {
            //i+1을 기준으로 i를 돌릴지 말지 결정
            if (gear[i + 1][6] != gear[i][2])
            {
                turnList[i] = turnList[i+1]*-1;
            }
            else
            {
                break;
            }
        }
    }
    if (idx != n)
    {
        //오른
        for (int i = idx + 1; i <= n; i++)
        {
            //i-1을 기준으로 i를 돌릴지 말지 결정
            if (gear[i - 1][2] != gear[i][6])
            {
                turnList[i] = turnList[i-1]*-1;
            }
            else
            {
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(turnList[i]!=0){
            turn(i,turnList[i]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            gear[i][j] = s[j] - '0';
        }
    }
    scanf("%d", &m);
    int idx, dir;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &idx, &dir);
        act(idx, dir);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (gear[i][0] == 1)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}