#include <bits/stdc++.h>
using namespace std;

int a,b,l,max_num,min_num,res;
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,comp;
    cin>>N;
    cin>>a>>b;
    if (a>b) swap(a,b);
    max_num=b;
    min_num=a;
    for (int i=1; i<N; ++i){
        cin>>a>>b;
        if (a>b) swap(a,b);
        if (b>max_num) swap(b,max_num);
        if (a<min_num) swap(a,min_num);
    }
    cin>>l;
    res=max_num-min_num-1;
    cout<<(res);
    cout<<'\n';
    if (res>l) cout<<"He had overdone the plan.";
    if (res<l) cout<<"He didn’t cope with the plan.";
    if (res==l) cout<<"He had managed with the plan.";
	return 0;
}
