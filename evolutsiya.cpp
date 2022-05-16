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
    if (a.number[Nmax] == b.number[Nmax]) {
        a.number[Nmax] = 1;
        b.number[Nmax] = 2;
    }
    if (a.len > b.len) return 1;
    if (a.len < b.len) return -1;
    int i = Nmax-a.len;
    while (a.number[i] == b.number[i]) ++i;
    if (i == Nmax) return 0;
    if (a.number[i] > b.number[i]) return 1;
    return -1;
}
int LenLong(Tlong a) {
	a.number[Nmax] = 777;
	int i = 0;
	while (!a.number[i]) ++i;
	if (i == Nmax) return 1;
	return Nmax-i;
}
Tlong divmod_short(Tlong a, int b){ 
    Tlong res;  
    int ost;
    ost=0;
    for (int i=Nmax-a.len; i<Nmax; i++){ 
        ost=ost*10+a.number[i]; 
        res.number[i]=ost/b;
        ost=ost%b; 
    } 
    res.len=LenLong(res); 
    return res; 
}

int main() {
    Tlong a,b;
    int J,compare;
    cin>>J;
    readlong(a);
    readlong(b);
    compare=comp_abs(a,b);
    while ((compare==1)||(compare==-1)){
        if (compare==-1) b=(divmod_short(b,2));
        else a=(divmod_short(a,2));
        compare=(comp_abs(a,b));
    }
    writelong(a);
    return 0;
}
