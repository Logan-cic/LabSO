#include <stdio.h> 
#include <fcntl.h> 
#include <string.h> 
#include <stdlib.h> 

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int main() {
  char *buff, fn[10]; 
  int fd, n; //fd = descritor de arquivo; n = número de bytes lidos e guardados do arquivo apontado por fd

  printf("Entre com o nome de um arquivo novo:\n"); 
  scanf("%s", fn); 

  flush_in(); 

  // Caracterisca do scanf ->  ele irá ler uma string até achar um espaço em branco.
  // Quando o mesmo encontra na string um espaço em branco ele finaliza o processo.
  // Por esse motivo para gravar uma sequencia de texto que sera guardada dentro aquivo
  // sera utlizado o comando fgets.

  printf("Entre com o texto que será inserido nesse arquivo novo:\n"); 
  fgets(buff, 100, stdin); 
  
  // Como mencionado acima, foi utilizado o fgets para caprturar uma sequencia de texto.
  // O texto será armazenado em "buff" quem tem um espaço de 100b alocados.
  
  fd = open(fn, O_CREAT | O_WRONLY); 
  n = write(fd, buff, strlen(buff)); 
  close(fd); 
  free(buff);

  printf("\n\nVeja o conteúdo do arquivo criado\n"); 

  return 0; 
}

