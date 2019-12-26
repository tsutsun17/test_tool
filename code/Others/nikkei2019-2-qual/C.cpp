#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// DAME:
/*
    n-1回のswapでどんな順番にすることができることは自明 -> 最高n-1回
    今回はn-2回

    1. A, Bをソートして対応させた時に B_i >= A_iが満たされなかったら "No"
    2. A, Bのソート順に対応させるために何回swapするのかを巡回置換をサイクル分解することで求める
        (サイクル分解の方法)
            1. A, Bの元のindexを取得、
            2. 隣接リスト表現のように,ソートしたA_i、B_iに対応するindexを
                    G[A_iのindex] = B_iのindex
               のように格納する
            3. 任意の数字aで, G[a]からindexを辿り、G[b] = aとなるまで続ける
            4. その時に、全てのindexを使用した場合は、サイクルが1個しか存在しないことがわかる

    3. 2.で求めた時にサイクルが２個以上になったら、n-2以下になるため "Yes"
    4. サイクルが１個の時は、ソートにn-1回かかることがわかるため、ソートから一回でもswapできれば、n-2以下にすることができる
    5. ソート順 A_{i+1} <= B_{i}が一つでもあれば、A_{i+1}を一個左(A_{i+1}とB_iを対応)にずらすことが可能 -> n-2以下にすることができる
    6. それ以外の場合は、ソート順のみ A_i <= B_i　を満たすが、ソートさせるにはn-1回のswapが必要なため, "No"
*/

int main() {
    int n;
    cin >> n;
    vector<pair<ll, int>> A(n), B(n);
    rep(i, n){
        ll tmp;
        cin >> tmp;
        A[i] = make_pair(tmp, i);
    }
    rep(i, n){
        ll tmp;
        cin >> tmp;
        B[i] = make_pair(tmp, i);
    }

    sort(A.begin(), A.end()); sort(B.begin(), B.end());

    // 最低条件
    rep(i, n){
        if(A[i].first > B[i].first){
            cout << "No" << endl;
            return 0;
        }
    }

    // 巡回置換の表示
    vector<int> G(n);
    rep(i, n) G[A[i].second] = B[i].second;

    // サイクルが1個かどうか
    int cur = G[0];
    int count = 0;
    rep(i, n){
        if(cur == 0) break;
        cur = G[cur];
        count++;
    }

    // サイクルが2個以上あったらYes
    if(count < n-1){
        cout << "Yes" << endl;
        return 0;
    }

    // ソート順から一回以上swapできるかどうか
    rep(i, n-1){
        if(A[i+1].first <= B[i].first){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}