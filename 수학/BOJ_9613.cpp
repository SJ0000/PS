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

int gcd(int a, int b){
    if(a%b==0){
        return b;
    }
    return gcd(b,a%b);
}

bool desc(int a,int b){
    return a>b;
}
int main()
{
    //유클리드 gcd(a,b) = gcd(b,a%b)
    int TC,n,val,ret;
    scanf("%d",&TC);
    vector<int> v;
    while(TC--){
        ret = 0;
        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&val);
            v.push_back(val);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ret += gcd(v[i],v[j]);
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}