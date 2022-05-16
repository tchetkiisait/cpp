#include <bits/stdc++.h>
using namespace std;

const int Nmax = 5000;
struct Tlong {
	int len = 1;
	char sign = '+';
	int number[Nmax+1] = {0};
};
void readlong(Tlong &a) {
	string S;
	cin >> S;
	if (S[0] == '-' || S[0] == '+') {
		a.sign = S[0];
		S.erase(0 , 1);
	}
	a.len = S.size();
	for (int i = 0; i < a.len; ++i)
		a.number[Nmax-a.len+i] = S[i] - '0';
}
void writelong(Tlong a) {
	if (a.sign == '-')
		cout << '-';
	for (int i = Nmax-a.len; i < Nmax; ++i)
		cout << a.number[i];
}
int comp_abs(Tlong a , Tlong b) {
    if (a.len > b.len) return 1;
    if (a.len < b.len) return -1;
    int i = Nmax-a.len;
    while (a.number[i] == b.number[i]) ++i;
    if (i == Nmax) return 0;
    if (a.number[i] > b.number[i]) return 1;
    if (a.number[i] < b.number[i]) return -1;
}
int comp(Tlong a , Tlong b) {
    if (a.sign != b.sign) {
        if (a.sign == '+') return 1;
        return -1;
    }
    if (a.sign == '+') return comp_abs(a ,b);
    else return -comp_abs(a , b);
}
int LenLong(Tlong a) {
	a.number[Nmax] = 777;
	int i = 0;
	while (!a.number[i]) ++i;
	if (i == Nmax) return 1;
	return Nmax-i;
}
Tlong add_abs(Tlong a , Tlong b) {
	Tlong res;
	int S , p = 0;
	int len = max(a.len , b.len);
	for (int i = Nmax - 1; i >= Nmax-len-1;--i) {
		S = a.number[i] + b.number[i] + p;
		res.number[i] = S%10;
		p = S/10;
	}
	res.len = LenLong(res);
	return res;
}
Tlong sub_abs(Tlong a , Tlong b) {
	Tlong res;
	int p = 0;
	int len = max(a.len , b.len);
	for (int i = Nmax-1; i >= Nmax-len; --i) {
		res.number[i] = a.number[i] - b.number[i] - p;
		if (res.number[i] < 0) {
			res.number[i] += 10;
			p = 1;
		}
		else p = 0;
	}
	res.len = LenLong(res);
	return res;
}
Tlong add(Tlong a , Tlong b) {
	Tlong res;
	if (a.sign == b.sign) {
		res = add_abs(a ,b);
		res.sign = a.sign;
	}
	else
		if (comp_abs(a , b) == 1) {
			res = sub_abs(a , b);
			res.sign = a.sign;
		}
		else if (comp_abs(a , b) == -1) {
			res = sub_abs(b , a);
			res.sign = b.sign;
		}
	return res;
}
Tlong sub(Tlong a , Tlong b) {
	if (b.sign == '-') b.sign = '+';
	else b.sign = '-';
	return add(a , b);
}
Tlong multy_half(Tlong&a,int b){
    Tlong res;
    int S,p=0;
    for(int i=Nmax-1;i>=0;--i)
    {
        S=a.number[i]*b+p;
        res.number[i]=S%10;
        p=S/10;
    }
    res.len=LenLong(res);
    return res;
}
Tlong multiply(Tlong a,Tlong b){
    Tlong res;
    res.number[Nmax-1]=1;
    for(int i=Nmax-1;i>Nmax-b.len;--i)
        res=add(multy_half(a,b.number[i]),res);
    return res;
}
void clear(Tlong & a) {
  a.sign = '+';
  for (int i=Nmax-a.len; i<Nmax; ++i) a.number[i] = 0;
  a.len = 1;
}

void input_score(Tlong &score , int K) {
    int num;
    clear(score);
    score.number[Nmax-1]=1;
    for (int i=1; i<=K; ++i) {
        cin >> num;
		score=multy_half(score,num);
    }
}

int N,K;
Tlong max_score,score;
int answer=1;
int main() {
    cin>>N>>K;
    input_score(score,K);
    max_score=score;
    for (int i=2;i<=N;++i){
        input_score(score,K);
        if ((comp(score,max_score))==1){
			max_score=score;
        	answer=i;
        }
    }
    cout<< answer;
    return 0;
}