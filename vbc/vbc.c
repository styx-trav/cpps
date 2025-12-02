#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MULTI 2
#define VAL 0
#define ADD 1

typedef struct s_node
{
  int val;
  int type;
  struct s_node *l;
  struct s_node *r;
}       t_node;

t_node *newnode(int val, int type)
{
  t_node *item = malloc(sizeof(t_node));
  if (!item)
    return NULL;
  item->val = val;
  item->type = type;
  item->l = NULL;
  item->r = NULL;
  return item;
}

int check(char *s)
{
  if (!s)
    return 0;
  if (!isdigit(s[0]) && s[0] != '(')
    return 0;
  int par = 0;
  if (s[0] == '(')
    par++;
  int i = 1;
  while (s[i])
  {
    if (!isdigit(s[i]) && s[i] != '*' && s[i] != '(' && s[i] != ')' && s[i] != '+')
      return 0;
    if (isdigit(s[i -1]) && isdigit(s[i]))
      return 0;
    if (s[i] == ')' && s[i -1] == '(')
      return 0;
    if (s[i] == '*' || s[i] == '+')
    {
      if (s[i -1] == '*' || s[i -1] == '+')
        return 0;
    }
    if (s[i] == '(')
      par++;
    if (s[i] == ')')
    {
      if (!par)
        return 0;
      par--;
    }
    i++;
  }
  if (!isdigit(s[i -1]) && s[i -1] != ')')
    return 0;
  return 1;
}

void destroy(t_node *head)
{
  if (head->type == VAL)
    free(head);
  else
  {
    destroy(head->l);
    destroy(head->r);
    free(head);
  }
}

t_node *make_chain(char *s)
{
  int i = 1;
  t_node *head;
  t_node *item;
  t_node *tmp;
  if (isdigit(s[0]))
    head = newnode(s[0] - '0', VAL);
  item = head;
  while (s[i])
  {
    if (isdigit(s[i]))
    {
      if (!item->l)
        item->l = newnode(s[i] - '0', VAL);
      else
        item->r = newnode(s[i] - '0', VAL);
      i++;
    }
    if (s[i] == '*')
    {
      tmp = item->r;
      item->r = newnode(0, MULTI);
      item = item->r;
      item->l = tmp;
    }
    if (s[i] == '+')
    {
      tmp = head;
      head = newnode(0, ADD);
      item = head;
      item->l = tmp;
    }
    if (s[i])
     i++;
  }
  return head;
}

int calc(t_node *item)
{
  if (!item)
    return 0;
  switch(item->type)
  {
    case ADD:
      return (calc(item->l) + calc(item->r));
    case MULTI:
      return (calc(item->l) * calc(item->r));
    default:
      return item->val;
  }
}

int main(int argc, char **argv)
{
  if (argc != 2)
    return 0;
  if (check(argv[1]) == 0)
  {
    printf("something went wrong with the input\n");
    return 0;
  }
  t_node *chain = make_chain(argv[1]);
  printf("%d\n", calc(chain));
  destroy(chain);
}
