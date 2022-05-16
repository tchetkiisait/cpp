#include <bits/stdc++.h>
using namespace std;

bool normal_word(string S){
    int i;
    while(!S.empty()){
        bool checker = true;
        while((i = S.find("~@")) != -1 || (i = S.find("#$")) != -1 || (i = S.find("%&")) != -1){
	    checker = false;
            S.erase(i, 2);
        }
        if(checker)return false;
    }
    return true;
}

int main()
{
    string word;
    while(cin>>word){
        if(normal_word(word))cout<<"OK";
        else cout<<"WRONG";
	cout<<'\n';
    }
}
