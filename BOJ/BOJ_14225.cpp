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

int n,m;
vector<int> s;
bool check[2000001];
int main()
{
    scanf("%d",&n);
    int val;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        s.push_back(val);
    }
    int now;
    for(int mask=1;mask<(1<<n);mask++){
        now = 0;
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                now += s[i];
            }
        }
        check[now] = true;
    }

    for(int i=1;i<=2000000;i++){
        if(!check[i]){
            printf("%d",i);
            break;
        }
    }


    return 0;
}