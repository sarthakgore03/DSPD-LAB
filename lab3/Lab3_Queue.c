//SarthakGore-IT-B-172
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;
void insert(char element);
char delete();
void display();
void checkOverflow();
void checkUnderflow();

int main() {
    int choice;
    char element, deletedElement;
    while (1) {
        printf("\n----- QUEUE OPERATIONS MENU -----\n");
        printf("1. Insert an Element into Queue\n");
        printf("2. Delete an Element from Queue\n");
        printf("3. Demonstrate Overflow\n");
        printf("4. Demonstrate Underflow\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case 2:
                deletedElement = delete();
                if (deletedElement != '\0')
                    printf("Deleted element: %c\n", deletedElement);
                break;
            case 3:
                checkOverflow();
                break;
            case 4:
                checkUnderflow();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void insert(char element) {
    if (rear == MAX - 1)
        printf("Queue Overflow! Cannot insert %c\n", element);
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = element;
        printf("%c inserted into queue.\n", element);
    }
}
char delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
        front = rear = -1;
        return '\0';
    } else {
        char deleted = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return deleted;
    }
}
void display() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        printf("Queue elements (front to rear): ");
        for (int i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}
void checkOverflow() {
    rear = MAX - 1;
    front = 0;
    printf("Queue is full now. Trying to insert an element...\n");
    insert('Z');
}
void checkUnderflow() {
    front = rear = -1;
    printf("Queue is empty now. Trying to delete an element...\n");
    delete();
}