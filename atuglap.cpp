#include <bits/stdc++.h>
using namespace std; 
int main()  {  
    string s;
    cin>>s;
    int a1,a2,a3;
    a1=0;a2=0;a3=0;
    for (int i=0;i<s.size();++i){
       if (s[i]=='~') ++a1;
       if (s[i]=='@') --a1;
       if (s[i]=='#') ++a2;
       if (s[i]=='$') --a2;
       if (s[i]=='%') ++a3;
       if (s[i]=='&') --a3;
    }
    if ((a1==0)&&(a2==0)&&(a3==0)) cout<<"OK";
    else cout<<"WRONG";
    return 0;  
}  


