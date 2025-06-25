#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char buffer[100];
  char *c;
  
  printf("> ");
  fgets(buffer,100,stdin);

  printf("%s",buffer);

  if (space_char(' ')){
    printf("it works\n");
  }

  c = token_start(buffer); 
  printf("what token_start returns: %s",c);
  printf("%c\n", c[0]);
  c = token_terminator(c);
  printf("what token_terminator returns: %s",c);
}
