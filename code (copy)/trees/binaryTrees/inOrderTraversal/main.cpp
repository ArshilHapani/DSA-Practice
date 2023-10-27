#include <iostream>
#include <memory>

class Node
{
public:
    int data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int data) : data(data), left(nullptr), right(nullptr){};
};

class Tree
{
    std::shared_ptr<Node> root;

public:
    Tree()
    {
        this->root = nullptr;
    }

    std::shared_ptr<Node> createRoot(int data)
    {
        if (this->root == nullptr)
        {
            this->root = std::make_shared<Node>(data);
            std::shared_ptr<Node> temp = this->root;
            return temp;
        }
        else
        {
            std::cout << "Head is occupied \n";
            return nullptr;
        }
    }

    std::shared_ptr<Node> appendLeft(std::shared_ptr<Node> node, int data)
    {
        if (node->left == nullptr)
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
            node->left = newNode;
            return newNode;
        }
        else
        {
            std::cout << "Left Node is already occupied with data " << node->left->data << std::endl;
            return nullptr;
        }
    }
    std::shared_ptr<Node> appendRight(std::shared_ptr<Node> node, int data)
    {
        if (node->right == nullptr)
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
            node->right = newNode;
            return newNode;
        }
        else
        {
            std::cout << "Right Node is already occupied with data " << node->right->data << std::endl;
            return nullptr;
        }
    }

    void inOrderTraversal(std::shared_ptr<Node> root)
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty\n";
            return;
        }
        if (root->left != nullptr)
        {
            inOrderTraversal(root->left);
        }
        std::cout << root->data << " ";
        if (root->right != nullptr)
        {
            inOrderTraversal(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    Tree t;
    std::shared_ptr<Node> root = t.createRoot(4);
    root->left = t.appendLeft(root, 1);
    root->right = t.appendRight(root, 6);

    root->left->left = t.appendLeft(root->left, 5);
    root->left->right = t.appendRight(root->left, 2);

    t.inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
