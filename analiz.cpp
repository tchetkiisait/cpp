#include <bits/stdc++.h>
using namespace std;

bool iszero(int mas[],int N){
    for(int i=0;i<N;++i)
        if(mas[i]!=0)return false;
    return true;
}

int main(){
    string S;
    int mas[26]={0};
    while(getline(cin,S))
    {
        for(int i=0;i<S.size();++i)
        {
            if(S[i]>='a'&&S[i]<='z')S[i]=S[i]-'a'+'A';
            if(S[i]>='A'&&S[i]<='Z')++mas[S[i]-'A'];
        }
    }
    if(iszero(mas,26))cout<<-1;
    else
    {
        for(int i=0;i<26;++i)
            cout<<char(i+65)<<' '<<mas[i]<<'\n';
    }
    return 0;
}
