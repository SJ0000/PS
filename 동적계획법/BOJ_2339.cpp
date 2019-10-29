#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int MAXW = 100000;
int d[101][MAXW+1];

int main(){

    int n,k;
    vector<pair<int,int>> wv;
    scanf("%d %d",&n,&k);
    int w,v;
    for(int i=0;i<n;i++){
        scanf("%d %d",&w,&v);
        wv.push_back(make_pair(w,v));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=MAXW;j++){
             if(i==0) {
                 d[i][j] = j>=wv[i].first ? wv[i].second : 0;
             }else{
                 if(j>=wv[i].first){
                     d[i][j] = max(d[i-1][j],d[i-1][j-wv[i].first]+wv[i].second);
                 }else{
                     d[i][j] = d[i-1][j];
                 }                 
             }
        }
    }

    printf("%d",d[n-1][k]);
    return 0;

}