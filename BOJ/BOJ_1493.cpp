#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

// 실수한점 1) 부피로 처리(long long 범위를 초과한다)
// 실수한점 2) 자르는 방식(처음에 가장 큰것을 반으로 잘랐음)
// 실수한점 3) cutBox에서 못 자르는 경우를 생각하지 않음.
// 실수한점 4) 최대 1개만 자르니까 중복되는 경우가 너무많아서 시간초과

ll requiredCube[21] = {0,};

//len,wid,hei의 길이를 가진 box를 2^i크기로 쪼갠다.
void cutBox(int len,int wid,int hei,int i){

    vector<int> sizes{len,wid,hei};
    sort(sizes.begin(),sizes.end());

    int cutSize = 1<<i;
    //존재하지 않는 경우
    if(sizes[0]<=0){
        return;
    }
    //잘라봤자 소용없는경우
    if(sizes[0]==1 || i==0){
        requiredCube[0]+=(ll)(len*wid*hei);
        return;
    }
    //자르려는 길이가 더 큰 경우
    if(sizes[0]<cutSize){
        cutBox(len,wid,hei,i-1);
        return;
    }
    //쪼개야 하는 경우
    int xcut = sizes[0]/cutSize;
    int ycut = sizes[1]/cutSize;
    int zcut = sizes[2]/cutSize;
    requiredCube[i]+= 1LL*xcut*ycut*zcut;
    cutBox(sizes[0],sizes[1],sizes[2]-(zcut*cutSize),i-1);
    cutBox(sizes[0],sizes[1]-(ycut*cutSize),zcut*cutSize,i-1);
    cutBox(sizes[0]-(xcut*cutSize),ycut*cutSize,zcut*cutSize,i-1);
    return;
}

int main(){

    ll currentCube[21]={0,};
    
    int l,w,h,n;
    scanf("%d %d %d %d",&l,&w,&h,&n);
    int a;
    ll b;
    for(int i=0;i<n;i++){
        scanf("%d %lld",&a,&b);
        currentCube[a] += b;
    }

    cutBox(l,w,h,20);

    ll ret = 0;
    //required랑 current랑 비교
    //길이 n짜리는 길이n-1의 8개로 대체가능.
    //cur[i]로 처리하지 못한 req[i]를 req[i-1]에 8배로 곱해서 넘겨버림
    for(int i=20;i>=1;i--){
        if(requiredCube[i]>currentCube[i]){   
            requiredCube[i-1]+=8*(requiredCube[i]-currentCube[i]);
            requiredCube[i]=0;
            ret+=currentCube[i];
        }else{
            ret+=requiredCube[i];
        }
    }
    if(requiredCube[0]<=currentCube[0]){
        ret+=requiredCube[0];
    }else{
        ret = -1;
    }

    printf("%lld\n",ret);

    return 0;
}