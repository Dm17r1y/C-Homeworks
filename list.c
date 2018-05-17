#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node * next;
  char val;
} node_t;

void print_list(node_t *head) {
  node_t * current = head;

  while (current != NULL) {
    printf("%c->", current->val);
    current = current->next;
  }

  printf("\n");
}

void add(node_t * head, char val) {
  node_t * current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = (node_t * )malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;
}

int index(node_t * head, char val) {
  int index = 0;
  node_t * current = head;
  while (current != NULL) {
    if (current->val == val) {
      return index;
    }
    index++;
    current = current->next;
  }
  return -1;
}

void remove_first(node_t * head) {
  head->val = head->next->val;
  head->next = head->next->next;
}

void remove_last(node_t * head) {
  node_t * current = head;
  node_t * previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  if (previous == NULL) {
    return;
  }
  previous->next = NULL;
}

int main() {
  char c;
  node_t head = { .next = NULL, .val = ' ' };

  while ((c = getc(stdin)) != EOF) {
    add(&head, c);
  }


  remove_first(&head);
  remove_last(&head);
  print_list(&head);
  printf("%d\n", index(&head, 'w'));
}
