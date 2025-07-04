#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if((c == '\t') || (c == ' ')){
    return 1;
  }
  return 0;
};

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if (!space_char(c)){
    return 1;
  }
  return 0;
};

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  int i = 0;
  while (str[i] != '\0'){
    if(non_space_char(str[i])){
      return &str[i];
    }
    i++;
  }
  //printf("%s\n", str);
  return 0;
}; 

/* ReturnsOB a pointer terminator char following *token */
char *token_terminator(char *token)
{
  int i = 0;
  while(token[i] != '\0'){
    if(space_char(token[i])){
      return &token[i];
    }
    i++;
  }
  return &token[i];
};

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int num = 0;
  char *p = token_start(str);
  while(p){
    p = token_start(p);
    if (p) {
      num++;
      p = token_terminator(p);
    };
  }
  return num;
};

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
// im going to pass the start of the token and 
char *copy_str(char *inStr, short len)
{
  char *newStr;
  newStr = malloc((len+1) * sizeof(char));
  for(int i = 0; i < len; i++){
    newStr[i] = inStr[i]; 
  }
  newStr[len] = '\0';
  return newStr;
};

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  char **tokens;
  int num = count_tokens(str);
  char *p = str;
  tokens = malloc((num + 1) * sizeof(char*));
  for(int i = 0; i < num; i++){
    p = token_start(p);
    tokens[i] = copy_str(p, token_terminator(p)-p);
    p = token_terminator(p);
  }
  tokens[num] = 0;
  return tokens;
};

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  for(int i = 0;tokens[i] != 0;i++){
    printf("%s\n",tokens[i]);
  }
};

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  if (tokens == 0) {
    return;
  }
  for(int i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }

  free(tokens);
};

#endif
