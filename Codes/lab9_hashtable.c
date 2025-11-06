//SarthakGore-IT-B-172
#include <stdio.h>

#define SIZE 7

int main() {
    int hashTable[SIZE];
    int keys[SIZE];
    int n, i, j, hash;

   
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert (max %d): ", SIZE);
    scanf("%d", &n);

    printf("Enter %d keys: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    
    for (i = 0; i < n; i++) {
        hash = keys[i] % SIZE; 

       
        j = hash;
        while (hashTable[j] != -1) {
            j = (j + 1) % SIZE; 
        }

        hashTable[j] = keys[i];
    }

    
    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d → %d\n", i, hashTable[i]);
        else
            printf("Slot %d → EMPTY\n", i);
    }

    return 0;
}
