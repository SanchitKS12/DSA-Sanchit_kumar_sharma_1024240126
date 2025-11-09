#include<bits\stdc++.h>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *left, *right;
    BSTNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(BSTNode* node, long long minAllowed, long long maxAllowed) {
    if (!node) return true;
    if (node->key <= minAllowed || node->key >= maxAllowed) return false;
    return isBSTUtil(node->left, minAllowed, node->key) &&
           isBSTUtil(node->right, node->key, maxAllowed);
}

bool isBST(BSTNode* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}