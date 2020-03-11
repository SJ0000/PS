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

int a[1001];
int d[1001][1002]; // i번째에서 j랑 팀했을때 얻을 수 있는 최대 값.대기인원 없는경우 1001
int n;
int go(int now,int wait){
    //before == -1인경우, 대기중인 팀원 없음.
    int &ret = d[now][wait];
    if(ret!=-1) return ret;
    if(now==0){
        if(wait==1001){
            ret = 0;
            return ret;
        }
        else{
            int diff = abs(a[now]-a[wait]);
            //printf("Case C : %d,%d : %d\n",now,wait,diff);
            ret = diff;
            return ret;
        }
    }
    if(wait==1001){
        //now를 대기장소로 이동
        ret = go(now-1,now);
        //printf("Case a : %d,%d : %d\n",now,wait,ret);
        return ret;
    }else{
        //팀을 이루는 경우 or 혼자 팀을 하는 경우
        int diff = abs(a[now]-a[wait]);
        //1) wait이 혼자 팀을 하는 경우
        //2) now가 혼자 팀을 하는 경우
        //3) now와 wait이 짝이 되고 대기자가 없는 상태
        ret = max(go(now-1,now),max(go(now-1,1001)+diff,go(now-1,wait))); 
        //printf("Case b : %d,%d : %d\n",now,wait,ret);
        return ret;
    }
}


int main()
{
    memset(d,-1,sizeof(d));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",go(n-1,1001));
    return 0;
}