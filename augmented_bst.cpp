#include <bits/stdc++.h>
using namespace std;

struct Node {
int key;
int size; // size of subtree rooted at this node
Node *left, *right;

Node(int k) {
    key = k;
    size = 1;
    left = right = NULL;
}


};

// Utility to get size
int getSize(Node* node) {
return node ? node->size : 0;
}

// Update size
void updateSize(Node* node) {
if (node)
node->size = 1 + getSize(node->left) + getSize(node->right);
}

// Insert
Node* insert(Node* root, int key) {
if (!root) return new Node(key);

if (key < root->key)
    root->left = insert(root->left, key);
else
    root->right = insert(root->right, key);

updateSize(root);
return root;


}

// Find minimum
Node* findMin(Node* root) {
while (root->left) root = root->left;
return root;
}

// Delete
Node* deleteNode(Node* root, int key) {
if (!root) return NULL;

if (key < root->key)
    root->left = deleteNode(root->left, key);
else if (key > root->key)
    root->right = deleteNode(root->right, key);
else {
    // node found
    if (!root->left) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (!root->right) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else {
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
}

updateSize(root);
return root;


}

// Kth smallest (1-based index)
int kthSmallest(Node* root, int k) {
if (!root) return -1;

int leftSize = getSize(root->left);

if (k == leftSize + 1)
    return root->key;
else if (k <= leftSize)
    return kthSmallest(root->left, k);
else
    return kthSmallest(root->right, k - leftSize - 1);

}

// Rank of key (number of elements <= key)
int getRank(Node* root, int key) {
if (!root) return 0;

if (key < root->key)
    return getRank(root->left, key);
else
    return getSize(root->left) + 1 + getRank(root->right, key);

}

// Inorder traversal
void inorder(Node* root) {
if (!root) return;
inorder(root->left);
cout << root->key << " ";
inorder(root->right);
}

int main() {
Node* root = NULL;

// Insert elements
vector<int> arr = {20, 10, 30, 5, 15, 25, 35};
for (int x : arr)
    root = insert(root, x);

cout << "Inorder: ";
inorder(root);
cout << endl;

cout << "3rd smallest: " << kthSmallest(root, 3) << endl;
cout << "Rank of 25: " << getRank(root, 25) << endl;

// Delete
root = deleteNode(root, 20);

cout << "After deletion (20): ";
inorder(root);
cout << endl;

return 0;

}
