#include <stdio.h>
#include <stdlib.h>

struct node_t {
    double data;
    struct node_t *next;
    struct node_t *previous;
};

struct info_t {
    unsigned int count; /*count of nodes in list*/

    struct node_t *head;
    struct node_t *tail;
};

struct info_t *create_sentinel();
struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct info_t *sentinel);
void print_reverse_list(struct info_t *sentinel);
struct info_t *insert_head(struct info_t *sentinel, struct node_t *node);
struct info_t *insert_tail(struct info_t *sentinel, struct node_t *node);
struct info_t *insert_middle(struct info_t *sentinel, struct node_t *node);
float count_nodes(struct info_t *sentinel);
struct info_t *delete_node(struct info_t *sentinel, double n);
struct info_t *delete_list(struct info_t *sentinel);
struct info_t *create_sequence(struct info_t *sentinel, int n) ;
struct info_t *create_sorted_list(struct info_t *sentinel, int n);
struct info_t *create_even_list(struct info_t *sentinel, int n);
struct info_t *create_odd_list(struct info_t *sentinel, int n);

int main()
{
    struct info_t *sentinel = create_sentinel();

    int i =1;
    char buff[1024];
    int choice;
    int hailstart;

    while (i == 1) {

        printf("%p", &sentinel->head);
        printf("\n1) Enter a number, the hailstone sequence is calculated\n2) Pint the hailstone sequence\n3) Print the hailstone sequence in reverse order\n4) Print the hailstone sequence in sorted order\n5) Print the hailstone sequence in reverse sorted order\n6) Print the stopping time (how many items in the list)\n7) Find the max element of the hailstone sequence\n8) Create a sequence of the even numbers in the hailstone sequence\n9) Create a sequence of odd numbers in the hailstone sequence\n10) Print all even elements of the hailstone sequence\n11) Print all odd elements of the hailstone sequence\n12) Find the ratio of even to odd numbers in the hailstone sequence\n");
        printf("13) End program\n");

        fgets(buff, 100, stdin);
        sscanf(buff, "%d", &choice);
        
        if (choice == 13) {
            delete_list(sentinel);
            printf("\nbuh bye bb\n");
            exit(EXIT_SUCCESS);
        }

        else if (choice == 1) {
            printf("\nwhat value will you use?\n");
            fgets(buff, 100, stdin);
            sscanf(buff, "%d", &hailstart);
            sentinel = create_sequence(sentinel, hailstart);
        }

        else if (choice == 2) {
            print_list(create_sequence(sentinel, hailstart));
        }

        else if (choice == 3) {
            print_reverse_list(create_sequence(sentinel, hailstart));
        }

        else if (choice == 4) {
            print_list(create_sorted_list(sentinel, hailstart));
        }
        
        else if (choice ==5) {
            print_reverse_list(create_sorted_list(sentinel, hailstart));
        }

        else if (choice == 6) {
            printf("node count: %f\n\n", count_nodes(sentinel));
        }

        else if (choice == 7) {
            sentinel = delete_list(sentinel);
            sentinel = create_sorted_list(sentinel, hailstart);
            printf("max element: %f\n\n", sentinel->tail->data);
        }

        else if (choice == 8) {
            sentinel = delete_list(sentinel);
            sentinel = create_even_list(sentinel, hailstart);
        }
    
        else if (choice == 9) {
            sentinel = delete_list(sentinel);
            sentinel = create_odd_list(sentinel, hailstart);
        }
        
        else if (choice == 10) {
            sentinel = delete_list(sentinel);
            print_list(create_even_list(sentinel, hailstart));
        }

        else if (choice == 11) {
            sentinel = delete_list(sentinel);
            print_list(create_odd_list(sentinel, hailstart));
        }

        else if (choice == 12) {
            printf("ratio of %f:%f, %f\n\n", count_nodes(create_even_list(sentinel,hailstart)), count_nodes(create_odd_list(sentinel,hailstart)), count_nodes(create_even_list(sentinel,hailstart)) / count_nodes(create_odd_list(sentinel,hailstart)));
        }

    }
    return 0;
}



