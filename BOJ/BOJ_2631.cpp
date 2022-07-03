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

int lis[201];
int a[201];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        lis[i] = 1;
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                lis[i] = max(lis[i],lis[j]+1);
                ans = max(ans,lis[i]);
            }
        }
    }
    printf("%d",n-ans);
    return 0;
}