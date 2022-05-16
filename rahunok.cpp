#include <bits/stdc++.h>

using namespace std;

const int Nmax=1000000;

struct Tlong
{
    int len=1;
    int number[Nmax]={0};
    char sign='+';
};

void clear(Tlong&a){
    for (int i=Nmax-a.len;i<Nmax;i++)
        a.number[i]=0;
    a.len=1;
    a.sign='+';
}

void readlong(Tlong&a)
{
    string S;
    cin>>S;
    if (S[0]=='+' || S[0]=='-')
    {
        a.sign=S[0];
        S.erase(0,1);
    }
    else a.sign='+';
    a.len=S.size();
    for (int i=0;i<a.len;++i)
        a.number[Nmax-a.len+i]=S[i]-'0';
}
void writelong(Tlong&a){
    if (a.sign=='-')
        cout<<'-';
    for (int i=Nmax-a.len;i<Nmax;++i)
        cout<<a.number[i];
}
void inc_long(Tlong&a){
    int i=Nmax;
    while (a.number[--i]==9)
        a.number[i]=0;
    if (i==Nmax-a.len-1)
        a.len++;
    a.number[i]++;
}

Tlong a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=0;i<n;++i){
        clear(a);
        readlong(a);
        inc_long(a);
        writelong(a);
        cout<<'\n';
    }
    return 0;
}