/* don't let the EXIT_SUCCESS fool you
 * they really mean "bitter failure"
 */
struct info_t *create_sentinel()
{
    struct info_t *s;

    if (!(s = malloc(sizeof(struct info_t)))) {
        printf("malloc has failed");
        exit(EXIT_SUCCESS);
        /*the "success" is meant to be sarcastic*/
    }
    
    s->count = 0;
    s->head = NULL;
    s->tail = NULL;
    
    return s;
}

/* uses an if statement to malloc the node
 * assignes n to node->data
 * returns node
 */
struct node_t *create_node(double n)
{
    struct node_t *node;

    if (!(node = malloc(sizeof(struct node_t)))) {
        printf("malloc has failed");
        exit(EXIT_SUCCESS);
    }
    
    node->data = n;

    node->next = malloc(sizeof(struct node_t));
    node->previous = malloc(sizeof(struct node_t));
    return node;
}

/* prints a desired node
 * node is passed in
 * returns nothing. is stingy.
 */
void print_node(struct node_t *node) 
{
    printf("previous: %p, data: %f, next: %p", node->previous, node->data, node->next);
}


/* places node at start of list
 * assigns head = node
 * returns head
 */   
struct info_t *insert_head(struct info_t *sentinel, struct node_t *node) 
{
    if (sentinel->head == NULL)
        sentinel->head = node;
    else {
        sentinel->head->previous = node;
        node->next = sentinel->head;
        sentinel->head = node;
    }
    sentinel->count += 1;
    return sentinel;

}

/* places node at end of the list
 * 
 * returns head but usually doesn't "need" to
 */   
struct info_t *insert_tail(struct info_t *sentinel, struct node_t *node)
{
    struct node_t *tmp = sentinel->head;
    if (sentinel->head == NULL) {
        sentinel->head = node;
    }
    else {
        for ( ; tmp->next != NULL; tmp=tmp->next)
            ;
        tmp->next = node;
        node->previous = tmp;
        sentinel->tail = node;
    }
    sentinel->count += 1;
    return sentinel;
}

/* places node at the "middle" of list
 * 
 * returns sentinel
 */   
struct info_t *insert_middle(struct info_t *sentinel, struct node_t *node)
{
    struct node_t *lag = sentinel->head;
    struct node_t *tmp = lag->next;

    if (sentinel->head == NULL) {
        return insert_head(sentinel, node);
    }

    else if (lag->data >= node->data) {
        return insert_head(sentinel, node);
    }

    for ( ; tmp != NULL; lag = tmp, tmp = tmp->next) {
        if (tmp->data >= node->data) {
            lag->next = node;
            tmp->previous = node;
            node->next = tmp;
            node->previous = lag;
            sentinel->count += 1;
            return sentinel;
        }
    }    
    if (tmp == NULL)
        insert_tail(sentinel, node);
    sentinel->count += 1;
    return sentinel;
}

    
/* counts elemnts linked together
 * +1 accounts for head or end.
 * returns a int
 */   
float count_nodes(struct info_t *sentinel) 
{
    return sentinel->count;
}

/* deletes the first node with a specific value
 * not really used in this lab
 * returns sentinel
 * 
 */   
struct info_t *delete_node(struct info_t *sentinel, double n)
{
    struct node_t *tmp;

    if (sentinel->head->data == n) {
        tmp = sentinel->head;
        sentinel->head = sentinel->head->next;
        free(tmp);
        sentinel->count -= 1;
        return sentinel;
    }

    struct node_t *position = sentinel->head->next;
    struct node_t *lag = sentinel->head;
    
    for ( ; position->next != NULL; position = position->next , lag = lag->next) {
        if (position->data == n) {
            lag->next = position->next;
            //free(position->data);
            free(position);
            sentinel->count -= 1;
            return sentinel;
        }
    }
    return sentinel;
}

