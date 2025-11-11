#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1; // Initially queue is empty

// Enqueue operation (Insertion)
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1)
        front = 0; // First element
    rear++;
    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

// Dequeue operation (Deletion)
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! No element to delete.\n");
        return;
    }
    printf("%d deleted from the queue.\n", queue[front]);
    front++;
    if (front > rear)
    { // Reset queue after last element is dequeued
        front = rear = -1;
    }
}

// Search operation
void search(int value)
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        if (queue[i] == value)
        {
            printf("%d found at position %d in the queue.\n", value, i - front + 1);
            return;
        }
    }
    printf("%d not found in the queue.\n", value);
}

// Display queue elements
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
