#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

void insert(int ht[], int key)
{
    int index = hash(key);
    int i = 0;

    while (i < SIZE)
    {
        int pos = (index + i) % SIZE;

        if (ht[pos] == -1)
        {
            ht[pos] = key;
            return;
        }

        i++;
    }

    printf("Hash Table is Full\n");
}

void display(int ht[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("%d -> %d\n", i, ht[i]);
    }
}

int main()
{
    int ht[SIZE];
    int n, key, i;

    for (i = 0; i < SIZE; i++)
        ht[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(ht, key);
    }

    printf("\nHash Table:\n");
    display(ht);

    return 0;
}