#include <stdio.h>
#include <stdlib.h>

typedef struct item {
  int value;
  struct item *prox;
} Item;

typedef struct head {
  int size;
  Item *first;
} Head;

void push(Head *head, int value) {
  Item *newItem = (Item*) malloc(sizeof(Item));
  newItem->value = value;
  newItem->prox = NULL;

  Item *aux = head->first;

  if(!head->first) {
    head->first = newItem;
    return;
  }

  while(aux->prox) {
    aux = aux->prox;
  }

  aux->prox = newItem;
}

Head* create_head() {
  Head *head = (Head*) malloc(sizeof(Head));

  head->first = NULL;
  head->size = 0;

  return head;
}

void print(Head* head) {
  if(!head->first) return;

  Item* aux = head->first;

  while(aux) {
    printf("%d", aux->value);
    aux = aux->prox;
  }

  printf("\n");
}

int main() {
  Head* head = create_head();

  push(head,  3);
  push(head, 4);
  push(head, 5);

  print(head);

  return 0;
}