#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
using namespace std;

typedef long long ll;

bool solve(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top()==s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    return st.empty();
}

int main()
{
    int n;
    scanf("%d",&n);
    string s;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> s;
        if(solve(s)) ans++;
    }
    printf("%d",ans);
    return 0;
}