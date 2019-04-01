#include <iostream>
#include <set>
using namespace std;
struct node {
    int val;
    node * left;
    node * right;
    int level;
    node(int x) {
        val = x;
        level = -1;
        left = NULL;
        right = NULL;
    }
};
 
node * add(node * root, int x) {
    node *n = new node(x);
    if (root == NULL) {
        root = n;
        root->level = 0;
    }
    else {
        if (x < root->val) {
            if (root->left == NULL) {
                root->left = n;
                root->left->level = root->level + 1;
            }
            else {
                add(root->left, x);
            }
        }
        else if (x > root->val) {
            if (root->right == NULL) {
                root->right = n;
                root->right->level = root->level + 1;
            }
            else {
                add(root->right, x);
            }
        }
    }
    return root;
}
 
void find(int x) {
 
}
 
int rightmost(node * root) {
    while (root->right != NULL)
        root = root->right;
    return root->val;
}
 
node * del(node * root, int x) {
    if (root == NULL) return root;
    if (root->val == x) {
        if (root->right == NULL && root->left == NULL) {
            delete root;
            return NULL;
        }
        if (root->right != NULL && root->left == NULL) {
            node * temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL && root->left != NULL) {
            node * temp = root->left;
            delete root;
            return temp;
        }
//      root = rightmost(root->left);
        root->left = del(root->left, root->val);
        return root;
    }
 
    if (x < root->val) {
        root->left = del(root->left, x);
        return root;
    }
 
    if (x > root->val) {
        root->right = del(root->right, x);
        return root;
    }
}
void print(node * n) {
    if (n == NULL) return;
    print(n->left);
    print(n->right);
}
int maxHeight(node *n) {
    if (n == NULL) return 0;
    else {
        int heightLeft = maxHeight(n->left);
        int heightRight = maxHeight(n->right);
        if (heightLeft > heightRight)return (heightLeft + 1);
        else return heightRight + 1;
    }
}
int getSize(node *n) {
    if (n == NULL) return 0;
    else return (getSize(n->left) + 1 + getSize(n->right));
}
 
int main() {
 
    node * root = NULL;
    set<int> s;
    int n;
    while (cin >> n && n != 0) {
        root = add(root, n);
        s.insert(s.end(), n);
    }
 
    set<int>::iterator it;
    if (s.size() == 1) {
        it = s.begin();
    }
    else {
        s.erase(--s.end());
        it = --s.end();
    }
    cout << *it;
 
 
 
    return 0;
}