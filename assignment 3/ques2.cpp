#include<iostream>
#include<stack>
#include<string>
using namespace std;
void reversing(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
            st.push(s[i]);
        }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;


}
int main(){
    string s;
    getline(cin,s);
    reversing(s);
    return 0;
}
