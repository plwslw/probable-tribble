#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {int x; struct node* next;};
void print_list(struct node* n);
struct node* insert_front(struct node* rt, int x);
struct node* free_list(struct node *n);

//Takes a pointer to a node struct and print out all of the data in the list
void print_list(struct node* n){
  if (!n) return;
  printf("%d",n->x);
  if (n->next){
    printf(", ");
    print_list(n->next);
  }
}

// Takes a pointer to the existing list and the data to be added, create a new node, put it at the beginning of the list and return a pointer to the beginning of the list.
struct node* insert_front(struct node* rt, int x){
  printf("inserting %d \n",x);
  struct node* new;
  new=(struct node *)malloc(sizeof(struct node));
  new->x=x;
  new->next=rt;
  return new;
}


//Should take a pointer to a list as a parameter and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).
struct node* free_list(struct node *n){
  /*
  if (n) free_list(*n.next);
  free(n.next);
  return n;
  */
  printf("freeing %d \n", n->x);
  struct node *next;
  next=n->next;
  free(n);
  if (next) free_list(next);
}

int main(){
  printf("%s","Beginning program");
  struct node* rt=0;
  print_list(rt);
  printf("\n");

  rt=insert_front(rt, 142);
  print_list(rt);
  printf("\n");
  
  rt=insert_front(rt, -13);
  print_list(rt);                                                                 
  printf("\n"); 

  rt=free_list(rt);
}
