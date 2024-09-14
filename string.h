#ifndef STRINGS
#define STRINGS

struct string;

struct string *new_string();
void push_front(struct string*, char);
void push_back(struct string*, char);

#endif // STRINGS