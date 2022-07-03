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

//총 f층, 목적지 g층, 현재위치 s층, + u, -d 층 가능

bool check[1000001];
int f,s,g,u,d;

int main()
{
    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
    queue<int> q;
    memset(check,0,sizeof(check));
    check[s] = true;
    q.push(s);
    int click = 0;
    int qs,now;
    bool getAns = false;
    if(s==g) getAns = true;
    while(!q.empty()){
        if(getAns) break;
        qs = q.size();
        click++;
        for(int i=0;i<qs;i++){
            now = q.front();
            q.pop();
            if(now-d==g || now+u==g){
                getAns = true;
                break;
            }
            if(1 <= now-d){
                if(!check[now-d]){
                    check[now-d]=true;
                    q.push(now-d);
                }
            }
            if(now+u <= f){
                if(!check[now+u]){
                    check[now+u]= true;
                    q.push(now+u);
                }
            }
        }
    }
    if(getAns){
        printf("%d",click);
    }else{
        printf("use the stairs");
    }
    return 0;
}