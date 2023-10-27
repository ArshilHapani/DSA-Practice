#include <iostream>
using namespace std;

class ArrayADT
{
    int totalLength;
    int usedLength;
    int *ptr;

public:
    ArrayADT(int totalLength, int usedLength)
    {
        this->usedLength = usedLength;
        this->totalLength = totalLength;
        this->ptr = new int[totalLength];
    }
    void get()
    {
        for (int i = 0; i < usedLength; i++)
        {
            cout << "Enter element " << i << ":";
            cin >> ptr[i];
        }
    }
    void show()
    {
        for (int i = 0; i < usedLength; i++)
        {
            cout << ptr[i] << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    ArrayADT adt(10, 3);
    adt.get();
    adt.show();
    return 0;
}
