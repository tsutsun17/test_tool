#include <bits/stdc++.h>
using namespace std;

// 約数列挙
vector<int> divisor_list(int n){
    vector<int> ans;
    // 約数のペアの小さい方はi^2までにある
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            int tmp = n/i;
            ans.push_back(tmp);
            ans.push_back(i);
        }
    }

    return ans;
}