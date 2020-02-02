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

typedef pair<int,int> pii;
bool check[1501][1501]; // 각 그룹의 돌이 a,b인 경우 (c는 a,b에 의존적)
queue<pii> q;

void checkAndPush(int x,int y){
    if(!check[x][y]){
        check[x][y] = true;
        q.push(make_pair(x,y));
    }
}
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    memset(check,0,sizeof(check));
    int sum = a+b+c;
    q.push(make_pair(a,b));
    check[a][b] = true;
    int na,nb,nc;
    bool getAns = false;
    if(sum%3!=0){
        printf("0");
        return 0;
    }
    while(!q.empty()){
        na = q.front().first;
        nb = q.front().second;
        nc = sum - na - nb;
        q.pop();

        printf("%d %d %d\n",na,nb,nc);

        if(na==nb && nb==nc){
            getAns = true;
            break;
        }
        //A B
        if(na>nb){
            checkAndPush(na-nb,nb*2);
        }else if(na<nb){
            checkAndPush(na*2,nb-na);
        }
        //A C
        if(na>nc){
            checkAndPush(na-nc,nb);
        }else if(na<nc){
            checkAndPush(na*2,nb);
        }
        //B C
        if(nb>nc){
            checkAndPush(na,nb-nc);
        }else if(nb<nc){
            checkAndPush(na,nb*2);
        }
    }
    if(getAns){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}