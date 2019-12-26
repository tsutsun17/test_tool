#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// TIPS: 全探索かい
int main() {
    int A, B, C, D, E, F;
    int water = 0;
    int sugar = 0;
    double nodo = -1;
    cin >> A >> B >> C >> D >> E >> F;

    for(int a=0; a<101; a++){
        for(int b=0; b<101; b++){
            for(int c=0; c<101; c++){
                for(int d=0; d<101; d++){
                    if(a==0 && b==0 && c==0 && d==0){
                        continue;
                    }
                    if((A*a + B*b)*100 + C*c + D*d > F || C*c+D*d > (A*a + B*b)*E){
                        continue;
                    }
                    if((double)(C*c+D*d)/((A*a+B*b)*100+C*c+D*d) > nodo){
                        water = (A*a+B*b)*100;
                        sugar = (C*c+D*d);
                        nodo = (double)sugar/(water + sugar);
                    }
                }
            }
        }
    }

    cout << water+sugar << ' ' << sugar << endl;

    return 0;
}
