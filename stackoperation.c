#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1; // Initially stack is empty

// Push operation (Insertion)
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed to the stack.\n", value);
}

// Pop operation (Deletion)
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No element to pop.\n");
        return;
    }
    printf("%d popped from the stack.\n", stack[top]);
    top--;
}

// Search operation
void search(int value)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        if (stack[i] == value)
        {
            printf("%d found at position %d from top of stack.\n", value, top - i + 1);
            return;
        }
    }
    printf("%d not found in the stack.\n", value);
}

// Display stack elements
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
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
