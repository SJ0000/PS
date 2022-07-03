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

bool check[61][61][61];
queue<pair<pair<int,int>,int>> q;

int atk[6][3] = {{1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1}};

int n;

int bfs(){

    int qs;
    int a,b,c,na,nb,nc;
    int ret = 0;
    while(!q.empty()){
        qs = q.size();
        while(qs--){
            a = q.front().first.first;
            b = q.front().first.second;
            c = q.front().second;
            q.pop();

            // printf("%d %d %d \n",a,b,c);

            if(a==0 && b==0 && c==0){
                return ret;
            }

            for(int i=0;i<6;i++){
                na = a;
                nb = b;
                nc = c;
                na-atk[i][0] >= 0 ? na-=atk[i][0] : na = 0;
                nb-atk[i][1] >= 0 ? nb-=atk[i][1] : nb = 0;
                nc-atk[i][2] >= 0 ? nc-=atk[i][2] : nc = 0;
                if(!check[na][nb][nc]){
                    check[na][nb][nc] = true;
                    q.push(make_pair(make_pair(na,nb),nc));
                }
            }
        }
        ret++;
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    int a[3] = {0,0,0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    memset(check,0,sizeof(check));
    q.push(make_pair(make_pair(a[0],a[1]),a[2]));
    check[a[0]][a[1]][a[2]] = true;
    int ans = bfs();
    printf("%d",ans);
    return 0;
}