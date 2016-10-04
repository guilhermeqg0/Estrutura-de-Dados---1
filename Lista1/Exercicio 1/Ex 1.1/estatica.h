#define MAX 10000

typedef int elem_t;

typedef struct {
  elem_t item[MAX];
  int tam;
} vet;

// Inicializa o vetor
void inicia (vet *v);

// Insere um elemento no final do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insere (vet *v, elem_t n);

// Retorna 1 caso o vetor esteja cheio ou 0 caso contrario
int cheio (vet v);

// Printa todos os itens do vetor
void printa(vet *v);

// Printa todos os itens do vetor de forma invertida
void printaInvertido(vet *v);

// Ordena de forma crescente todos os itens do vetor
void ordena(vet *v);

// Printa a media da soma de todos os itens do vetor
void media(vet *v);
