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
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(true){
        if(q.size()==1) break;
        q.pop();
        if(q.size()==1) break;
        int x = q.front();
        q.pop();
        q.push(x);
    }
    printf("%d\n",q.front());
    return 0;
}