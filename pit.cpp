#include <bits/stdc++.h>
using namespace std;

int main(){
    char symb,symb_prev;
    int cnt=0;
    while(cin>>symb)
    {
        if(cnt==0&&symb==')')
        {
            cout<<"ERROR";
            return 0;
        }
        ++cnt;
        if(symb_prev==symb)
        {
            cout<<"ERROR";
            return 0;
        }
        symb_prev=symb;
    }
    if(symb=='(')cout<<"INSIDE";
    else cout<<"OUTSIDE";
    return 0;
}
