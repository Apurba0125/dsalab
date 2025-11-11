#include <stdio.h>

int main()
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Binary Search logic
    int low = 0, high = n - 1, mid, foundIndex = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            foundIndex = mid;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (foundIndex != -1)
    {
        printf("Element found at index %d\n", foundIndex);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
