#include <bits/stdc++.h>
using namespace std;

int roman_to_int(string s){
    map<char, int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C', 100},{'D', 500},{'M', 1000}};
    int answer=0;
    for(int i=0;i<s.length();i++){
        if(m[s[i+1]]<=m[s[i]]) answer+=m[s[i]]; 
        else answer-=m[s[i]];  
    }
    return answer;
}

int main(){
	string roman;
	getline(cin,roman);
	cout<<roman_to_int(roman);
	return 0;
}
