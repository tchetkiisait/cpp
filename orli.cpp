#include <bits/stdc++.h>
using namespace std;
const int Nmax=700;
struct Tlong{
    int len=1;
    short digit[Nmax]={0};
};

int Lenlong(Tlong&a){
    int i=0;
    while(i<Nmax-1&&a.digit[i]==0)++i;
    return Nmax-i;
}

void output_long(Tlong&a){
    for(int i=Nmax-a.len;i<Nmax;++i)
        cout<<a.digit[i];
}

Tlong multy_half(Tlong &a,int b){
    Tlong res;
    int S,p=0;
    for (int i=Nmax-1;i>=0;--i)
    {
        S=a.digit[i]*b+p;
        res.digit[i]=S%10;
        p=S/10;
    }
    res.len=Lenlong(res);
    return res;
}

Tlong pow_long(int pow_3,int ost){
    Tlong res;
    res.digit[Nmax-1]=ost;
    for(int i=0;i<pow_3;++i)
        res=multy_half(res,3);
    return res;
}

int main()
{
    int N_heads;
    cin>>N_heads;
    int pow_3=N_heads/3;
    int ost=N_heads%3;
    if(ost==1)
    {
        --pow_3;
        ost=4;
    }
    if(ost==0)ost=1;
    Tlong res=pow_long(pow_3,ost);
    output_long(res);
    return 0;
}
