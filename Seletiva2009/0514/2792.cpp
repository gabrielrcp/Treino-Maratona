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

  int n = strlen(expr);
  expr[n] = ')';
  op.push('(');

  for(int i = 0; i <= n; i++){
    switch(expr[i]){
    case '+':
    case '-':
    case ')':
      while(op.top() != '('){
	temp = novo_no();
	temp->l = op.top(); op.pop();
	temp->dir = final.top(); final.pop();
	temp->esq = final.top(); final.pop();
	final.push(temp);
      }
      if(expr[i] == ')')
	op.pop();
      else
	op.push(expr[i]);
      break;

    case '*':
    case '/':
      while(op.top() == '*' || op.top() == '/'){
	temp = novo_no();
	temp->l = op.top(); op.pop();
	temp->dir = final.top(); final.pop();
	temp->esq = final.top(); final.pop();
	final.push(temp);
      }
      op.push(expr[i]);
      break;

    case '(':
      op.push(expr[i]);
      break;
    default:
      temp = novo_no();
      temp->l = expr[i];
      temp->esq = temp->dir = NULL;
      final.push(temp);
    }
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

int main()
{

  scanf(" %s", expr);

  nos_usados = 0;
  no *arv = avalia();
  imprime(arv, false, false);
  printf("\n");
  return 0;
}
