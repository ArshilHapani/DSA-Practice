#include <stdio.h>

void printTableOfGivenNumber(int n)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

void sumOfNumbers(int n)
{
    int temp;
    for (int i = 1; i <= n; i++)
    {
        temp += i;
    }
    printf("Sum of %d number is %d\n", n, temp);
}
void largestNumInArr(int *arr, int size)
{
    int var;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                var = arr[i];
            }
        }
    }
    printf("Largest var is %d\n", var);
}
int main()
{
    // printTableOfGivenNumber(10);
    // sumOfNumbers(5);
    int arr[] = {1, 3, 40, 2, 5};
    largestNumInArr(arr, 5);
    return 0;
}
