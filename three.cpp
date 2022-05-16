#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    string S;
    for(int i=0;i<N;++i){
        long long res=0;
        cin>>S;
        for(int j=0;j<S.size();++j)
            res+=S[j]-'0';
        if(res%3==0)cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}
