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

//i원을 지불하는 최소동전 개수.
int d[100001];

string s;

bool check(int now, bool isStep2)
{
    //끝까지 온 경우
    if (now >= s.size())
        return true;

    if (s[now] == '0')
    {
        if (s[now + 1] == '1')
            return check(now + 2, false);
        else
            return false;
    }
    else
    {
        if (isStep2)
        {
            return check(now, false) || check(now + 1, true);
        }
        else
        {
            if (s[now + 1] == '0')
            {
                //0이 n개
                now += 2;
                int zeros = 0;
                while (true)
                {
                    printf("now : %d\n",now);
                    if (now >= s.size())
                        return false;
                    if (s[now] == '0')
                    {
                        zeros++;
                        now++;
                    }
                    else
                    {
                        break;
                    }
                }
                //1이 n개
                if(zeros==0) return false;

                return check(now + 1, true);
            }
            else
            {
                return false;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        cin >> s;
        if (check(0, false))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}