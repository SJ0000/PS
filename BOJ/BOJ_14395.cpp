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

//n이 너무커서 check를 배열로 못씀
set<int> check;
queue<pair<int, string>> q;
int s, t;

string bfs()
{
    if (s == t)
        return "0";
    int nown = q.front().first;
    string nows = q.front().second;
    // 0이랑 1은 어디서 해도 똑같으니깐 1번만 해도됨
    // 사전순땜에  * + - / 순서대로 넣고, 이후는 * + 만 반복
    // mode : *
    if (nown <= 31624)
    { // sqrt(10억)
        if (check.find(nown * nown) == check.end())
        {
            check.insert(nown * nown);
            q.push(make_pair(nown * nown, nows + '*'));
        }
    }
    // mode : + 
    if (nown <= 500000000)
    {
        if (check.find(nown * 2) == check.end())
        {
            check.insert(nown * 2);
            q.push(make_pair(nown * 2, nows + '+'));
        }
    }
    // mode : -
    q.push(make_pair(0, nows + '-'));
    check.insert(0);
    // mode : /
    if (check.find(1) == check.end())
    {
        q.push(make_pair(1, nows + '/'));
        check.insert(1);
    }

    while (!q.empty())
    {
        nown = q.front().first;
        nows = q.front().second;
        q.pop();
        // cout << nown << " " << nows << endl;
        if (nown == t)
        {
            return nows;
        }
        //사전순을 위해 *먼저
        // mode : *
        if (nown <= 31624)
        { // sqrt(10억)
            if (check.find(nown * nown) == check.end())
            {
                check.insert(nown * nown);
                q.push(make_pair(nown * nown, nows + '*'));
            }
        }
        // mode : +
        if (nown <= 500000000)
        {
            if (check.find(nown * 2) == check.end())
            {
                check.insert(nown * 2);
                q.push(make_pair(nown * 2, nows + '+'));
            }
        }
    }
    return "-1";
}

int main()
{
    scanf("%d %d", &s, &t);
    q.push(make_pair(s, ""));
    check.insert(s);
    cout << bfs();

    return 0;
}