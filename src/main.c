#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *lnklst;
  char buffer[100];
  char *c;
  char *newStr;
  char **tokens;

  //here i create the list
  lnklst = init_history();
  //printf("> ");
  //fgets(buffer,100,stdin);


  //here i add the buffer into the list
  //add_history(lnklst, buffer);
  //this was the first waypoint
  //printf("%s",buffer);

  
  /*if (space_char(' ')){
    printf("it works\n");
    }*/

  //c = token_start(buffer);
  //printf("what token_start returns: %s",c);
  //printf("%c\n", c[0]);
  //c = token_terminator(c);
  //printf("what token_terminator returns: %s",c);
  //printf("How many tokens: %d\n",count_tokens(buffer));

  //c = token_start(buffer);
  //newStr = copy_str(c, token_terminator(c)-token_start(c));
  //printf("this is the new copied str: %s\n", newStr);
  //printf("PROOF\npointer of c: %p\npointer of newStr:%p\n",c,newStr);
  //free(newStr);
  
  //c = token_start(buffer);
  //tokens = tokenize(c);
  //print_tokens(tokens);
  //free_tokens(tokens);



  for(int i = 1;i != 0;i++){
    printf("this is the history\n");
    print_history(lnklst);
    printf("Enter Tokens, type ! and id to retrieve history, type q to quit program\n");
    printf("> ");
    fgets(buffer,100,stdin);


    //type q to quit
    if (buffer[0] == '!'){
      int num = atoi(buffer + 1);
      newStr = get_history(lnklst, num);
      c = token_start(newStr);
      tokens = tokenize(c);
      print_tokens(tokens);
      free_tokens(tokens);
    } else if (buffer[0] == 'q') {
      break;
    } else {
      add_history(lnklst, buffer);
      c = token_start(buffer);
      tokens = tokenize(c);
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }

  free_history(lnklst);
  return 0;
}
