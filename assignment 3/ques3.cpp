#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool checkParanthesis(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'|| s[i]=='}' || s[i]==']'){
            if(st.empty()){
                return false;
            }
            char top =st.top();
            st.pop();
            if(s[i]=='(' && top==')'|| s[i]=='{' && top=='}'|| s[i]=='[' && top==']'){
                
            }
            }
       }
       return st.empty();
    }
    
int main(){
    string s;
    cout<<"Enter expression"<<endl;
    getline(cin,s);
    int i=checkParanthesis(s);
    if(i==1){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}
