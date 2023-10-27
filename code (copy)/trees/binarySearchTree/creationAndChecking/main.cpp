#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    int data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(int data) : data(data), left(nullptr), right(nullptr){};
};

class Tree
{
    shared_ptr<Node> root;

public:
    Tree() : root(nullptr){};

    shared_ptr<Node> createRoot(int data)
    {
        if (this->root == nullptr)
        {
            this->root = make_shared<Node>(data);
            return this->root;
        }
        cout << "Root is not null\n";
        return nullptr;
    }

    shared_ptr<Node> appendLeft(shared_ptr<Node> node, int data)
    {
        if (this->root == nullptr)
        {
            cout << "Root is empty\n";
            return nullptr;
        }
        if (node->left != nullptr)
        {
            cout << "Left side of provided node is notnull\n";
            return nullptr;
        }
        shared_ptr<Node> newNode = make_shared<Node>(data);
        node->left = newNode;
        return newNode;
    }

    shared_ptr<Node> appendRight(shared_ptr<Node> node, int data)
    {
        if (this->root == nullptr)
        {
            cout << "Root is empty\n";
            return nullptr;
        }
        if (node->right != nullptr)
        {
            cout << "Right side of provided node is notnull\n";
            return nullptr;
        }
        shared_ptr<Node> newNode = make_shared<Node>(data);
        node->right = newNode;
        return newNode;
    }

    void inOrderTraversal(shared_ptr<Node> node)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->left != nullptr)
        {
            this->inOrderTraversal(node->left);
        }
        cout << node->data << " ";
        if (node->right != nullptr)
        {
            this->inOrderTraversal(node->right);
        }
    }

    bool isBST(shared_ptr<Node> node)
    {
        static shared_ptr<Node> prev = nullptr;
        if (node != nullptr)
        {
            if (!this->isBST(node->left))
            {
                return false;
            }
            if (prev != nullptr && node->data <= prev->data)
            {
                return false;
            }
            prev = node;
            return isBST(node->right);
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    /*
        4
       /\
      2 10
     /\
    1 3

    */
    Tree t;
    shared_ptr<Node> root = t.createRoot(4);
    shared_ptr<Node> l1 = t.appendLeft(root, 2);
    shared_ptr<Node> r1 = t.appendRight(root, 10);
    t.appendLeft(l1, 1);
    t.appendRight(l1, 3);
    t.inOrderTraversal(root);
    cout << endl;
    cout << t.isBST(root) << endl;
    return 0;
}
