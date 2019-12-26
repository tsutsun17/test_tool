#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    int count = 0; 
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            sum += tmp*b[j];
        }
        if(sum+c > 0){
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}