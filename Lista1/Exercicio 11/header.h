typedef struct pet{
  char nome[50];
  struct pet *prox;
} pet;
typedef pet* Pet;

typedef struct carro{
  char modelo[50];
  struct carro *prox;
} carro;
typedef carro* Carro;

typedef struct pessoa{
  char nome[50];
  pet *animais;
	int idade;
  carro *veiculos;
  struct pessoa *prox;
} pessoa;
typedef pessoa* Pessoa;

void cadastrarPessoa(Pessoa *head, char *nome, int idade); // Realiza o cadastro de uma pessoa.
Pessoa acharPessoa(Pessoa *head,char *nome); // Retorna o endereco do no da pessoa.
void inserirCarro(Pessoa *head, char *modelo); //Usar junto com o acharPessoa.
void inserirPet(Pessoa *head,char *nome); //Usar junto com o acharPessoa.
void imprimirPessoa(Pessoa *head, char *nome); // Conforme regras.
void libera(Pessoa *head); // Liberar sublistas tambem.

