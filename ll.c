#include <stdio.h>
#include <stdlib.h>

struct node
{
  int x;
  struct node *next;
};

void insert(struct node *p, int val);
void delete(struct node *p, int val);
void search(struct node *p, int val);
void printList(struct node *p);

int main()
{
  struct node *head;
  struct node *ll;
  int n = 0, val;
  unsigned int i, choice;

  printf("Enter number of nodes in linked list: ");
  scanf("%d", &n);

  printf("\nsizeof struct node = %ld\n", sizeof(struct node));

  // head node
  head = (struct node *) malloc(sizeof(struct node));
  head->next = NULL;
  head->x = -99;

  // start linked list
  ll = head;

  if (n > 0)
  {
    printf("Enter values for nodes: ");
  }

  for(i = 0; i < n; i++)
  {
    ll->next = (struct node *) malloc(sizeof(struct node));

    if (ll->next == 0)
    {
      printf("Memory allocation error!\n");
      return -1;
    }

    ll = ll->next;
    scanf("%d", &ll->x);
  }

  ll->next = 0;

  // What's next? Insert/delete/search
  printf("\n\tWhat next?\n\n");
  printf("\t1. Insert an element \n");
  printf("\t2. Delete an element \n");
  printf("\t3. Search an element \n");
  printf("\t4. Display the list \n");
  printf("\t9. Exit the program \n");

  begin:
  printf("\t\nEnter the choice:_ ");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Enter value of the node to be inserted: ");
      scanf("%d", &val);
      ll = head->next;
      insert(ll, val);
      goto begin;
      break;

    case 2:
      printf("Enter value of the node to be deleted: ");
      scanf("%d", &val);
      ll = head->next;
      //printList(ll);
      delete(ll, val);
      goto begin;
      break;

    case 3:
      printf("Enter value of the node to search: ");
      scanf("%d", &val);
      ll = head->next;
      search(ll, val);
      goto begin;
      break;

    case 4:
      printf("\nValues of nodes in linked list: ");
      ll = head->next;
      printList(ll);
      goto begin;
      break;

    case 9:
      printf("\nExiting the program\n");
      break;

    default: 
      printf("\n\tNot a valid choice.\n");
      goto begin;
  }

  return 0;
}

// Insert a node with val - at the begining, at the end, after a certain node
// Can you complete this logic? 
void insert(struct node *p, int val)
{
  int location;

  if (p == NULL)
  {
    printf("\nLinked list is empty!\n");
  }
  else
  {
    printf("Insert node: 0 => at the begining, ");
    printf("1 => after a certain node, 2 => at the end\n");
    scanf("%d", &location);
  }

  switch(location)
  {
    case 0:
      // Insert node at the beginng of the list

      break;

    case 1:
      // Insert node after a certain node

      break;

    case 2:
      // Insert node at the end of the list

      break;

    default:
      printf("\nInvalid location\n");
      return;
  }

}

// There is one problem while deleting first node of the linked list
// Can you fix it? 
void delete(struct node *p, int val)
{
  if (p == NULL)
  {
    printf("\nLinked list is empty!\n");
    return;
  }

  struct node *l, *prev;
  int found = 0;

  l = p;

  while(l != NULL)
  {
    if (l->x == val)
    {
      if (l == p)
      {
        // first node ?
        p = l->next;
        free(l);
      }
      else
      {
        prev->next = l->next;
        free(l);
      }

      found = 1;
    }
    else
    {
      prev = l;
      l = l->next;
    }
  }

  if (!found)
  {
    printf("\nValue %d not found in linked list\n", val);
  }

}

// Search an element in the linked list
void search(struct node *p, int val)
{
  if (p == NULL)
  {
    printf("\nLinked list is empty!\n");
    return;
  }

  struct node *l;
  unsigned int i = 1;
  unsigned int found = 0;

  l = p;

  while (l != 0)
  {
    if (l->x == val)
    {
      found = 1;
      printf("%d is present in the linked list at location %d\n", val, i);
      break;
    }
    l = l->next;
    i++;
  }

  if (!found)
  {
    printf("%d is not found in the linked list\n", val);
  }

}

// Print linked list
void printList(struct node *p)
{
  while (p != 0)
  {
    printf("%d ", p->x);
    p = p->next;
  }

  printf("\n\n");
}


