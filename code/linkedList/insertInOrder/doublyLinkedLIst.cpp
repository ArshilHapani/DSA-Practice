#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    int data;
    shared_ptr<Node> next;
    shared_ptr<Node> prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
protected:
    shared_ptr<Node> head;

    shared_ptr<Node> createNode(int data)
    {
        shared_ptr<Node> newNode = make_shared<Node>(data);
        return newNode;
    }

    void display()
    {
        shared_ptr<Node> current = this->head;
        while (current != nullptr)
        {
            cout << "(" << (current->prev == nullptr ? 0 : current->prev->data) << "," << current->data << ")->";
            current = current->next;
        }
        cout << nullptr << endl;
    }
    void append(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            shared_ptr<Node> current = this->head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
    void insertInBeginning(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }
    }
    void appendAtEnd(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            shared_ptr<Node> current = this->head->next;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
    void insertInOrder(int data)

    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            if (data < this->head->data)
            {
                this->insertInBeginning(data);
            }
            else
            {
                shared_ptr<Node> current = this->head->next;
                shared_ptr<Node> prev = this->head;
                while (current != nullptr)
                {
                    if (current->next == nullptr && current->data < data)
                    {
                        this->appendAtEnd(data);
                        break;
                    }
                    if (current->data < data && current->next->data > data)
                    {
                        newNode->next = current->next;
                        current->next->prev = newNode;
                        current->next = newNode;
                        newNode->prev = current;
                    }
                    prev = prev->next;
                    current = current->next;
                }
            }
        }
    }

    // deleting
    /*
        @return deleted node
        @param node to be delete with specific value F
    */
    shared_ptr<Node> deleteUsingValue(int value)
    {
        shared_ptr<Node> current = this->head->next;
        shared_ptr<Node> prev = this->head;
        shared_ptr<Node> nodeToReturn;

        // case if the node is head
        if (value == this->head->data)
        {
            nodeToReturn = this->head;
            this->head = nodeToReturn->next;
            this->head->prev = nullptr;
            return nodeToReturn;
        }
        while (current != nullptr)
        {
            if (current->data == value)
            {
                // if the node to be delete is last node
                if (current->next == nullptr)
                {
                    nodeToReturn = current;
                    current->prev->next = nullptr;
                    current->prev = nullptr;
                    break;
                }
                // if the node to be delete is specific in between node
                current->next->prev = prev;
                prev->next = current->next;
            }

            current = current->next;
            prev = prev->next;
        }
        return nodeToReturn;
    }

public:
    DoublyLinkedList() : head(nullptr){};

    void useMenu()
    {
        cout << "\n\nSelect the specific operation to perform\n\n";
        cout << "\n-------------------------------------------------------------------\n";
        cout << "\nInsertion\n";
        cout << "1. to insert value at the end of the linkedList\n";
        cout << "2. to insert value in order\n";

        cout << "\nDeletion\n";
        cout << "3. to delete value using value\n";
        cout << "4. to display\n";

        cout << "\n5. for quit";
        cout << "\n-------------------------------------------------------------------\n";

        int choice = 0, val;

        while (choice != 5)
        {
            cout << "\n\nEnter your choice:";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter value to append: ";
                cin >> val;
                this->append(val);
                cout << "Value inserted\n";
                break;
            case 2:
                cout << "Enter element for appending it in order:";
                cin >> val;
                this->insertInOrder(val);
                cout << "Value inserted at appropriate position\n";
                break;
            case 3:
                cout << "Enter element to delete node from list:";
                cin >> val;
                this->deleteUsingValue(val);
                cout << "Node deleted\n";
                break;
            case 4:
                cout << "\nList\n";
                this->display();
                break;
            case 5:
                cout << "Good bye...\n";
                break;
            default:
                cout << "Enter the valid choice\n";
                break;
            }
        }
    }
};

int main()
{
    DoublyLinkedList l;
    l.useMenu();
    return 0;
}
