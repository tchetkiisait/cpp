#include <bits/stdc++.h>
using namespace std;
const static int Nmax=10000;
class Tlong {
    private:
        int len;
        char sign;
        int num[Nmax];
        int comp_abs(Tlong&a,Tlong&b);
        int comp(Tlong&a,Tlong&b);
        int LenLong();
        Tlong add_abs(Tlong&a,Tlong&b);
        Tlong sub_abs(Tlong&a,Tlong&b);
    public:
        Tlong(){
            sign='+';
            len=1;
            for (int i=0;i<Nmax;i++)
                num[i]=0;
        }
        void readlong();
        void writelong();
        Tlong operator+(Tlong&b);
        Tlong operator-(Tlong&b);
        Tlong operator*(int b);
        Tlong operator*(Tlong&b);
        Tlong operator/(int b);
        Tlong operator/(Tlong&);
        int   operator%(int b);
        Tlong operator%(Tlong&);
        void  operator++();
        void  operator--();
        bool  operator>(Tlong&);
        bool  operator<(Tlong&);
        bool  operator==(Tlong&);
        bool  operator>=(Tlong&);
        bool  operator!=(Tlong&);
        bool  operator<=(Tlong&);
        bool  is_zero();
};
void  Tlong::readlong(){
	string S;   cin>>S;
	if(S[0]=='-' || S[0]=='+'){
	    sign=S[0];
		S.erase(0,1);
	}
	len=S.size();
	for(int i=0;i<len;++i)
		num[Nmax-len+i]=S[i]-'0';
}
void  Tlong::writelong(){
	if(sign=='-')   cout<<'-';
	for(int i=Nmax-len;i<Nmax;++i)
		cout<<num[i];
}
int   Tlong::comp_abs(Tlong&a,Tlong&b){
    if(a.len>b.len)return 1;
    if(a.len<b.len)return -1;
    for(int i=Nmax-a.len;i<Nmax;++i){
        if(a.num[i]>b.num[i])return 1;
        if(a.num[i]<b.num[i])return -1;
    }
    return 0;
}
int   Tlong::comp(Tlong&a,Tlong&b){
    if(a.sign!=b.sign){
        if(a.sign == '+')return 1;
        return-1;
    }
    if(a.sign=='+')return comp_abs(a,b);
    else return-comp_abs(a,b);
}
int   Tlong::LenLong(){
	num[Nmax]=777; int i=0;
	while(!num[i])++i;
	if(i==Nmax)return 1;
	return Nmax-i;
}
Tlong Tlong::add_abs(Tlong&a,Tlong&b){
	Tlong res;
	int S,p=0;
	int len=max(a.len,b.len);
	for (int i=Nmax-1;i>=Nmax-len-1;--i) {
		S=a.num[i]+b.num[i]+p;
		res.num[i]=S%10;
		p=S/10;
	}
	res.len=res.LenLong();
	return res;
}
Tlong Tlong::sub_abs(Tlong&a,Tlong&b){
	Tlong res;
	int p=0;
	int len=max(a.len , b.len);
	for (int i=Nmax-1;i>=Nmax-len; --i) {
		res.num[i]=a.num[i]-b.num[i]-p;
		if(res.num[i]<0){
			res.num[i]+=10;
			p=1;
		}
		else p=0;
	}
	res.len=res.LenLong();
	return res;
}
bool Tlong::is_zero(){
    if(len==1 && num[Nmax-1]==0)
        return 1;
    return 0;
}
Tlong Tlong::operator-(Tlong&b){
	if (b.sign == '-') b.sign = '+';
	else b.sign = '-';
	return (*this+b);
}
Tlong Tlong::operator+(Tlong&b){
	Tlong res;
	if (sign==b.sign) {
		res=add_abs(*this,b);
		res.sign=sign;
	}
	else
		if (comp_abs(*this,b)==1) {
			res=sub_abs(*this, b);
			res.sign=sign;
		}
		else if (comp_abs(*this,b) == -1) {
			res=sub_abs(b,*this);
			res.sign=b.sign;
		}
	return res;
}
Tlong Tlong::operator*(int b){
    Tlong c;
    char bsign='+';
    if(b<0){
        bsign='-';
        b*=-1;
    }
    c.sign='+';
    if(sign!=bsign) c.sign='-';
    c.len=len+10;
    for(int i=1;i<=c.len;++i){
        c.num[Nmax-i]+=num[Nmax-i]*b;
        c.num[Nmax-i-1]+=c.num[Nmax-i]/10;
        c.num[Nmax-i]%=10;
    }
    while(c.num[Nmax-c.len]==0 && c.len>1)
        --c.len;
    return c;
}
Tlong Tlong::operator*(Tlong&b){
    Tlong c;
    c.len=len+b.len;
    c.sign='-';
    if(sign==b.sign)
        c.sign='+';
    for(int i=1;i<=len;++i)
        for(int j=1;j<=b.len;++j)
            c.num[Nmax-i-j+1]+=num[Nmax-i]*b.num[Nmax-j];
    for(int i=1;i<=c.len;++i){
        c.num[Nmax-i-1]+=c.num[Nmax-i]/10;
        c.num[Nmax-i]%=10;
    }
    while(c.num[Nmax-c.len]==0 && c.len>1)
        --c.len;
    if(c.len==1 && c.num[Nmax-1]==0)
        c.sign='+';
    return c;
}
Tlong Tlong::operator/(int b){
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
    for(int i=len;i>1;--i){
        temp=num[Nmax-i]+c.num[Nmax-i];
        c.num[Nmax-i]=temp/b;
        c.num[Nmax-i+1]+=10*(temp%b);
    }
    c.num[Nmax-1]+=num[Nmax-1];
    c.num[Nmax-1]/=b;
    while(c.num[Nmax-c.len]==0 && c.len>1)
        --c.len;
    return c;
}
Tlong Tlong::operator/(Tlong&b){
    Tlong ost,c;
    c.len=len;
    char bsign=b.sign,asign=sign;
    if(sign!=b.sign)
        c.sign='-';
    b.sign='+';
    sign='+';
    for(int i=Nmax-len;i<Nmax;++i){
        ++ost.len;
        for (int j=Nmax-ost.len;j<Nmax-1;++j)
            ost.num[j]=ost.num[j+1];
        if(ost.len==2 && ost.num[Nmax-2]==0)
            ost.len--;
        ost.num[Nmax-1]=num[i];
        int cnt=0;
        while(comp_abs(ost,b)!=-1){
            ost=ost-b;;
            cnt++;
        }
        c.num[i]=cnt;
    }
    while(c.num[Nmax-c.len]==0 && c.len>1)
        c.len--;
    b.sign=bsign;
    sign=asign;
    ost.sign=asign;
    if(c.is_zero())
        c.sign='+';
    return c;
}
int   Tlong::operator%(int b){
    Tlong c;
    c=*this;
    int temp;
    for(int i=c.len;i>1;--i){
        temp=c.num[Nmax-i];
        c.num[Nmax-i+1]+=10*(temp%b);
    }
    return c.num[Nmax-1]%=b;
}
Tlong Tlong::operator%(Tlong&b){
    Tlong ost,c;
    c.len=len;
    char bsign=b.sign,asign=sign;
    if(sign!=b.sign)
        c.sign='-';
    b.sign='+';
    sign='+';
    for(int i=Nmax-len;i<Nmax;++i){
        ++ost.len;
        for (int j=Nmax-ost.len;j<Nmax-1;++j)
            ost.num[j]=ost.num[j+1];
        if(ost.len==2 && ost.num[Nmax-2]==0)
            ost.len--;
        ost.num[Nmax-1]=num[i];
        int cnt=0;
        while(comp_abs(ost,b)!=-1){
            ost=ost-b;;
            cnt++;
        }
        c.num[i]=cnt;
    }
    b.sign=bsign;
    sign=asign;
    ost.sign=asign;
    if(ost.is_zero())
        ost.sign='+';
    return ost;
}
void  Tlong::operator++(){
    if(sign=='+'){
        int pos=Nmax-1;
        num[Nmax-len-1]=0;
        while(num[pos]==9){
            num[pos]=0;
            --pos;
        }
        ++num[pos];
        if(num[Nmax-len-1]==1){
            ++len;
        }
    }
    else{
        int pos=1;
        while(num[Nmax-pos]==0){
            num[Nmax-pos]=9;
            pos++;
        }
        --num[Nmax-pos];
        if(num[Nmax-len]==0)
            --len;
    }
}
void  Tlong::operator--(){
    char asign=sign;
    if(sign=='+') sign='-';
    else sign='+';
    ++*this;
    sign=asign;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Tlong a,b,res,resfact; int c;
    a.readlong();  b.readlong();  cin>>c;
    res=a+b; a.writelong(); cout<<"+("; b.writelong(); cout<<")="; res.writelong();
    res=a-b; a.writelong(); cout<<"-("; b.writelong(); cout<<")="; res.writelong();
    res=a*b; a.writelong(); cout<<"*("; b.writelong(); cout<<")="; res.writelong();
    res=a/b; a.writelong(); cout<<"/("; b.writelong(); cout<<")="; res.writelong();
}
