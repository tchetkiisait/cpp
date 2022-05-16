#include <bits/stdc++.h>
using namespace std;

const int Nmax = 100000;
struct Tlong {
  int len = 1;
  char sign = '+';
  int num[Nmax+1] = {0};
};
int LenLong(Tlong a) {
  a.num[Nmax] = 13;
  int i = 0;
  while (!a.num[i]) ++i;
  if (i == Nmax) return 1;
  return Nmax-i;
}
Tlong multiply(Tlong&a,int b){
    Tlong res;
    int S,p=0;
    for(int i=Nmax-1;i>Nmax-a.len-12;--i)
    {
        S=a.num[i]*b+p;
        res.num[i]=S%10;
        p=S/10;
    }
    res.len=LenLong(res);
    return res;
}
void readlong(Tlong &a,string S){
    if (S[0]=='-' || S[0]=='+')
    {
        a.sign=S[0];
        S.erase(0,1);
    }
    a.len=S.size();
    for (int i=0; i<a.len; i++)
        a.num[Nmax-a.len+i]=S[i]-48;
}
void writelong(Tlong a) {
  if (a.sign == '-')
    cout << '-';
  for (int i = Nmax-a.len; i < Nmax; ++i)
    cout << a.num[i];
}
Tlong a;
int main() {
    int N,K;
    cin>>K>>N;
    a.num[Nmax-1]=1;
    for (int i=(N-K+1);i<=N;++i)
        a=multiply(a,i);
    writelong(a);
    return 0;
}
