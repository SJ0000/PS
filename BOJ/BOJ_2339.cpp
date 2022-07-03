#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
int b[21][21];

//dir 0 가로, 1 세로
//cutblock
ll cutb(pair<int,int> st,pair<int,int> ed,int dir){
    //존재하지 않는 경우
    if(st.first<0 || st.second<0 || ed.first<0 || ed.second<0){
        return 0;
    }
    //cut되지 않는 경우.
    ll ret = 0;
    int jewels=0;
    vector<pair<int,int>> impurities;
    for(int i = st.first;i<= ed.first;i++){
        for(int j=st.second;j<=ed.second;j++){
            if(b[i][j]==1){
                impurities.push_back(make_pair(i,j));
            }else if(b[i][j]==2){
                jewels++;
            }
        }
    }
    // base 1) 보석이 없는 경우
    if(jewels==0) return 0;
    // base 2) 불순물 x, 보석 2이상
    if(impurities.empty() && jewels>=2) return 0;
    // base 3) 1덩어리 완성
    if(jewels==1 && impurities.empty()) return 1;

    //자르는 경우 - 불순물 유무 check
    for(int i=0;i<impurities.size();i++){
        pair<int,int> now = impurities[i];
        bool isPossible = true;
        if(dir==0){
            for(int j=st.second;j<=ed.second;j++){
                if(b[now.first][j]==2 && j!=now.second){
                    isPossible = false;
                    break;
                }
            }
            if(isPossible){
                ret += cutb(st,make_pair(now.first-1,ed.second),1)*cutb(make_pair(now.first+1,st.second),ed,1);
            }else{
                continue;
            }     
        }else{
            for(int j=st.first;j<=ed.first;j++){
                if(b[j][now.second]==2 && j!=now.first){
                    isPossible = false;
                    break;
                }
            }
            if(isPossible){
                ret += cutb(st,make_pair(ed.first,now.second-1),0)*cutb(make_pair(st.first,now.second+1),ed,0);
            }else{
                continue;
            }
        }
    }
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    ll ans = 0;
    pair<int,int> st = make_pair(0,0);
    pair<int,int> ed = make_pair(n-1,n-1);
    ans = cutb(st,ed,0) + cutb(st,ed,1);

    ans==0 ? printf("-1") : printf("%lld\n",ans);
    return 0;

}