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
//Copies the string over to a new memory allocation
char *copy_str(char *inStr, short len){
  char *str_copy= (char*)malloc(sizeof(char)*len);
  int i=0;
  while (i < len){
    *str_copy = *inStr;
    str_copy++;
    inStr++;
    i++;
  }
  str_copy-=len;
  return str_copy;
}

//TODO incrament tokens
char **tokenize(char* str){
  
  int word_size=0;
  int i =0;
  int total_words=count_words(str);
  
  char *word_end;
  char *word_begin;
  
  char **tokens = (char**)malloc(sizeof(char*)*total_words); // Where the tokens are stored
  char *pointer = word_start(str); // temp pointer for incramenting
  char **startAddress = tokens;
  while(i < total_words){
    
    word_begin = pointer;
    word_end = word_terminator(word_begin);    // Finds the end of the word
    pointer = word_end;                        // Preparing pointer for next iteration
    word_size = word_end - word_begin;         // Finding the exact size to copy over for the word
    *tokens = copy_str(word_begin, word_size); // Coping over word to *tokens
    tokens++;
    pointer = word_start(word_end);            // Itterators for next word
    i++
     } 
   return startAddress;
}
  
/* Prints all tokens. */
void print_tokens(char **tokens){
  while(*tokens){
    printf("\n%s", *tokens);
    tokens++;
  }
}
        
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  while(*tokens){
    free(*tokens);
    tokens++;
  }
}
#endif
        





          
