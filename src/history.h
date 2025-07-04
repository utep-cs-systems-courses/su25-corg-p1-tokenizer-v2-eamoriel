#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *lnklst;
  lnklst = malloc(sizeof(List));
  lnklst->root = 0;
  return lnklst;
};

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
   if(list->root == 0){
    Item *rootNde;
    rootNde = malloc(sizeof(Item));
    rootNde->id = 1;

    //copy of str                                                                                                       
    int len = 0;
    while (str[len]) len++;
    rootNde->str = copy_str(str, len);

    rootNde->next = 0;
    list->root = rootNde;
  } else {
    //int num = 1;                                                                                                      
    Item *p = list->root;
    while(p->next){
      p = p->next;
      //num++;                                                                                                          
    }
    if (p->next == 0){
      Item *nxtNde;
      nxtNde = malloc(sizeof(Item));
      nxtNde->id = p->id + 1;

      //copy of str                                                                                                     
      int len = 0;
      while (str[len]) len++;
      nxtNde->str = copy_str(str, len);

      nxtNde->next = 0;
      p->next =	nxtNde;
    }
  }
};

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *p = list->root;
  while(p){
    if (p->id == id){
      return p->str;
    }
    p = p->next;
  }
  //printf("id not found\n");                                                                                           
  return 0;
};

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *p = list->root;
  while(p){
    printf("%d. %s",p->id,p->str);
    p = p->next;
  }
};

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *p = list->root; 
  while(p){
    Item *next = p->next;
    free(p->str);
    free(p);
    p =	next;
  }
  free(list);
};

#endif
