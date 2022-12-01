
#include <stdio.h> //Biblioteca que contém as funções de entrada e saída de dados
#include <stdlib.h> //Biblioteca que contém as funções de alocação e liberação de memória
#include <dirent.h> //Biblioteca que contém as funções de gerenciamento de diretórios

int main() {
  char d[10]; //d = vetor de 10 posições do tipo char
  DIR *p; //p = ponteiro para DIR
  struct dirent *d1; //d1 = ponteiro para struct dirent

  printf("Entre com um nome de um diretório:\n"); //Usuário entra com o nome de um diretório
  scanf("%s", d); //Captura a string inserida pelo usuário e guarda em d

  p = opendir(d); //opendir = retorna o arquivo que está guardado em d e guarda em p

  if(p == NULL) { //Caso p (diretório) não exista...
    perror("Diretório não encontrado"); //Imprime a mensagem de erro
    exit(-1); //Retorna -1
  }

  while(d1 = readdir(p)) { //d1 guardará o nome do próximo arquivo do diretório indicado em p
    printf("%s\n", d1->d_name); //Imprime na tela o nome de cada arquivo presente no diretório
  }

  return 0; //Caso não haja erro retorna 0, se não retorna 1
}