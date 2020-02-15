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

int n, m;
int a[11][11];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int check[11][11][2];   // x[i][j][추가오작교 사용여부] // 시간으로 기록, 대기하는 경우가 있기 때문
queue<pair<int, int>> q; // x*100+y , 추가오작교 사용여부

bool rangeCheck(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}
int bfs()
{
    int x, y, opt, ax, ay;
    int qs, now;
    now = 1;
    while (!q.empty())
    {
        qs = q.size();
        for (int k = 0; k < qs; k++)
        {
            x = q.front().first / 100;
            y = q.front().first % 100;
            opt = q.front().second;
            q.pop();
            if (x == n - 1 && y == n - 1){
                return now-1;
            }
            for (int i = 0; i < 4; i++)
            {
                ax = x + dx[i];
                ay = y + dy[i];
                if (!rangeCheck(ax, ay))
                    continue;                
                //이미 대기중인 경우
                if (check[ax][ay][opt] == now)
                    continue;
                //오작교에서 오작교로는 못건너감
                if (a[x][y] > 1 && a[ax][ay] > 1)
                    continue;
                //추가 오작교에서 오작교로는 못건너감
                if(a[x][y]==0 && a[ax][ay]>1)
                    continue;
                //오작교
                if (a[ax][ay] > 1)
                {
                    //건널수 있으면 건넘
                    if(now%a[ax][ay]==0){
                        check[ax][ay][opt] = now;
                        q.push(make_pair(ax * 100 + ay, opt));
                        continue;                    
                    }else{
                        //못건너면 대기
                        check[x][y][opt] = now;
                        q.push(make_pair(x*100+y,opt));
                        continue;
                    }
                }
                //절벽인데 오작교 만들 수 있는 경우
                //대기해야 하는 경우, 갈 수 있는 경우 두개로 나누기
                if (a[ax][ay] == 0 && opt == 0)
                {   
                    //건널 수 있는 경우
                    if(now%m == 0){
                        check[ax][ay][1] = now;
                        q.push(make_pair(ax * 100 + ay, 1));
                        continue;
                    }else{
                        //대기해야 하는 경우
                        check[x][y][opt] = now;
                        q.push(make_pair(x*100+y,opt));
                        continue;
                    }                    
                }
                //그냥 건널 수 있는 경우
                if (a[ax][ay] == 1)
                {
                    check[ax][ay][opt] = now;
                    q.push(make_pair(ax * 100 + ay, opt));
                    continue;
                }
            }
        }
        now++;
    }
    return 0;
}
int main()
{
    //time%m == 0 이면 오작교 건널 수 있음
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    memset(check, 0, sizeof(check));
    check[0][0][0] = 1;
    q.push(make_pair(0, 0));
    printf("%d", bfs());
    return 0;
}