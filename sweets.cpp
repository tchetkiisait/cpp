#include <iostream>
using namespace std;

bool palindrom(string S){
    for (int j = 0; j <= S.size()/2; ++j)
        {
            if (!isdigit(S[j]) || !isdigit(S[S.size()-1-j]))
                return false;
            if (S[j] != S[S.size()-1-j])
                return false;
        }
    return true;
}

int main(){
    string S;
    int opt = 0;
    while (cin>>S){
        if (palindrom(S)){
            cout<<S<<'\n';
            ++opt;
        }
    }
    if (!opt)cout<<"The notepad is clean.";
}
