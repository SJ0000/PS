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

queue<vector<deque<int>>> q;
vector<deque<int>> v;
deque<int> now[3];
set<string> check;
//1번 반복

//0의 가장 밑이 0이면 시간단축을 위해 그냥 지워버림

void printNow(){
    printf("***PRINT NOW***\n");
    for(int i=0;i<3;i++){
        printf("%d : ",i);
        for(int j=0;j<now[i].size();j++){
            printf("%d ",now[i][j]);
        }
        printf("\n");
    }
}
string toStringNow(){
    string ret = "";
    for(int i=0;i<3;i++){
        for(int j = 0;j<now[i].size();j++){
            ret.push_back(now[i][j]+'0');
        }
        ret.push_back(now[i].size()+'0');
    }
    return ret;
}
void init()
{
    for (int i = 0; i < 3; i++)
    {
        if (now[i].size() == 0)
            continue;
        while (now[i][0] == i)
        {   
            now[i].pop_front();
            if(now[i].size()==0)break;
        }
    }
}
void pushNow()
{
    //check해서 이전에 같은 결과가 나온적이 없으면 queue에 삽입.
    string key = toStringNow();
    if(check.find(key)!=check.end()) return;
    check.insert(key);
    vector<deque<int>> v;
    for (int i = 0; i < 3; i++)
    {
        v.push_back(now[i]);
    }
    q.push(v);
    v.clear();
}

//a -> b 로 가고 원복까지
void move(int a, int b)
{
    now[b].push_back(now[a].back());
    now[a].pop_back();
    pushNow();
    now[a].push_back(now[b].back());
    now[b].pop_back();
}

int bfs()
{
    int moves = 0;
    int qs;
    while (!q.empty())
    {
        qs = q.size();
        while (qs--)
        {
            for (int i = 0; i < 3; i++)
            {
                now[i] = q.front()[i];
            }
            // printNow();
            q.pop();
            init();
            if (!(now[0].size() || now[1].size() || now[2].size()))
            {
                return moves;
            }

            if (now[0].size() > 0)
            {
                move(0, 1);
                move(0, 2);
            }
            if (now[1].size() > 0)
            {
                move(1, 0);
                move(1, 2);
            }
            if (now[2].size() > 0)
            {
                move(2, 0);
                move(2, 1);
            }
        }
        moves++;
    }
    return moves;
}

int main()
{
    int n;
    string s;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &n);
        if(n!=0){
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                now[i].push_back(s[j] - 'A');
            }
        }
    }
    pushNow();
    int ret = bfs();

    printf("%d", ret);
    return 0;
}