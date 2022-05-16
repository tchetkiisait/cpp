#include <bits/stdc++.h>
using namespace std;

void password_out(string s, string num[], int password_number[], bool& flag){
    int dig = -1;
    for (int j = 0; j < 8; ++j){
        dig = -1;
        for (int i = 0; i < 10; ++i){
            if (num[i] == string(s.begin() + j * 10, s.begin() + j * 10 + 10))
            dig = i;
        }
        if (dig == -1)flag = false;
        else password_number[j] = dig;
    }
    if (flag)
        for (int i = 0; i < 8; ++i)
            cout << password_number[i];
}


int main()
{
    string s;
    string num[10];
    int num_in_pass[8];
    bool flag = true;
    cin >> s;
    for (int i = 0; i < 10; ++i)
        cin >> num[i];
    password_out(s, num, num_in_pass, flag);
    if (!flag) cout << -1;

    return 0;
}
