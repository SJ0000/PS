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

// 0,n+1은 시작과 끝지점
int d[103]; // d[i] : i에서 정비를 받았을 때 최소 정비시간
int len[103]; // len[i] : i-1에서 i까지의 거리
int repair[103]; //repair[i] : i에서 정비받는데 걸리는 시간
int r,n;
int go(int now){ // 남은 갈 수 있는 거리

    int &ret = d[now];
    if(ret!=-1) return ret;
    ret = 2147483647;
    int sum = 0;
    for(int i=now-1;i>=0;i--){
        //i에서 정비를 받고 now로 올 수 있는 경우
        sum += len[i+1];
        if(sum<=r){
            ret = min(ret,go(i)+repair[i]);
        }else{
            break;
        }
    }
    return ret;
}

void test(){
    printf("\n");
    for(int i=0;i<=n+1;i++){
        printf("%d ",d[i]);
    }
}

void tracking(){

}

int main()
{
    memset(d,-1,sizeof(d));
    scanf("%d %d",&r,&n);
    for(int i=1;i<=n+1;i++){
        scanf("%d",&len[i]);
    } 
    for(int i=1;i<=n;i++){
        scanf("%d",&repair[i]);
    }
    d[0] = 0;
    go(n+1);
    deque<int> ans;
    int now = d[n+1];
    for(int i=n;i>0;i--){
        if(now-repair[i]==d[i]){
            ans.push_front(i);
            now = d[i];
        }
    }
    printf("%d\n",d[n+1]);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d ",ans[i]);
    }
    return 0;
}