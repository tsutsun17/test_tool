#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int MAX = 100005;
const int NIL = -1;

struct Node {
    int p;  // parent
    int l;  // left: 最も左の子
    int r;  // right: すぐ右の兄弟
};

vector<Node> tree;

int rec(int u, int p, vector<int>& depth){
    depth[u] = p;
    if(tree[u].r != NIL) rec(tree[u].r, p, depth); // 右の兄弟にも同じふかさを設定
    if(tree[u].l != NIL) rec(tree[u].l, p+1, depth); // 最も左の子に自分の深さ+1を設定
}

int main(){
    int n, root;
    cin >> n;
    tree.resize(n, Node{NIL, NIL, NIL});

    rep(i, n){
        int id, k, left; // id, 次数, 左の要素
        cin >> id >> k;
        rep(j, k){
            int child;
            cin >> child;
            if(j==0) tree[id].l = child; // idの最も左の子要素
            else tree[left].r = child; // leftの兄弟要素

            left = child;
            tree[child].p = id;
        }
    }

    // rootの検索
    rep(i, n){
        if(tree[i].p == NIL) root=i;
    }

    // それぞれの深さを調べる
    vector<int> depth(n);
    rec(root, 0, depth);

    return 0;
}