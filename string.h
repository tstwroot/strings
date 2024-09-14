#ifndef STRINGS
#define STRINGS

struct string;

struct string *new_string();
void push_front(struct string*, char);
void push_back(struct string*, char);
void pop_front(struct string*);
void pop_back(struct string*);
void insert(struct string*, unsigned long long int, char);
void show_string(struct string*);

#endif // STRINGS