#include <bits/stdc++.h>
using namespace std;

// DAME:
int main(){
    int n, m;
    cin >> n >> m;
    vector< tuple<int, int, int> > pyi(m);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        pyi[i] = make_tuple(a, b, i);
    }
    sort(pyi.begin(), pyi.end());
    int num = 0;
    // TIPS: tupleに格納されている値はget<i>で指定する
    int x = get<0>(pyi[0]);
    // ans {index, p, num: count}
    vector< vector<int> > ans(m, vector<int>(3));
  
    for(int i=0; i<m; i++){
        int y = get<0>(pyi[i]);
        if(x!=y){
            num = 0;
            x = get<0>(pyi[i]);
        }
        num++;
        int z = get<2>(pyi[i]);
        ans[i][0] = z;
        ans[i][1] = x;
        ans[i][2] = num;
    }

    sort(ans.begin(), ans.end());
  
    for(int i=0; i<m; i++){
        cout << setfill('0') << right << setw(6) << ans[i][1];
        cout << setfill('0') << right << setw(6) << ans[i][2];
        cout << endl;
    }
}
