#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int MAX = 100005;
const int NIL = -1;

// 二分木
struct Node {
    int parent; // 親
    int left;   // 左の子要素
    int right;  // 右の子要素
};

vector<Node> tree;
vector<int> depth, height;

// 深さ
void setDepth(int u, int d){
    if(u==NIL) return;
    depth[u] = d;
    setDepth(tree[u].left, d+1);
    setDepth(tree[u].right, d+1);
}

// 高さ
int setHeight(int u){
    int h1=0, h2=0;
    if(tree[u].left != NIL) h1 = setHeight(tree[u].left) + 1;
    if(tree[u].right != NIL) h2 = setHeight(tree[u].right) + 1;

    return height[u] = max(h1, h2);
}

// 節点 u　の兄弟を返す
int getSibling(int u){
    if(tree[u].parent == NIL)  return NIL;

    if(tree[tree[u].parent].left != u && tree[tree[u].parent].left != NIL){
        return tree[tree[u].parent].left;
    }

    if(tree[tree[u].parent].right != u && tree[tree[u].parent].right != NIL){
        return tree[tree[u].parent].right;
    }

    return NIL;
}

void print(int u){
    cout << "node" << u << ": ";
    cout << "parent = " << tree[u].parent << " ";
    cout << "sibling = " << getSibling(u) << " ";
    int deg = 0;
    if(tree[u].left != NIL) deg++;
    if(tree[u].right != NIL) deg++;

    cout << "degree = " << deg << " ";
    cout << "depth = " << depth[u] << " ";
    cout << "height = " << height[u] << " ";

    if(tree[u].parent == NIL){
        cout << "root" << endl;
    }else if (tree[u].left == NIL and tree[u].right == NIL){
        cout << "leaf" << endl;
    }else{
        cout << "internal node" << endl;
    }
}

int main(){
    int n, root;
    cin >> n;
    depth.resize(n, 0); height.resize(n, 0); tree.resize(n, Node{NIL, NIL, NIL});
    rep(i, n) tree[i].parent = NIL;

    rep(i, n){
        int id, left, right;
        cin >> id >> left >> right;
        tree[id].left = left;
        tree[id].right = right;

        if(left != NIL) tree[left].parent = id;
        if(right != NIL) tree[right].parent = id;
    }

    // root
    rep(i, n){
        if(tree[i].parent == NIL) root = i;
    }

    // 深さ
    setDepth(root, 0);
    // 高さ
    setHeight(root);

    rep(i, n){
        print(i);
    }
}
