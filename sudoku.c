#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node *n) {
    // Arreglos para marcar números en filas, columnas y submatrices
    int rowCheck[9][10] = {0};
    int colCheck[9][10] = {0};
    int subgridCheck[3][3][10] = {0};

    // Verificar filas y columnas
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num = n->sudo[i][j];
            if (num == 0) continue; // Ignorar celdas vacías
            if (rowCheck[i][num] || colCheck[j][num]) return 0; // Número repetido en fila o columna
            rowCheck[i][num] = 1;
            colCheck[j][num] = 1;

            // Verificar submatrices 3x3
            int subgridRow = i / 3;
            int subgridCol = j / 3;
            if (subgridCheck[subgridRow][subgridCol][num]) return 0; // Número repetido en submatriz
            subgridCheck[subgridRow][subgridCol][num] = 1;
        }
    }
    return 1; // Estado válido
}



List* get_adj_nodes(Node* n) {
    List* list = createList();
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (n->sudo[i][j] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    Node* newNode = copy(n);
                    newNode->sudo[i][j] = num;
                    if (is_valid(newNode)) {
                        pushBack(list, newNode); // Usamos pushBack para agregar al final de la lista
                    } else {
                        free(newNode);
                    }
                }
                return list;
            }
        }
    }
    return list;
}



int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/