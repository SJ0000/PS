#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

typedef long long ll;

void calc(string str){

    list<char> li;
    list<char>::iterator iter = li.begin();
    for(int i=0;i<str.size();i++){
        if(str[i]=='<'){
            if(iter!=li.begin()){
                iter--;
            }
        }else if(str[i]=='>'){
            if(iter!=li.end()){
                iter++;
            }
        }else if(str[i]=='-'){
            if(iter!=li.begin()){
                iter = li.erase(--iter);
            }
        }else{
            li.insert(iter,str[i]);
        }        
    }

    for(iter = li.begin();iter!=li.end();++iter){
        cout << *iter;
    }
    cout<<endl;
}


int main(){

    int n;
    string str;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin >> str;
        calc(str);
    }
   
    return 0;
}