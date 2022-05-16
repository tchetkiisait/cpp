#include <bits/stdc++.h>
using namespace std;

bool leap_year(int year){
    if((year%4==0&&year%100!=0)||year%400==0)return true;
    return false;
}

bool is_data(string S){
    cin>>S;
    int day,month,year;
    day=(S[9]-'0')*10+(S[8]-'0');
    month=(S[7]-'0')*10+(S[6]-'0');
    year=(S[4]-'0')*1000+(S[3]-'0')*100+(S[1]-'0')*10+(S[0]-'0');
    if(month>12)return false;
    if(month==4||month==6||month==9||month==11){
        if(day<=30)return true;
        else return false;
    }
    if(month==2){
        if(leap_year(year))
        {
            if(day<=29)return true;
            else return false;
        }
        if(day<=28)return true;
        else return false;
    }
    if(day<=31)return true;
    return false;
}

int main()
{
    int N;
    string S;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        if(is_data(S))cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}
