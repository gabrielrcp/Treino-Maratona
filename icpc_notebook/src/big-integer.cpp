/* NÚMEROS GRANDES
 * Contem rotinas para operações com números grandes.
 * Os números serão representados em base 10000.
 * Os digitos menos significativos vão aparecer nas
 * primeiras posicoes do vetor. 
 * Ex: 15000 => num[0] = 5000, num[1] = 1
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100 /* (Numero de digitos)/4 */

/* STRING_TO_NUM
 * Converte um número de string para inteiro
 * Parâmetros:
 * -entrada: Número em forma de string
 * -num: Vetor onde o número convertido ficará guardado
 * Saída:
 * -ndig: Número de posições ocupadas pelo número em num (base 10000)
 */
int stringToNum(char *entrada, int num[100]) {
  int i,j,k,tam; 
  int ndig;

  tam = strlen(entrada); 
  ndig = 0;

  for (i = tam-1; i >= 0; i--) { 
    num[ndig] = 0; 
    k = 1; 
    for (j = 0; j < 4 && i >= 0; j++,i--) { 
      num[ndig] = num[ndig] + k*(entrada[i]-'0'); 
      k *= 10; 
    } 
    i++; 
    ndig++; 
  } 

  /* Tirar 0s à esquerda */
  while(ndig >= 1 && num[ndig-1] == 0)
    ndig--;

  /* Caso patológico... */
  if (ndig == 0) {
    num[0] = 0;
    ndig = 1;
  }

  return ndig; 
}

/* IMPRIME
 * Imprime um número grande
 * Parâmetros:
 * -a: Vetor com o número grande
 * -tam: Posições de a ocupadas pelo número
 */
void imprime(int a[MAX], int tam) { 
  int i = tam-1; 
  printf("%d",a[i]); 
  for (i--; i>= 0; i--) { 
    printf("%04d",a[i]); 
  } 
  return;
} 

/* SOMA 
 * Calcula a soma de dois inteiros grandes
 * Parâmetros:
 * -a,tama: Vetor com o 1º número e seu tamanho
 * -b,tamb: Vetor com o 2º número e seu tamanho
 * -c: Vetor que recebe o resultado
 * Saída:
 * -Devolve o tamanho do vetor c
 */
int soma(int a[MAX], int tama, int b[MAX], int tamb, int c[MAX]) { 
  int i,j,cont = 0, tamc; 
  
  for (i = 0; i < tama && i < tamb; i++) { 
    c[i] = a[i]+b[i]+cont; 
    cont = c[i]/10000; 
    c[i] = c[i]%10000; 
  } 
  while (i < tama) { 
    c[i] = a[i]+cont; 
    cont = c[i]/10000; 
    c[i] = c[i]%10000; 
    i++; 
  } 
  while (i < tamb) { 
    c[i] = b[i]+cont; 
    cont = c[i]/10000; 
    c[i] = c[i]%10000; 
    i++; 
  } 
  if (cont) 
    c[i++] = cont; 
  tamc = i; 
  return tamc; 
} 

/* SOMA2 
 * Calcula a soma de dois inteiros grandes e guarda no primeiro
 * Parâmetros:
 * -a,tama: Vetor com o 1º número e seu tamanho
 * -b,tamb: Vetor com o 2º número e seu tamanho
 * Saída:
 * -Devolve o tamanho do vetor c
 */
int soma2(int a[MAX], int tama, int b[MAX], int tamb) { 
  int i,j,cont = 0, tamc; 
  
  for (i = 0; i < tama && i < tamb; i++) { 
    a[i] = a[i]+b[i]+cont; 
    cont = a[i]/10000; 
    a[i] = a[i]%10000; 
  } 
  while (i < tama) { 
    a[i] = a[i]+cont; 
    cont = a[i]/10000; 
    a[i] = a[i]%10000; 
    i++; 
  } 
  while (i < tamb) { 
    a[i] = b[i]+cont; 
    cont = a[i]/10000; 
    a[i] = a[i]%10000; 
    i++; 
  } 
  if (cont) 
    a[i++] = cont; 
  tamc = i; 
  return tamc; 
} 





/* MULT 
 * Calcula a múltiplicação de dois inteiros grandes
 * Parâmetros:
 * -a,ta: Vetor com o 1º número e seu tamanho
 * -b,tb: Vetor com o 2º número e seu tamanho
 * -c: Vetor que recebe o resultado
 * Saída:
 * -Devolve o tamanho do vetor c
 */
int mult(int a[MAX], int ta, int b[MAX], int tb, int c[MAX]) {
  int i, j, k, tc, aux,resto;

  /* Zera o vetor da resposta */
  tc = ta + tb + 1;
  for (i = 0; i < tc; i++)
    c[i] = 0;

  resto = 0;
  for (i = 0; i < ta; i++) {
    for (j = 0; j < tb; j++) {
      aux = a[i]*b[j] + resto + c[i+j];
      c[i+j] = (aux)%10000;
      resto = (aux)/10000;
    }
    j = i + j;
    while(resto) {
      aux = resto + c[j];
      c[j] = (aux)%10000;
      resto = (aux)/10000;
      j++;
    }
  }
  if (resto)
    c[tc-1] = resto;

  /* Retira os zeros à esquerda */
  i = tc - 1;
  while(c[i] == 0 && i > 0)
    i--;

  return i + 1;
}


