/**
 * @file lab9.c
 * @author Noah Cherry
 * @date Spring 2015
 * @brief contains a magic and wonder filled example of singly linked lists
 */

#include <stdio.h>
#include <stdlib.h>

struct node_t {
    double data;
    struct node_t *next;
};

struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos);
int count_nodes(struct node_t *head);
struct node_t *delete_node(struct node_t *head, double n);
void delete_list(struct node_t *head);

int main()
{
        struct node_t *head = NULL;
        
        int i =1;
        char buff[1024];
            /*theses keep track of menu choices*/
        int choice;
        int choice2;
        int choice3;
        int pos;

        while (i == 1) {
                printf("%p", &head);
                printf("\n1) Enter a number\n2) Delete a number\n3) Print all numbers\n4) Display node count\n");
                printf("5) End program\n");
                fgets(buff, 1024, stdin);
                sscanf(buff, "%d", &choice);
        
                //exit the program
                if (choice == 5) {
                        if(count_nodes(head) > 0)
                                delete_list(head);
                        printf("\nEXITING\n");
                        exit(EXIT_SUCCESS);
                }

                //add a new node to the list
                else if (choice == 1) {
                        printf("\nwhat value will this node hold?\n");
                        fgets(buff, 1024, stdin);
                        sscanf(buff, "%d", &choice2);
                        printf("where will it go?\n1) Head\n2) Tail\n3) Middle\n");
                        fgets(buff, 1024, stdin);
                        sscanf(buff, "%d", &choice3);

                        //determine how new node will be inserted
                        if (choice3 == 1)
                                head = insert_head(head, create_node(choice2));
                        if (choice3 == 2)
                                head = insert_tail(head, create_node(choice2));
                        if (choice3 == 3) {
                                printf("where will it go?\n");
                                fgets(buff, 1024, stdin);
                                sscanf(buff, "%d", &pos);
                                head = insert_middle(head, create_node(choice2), pos);
                        }
                }

                //delete a single node
                else if (choice == 2) {
                        printf("\nWhat value should be deleted?\n");
                        fgets(buff, 1024, stdin);
                        sscanf(buff, "%d", &choice2);
                        head = delete_node(head, choice2);
                }

                //print the entire list
                else if (choice == 3) {
                        print_list(head);
                }

                //print count of node linked together
                else if (choice == 4) {
                        printf("you have %d linked nodes\n", count_nodes(head));
                }
        }
        return 0;
}

/** uses an if statement to malloc a node
 * @param n assigns n to node->data
 * @returns node
 */
struct node_t *create_node(double n)
{
        struct node_t *node;

        if (!(node = malloc(sizeof(struct node_t)))) {
                printf("malloc has failed");
                exit(EXIT_SUCCESS);
        }
    
        node->data = n;
        node->next = NULL;
        return node;
}

/** prints a desired node
 * @param node node structure is passed in
 */
void print_node(struct node_t *node) 
{
        printf("data: %f, next: %p", node->data, node->next);
}


/** places node at start of list
 * @param head the first elemt of the list
 * @param node node to be inserted
 * @return the head of the list
 */   
struct node_t *insert_head(struct node_t *head, struct node_t *node) 
{
        if (head == NULL)
                head = node;
        else {
                node->next = head;
                head = node;
        }
        return head;

}

/** places node at end of the list
 * @param head the first element of the list
 * @param node the node to be inserted
 * @return the head of the list
 */   
struct node_t *insert_tail(struct node_t *head, struct node_t *node)
{
        struct node_t *tmp = head;
        if (head == NULL) {
                head = node;
                return head;
        }
        else {
                for ( ; tmp->next != NULL; tmp=tmp->next)
                        ;
                tmp->next = node;
                return head;
        }
}

/** places node at the list index pos
 * @param head the first element of the list
 * @param node the node to be inserted
 * @param pos the desired position to insert at
 * @return head
 */   
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos)
{
        if(pos < 1)
                return head;
        if(pos > count_nodes(head))
                return insert_tail(head, node);
        if(pos == 1)
                return insert_head(head, node);
        
        struct node_t *tmp = head;      
        int count = 1;

        while(count < pos - 1) {
                count++;
                tmp = tmp->next;
        }
        struct node_t *tmpn = tmp->next;
        node->next = tmpn;
        tmp->next = node;
        return head;
        
}
    
/** counts elemnts linked together
 * @param head the first element of the list
 * @return an int count of elements linked together
 */   
int count_nodes(struct node_t *head) 
{
        int i =0;

        if (head == NULL)
                return 0;
        if (head->next == NULL) 
                return 1;
        for ( ; head->next != NULL; i++) { 
                head = head->next;
        }
        return i + 1;
}

/** deletes the first node with a specific value
 * @param head the first element of the list
 * @param n the value to search for and delete
 * @return the head of the list
 */   
struct node_t *delete_node(struct node_t *head, double n)
{
        struct node_t *tmp;

        if (head->data == n) {
                tmp = head;
                head = head->next;
                free(tmp);
                return head;
        }

        struct node_t *position = head->next;
        struct node_t *lag = head;
    
        for ( ; position->next != NULL; position = position->next , lag = lag->next) {
                if (position->data == n) {
                        lag->next = position->next;
                        free(position);
                        return head;
                }
        }
        return head;
}

/** deletes the entire list via a for loop
 * @param head the first element of the list
 */
void delete_list(struct node_t *head)
{
        struct node_t *position = head->next;
        while(count_nodes(head) > 1) {
                free(head);
                head = position;
                position = position->next;
        }
        free(head);
}

/** prints each linked element in a list
 * @param head the first element of the list
 */
void print_list(struct node_t *head)
{
        int i =0;
        for( ; head->next != NULL; head = head-> next) {
                i++;
                printf("node %d:address %p, data %f, next %p\n", i, &head, head->data, head->next);
        }   
        printf("node %d:address %p, data %f, next %p\n", ++i, &head, head->data, head->next);
} 
