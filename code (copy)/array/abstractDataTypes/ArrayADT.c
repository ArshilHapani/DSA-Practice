
/*
    address to value = we use (*variable)
    value to address = we use &variable
    * = value of
    & = address at
*/

#include <stdio.h>
#include <cstdlib>

struct ArrayADT
{
    int total_size;
    int used_index;
    int *dynamic_array_address;
};

void setStructure(struct ArrayADT *a, int tSize, int uSize)
{
    // (*a).total_size = tSize; // DeReferencing pointer (destructuring)
    // (*a).used_index = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int)); // It returns pointer which points to the reserved memory block in heap
    // OR

    a->total_size = tSize;
    a->used_index = uSize;
    // here we use malloc because it provide us memory from the heap and that memory persist even after function is closed.
    a->dynamic_array_address = (int *)malloc(tSize * sizeof(int));
}
void showInfo(struct ArrayADT *a)
{
    // printf("Address of structure pointer %p\n and size is %d", &a, a->total_size);
    for (int i = 0; i < a->used_index; i++)
    {
        printf("%d\n", (a->dynamic_array_address)[i]);
    }
}
void setValue(struct ArrayADT *a)
{
    int n;
    for (int i = 0; i < a->used_index; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        (a->dynamic_array_address)[i] = n;
    }
}
int main()
{

    struct ArrayADT arr;
    setStructure(&arr, 10, 3);
    setValue(&arr);
    showInfo(&arr);

    return 0;
}