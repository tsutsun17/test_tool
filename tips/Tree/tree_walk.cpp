#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int MAX = 100005;
const int NIL = -1;

// 二分木の巡回 O(n)
/*
    根節点 -> 左部分木 -> 右部分木
        先行順巡回(Preorder)
    左部分木 -> 根節点 -> 右部分木
        中間順巡回(Inorder)
    左部分木 -> 右部分木 -> 根節点
        後行順巡回(Postorder)
*/

struct Node {
    int parent;
    int left;
    int right;
};

vector<Node> tree;

// Preorder
void preParse(int u){
    if(u==NIL) return;
    cout << u << " ";
    preParse(tree[u].left);
    preParse(tree[u].right);
}

// Inorder
void inParse(int u){
    if(u==NIL) return;
    inParse(tree[u].left);
    cout << u << " ";
    inParse(tree[u].right);
}

// Postorder
void postParse(int u){
    if(u==NIL) return;
    postParse(tree[u].left);
    postParse(tree[u].right);
    cout << u << " ";
}


int main(){
    int n, root;
    cin >> n;
    tree.resize(n, Node{NIL, NIL, NIL});
    rep(i, n){
        int id, left, right;
        cin >> id >> left >> right;
        tree[id].left = left;
        tree[id].right = right;
        if(left!=NIL) tree[left].parent = id;
        if(right!=NIL) tree[right].parent = id;
    }

    rep(i, n){
        if(tree[i].parent == NIL) root = i;
    }

    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;

    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;

    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;

    return 0;

}