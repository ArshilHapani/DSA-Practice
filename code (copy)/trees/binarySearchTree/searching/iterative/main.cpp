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

    // worst case o(n) best case o(log n)
    shared_ptr<Node> searchIter(shared_ptr<Node> node, int key)
    {
        while (node != nullptr)
        {
            if (key == node->data)
            {
                return node;
            }
            else if (key < node->data)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return nullptr;
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
    shared_ptr<Node> ptr = t.searchIter(root, 12);
    cout << ptr->data << endl;
    return 0;
}
