/**
 * C program to reverse a Singly Linked List
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define DEBUG 1


/* Structure of a node */
struct ListNode {
    int data; //Data part
    struct ListNode *next; //Address part
}*head;


/* Functions used in the program */
void create_cycled_list(int n, struct ListNode *head);
void reverseList(struct ListNode *head);
void displayList(struct ListNode *head);
bool hasCycle(struct ListNode *head);
void move(int step, struct ListNode *head);


int main()
{
    int n, choice;
    struct ListNode * head;
    bool cycled = false;
    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create_cycled_list(n, head);

    // printf("\nData in the list \n");
    // displayList(head);

    /*
     * Reverse the list
     */
    printf("\nPress 1 to detect cycle of the singly linked list\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        cycled = hasCycle(head);
    }

    printf("Cycle detected: %d\n", cycled);

    return 0;
}


/*
 * Create a list of n nodes
 */
void create_cycled_list(int n, struct ListNode *head)
{
    struct ListNode *newNode, *temp, *cycledNode;
    int data, i;
    int cycle = 0;

    if(n <= 0)
    {
        printf("List size must be greater than zero.\n");
        return;
    }

    srand((int)getpid());

#if DEBUG
    cycle = 0;
#else
    // cycle == 0 means no cycle
    cycle = random() % (n + 1);
#endif

    printf("Cycle at node %d\n", cycle);

    head = (struct ListNode *)malloc(sizeof(struct ListNode));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Read data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;
        cycledNode = NULL;

        if (cycle == 1)
        {
            cycledNode = head;
            head->next = cycledNode;
            printf("Cycled Node: %d\n", cycledNode->data);
        }

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                if (i == cycle)
                {
                    cycledNode = newNode;

                    printf("Cycled node %d data %d\n", cycle, cycledNode->data);
                }

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = cycledNode; // Link the address field of newNode with cycled node

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("Circular SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/*
 * Reverse the order of nodes of a singly linked list
 */
void reverseList(struct ListNode *head)
{
    struct ListNode *prevNode, *curNode;

    if(head != NULL)
    {
        // prevNode = head;
        // curNode = head->next;
        // head = head->next;

        // prevNode->next = NULL; // Make first node as last node

        // while(head != NULL)
        // {
        //     head = head->next;
        //     curNode->next = prevNode;

        //     prevNode = curNode;
        //     curNode = head;
        // }

        // head = prevNode; // Make last node as head

        /* Mine Solution Below*/
        curNode = head;
        prevNode = NULL;
        
        while (head != NULL)
        {
            curNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = curNode;
        }

        head = prevNode;

        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}


/*
 * Display entire list
 */
void displayList(struct ListNode *head)
{
    struct ListNode *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}

bool hasCycle(struct ListNode *head)
{
    bool ret = false;

    struct ListNode *hare = head;
    struct ListNode *turtoise = head;

    do 
    {
        if (hare != NULL)
        {
            if (hare->next != NULL && turtoise != NULL)
            {
                hare = hare->next->next;
                turtoise = turtoise->next;
            }
            else
            {
                ret =false;
                break;
            }
        }
        else
        {
            // The end of the list
            ret = false;
            break;
        }

        if (hare == turtoise)
        {
            ret = true;
            break;
        }
    } while (hare != NULL && turtoise != NULL);

    return ret;
}
