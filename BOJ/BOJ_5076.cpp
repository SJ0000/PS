#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
#include <string>
using namespace std;

typedef long long ll;

//<body></body> 처럼 닫히는 구조
//<br />처럼 한번에 열고닫는구조도 가능함.

bool isPossible(string s){
    stack<string> st;
    vector<string> tags;
    //makeTag
    string tag="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='<'){
            tag.push_back(s[i]);
            while(true){
                i++;
                if(i>s.size()) break;
                tag.push_back(s[i]);
                if(s[i]=='>') break;                
            }
        }
        if(tag[0]=='<' && tag[tag.size()-1]=='>'){
            tags.push_back(tag);
        }
        tag.clear();
    }
    /*
    for(int i=0;i<tags.size();i++){
        cout << tags[i] << endl;
    }
    */
    //stack
    for(int i=0;i<tags.size();i++){
        string now="";
        tag = tags[i];
        //여닫는 태그 무시
        if(tag[tag.size()-2]=='/') continue;
        //attr 제거
        for(int i=1;i<tag.size()-1;i++){
            if(tag[i]==' ') break;
            now.push_back(tag[i]);
        }
        if(now[0]!='/'){
            st.push(now);
        }else{
            if(!st.empty()){
                if(st.top()==now.substr(1,now.size()-1)){
                    st.pop();
                }
            }
        }
    }
    return st.empty();
}

int main()
{
    string s;
    while(true){
        getline(cin,s);
        if(s=="#") break;
        
        if(isPossible(s)){
            printf("legal\n");
        } 
        else{
            printf("illegal\n");
        } 
    }
    return 0;
}