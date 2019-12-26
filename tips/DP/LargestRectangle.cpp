#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 最大長方形
/*
    上から下のヒストグラムを考える
    列ごとにヒストグラム内の最大長方形を求める
*/

struct Rectangle {int height; int pos;};

int getLargestRectangleHG(int size, int buffer[]){
    stack<Rectangle> S;
    int maxv = 0;
    buffer[size] = 0;

    for(int i=0; i<=size; i++){
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if(S.empty()){
            S.push(rect);
        }else if(S.top().height < rect.height){
            S.push(rect);
        }else if(S.top().height > rect.height){
            // targetを使うことで左端の位置を左に動かしていく
            int target = i;
            while(!S.empty() and S.top().height >= rect.height){
                Rectangle pre = S.top(); S.pop();
                int area = pre.height * (i-pre.pos); // 面積
                chmax(maxv, area);
                target = pre.pos;
            }
            rect.pos = target;
            S.push(rect);
        }
    }
    return maxv;
}

const int MAX = 1400;
int h, w;
int buffer[MAX][MAX];
int T[MAX][MAX];

int getLargestRectangle(){
    // ヒストグラム化して解く

    rep(i, h)rep(j, w){
        if(buffer[i][j]){
            T[i][j] = 0;
        }else{
            // 上下逆のヒストグラム
            T[i][j] = (i>0) ? T[i-1][j]+1 : 1;
        }
    }

    int maxv = 0;
    rep(i, h) chmax(maxv, getLargestRectangleHG(w, T[i]));

    return maxv;
}

int main(){
    cin >> h >> w;
    rep(i, h)rep(j, w) cin >> buffer[i][j];

    cout << getLargestRectangle() << endl;
    return 0;
}