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

bool dp[50][50][50][2][3]; // i a b , b 출근가능여부,c 출근가능여부 유무
string s;
char ret[51];
int A,B,N;

//pb = 0이면 b출근 불가능 , pc가 0,1 이면 c출근 불가능
bool go(int i,int a,int b,int pb,int pc){

    if(a>A || b>B || i-a-b>N-A-B) return false;

    if(i==N){
        // cout << ret << endl;
        if(a==A && b==B) return true;
        return false;
    }

    //시간초과 해결 필요
    //dp 점화식
    //dp[i][a][b] = 길이i에서 A a개 B b개 방문 ok?

    if(pb>1) pb = 1;
    if(pc>2) pc = 2;

    if(dp[i][a][b][pb][pc]) return false;
    dp[i][a][b][pb][pc] = true;


    ret[i] = 'A';
    if(go(i+1,a+1,b,1,pc+1)) return true;

    if(pb==1){
        ret[i] = 'B';
        if(go(i+1,a,b+1,0,pc+1)) return true;
    }

    if(pc==2){
        ret[i] = 'C';
        if(go(i+1,a,b,1,0)) return true;
    }
    return false;
}

int main()
{
    cin >> s;
    A = B = 0;
    N = s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]=='A') A++;
        if(s[i]=='B') B++;
    }

    if(go(0,0,0,1,2)){
        cout << ret;
    }else{
        cout << -1;
    }
    
    return 0;
}