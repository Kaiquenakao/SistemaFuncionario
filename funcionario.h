// Funcionario.h

// Lista estática
struct cargo{
    int cargoID;
    char nomeCargo[90];

};
typedef struct lista ListaE;
ListaE *cria_lista();
void ocupacoes(ListaE *Lie);
int insere_listaE_ordenada(ListaE *liE, struct cargo CBO);
int menuPosto();


// Lista sequencial
typedef struct funcionario{
    int id;
    char nome[64];
    char endereco[90];
    int idade;
    float salario;
    int cargo;
}FUNCIONARIO;
typedef struct elemento* Lista;

int menuPrincipal();

FUNCIONARIO coletaDados();

int tamanhoLista(Lista *li);

void limpaTela();

Lista *criaLista();

int listaVazia(Lista *li);

int insere_lista_ordenada(Lista *li, FUNCIONARIO database);

int consulta_lista_id(Lista *li, int id, FUNCIONARIO *database);

int remove_lista(Lista *li, int id);

int alterarFuncionario(Lista *li, int id, ListaE *liE, FUNCIONARIO database);

void exibeFuncionarios(FUNCIONARIO database);

void exibeTodosFuncionariosID(Lista *li);

int buscaFaixa(Lista *li, float minimo, float maximo);

void apagaLista(Lista *li);

int consulta_lista_nome();

int alterarFuncionarioNome(Lista *li, char *nome, ListaE *liE, FUNCIONARIO database);

int opcaoPergunta();

void libera_lista(ListaE *liE);
