#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

#define MAX 1100

struct no{
  char l;
  struct no *esq, *dir;
};

no no_livre[MAX];
int nos_usados;

no *novo_no()
{
  nos_usados++;
  return &(no_livre[nos_usados-1]);
}

no *novo_no(char l)
{
  no *novo = novo_no();
  novo->l = l;
  novo->esq = novo->dir = NULL;
  return novo;
}

char expr[MAX];

no *avalia()
{

  stack<char> op;
  stack<no *> final;

  no *temp;

  op.push('(');
  for(int i = 0; expr[i] != '\0'; i++){
    switch(expr[i]){
    case '+':
    case '-':
      while(op.top() != '('){
	temp = novo_no(op.top()); op.pop();
	temp->dir = final.top(); final.pop();
	temp->esq = final.top(); final.pop();
	final.push(temp);
      }
      op.push(expr[i]);
      break;

    case '*':
    case '/':
      while(op.top() == '*' || op.top() == '/'){
	temp = novo_no(op.top()); op.pop();
	temp->dir = final.top(); final.pop();
	temp->esq = final.top(); final.pop();
	final.push(temp);
      }
      op.push(expr[i]);
      break;

    case '(':
      op.push('(');
      break;

    case ')':
      while(op.top() != '('){
	temp = novo_no(op.top()); op.pop();
	temp->dir = final.top(); final.pop();
	temp->esq = final.top(); final.pop();
	final.push(temp);
      }
      op.pop();
      break;

    default:
      final.push(novo_no(expr[i]));
    }
  }

  while(op.top() != '('){
    temp = novo_no(op.top()); op.pop();
    temp->dir = final.top(); final.pop();
    temp->esq = final.top(); final.pop();
    final.push(temp);
  }
  return final.top();
}

inline bool mais_toplevel(no *arv)
{
  return (arv->l == '+' || arv->l == '-');
}


void imprime(no *arv, bool im, bool id)
{

  if('a' <= arv->l && arv->l <= 'z'){
    putchar(arv->l);
    return;
  }

  switch(arv->l){
  case '+':
    imprime(arv->esq, im, false);
    printf("%c", (im ? '-' : '+'));
    imprime(arv->dir, im, false);
    break;

  case '-':
    imprime(arv->esq, im, false);
    printf("%c", (im ? '+' : '-'));
    imprime(arv->dir, !im, false);
    break;

  case '*':
    if(mais_toplevel(arv->esq)){
      printf("(");
      imprime(arv->esq, false, false);
      printf(")");
    }
    else
      imprime(arv->esq, false, id);

    printf("%c", (id ? '/' : '*'));

    if(mais_toplevel(arv->dir)){
      printf("(");
      imprime(arv->dir, false, false);
      printf(")");
    }
    else
      imprime(arv->dir, false, id);
    break;


  case '/':
    if(mais_toplevel(arv->esq)){
      printf("(");
      imprime(arv->esq, false, false);
      printf(")");
    }
    else
      imprime(arv->esq, false, id);

    printf("%c", (id ? '*' : '/'));

    if(mais_toplevel(arv->dir)){
      printf("(");
      imprime(arv->dir, false, false);
      printf(")");
    }
    else
      imprime(arv->dir, false, !id);
    break;
  }
}

void imprime2(no *arv)
{
  if('a' <= arv->l && arv->l <= 'z'){
    putchar(arv->l);
    return;
  }
  printf("(");
  imprime2(arv->esq);
  printf(")%c(", arv->l);
  imprime2(arv->dir);
  printf(")");
}

int main()
{

  scanf(" %s", expr);

  nos_usados = 0;
  no *arv = avalia();
  imprime(arv, false, false);
  printf("\n");
  /*
  imprime2(arv);
  printf("\n");
  */
  return 0;
}
