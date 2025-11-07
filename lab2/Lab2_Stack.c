//SarthakGore-IT-B-172
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int element);
int pop();
void display();
void checkPalindrome();
void checkOverflow();
void checkUnderflow();

int main() {
    int choice, element, poppedElement;

    while (1) {
        printf("\n----- STACK OPERATIONS MENU -----\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow\n");
        printf("5. Demonstrate Underflow\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                poppedElement = pop();
                if (poppedElement != -1)
                    printf("Popped element: %d\n", poppedElement);
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                checkOverflow();
                break;
            case 5:
                checkUnderflow();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void push(int element) {
    if (top == MAX - 1)
        printf("Stack Overflow! Cannot push %d\n", element);
    else {
        top++;
        stack[top] = element;
        printf("%d pushed onto stack.\n", element);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1;
    } else {
        int popped = stack[top];
        top--;
        return popped;
    }
}

void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void checkPalindrome() {
    char str[100], rev[100];
    int i, len = 0, isPalindrome = 1;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    // Manually calculate string length
    while (str[len] != '\0')
        len++;

    top = -1; // reset stack

    // Push each character of string into stack
    for (i = 0; i < len; i++)
        push(str[i]);

    // Pop characters to form reversed string
    for (i = 0; i < len; i++)
        rev[i] = pop();
    rev[i] = '\0';

    // Manual comparison of original and reversed string
    for (i = 0; i < len; i++) {
        if (str[i] != rev[i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("'%s' is a palindrome.\n", str);
    else
        printf("'%s' is not a palindrome.\n", str);
}

void checkOverflow() {
    top = MAX - 1;
    printf("Trying to push element into full stack...\n");
    push(999);
}
void checkUnderflow() {
    top = -1;
    printf("Trying to pop element from empty stack...\n");
    pop();
}
