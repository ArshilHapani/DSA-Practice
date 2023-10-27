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

class BinaryTree
{
    shared_ptr<Node> head;

public:
    shared_ptr<Node> createRoot(int data)
    {
        this->head = make_shared<Node>(data);
        return this->head;
    }
    shared_ptr<Node> appendLeft(shared_ptr<Node> node, int data)
    {
        shared_ptr<Node> newNode = make_shared<Node>(data);
        node->left = newNode;
        return newNode;
    }
    shared_ptr<Node> appendRight(shared_ptr<Node> node, int data)
    {
        shared_ptr<Node> newNode = make_shared<Node>(data);
        node->right = newNode;
        return newNode;
    }
    shared_ptr<Node> createNode(int data)
    {
        return make_shared<Node>(data);
    }
    void display(int level, shared_ptr<Node> node)
    {
        if (node == nullptr)
        {
            return;
        }
        display(level + 1, node->right);
        for (int i = 0; i < level; i++)
        {
            cout << "    ";
        }
        cout << node->data << endl;
        display(level + 1, node->left);
    }
};

int main(int argc, char const *argv[])
{
    BinaryTree tree;
    shared_ptr<Node> root = tree.createRoot(10);
    shared_ptr<Node> lRoot = tree.appendLeft(root, 5);
    shared_ptr<Node> rRoot = tree.appendRight(root, 8);
    tree.appendLeft(lRoot, 3);
    tree.appendRight(lRoot, 2);
    tree.appendLeft(rRoot, 6);
    tree.appendRight(rRoot, 13);
    tree.display(0, root);
    return 0;
}
