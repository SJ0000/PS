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

int n;
int e[11];
bool check[11];


int main()
{
    //앞뒤 곱이 가장 높은걸 구하면됨
    //greedy 안되고 모든 순서를 다 해봐야함
    // 2~n-1 조합
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&e[i]);
    }
    vector<int> cases;
    for(int i=1;i<=n-2;i++){
        cases.push_back(i);
    }
    int ret = 0;
    int nowE,l,r;
    do{
        printf("* * * * Start * * * *\n");
        nowE = 0;
        memset(check,0,sizeof(check));
        for(int i=0;i<n-2;i++){      
            l = r = 1;      
            while(check[cases[i]-l]) l++;
            while(check[cases[i]+r]) r++;
            check[cases[i]] = true;
            nowE += e[cases[i]-l]*e[cases[i]+r];
            printf("cases[i],l,r : %d %d %d / nowE : %d \n",cases[i],l,r,nowE);
        }
        ret = max(ret,nowE);
    }while(next_permutation(cases.begin(),cases.end()));

    printf("%d",ret);

    return 0;
}