#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// ヒストグラム内の最大長方形
// http://algorithms.blog55.fc2.com/blog-entry-132.html
/*
    部分問題の未解決の解をスタックに記憶していく
    スタックには、長方形の高さと位置の情報を記録していく

    スタックをからにして、各長方形rectを左から右へ向かって以下の処理を行う

    1. スタックがからの場合
        スタックにrectを追加する
    2. スタックの頂点にある長方形の高さがrectの高さより低い場合
        スタックにrectを追加する
    3. スタックの頂点にある長方形の高さがrectの高さと等しい場合
        何もしない
    4. スタックの頂点にある長方形の高さがrectの高さよりも高い場合
        - スタックが空でなく、スタックの頂点にある長方形の高さがrectの高さ以上である限り、スタックから長方形を取り出し、その面積を計算し最大値を更新する。長方形の横の長さは現在の位置iと記録されている左端の位置posから計算できる
        - スタックにrectを追加する。ただし、rectの左端の位置posは最後にスタックから取り出した長方形のposの値とする
*/

struct Rectangle{ int height; int pos; }; // 高さ, 左端の位置

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

int main(){

    return 0;
}