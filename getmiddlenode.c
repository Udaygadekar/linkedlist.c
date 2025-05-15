#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int ch, count;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &newnode->data);
                newnode->next = head;
                head = newnode;
                break;

            case 2:
                newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &newnode->data);
                newnode->next = NULL;
                if (head == NULL) {
                    head = newnode;
                } else {
                    temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newnode;
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice.\n");
        }

        // Count total nodes
        count = 0;
        temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        
        int mid = count / 2;
        temp = head;
        for (int i = 0; i < mid; i++)
        {
            temp = temp->next;
        }

        printf("Middle node data is: %d\n", temp->data);
    }

    return 0;
}
