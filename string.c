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

void push_front(struct string *string, char value)
{
  if(string == NULL)
  {
    // Put a error message here.
    return;
  }

  if(string->size == 0)
  {
    string->start = new_char(value);
    string->end = string->start;
    string->size++;
    return;
  }

  struct __char *aux = string->start;
  string->start = new_char(value);
  string->start->next = aux;
  aux->prev = string->start;
  string->size++;
  return;
}

void push_back(struct string *string, char value)
{
  if(string == NULL)
  {
    // Put a error message here. 
    return;
  }

  if(string->size == 0)
  {
    string->start = new_char(value);
    string->end = string->start;
    string->size++;
    return;
  }
  
  struct __char *aux = string->end;
  string->end = new_char(value);
  string->end->prev = aux;
  aux->next = string->end;
  string->size++;
  return;
}

void pop_front(struct string *string)
{
  if(string == NULL)
  {
    return;
  }
  
  if(string->size == 0)
  {
    return;
  }

  if(string->size == 1)
  {
    free(string->start);
    string->start = NULL;
    string->end = NULL;
    string->size--;
    return;
  }

  struct __char *aux = string->start->next;
  free(string->start);
  string->start = aux;
  string->size--;
  return;
}

void pop_back(struct string *string)
{
  if(string == NULL)
  {
    return;
  }

  if(string->size == 0)
  {
    return;
  }

  if(string->size == 1)
  {
    free(string->start);
    string->start = NULL;
    string->end = NULL;
    string->size--;
    return;
  }

  struct __char *aux = string->end->prev;
  free(string->end);
  string->end = aux;
  string->size--;
  return;
}

void insert(struct string *string, unsigned long long int index, char value)
{
  if(string == NULL)
  {
    return;
  }

  if(index < 0 || string->size < index) 
  {
    return; 
  }

  if(index == 0)
  {
    pop_front(string);
    return;
  }

  if(index == string->size)
  {
    pop_back(string);
    return;
  }

  struct __char *aux = string->start;
  
  for(int i = 0; (i < index) || (aux != NULL); i++)
  {
    aux = aux->next;
  }

  aux->prev->next = aux->next;
  aux->next->prev = aux->prev;
  free(aux);
  aux = NULL;
  string->size--;
  return;
}

void show_string(struct string *string)
{
  struct __char *aux = string->start;

  while(aux != NULL)
  {
    write(1, &aux->c, 1);
    aux = aux->next;
  }
  write(1, &"\n", 1);

  aux = NULL;
  return;
}

char *get_string(struct string *string)
{
  char *return_string = calloc(string->size + 1, sizeof(char));

  struct __char *aux = string->start;

  for(int i = 0; i < string->size || aux != NULL; i++)
  {
    return_string[i] = aux->c;
    aux = aux->next;
  }

  aux = NULL;
  return return_string;
}
