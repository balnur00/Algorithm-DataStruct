#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <list>

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
int h = 0;
vector<node *> lisst;
node * add(node * root, int x) {
    node *n = new node(x);
 
    if (root == NULL) {
        lisst.push_back(n);
        root = n;
        root->level = 0;
        //h = max(h, root->level);
    }
    else {
        if (x < root->val) {
 
            if (root->left == NULL) {
                lisst.push_back(n);
                root->left = n;
                root->left->level = root->level + 1;
                //h = max(h, root->left->level);
            }
            else {
                add(root->left, x);
            }
        }
        else if (x > root->val) {
 
            if (root->right == NULL) {
                lisst.push_back(n);
                root->right = n;
                root->right->level = root->level + 1;
                //h = max(h, root->right->level);
            }
            else {
                add(root->right, x);
            }
        }
    }
    return root;
}
 
 
 
int rightmost(node * root) {
    while (root->right != NULL)
        root = root->right;
    return root->val;
    //rightmost(root->right);
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
        root->val = rightmost(root->left);
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
    return root;
}
 
void print(node * n) {
    if (n == NULL) return;
    cout << n->val << " " << n->level << endl;
    print(n->left);
    print(n->right);
}
 
 
 
 
int main() {
 
    node * root = NULL;
    set<int> s;
    int n;
    while (cin >> n && n != 0) {
        root = add(root, n);
        //s.insert(s.end(),n);
    }
 
 
    for (int i = 0; i<lisst.size(); i++) {
        if (lisst[i]->left != NULL && lisst[i]->right != NULL)
            s.insert(s.end(), lisst[i]->val);
    }
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
 
 
 
    return 0;
}