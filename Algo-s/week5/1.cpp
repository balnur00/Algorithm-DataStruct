#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int level;
    node(int x){
        val = x;
        level = -1;
        left = NULL;
        right = NULL;
    }
};
int height;
node * add(node * root, int x){
    node *n = new node(x);
    if(root == NULL){
        root = n;
        root->level = 0;
    }else{
        if(x < root->val){
            if(root->left == NULL){
                root->left = n;
                root->left->level = root->level + 1;
                if(height < root->left->level)
                {
                    height = root->left->level;
                }
            }else{
                add(root->left, x);
            }
        }else if(x > root->val){
            if(root->right == NULL){
                root->right = n;
                root->right->level = root->level + 1;
                if(height < root->right->level)
                {
                    height = root->right->level;
                }
            }else{
                add(root->right, x);
            }
        }
   }
   return root;
}

node * find(int x){

}

int rightmost(node * root){
    if(root->right == NULL) return root->val;
    rightmost(root->right);
}

node * del(node * root, int x){
    if(root == NULL) return root;
    if(root->val == x){
        if(root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }
        if(root->right != NULL && root->left == NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL && root->left != NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        root->val = rightmost(root->left);
        root->left = del(root->left, root->val);
        return root;
    }

    if(x < root->val){
        root->left = del(root->left, x);
        return root;
    }

    if(x > root->val){
        root->right = del(root->right, x);
        return root;
    }
}

int maxDepth(node * root){
    if(root == NULL) return 0;
    else{
        int rDepth = maxDepth(root->right);
        int lDepth = maxDepth(root->left);

        if(rDepth > lDepth)
            return (rDepth+1);
        else return (lDepth+1);
    }
}

int findHeight(){
    return height+1;
}

void print(node * n){
    if(n == NULL) return;
    cout << n->val << " "  << n->level << endl;
    print(n->left);
    print(n->right);
}

int main(){
    node * root = NULL;
    int a;
    while(cin >> a){
        if(a == 0) break;
        root = add(root, a);
    }
    //cout << maxDepth(root) << endl;
    cout << findHeight() << endl;


    return 0;
}