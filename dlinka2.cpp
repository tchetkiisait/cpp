#include <bits/stdc++.h>
using namespace std;
class Tlong
{
    static const int nmax=1000000;
    private:
        char sign='+';
        int len=1;
        int num[nmax]={0};
        Tlong sum_abs(Tlong &, Tlong &);
        Tlong minusing_abs(Tlong &,Tlong &);
        int comp_abs(Tlong &,Tlong &);
        int comp(Tlong &,Tlong &);
    public:
        Tlong(int number);
        bool is_minus();
        void making_zero();
        void readlong();
        void writelong();
        void convert_str(string);
        Tlong operator +(Tlong &);
        Tlong operator -(Tlong &);
        Tlong operator *(Tlong &);
        Tlong operator *(int);
        Tlong operator /(int);
        Tlong operator /(Tlong &);
        int operator %(int);
        Tlong operator %(Tlong &);
        bool is_zero();
        void operator ++();
        void operator --();
        bool operator >(Tlong &);
        bool operator <(Tlong &);
        bool operator ==(Tlong &);
        bool operator >=(Tlong &);
        bool operator !=(Tlong &);
        bool operator <=(Tlong &);
        
};

Tlong::Tlong(int number = 0) {
  len = 0;
  if (number < 0) {
    sign = '-';
    number = abs(number);
  }
  else sign = '+';
  if (number == 0) ++len;
  while (number) {
    num[nmax-1-len++] = number%10;
    number/=10;
  }
}

bool Tlong::is_minus(){
    if(sign=='-')
        return 1;
    return 0;
}

void Tlong::convert_str(string s){
    if(s[0]=='-' ||  s[0]=='+'){
        sign=s[0];
        s.erase(0,1);
    }
    else sign='+';
    len=s.size();
    for(int i=0;i<len;++i)
        num[nmax-len+i]=s[i]-48;
}

bool Tlong::is_zero(){
    if(len==1 && num[nmax-1]==0) return 1;
    return 0;
}

void Tlong::readlong(){
   string s;
   cin >> s;
   if(s[0]=='-' || s[0]=='+'){
       sign=s[0];
       s.erase(0,1);
   }
   len=s.size();
   for(int i=0;i<len;++i)num[nmax-len+i]=s[i]-48;
}

void Tlong::writelong()
{
    if(sign=='-')
        cout << sign;
    for(int i=len;i>0;--i)
        cout << num[nmax-i];
}

void Tlong::making_zero()
{
   fill(num+nmax-len-15,num+nmax-2,0);
   len=1;
   sign='+';
}

int Tlong::comp_abs(Tlong &a,Tlong &b)
{
   if(a.len>b.len) return 1;
   if(a.len<b.len) return -1;
   else{
       for(int i=a.len;i>0;--i){
           if(a.num[nmax-i]>b.num[nmax-i])return 1;
           if(a.num[nmax-i]<b.num[nmax-i])return -1;
       }
   }
   return 0;
}

int Tlong::comp(Tlong &a,Tlong &b){
   if(a.sign!=b.sign){
       if(a.sign=='+')
           return 1;
       return -1;
   }
   else {
       if(a.sign=='+')
           return comp_abs(a,b);
       else
           return -comp_abs(a,b);
   }
}

Tlong Tlong::minusing_abs(Tlong &a,Tlong &b){
   Tlong c;
   Tlong t;
   c.sign='+';
   if(comp_abs(a,b)==1){
       t=a;
       c.len=t.len;
       for(int i=1;i<=t.len;++i){
           if(t.num[nmax-i]<b.num[nmax-i]){
               --t.num[nmax-i-1];
               t.num[nmax-i]+=10;
            }
            c.num[nmax-i]=t.num[nmax-i]-b.num[nmax-i];
       }
   }
   if(comp_abs(a,b)==-1){
       t=b;
       c.sign='-';
       c.len=t.len;
       for(int i=1;i<=t.len;++i){
           if(t.num[nmax-i]<a.num[nmax-i]){
               --t.num[nmax-i-1];
               t.num[nmax-i]+=10;
           }
           c.num[nmax-i]=t.num[nmax-i]-a.num[nmax-i];
       }
   }
   while(c.num[nmax-c.len]==0)
       --c.len;
   if(comp_abs(a,b)==0)
   {
       c.len=1;
       c.making_zero();
   }
   return c;
}

Tlong Tlong::sum_abs(Tlong &a,Tlong &b){
   Tlong c;
   int len_=max(a.len,b.len);
   c.len=len_+2;
   c.sign='+';
   for(int i=1;i<=c.len;++i)
   {
       c.num[nmax-i]+=a.num[nmax-i]+b.num[nmax-i];
       c.num[nmax-i-1]+=c.num[nmax-i]/10;
       c.num[nmax-i]%=10;
   }
   while(c.num[nmax-c.len]==0 && c.len>1)
       --c.len;
   if(!c.len)
       --c.len;
   return c;
}

Tlong Tlong::operator +(Tlong &b){
    Tlong c;
    if(sign==b.sign)
    {
        c=sum_abs(*this,b);
        c.sign=sign;
    }
    else{
        if(sign=='+')c=minusing_abs(*this,b);
        else c=minusing_abs(b,*this);
    }
    return c;
}


