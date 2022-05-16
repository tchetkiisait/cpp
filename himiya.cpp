#include <bits/stdc++.h>
using namespace std;

const int Nmax = 10000;
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
	res.len = len;
    if (res.number[Nmax-len-1]) ++res.len;
	return res;
}
int N;
Tlong curr,temp1,temp;
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    curr.number[Nmax-1]=1;
    temp1.number[Nmax-1]=2;
    for (int i=1; i<N; ++i){
    	temp=add_abs(curr,temp1);
    	curr=temp1;
    	temp1=temp;
    }
    writelong(temp);
    return 0;
}