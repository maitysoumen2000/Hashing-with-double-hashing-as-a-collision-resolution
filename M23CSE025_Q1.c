#include <stdio.h>
#include <conio.h>
int arr[10], i, hkey1, hkey2, ptr, count = 0;
void add(int val);
void lookup(int val);
void del(int x);
int main()
{
    for (i = 0; i < 10; i++)
    {
        arr[i] = -1;
    }
    add(5);
    add(12);
    add(19);
    add(8);
    add(14);
    add(36);
    lookup(14);
    del(12);
    add(21);
    lookup(12);
    add(0);
    add(6);
    add(23);
    add(19);
    add(2);
}
void add(int val)
{
    int check = 0;
    hkey1 = (val % 10);
    if (arr[hkey1] == -1 && count < 10)
    {
        arr[hkey1] = val;
        count++;
    }
    else if (count < 10)
    {
        hkey2 = (val % 8);
        for (i = 0; i < 10; i++)
        {
            ptr = (hkey1 + i * hkey2) % 10;
            if (arr[ptr] == -1)
            {
                arr[ptr] = val;
                count++;
                break;
            }
        }
    }
    else
        printf("hash table full\n");
}

void lookup(int val)
{

    hkey1 = val % 10;
    hkey2 = (val % 8);
    for (i = 0; i < 10; i++)
    {
        ptr = (hkey1 + i * hkey2) % 10;
        if (arr[ptr] == val)
        {
            printf("element %d is found at index %d\n", val, ptr);
            // flag = 1;
            break;
        }
    }
    if (i == 10)
        printf("element %d not found\n", val);
}

void del(int x)
{
    hkey1 = x % 10;
    hkey2 = (x % 8);
    for (i = 0; i < 10; i++)
    {
        ptr = (hkey1 + i * hkey2) % 10;
        if (arr[ptr] == x)
        {
            printf("element %d is deleted\n", arr[ptr]);
            arr[ptr] = -1;
            count--;
            break;
        }
    }
}