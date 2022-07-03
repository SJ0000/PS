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

int a[401][801];
int p[401][801];
int n,ret,now;
void init(){
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    ret= -9876543210;
    now=0;
}
//역삼각형으로 끝에서부터 퍼질때
int getMaxIdx(int i,int j){
    return min(j/2, (2*i-j)/2);
}
int main()
{
    int TC = 0;
    while(true){
        TC++;
        scanf("%d",&n);
        if(n==0) break;
        init();
        for(int i=0;i<n;i++){
            for(int j=0;j<2*i+1;j++){
                scanf("%d",&a[i][j]);
            }
        }
        //누적합
        for(int i=0;i<n;i++){
            p[i][0] = a[i][0];
            for(int j=1;j<i*2+1;j++){
                p[i][j] = p[i][j-1]+a[i][j];
            }
        }

        //debug
        
        printf("*****\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<2*n-1;j++){
                printf("%d ",p[i][j]);
            }
            printf("\n");
        }
        printf("*****\n");
        
        //정삼각형               
        for(int i=0;i<n;i++){
            for(int j=0;j<2*i+1;j+=2){
                now = 0;
                for(int idx=0;idx<n-i;idx++){
                    //시작높이가 i 일때 길이 n-i까지 구할 수 있음.
                    if(j==0){
                        now += p[i+idx][j+(2*(idx))];
                    }
                    else{
                        now += (p[i+idx][j+(2*(idx))]-p[i+idx][j-1]);
                    }
                    printf("%d,%d 's forward %d : %d \n",i,j,idx,now);
                    ret = max(ret,now);
                }
            }         
        }
        
        //역삼각형
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<2*i+1;j+=2){
                now = 0;
                //몇층까지 쌓을 수 있는지 판단.
                int maxIdx = getMaxIdx(i,j);
                for(int idx = 0;idx<=maxIdx;idx++){
                    //TODO 0115 : 이부분 다시 보기
                    if(j-(2*idx)==0){
                        now += p[i-idx][j];
                    }else{
                        now += p[i-idx][j] - p[i-idx][j-(2*idx)-1];
                    }
                    printf("%d,%d 's reverse idx %d : %d \n",i,j,idx,now);
                    ret = max(ret,now);                    
                }
            }   
        }
        printf("%d. %d\n",TC,ret);
    }
    return 0;
}