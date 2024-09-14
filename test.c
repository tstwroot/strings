#include <stdio.h>
#include "strings.h"

int main(int argc, char **argv)
{
  struct string *string1 = new_string("Hello World1");
  struct string *string2 = new_string(NULL); 
  
  show_string(string1);

  char *value = "Hello World2";

  for(int i = 0; value[i] != 0; i++)
  {
    push_back(string2, value[i]);
  }

  show_string(string2);

  return 0;
}
