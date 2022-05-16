#include <bits/stdc++.h>
using namespace std;

const int Nmax = 500;
struct Tlong{
    char sign = '+';
    int len = 1;
    int number[Nmax] = {0}; 
};

void writelong(Tlong a){
  if(a.sign == '-')
    cout<<'-';
  for(int i = Nmax - a.len; i < Nmax; i++)
    cout<<a.number[i];
}
int LenLong(Tlong &a){
    int i = 0;
    while(i < Nmax - 1 && a.number[i] == 0) ++i;
    return Nmax-i;
}
Tlong add_abs(Tlong&a,Tlong&b){
    Tlong res;
    int S = 0,p = 0;
    for(int i = Nmax - 1; i >= 0; --i)
    {
        S = a.number[i] + b.number[i] + p;
        res.number[i] = S % 10;
        p = S / 10;
    }
    res.len = LenLong(res);
    res.sign = '+';
    return res;
}
void clear(Tlong & a){
  a.sign = '+';
  for (int i = Nmax-a.len; i < Nmax; ++i) a.number[i] = 0;
  a.len = 1;
}
Tlong fibb(int stairs){
  int stair;
  Tlong curr,temp,res;
  curr.number[Nmax-1] = 1;
  for (int i=0; i<stairs; ++i){
    cin>>stair;
    if(stair){
      res=add_abs(curr, temp);
      curr=temp;
      temp=res;
    }
    else {
      curr=temp;
      clear(temp);
    }
  }
  return res;
}

int main()
{
  int stairs;
  cin>>stairs;
  writelong(fibb(stairs));
}