/* DIVIDE
 * Calcula a divisão de um inteiro grande por um inteiro pequeno
 * Parâmetros:
 * -a,tama: Vetor com o número grande e seu tamanho
 * -divi: Inteiro pequeno que vai dividir o inteiro grande
 * Saída:
 * -Devolve o tamanha do vetor a, que guarda o resultado da divisão
 */
int divide(int a[MAX], int tama, int divi) {
  int i,j,k,l,tam, resto, quoc; 
  char num[10000], resp[10000];

  i = tama -1;
  sprintf(num,"%d",a[i]); 
  tam = strlen(num);
  for (i--; i>= 0; i--) { 
    sprintf(num+tam,"%04d",a[i]); 
    tam = strlen(num);
  }

  resp[0] = 0;
  j = 0;
  resto = 0;
  quoc = num[0]-'0';
  i = 1;
  while(i < tam && quoc < divi) {
    quoc = 10*quoc + num[i]-'0';
    i++;
  }

  while(i <= tam) {
    resp[j] = ((quoc/divi))%10 + '0';
    j++;
    quoc = quoc%divi;
    quoc = 10*quoc + num[i]-'0';
    i++;
  }
  resp[j] = '\0';
  tama =  stringToNum(resp,a);
  return tama;
}






/* COMPARA 
 * Compara dois números grandes
 * Parâmetros:
 * -a,tama: Vetor com o 1º número e seu tamanho
 * -b,tamb: Vetor com o 2º número e seu tamanho
 * Saída:
 * -a > b:  1
 * -a < b: -1
 * -a = b:  0
 */
int compara(int *a, int tama, int *b, int tamb) { 
  int i; 
  if (tama > tamb) 
    return 1; 
  else if (tama < tamb) 
    return -1; 
  for (i = tama-1; i>= 0; i--) { 
    if (a[i] > b[i]) 
      return 1; 
    else if (a[i] < b[i]) 
      return -1; 
  } 
  return 0; 
} 



/* SUBTRAI
 * Subtrai o primeiro número do segundo (o primeiro deve ser maior).
 * Parâmetros:
 * -a,ta: Vetor com o 1º número e seu tamanho
 * -b,tb: Vetor com o 2º número e seu tamanho
 * -c: Vetor que recebe o resultado
 * Saída:
 * -Devolve o tamanho do vetor c
 */
int subtrai(int *a, int tama, int *b, int tamb,int *c) { 
  int tamc; 
  int i,j,cont = 0; 
  for (i = j = 0; i < tama && j < tamb; i++,j++) { 
    c[i] = a[i]-b[j]-cont; 
    if (c[i] < 0) { 
      cont = 1; 
      c[i] += 10000; 
    } 
    else 
      cont = 0; 
  } 
  while (i < tama) { 
    c[i] = a[i]-cont; 
    if (c[i] < 0) { 
      cont = 1; 
      c[i] += 10000; 
    } 
    i++; 
  } 
  tamc = i; 
  while(tamc > 1 && c[tamc-1] == 0) 
    tamc--; 
  return tamc; 
} 





int main() {
  char entrada[10000];
  int n1[100], t1;
  int n2[100], t2;
  int n3[100], t3;
  int k;

  while(1) {
    /* Leitura dos números e conversão */
    scanf("%s",entrada);
    t1 = stringToNum(entrada,n1);
    scanf("%s",entrada);
    t2 = stringToNum(entrada,n2);

    /* Soma dos números */
    t3 = soma(n1,t1,n2,t2,n3);
    printf("A soma dos números é ");
    imprime(n3,t3);
    putchar('\n');

    /* Produto dos números */
    t3 = mult(n1,t1,n2,t2,n3);
    printf("O produto dos números é ");
    imprime(n3,t3);
    putchar('\n');

    /* Compara os dois números */
    k = compara(n1,t1,n2,t2);
    if (k == 1)
      printf("O primeiro é maior que o segundo\n");
    if (k == 0)
      printf("Os dois números são iguais\n");
    if (k == -1)
      printf("O segundo é maior que o primeiro\n");


    /* Subtração dos números */
    if (k >= 0)
      t3 = subtrai(n1,t1,n2,t2,n3);
    else
      t3 = subtrai(n2,t2,n1,t1,n3);
    printf("A diferença dos números é ");
    imprime(n3,t3);
    putchar('\n');

    /* Divisão de números */

    t1 = divide(n1,t1,n2[0]);

    printf("A divisão dos números é ");
    imprime(n1,t1);
    putchar('\n');

  }
  return 0;
}
