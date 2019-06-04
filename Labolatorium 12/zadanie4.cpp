#include<iostream>

using namespace std;
template<class T>
class BST
{
    struct node
    {
        T data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(T x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(T x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void preorder(node* t)
    {
        if(t == NULL)
            return;
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }

    void postorder(node* t)
    {
        if(t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }

    node* find(node* t, T x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        root = makeEmpty(root);
    }

    void insert(T x)
    {
        root = insert(x, root);
    }

    void remove(T x)
    {
        root = remove(x, root);
    }

    void display()
    {
        cout << "Inorder:" << endl;
        inorder(root);
        cout << endl << "Preorder:" << endl;
        preorder(root);
        cout << endl << "Postorder" << endl;
        postorder(root);
        cout << endl;
    }

    void search(T x)
    {
        root = find(root, x);
    }
};

int main()
{
    BST<int> tree;
    tree.insert(20);
    tree.insert(25);
    tree.insert(15);
    tree.insert(10);
    tree.insert(30);
    tree.display();

}