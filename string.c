#include "strings.h"
#include <stdlib.h>
#include <unistd.h>

struct __char
{
  struct __char *next;
  struct __char *prev;
  char c;
};

struct string
{
  struct __char *start;
  struct __char *end;
  unsigned long long int size;
};

struct __char *new_char(char value)
{
  struct __char *new_char = malloc(sizeof(struct __char)); 
  
  if(new_char == NULL)
  {
    // Put a error message here.
    return NULL;
  }

  new_char->next = NULL;
  new_char->prev = NULL;
  new_char->c = value;
  return new_char;
}

struct string *new_string()
{
  struct string *new_string = malloc(sizeof(struct string));

  if(new_string == NULL)
  {
    // Put a error message here.
    return NULL;
  }

  new_string->start = NULL;
  new_string->end = NULL;
  new_string->size = 0;
  return new_string;
}