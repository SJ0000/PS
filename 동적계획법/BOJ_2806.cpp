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

typedef long long ll;

int n;
string s;
//a[i] : 0~i까지 다 a로 만드는 비용
int a[1000001];
int b[1000001];

int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    cin >> n;
    cin >> s;
    
    s[0]=='A' ? b[0] = 1 : a[0] = 1;
    for(int i=1;i<n;i++){
        if(s[i]=='A'){
            a[i] = min(a[i-1],b[i-1]+2);
            b[i] = min(a[i-1]+1,b[i-1]+1);
        }else{
            a[i] = min(a[i-1]+1,b[i-1]+1);
            b[i] = min(a[i-1]+2,b[i-1]);
        }
    }
    printf("%d",a[n-1]);
    
    return 0;
}