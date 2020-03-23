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

typedef pair<int,int> pii;
int n;
vector<pair<pii,pii>> blocks; // 밑면,높이,무게,번호
int d[101]; // d[i] = i까지 i를 골랐을때 최대 높이
int main()
{
    scanf("%d",&n);
    int a,b,c;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        blocks.push_back(make_pair(make_pair(a,b),make_pair(c,i+1)));
    }
    //밑면 순으로 정렬
    sort(blocks.begin(),blocks.end());
    d[0] = blocks[0].first.second;
    int nowh,noww,nexth,nextw;//height,weight
    for(int i=0;i<n;i++){
        nexth = blocks[i].first.second;
        nextw = blocks[i].second.first;
        d[i] = blocks[i].first.second;
        for(int j=0;j<i;j++){
            nowh = blocks[j].first.second;
            noww = blocks[j].second.first;            
            if(nextw>noww){
                d[i] = max(d[i],d[j]+nexth);
            }
        }
    }
    int total = 0;
    vector<int> ret;
    for(int i=0;i<n;i++){
        total = max(total,d[i]);
    }
    //끝에서부터 추적
    for(int i=n-1;i>=0;i--){
        //d[i]가 total이면 d[i]가 골라졌다는 뜻.
        if(d[i]==total){
            //block번호 삽입
            ret.push_back(blocks[i].second.second);
            total -= blocks[i].first.second;
        }
    }
    printf("%d\n",ret.size());
    for(int i=ret.size()-1;i>=0;i--){
        printf("%d\n",ret[i]);
    }
    return 0;
}