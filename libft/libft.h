#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// part 1
int ft_atoi(const char *str);
int strncmp(const char *s1, const char *s2, size_t n);
char *strnstr(const char *haystack, const char *needle);

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(signed char c);
int isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

// page 10
t_list *ft_lstnew(void *content);
void ft_Istadd_front(t_list **Ist, t_list *new);
int ft_Istsize(t_list *Ist);
t_list *ft_Istlast(t_list *Ist);
