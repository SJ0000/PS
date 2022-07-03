#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
using namespace std;

typedef long long ll;

int ret = 0;

stack<int> st[7];

void func(int m, int f)
{
    if (st[m].empty())
    {
        st[m].push(f);
        ret++;
        return;
    }
    if (st[m].top() < f)
    {
        st[m].push(f);
        ret++;
    }
    else if (st[m].top() > f)
    {

        while (!st[m].empty())
        {   
            if(st[m].top()>f){
                st[m].pop();
                ret++;
            }else{
                break;
            }
        }
        func(m, f);
    }
}

int main()
{

    int n, p;
    scanf("%d %d", &n, &p);
    int melody, frat;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &melody, &frat);
        func(melody, frat);
    }
    printf("%d", ret);

    return 0;
}