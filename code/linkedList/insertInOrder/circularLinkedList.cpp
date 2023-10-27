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

class CircularLinkedList
{
    shared_ptr<Node> head;

    shared_ptr<Node> createNode(int data)
    {
        shared_ptr<Node> newNode = make_shared<Node>(data);
        return newNode;
    }
    void append(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->next = this->head;
        }
        else
        {
            shared_ptr<Node> current = this->head;
            while (current->next != this->head)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = this->head;
        }
    }
    void appendAtBeginning(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->next = this->head;
        }
        else
        {
            shared_ptr<Node> current = this->head;
            while (current->next != this->head)
            {
                current = current->next;
            }
            newNode->next = this->head;
            this->head = newNode;
            current->next = this->head;
        }
    }
    void appendAtEnd(int data)
    {
        shared_ptr<Node> newNode = createNode(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->next = newNode;
        }
        else
        {
            shared_ptr<Node> current = this->head;
            while (current->next != this->head)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = this->head;
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
            shared_ptr<Node> current = this->head;
            // in case of head
            if (data < this->head->data)
            {
                this->appendAtBeginning(data);
            }
            else
            {
                do
                {
                    // in case of at end
                    if (current->next == this->head && current->data < data)
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
                } while (current != this->head);
            }
        }
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
            shared_ptr<Node> current = this->head;
            while (current->next != this->head)
            {
                current = current->next;
            }
            current->next = this->head->next;
            this->head = this->head->next;
            return;
        }
        shared_ptr<Node> current = this->head->next;
        shared_ptr<Node> prev = this->head;

        do
        {
            if (current->data == value)
            {
                prev->next = current->next;
                return;
            }
            prev = prev->next;
            current = current->next;
        } while (current != this->head);
        cout << "Value not found in list\n";
    }
    void display()

    {
        shared_ptr<Node> current = this->head;
        do
        {
            cout << current->data << "->";
            current = current->next;
        } while (current != this->head);
        cout << "(Head)" << current->data << endl;
    }

public:
    CircularLinkedList() : head(nullptr){};

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
    CircularLinkedList l;
    l.useMenu();
    return 0;
}
