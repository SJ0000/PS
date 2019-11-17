#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <deque>
using namespace std;


//나이 젊은순서대로임 n
// 1~n명, m개의 채널.

//이미 소비된 채널로 돌아올 경우 무한반복, -1
const int MAXN = 100001;
bool used[MAXN];
int like[MAXN]; // i번째 사람이 좋아하는 채널
int go[MAXN];// i번째 채널이 되었을때 움직이는 사람, i번째 채널을 싫어하는 사람중 가장 젊은 사람.

int solve(int p){
    int now = p;
    int next = 0;
    int ret=0;
    while(true){
        if(go[p]==0) return ret;
        if(used[p]) return -1;
        used[p]=true;
        ret++;
        p = like[go[p]];
    }
}

int main()
{

    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int a,b;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        like[i] = a;
        if(go[b]==0){
            go[b] = i;
        }
    }
    
    printf("%d\n",solve(p));
    
    return 0;
}