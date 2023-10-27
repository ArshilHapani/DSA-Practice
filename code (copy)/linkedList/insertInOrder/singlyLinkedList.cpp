#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    int data;
    shared_ptr<Node> next;
    Node(int data) : data(data), next(nullptr){};
};

class LinkedList
{
    shared_ptr<Node> head;
    shared_ptr<Node> createNode(int data)
    {
        shared_ptr<Node> newNode = make_shared<Node>(data);
        return newNode;
    }
    shared_ptr<Node> append(int data)
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
            newNode->next = nullptr;
        }
        return newNode;
    }
    shared_ptr<Node> appendAtBeginning(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        return newNode;
    }
    shared_ptr<Node> appendAtEnd(int data)
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
        }
        return newNode;
    }

    shared_ptr<Node> insertInOrder(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            // in case of head
            if (data < this->head->data)
            {
                this->appendAtBeginning(data);
            }
            else
            {

                shared_ptr<Node> current = this->head;
                while (current != nullptr)
                {
                    // in case of at end
                    if (current->next == nullptr && current->data < data)
                    {
                        this->appendAtEnd(data);
                        break;
                    }
                    // middle condition
                    if (current->data < data && current->next->data > data)
                    {
                        newNode->next = current->next;
                        current->next = newNode;
                    }
                    current = current->next;
                }
            }
        }
        return newNode;
    }

    void deleteUsingValue(int value)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (value == this->head->data)
        {
            this->head = this->head->next;
            return;
        }
        shared_ptr<Node> current = this->head->next;
        shared_ptr<Node> prev = this->head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                prev->next = current->next;
                return;
            }
            prev = prev->next;
            current = current->next;
        }
        cout << "Value not found in list\n";
    }

    void display()
    {
        if (this->head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        shared_ptr<Node> current = this->head;
        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << nullptr << endl;
    }

public:
    LinkedList() : head(nullptr){};

    void useMenu()
    {
        cout << "\n\nSelect the specific operation to perform\n\n";
        cout << "\n-------------------------------------------------------------------\n";
        cout << "\nInsertion\n";
        cout << "1. to insert value at the end of the linkedList\n";
        cout << "2. to insert value at the beginning\n";
        cout << "3. to insert value in order\n";

        cout << "\nDeletion\n";
        cout << "4. to delete value using value\n";
        cout << "5. to display\n";

        cout << "\n6. for quit";
        cout << "\n-------------------------------------------------------------------\n";

        int choice = 0, val;

        while (choice != 6)
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
                cout << "Enter value to append at beginning: ";
                cin >> val;
                this->appendAtBeginning(val);
                cout << "Value inserted at the beginning\n";
                break;

            case 3:
                cout << "Enter element for appending it in order:";
                cin >> val;
                this->insertInOrder(val);
                cout << "Value inserted at appropriate position\n";
                break;
            case 4:
                cout << "Enter element to delete node from list:";
                cin >> val;
                this->deleteUsingValue(val);
                cout << "Node deleted\n";
                break;
            case 5:
                cout << "\nList\n";
                this->display();
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
    LinkedList l;
    l.useMenu();
    return 0;
}
