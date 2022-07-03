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

vector<pair<int,int>> v[101];
int indegree[101];
int required[101][101]; // [i][j] : i를 만드는데 들어가는 baseParts인 j의 개수.
bool isBase[101];
queue<int> Q;
vector<int> baseParts;

int main()
{
    int n,m,x,y,k;
    scanf("%d %d",&n,&m);
    while(m--){
        //x를 만드는데 y가 k개 필요함.
        scanf("%d %d %d",&x,&y,&k);
        v[y].push_back(make_pair(x,k));
        indegree[x]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            Q.push(i);
            baseParts.push_back(i);
            isBase[i] = true;
        }
    }
    int bsz = baseParts.size();
    //기본부품이 몇개 들어가는지 update
    int now,next,sz,mag,bidx;
    for(int i=1;i<=n;i++){
        now = Q.front();
        Q.pop();
        printf("%d\n",now);
        sz = v[now].size();
        for(int idx = 0;idx<sz;idx++){
            next = v[now][idx].first;
            mag = v[now][idx].second;
            // printf("next , mag : %d %d\n",next,mag);
            if(isBase[now]){
                required[next][now] += mag;
            }else{
                for(int j = 0;j<bsz;j++){
                    bidx = baseParts[j];
                    required[next][bidx] += required[now][bidx]*mag;
                }
            }
            if(--indegree[next]==0){
                Q.push(next);
            }
        }
    }

    for(int i=0;i<bsz;i++){
        printf("%d %d\n",baseParts[i],required[n][baseParts[i]]);
    }

    return 0;
}