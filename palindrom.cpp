#include <iostream>
using namespace std;

bool is_palindrom(const string &s){ 
    for(int i = 0; i < s.size(); ++i) 
        if(s[i] != s[s.size()-1-i] && tolower(s[i]) != tolower(s[s.size()-1-i])) 
            return 0;
    return 1; 
} 
 
int main(){ 
    string S; 
    bool ifnull=true, pal_len = false; 
    int length = 0; 
    cin>>length;
    while(cin>>S) { 
        ifnull=false; 
        if(is_palindrom(S) && S.size() == length){ 
            cout<<S<<'\n'; 
            pal_len = true; 
        } 
    } 
    if (ifnull)cout<<"NULL"; 
    else if (!pal_len) cout<<-1;
}
