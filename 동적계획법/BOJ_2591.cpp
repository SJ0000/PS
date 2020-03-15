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

int a[41];
int d[41]; // i까지 왔을때 만들 수 있는 경우의 수

int go(int ed){
    if(ed<=0){
        if(ed==0){
            if(a[ed]==0) return 0;
        }
        return 1;
    }
    int &ret = d[ed];
    if(ret!=-1) return ret;
    ret = 0;

    //2자리 카드 만들 수 있는 경우
    int lastTwo;
    if(ed>=1){
        lastTwo = a[ed-1]*10+a[ed];
        if(10<= lastTwo && lastTwo <= 34) ret += go(ed-2);
    }
    //1자리 카드 만들 수 있는경우
    if(a[ed]>0){
        ret += go(ed-1);        
    }
    return ret;
}

int main()
{
    string s;
    memset(a,-1,sizeof(a));
    memset(d,-1,sizeof(d));
    cin >> s;
    for(int i=0;i<s.size();i++){
        a[i] = s[i]-'0';
    }
    d[0] = 1;
    int ret;
    ret = go(s.size()-1);
    printf("%d",ret);

    return 0;
}