/* deletes entire list
 * ddoesn't delet the "hanging fruit" of each element
 * 
 */   
struct info_t *delete_list(struct info_t *sentinel)
{
    sentinel->count = 0;
    struct node_t *position = sentinel->head;

    while (position) {
        struct node_t *node = position;
        position = position->next;       
        free(node->previous);
        free(node->next);
        free(node);
    }
    free(sentinel->tail);
    free(sentinel);
    return sentinel;
}


void print_list(struct info_t *sentinel)
{
    int i =0;
    for( ; sentinel->head->next != NULL; sentinel->head = sentinel->head->next) {
        i++;
        printf("address %p, data %f, next %p\n", &(sentinel->head->previous), sentinel->head->data, sentinel->head->next);
    }   
    printf("address %p, data %f, next %p\n", &sentinel->head, sentinel->head->data, sentinel->head->next);
} 

void print_reverse_list(struct info_t *sentinel)
{
    int i =0;
    for( ; sentinel->tail->previous != NULL; sentinel->tail = sentinel->tail->previous) {
        i++;
        printf("address %p, data %f, previous %p\n", &sentinel->tail, sentinel->tail->data, sentinel->tail->previous);
    }   
    printf("address %p, data %f, previous %p\n", &sentinel->tail, sentinel->tail->data, sentinel->tail->previous);
} 

struct info_t *create_sequence(struct info_t *sentinel, int n) 
{
    sentinel->count = 0;
    sentinel->head = create_node(n);
    
    struct node_t *tmp = sentinel->head;
      
        for ( ; n != 1; tmp->next = create_node(n), tmp->next->previous = tmp, tmp = tmp->next, sentinel->count += 1) {
            if (n % 2 == 0)
                n = n / 2;
            else
                n = 3 * n + 1;
        }
    sentinel->count += 1;
    sentinel->tail = tmp;
    return sentinel;
}


struct info_t *create_sorted_list(struct info_t *sentinel, int n) 
{
    sentinel->count = 0;
    sentinel->head = create_node(n);

    for( ; n != 1; ) {
        if (n % 2 == 0)
            n = n / 2;
        else{
            n = 3 * n + 1;
        }
            sentinel = insert_middle(sentinel, create_node(n));
    }

    for ( ; sentinel->head->previous != NULL; sentinel->head = sentinel->head->previous) {
        }

    return sentinel;
}

struct info_t *create_even_list(struct info_t *sentinel, int n) 
{
    sentinel->count = 0;
    
    struct node_t *tmp = sentinel->head;
    sentinel->head = NULL;
      
        for ( ; n != 1; ) {
            if (n % 2 == 0) {
                if (sentinel->head == NULL)
                    sentinel->head = create_node(n);
                else {
                    tmp->next = create_node(n);
                    tmp->next->previous = tmp;
                    tmp = tmp->next;
                }
                sentinel->count += 1;
                n = n / 2;
            }
            else
                n = 3 * n + 1;
        }
    sentinel->tail = tmp;
    return sentinel;
}

struct info_t *create_odd_list(struct info_t *sentinel, int n) 
{
    sentinel->count = 0;
    
    struct node_t *tmp = sentinel->head;
    sentinel->head = NULL;
      
        for ( ; n != 1; ) {
            if (n % 2 == 0) 
                n = n / 2;
            else {
                if (sentinel->head == NULL)
                    sentinel->head = create_node(n);
                else {
                    tmp->next = create_node(n);
                    tmp->next->previous = tmp;
                    tmp = tmp->next;
                }
                sentinel->count += 1;
                n = 3 * n + 1;
            }
        }
    tmp->next = create_node(n);
    tmp->next->previous = tmp;
    tmp = tmp->next;
    sentinel->count += 1;
    sentinel->tail = tmp;
    return sentinel;
}






