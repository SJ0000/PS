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


int main()
{

    queue<int> q[21];
    int n,k;
    scanf("%d %d",&n,&k);
    string name;
    long long ret = 0;
    int len;
    for(int i=0;i<n;i++){
        cin >> name;
        len = name.length();
        if(q[len].empty()){
            q[len].push(i);
        }else if(i-q[len].front()>k){
            //pop하면서 자기 친구들 몇명인지 세고 나감
            // printf("diff : %d \n",i-q[len].front());
            while(i-q[len].front()>k){
                ret+=(q[len].size()-1);
                q[len].pop();
                if(q[len].empty()) break;
            }
            q[len].push(i);
        }else{
            q[len].push(i);
        }       
    }
    //남아있는애들 구해야함
    int sz;
    for(int i=0;i<21;i++){
        sz = q[i].size();
        // printf("%d's len : %d\n",i,q[i].size());
        ret += (sz)*(sz-1)/2;
    }
    printf("%lld",ret);
    

    return 0;
}