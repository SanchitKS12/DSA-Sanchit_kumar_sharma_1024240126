#include <bits/stdc++.h>
using namespace std;

//(Insert, Delete, Max Depth, Min Depth)
struct BSTNode {
    int key;
    BSTNode *left, *right;
    BSTNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

BSTNode* bstInsert(BSTNode* root, int key) {
    if (!root) return new BSTNode(key);
    if (key < root->key) root->left = bstInsert(root->left, key);
    else if (key > root->key) root->right = bstInsert(root->right, key);
    return root;
}

BSTNode* findMinNode(BSTNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

bool isBST(BSTNode* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

BSTNode* bstDelete(BSTNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) root->left = bstDelete(root->left, key);
    else if (key > root->key) root->right = bstDelete(root->right, key);
    else {
        if (!root->left) {
            BSTNode* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            BSTNode* l = root->left;
            delete root;
            return l;
        } else {
            BSTNode* succ = findMinNode(root->right);
            root->key = succ->key;
            root->right = bstDelete(root->right, succ->key);
        }
    }
    return root;
}

int maxDepth(BSTNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(BSTNode* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorderPrint(BSTNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->key << " ";
    inorderPrint(root->right);
}

void freeBST(BSTNode* root) {
    if (!root) return;
    freeBST(root->left);
    freeBST(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // BST demonstration
    cout << "=== BST demo ===\n";
    BSTNode* root = nullptr;
    vector<int> arr = {50, 30, 20, 40, 70, 60, 80};
    for (int v : arr) root = bstInsert(root, v);
    cout << "Inorder (should be sorted): ";
    inorderPrint(root);
    cout << "\n";
    cout << "Max depth (nodes): " << maxDepth(root) << "\n";
    cout << "Min depth (nodes): " << minDepth(root) << "\n";
    cout << "Deleting 20, 30, 50 (root) sequentially...\n";
    root = bstDelete(root, 20);
    root = bstDelete(root, 30);
    root = bstDelete(root, 50);
    cout << "Inorder after deletes: ";
    inorderPrint(root);
    cout << "\n";
    cout << "Is tree a BST? " << (isBST(root) ? "Yes" : "No") << "\n";

    // Check non-BST
    BSTNode* nonbst = new BSTNode(10);
    nonbst->left = new BSTNode(5);
    nonbst->right = new BSTNode(20);
    nonbst->left->right = new BSTNode(15);
    cout << "Is constructed non-bst tree a BST? " << (isBST(nonbst) ? "Yes" : "No") << "\n";
    freeBST(root);
    freeBST(nonbst);
    return 0;
}