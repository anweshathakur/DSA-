
#include <stdio.h>

int heap[100];
int size = 0;

void insert(int value)
{
    int i = size;
    heap[size] = value;
    size++;

    while (i > 0 && heap[(i-1)/2] < heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;

        i = (i-1)/2;
    }
}

void deleteMax()
{
    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size-1];
    size--;

    int i = 0;

    while (1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

void display()
{
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    insert(40);
    insert(20);
    insert(10);
    insert(30);
    insert(50);

    printf("Max Heap: ");
    display();

    deleteMax();

    printf("After deletion: ");
    display();

    return 0;
}