Tlong Tlong::operator -(Tlong &b){
    Tlong c;
    char bsign=b.sign;
    if(b.sign=='-')
        b.sign='+';
    else
        b.sign='-';
    c=*this+b;
    b.sign=bsign;
    return c;
}

Tlong Tlong::operator *(int b){
    Tlong c;
    char bsign='+';
    if(b<0)
    {
        bsign='-';
        b*=-1;
    }
    c.sign='+';
    if(sign!=bsign)
        c.sign='-';
    c.len=len+10;
    for(int i=1;i<=c.len;++i)
    {
        c.num[nmax-i]+=num[nmax-i]*b;
        c.num[nmax-i-1]+=c.num[nmax-i]/10;
        c.num[nmax-i]%=10;
    }
    while(c.num[nmax-c.len]==0 && c.len>1)
        --c.len;
    return c;
}

Tlong Tlong::operator *(Tlong &b){
    Tlong c;
    c.len=len+b.len;
    c.sign='-';
    if(sign==b.sign)
        c.sign='+';
    for(int i=1;i<=len;++i)
        for(int j=1;j<=b.len;++j)
            c.num[nmax-i-j+1]+=num[nmax-i]*b.num[nmax-j];
    for(int i=1;i<=c.len;++i)
    {
        c.num[nmax-i-1]+=c.num[nmax-i]/10;
        c.num[nmax-i]%=10;
    }
    while(c.num[nmax-c.len]==0 && c.len>1)
        --c.len;
    if(c.len==1 && c.num[nmax-1]==0)
        c.sign='+';
    return c;
}

Tlong Tlong::operator /(int b){
    int temp;
    char bsign='+';
    if(b<0){
        bsign='-';
        b*=-1;
    }
    Tlong c;
    c.len=len;
    if(sign!=bsign)
        c.sign='-';
    for(int i=len;i>1;--i)
    {
        temp=num[nmax-i]+c.num[nmax-i];
        c.num[nmax-i]=temp/b;
        c.num[nmax-i+1]+=10*(temp%b);
    }
    c.num[nmax-1]+=num[nmax-1];
    c.num[nmax-1]/=b;
    while(c.num[nmax-c.len]==0 && c.len>1)
        --c.len;
    return c;
}

int Tlong::operator %(int b){
    Tlong c;
    c=*this;
    int temp;
    for(int i=c.len;i>1;--i)
    {
        temp=c.num[nmax-i];
        c.num[nmax-i+1]+=10*(temp%b);
    }
    return c.num[nmax-1]%=b;
}

Tlong Tlong::operator /(Tlong &b){
    Tlong ost,c;
    c.len=len;
    char bsign=b.sign,asign=sign;
    if(sign!=b.sign)
        c.sign='-';
    b.sign='+';
    sign='+';
    for(int i=nmax-len;i<nmax;++i)
    {
        ++ost.len;
        for (int j=nmax-ost.len;j<nmax-1;++j)
            ost.num[j]=ost.num[j+1];
        if(ost.len==2 && ost.num[nmax-2]==0)
            ost.len--;
        ost.num[nmax-1]=num[i];
        int cnt=0;
        while(comp_abs(ost,b)!=-1)
        {
            ost=ost-b;;
            cnt++;
        }
        c.num[i]=cnt;
    }
    while(c.num[nmax-c.len]==0 && c.len>1)
        c.len--;
    b.sign=bsign;
    sign=asign;
    ost.sign=asign;
    if(c.is_zero())
        c.sign='+';
    return c;
}

Tlong Tlong::operator %(Tlong &b){
    Tlong ost,c;
    c.len=len;
    char bsign=b.sign,asign=sign;
    if(sign!=b.sign)c.sign='-';
    b.sign='+';
    sign='+';
    for(int i=nmax-len;i<nmax;++i){
        ++ost.len;
        for (int j=nmax-ost.len;j<nmax-1;++j)
            ost.num[j]=ost.num[j+1];
        if(ost.len==2 && ost.num[nmax-2]==0)
            ost.len--;
        ost.num[nmax-1]=num[i];
        int cnt=0;
        while(comp_abs(ost,b)!=-1)
        {
            ost=ost-b;;
            cnt++;
        }
        c.num[i]=cnt;
    }
    b.sign=bsign;
    sign=asign;
    ost.sign=asign;
    if(ost.is_zero())
    {
        ost.sign='+';
    }
    return ost;
}

Tlong fact(int n){
    Tlong a;
    a.convert_str("1");
    for(int i=2;i<=n;i++)
        a=a*i;
    return a;
}

void Tlong::operator++(){
    if(sign=='+'){
        int pos=nmax-1;
        num[nmax-len-1]=0;
        while(num[pos]==9){
            num[pos]=0;
            --pos;
        }
        ++num[pos];
        if(num[nmax-len-1]==1)++len;
    }
    else{
        int pos=1;
        while(num[nmax-pos]==0){
            num[nmax-pos]=9;
            pos++;
        }
        --num[nmax-pos];
        if(num[nmax-len]==0)--len;
    }
}

void Tlong::operator --(){
    char asign=sign;
    if(sign=='+') sign='-';
    else sign='+';
    ++*this;
    sign=asign;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Tlong answer,a,b;
    a.readlong();
    b.readlong();
    answer=(a*b);
    ++a;
    ++b;
    answer=answer*a;
    answer=answer*b;
    answer=answer/4;
    answer.writelong();
    return 0;
}
