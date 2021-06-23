#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  int space = isspace(c);
  if (space > 0){
     printf("True");
  }
  else{
     printf("False");
   }
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  int space = isspace(c);
  if (space > 0){
     printf("False");
  }
  else{
     printf("True");
   }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char word_start(char *str){
  while(space_char(*str){
     str++;
  }
  return str;
} 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while(non_space_char(*word){
     word++;
  }
  return word;
}    

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int numWords = 0;
  while (*str){
     if(*str != ' ' || *str != '\t' || *str != '\n')
        ++numWords;
     ++str;
  }
  return numWords;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
