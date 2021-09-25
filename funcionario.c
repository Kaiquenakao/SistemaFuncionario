#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcionario.h"
#include <string.h>


//Lista estática
struct lista{
    int qtd;
    struct cargo dados[15];
};
ListaE *cria_lista(){ //Criação da lista estática
    ListaE *liE;
    liE = (ListaE*) malloc(15 * sizeof(struct lista));
    if(liE != NULL){
        liE->qtd = 0;
    }
    return liE;
}
void ocupacoes(ListaE *liE){ //Lista estática sendo implantada com os cargos e os códigos
    struct cargo CBO[15];
    int i;

    //Cargos
    strcpy(CBO[0].nomeCargo, "Cirurgião dentista - clínico geral");
    CBO[0].cargoID = 223208;


    strcpy(CBO[1].nomeCargo, "Colorista de papel ");
    CBO[1].cargoID = 311705;

    strcpy(CBO[2].nomeCargo, "Citotécnico");
    CBO[2].cargoID = 324215;

    strcpy(CBO[3].nomeCargo, "Enólogo");
    CBO[3].cargoID = 325005;

    strcpy(CBO[4].nomeCargo, "Aromista");
    CBO[4].cargoID = 325010;


    strcpy(CBO[5].nomeCargo, "Atendente de agência");
    CBO[5].cargoID = 413205;

    strcpy(CBO[6].nomeCargo, "Compensador de banco");
    CBO[6].cargoID = 413215;

    strcpy(CBO[7].nomeCargo, "Conferente de serviços bancários");
    CBO[7].cargoID = 413220;

    strcpy(CBO[8].nomeCargo, "Escriturário de banco");
    CBO[8].cargoID = 413225;

    strcpy(CBO[9].nomeCargo, "Agente de proteção de aeroporto");
    CBO[9].cargoID = 517305;

    strcpy(CBO[10].nomeCargo, "Ajudante de motorista");
    CBO[10].cargoID = 783225;

    strcpy(CBO[11].nomeCargo, "Engarrafador");
    CBO[11].cargoID = 784120;

    strcpy(CBO[12].nomeCargo, "Encarregado de acabamento de chapas e metais (têmpera)");
    CBO[12].cargoID = 821405;

    strcpy(CBO[13].nomeCargo, "Escarfador");
    CBO[13].cargoID = 821410;

    strcpy(CBO[14].nomeCargo, "Extrusor de fios ou fibras de vidro");
    CBO[14].cargoID = 823210;



    for(i = 0; i < 15; i++){
        insere_listaE_ordenada(liE, CBO[i]);
    }

}
int insere_listaE_ordenada(ListaE *liE, struct cargo CBO){ //Inserção de dados ordenados da lista estática
    if(liE == NULL){
        return 0;
    }
    int k, i = 0;
    while(i < liE->qtd && liE->dados[i].cargoID < CBO.cargoID){
        i++;
    }
    for(k = liE->qtd -1 ; k >= i; k--){
        liE->dados[k + 1] = liE->dados[k];
    }
    liE->dados[i] = CBO;
    liE->qtd++;
    return 1;
}
int consulta_listaE_pos(ListaE *liE, int cargo){ //Consulta da lista estatica atraves da posição que no caso é o CODCARGO
    return liE->dados[cargo - 1].cargoID;
}
int menuPosto(ListaE *liE){ //Menu posto usado na hora de selecionar qual profissão o funcionário atua
    int cargo, x;
    printf("            Menu Postos de trabalho\n");
    printf("1 - Cirurgião dentista - clínico geral\n");
    printf("2 - Colorista de papel\n");
    printf("3 - Citotécnico\n");
    printf("4 - Enólogo\n");
    printf("5 - Aromista\n");
    printf("6 - Atendente de agência\n");
    printf("7 - Compensador de banco\n");
    printf("8 - Conferente de serviços bancários\n");
    printf("9 - Escriturário de banco\n");
    printf("10 - Agente de proteção de aeroporto\n");
    printf("11 - Ajudante de motorista\n");
    printf("12 - Engarrafador\n");
    printf("13 - Encarregado de acabamento de chapas e metais (têmpera)\n");
    printf("14 - Escarfador\n");
    printf("15 - Extrusor de fios ou fibras de vidro\n");
    printf("Digite o número correspodente ao cargo desejado:  ");
    scanf("%d", &cargo);
    x = consulta_listaE_pos(liE, cargo);
    limpaTela();
    return x;
}

//Lista sequencial
struct elemento{
    FUNCIONARIO dados;
    struct elemento *prox;
};
typedef struct elemento ELEM;
int menuPrincipal(){ //Menu principal onde escolhe a opção da lista sequencial
    int opcao;
    printf("1 - Adicionar funcionário\n");
    printf("2 - Excluir funcionário\n");
    printf("3 - Editar funcionário\n");
    printf("4 - Buscar funcionário\n");
    printf("5 - Exibir funcionários ordenados por ID, com todos os seus dados\n");
    printf("6 - Exibir uma lista de funcionários por faixa salarial\n");
    printf("7 - Sair do menu\n");
    printf("Digite a opção:  ");
    scanf("%d", &opcao);

    return opcao;
}
FUNCIONARIO coletaDados(ListaE *liE){ // o coleta dados dos funcionários como por exemplo nome, salario...
    FUNCIONARIO func;
    printf("Informe o no. de identificação do funcionario:  ");
    scanf("%d", &func.id);
    getchar();
    printf("Informe o nome do funcionario:  ");
    fgets(func.nome, 64, stdin);
    func.nome[strlen(func.nome)-1]='\0';
    printf("Informe o endereço do funcionario:  ");
    fgets(func.endereco, 64, stdin);
    func.endereco[strlen(func.endereco)-1]='\0';
    printf("Informe a idade do funcionario:  ");
    scanf("%d", &func.idade);
    printf("Informe o salário do funcionario:  ");
    scanf("%f", &func.salario);
    limpaTela();
    func.cargo = menuPosto(liE);
    return func;
}
int tamanhoLista (Lista *li) { // Função para saber o tamanho da lista, fundamental para aplicar em outras funções
  if (li == NULL) {
    return 0;
  }

  int tamanho = 0;
  ELEM *no = *li;

  while (no != NULL) {
    tamanho++;
    no = no->prox;
  }

  return tamanho;
}
void limpaTela(){ //limpa tela com o system CLS, para ajudar na hora de visualizar
    system("CLS");
}
Lista *criaLista(){ // Criação da lista sequencial
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
int listaVazia(Lista *li){ // Verificar se a lista está vazia, sendo essencial para outras funções
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}
int insere_lista_ordenada(Lista *li, FUNCIONARIO database){ // Inserindo dados de forma ordenadada através do ID
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = database;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.id < database.id){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}
int consulta_lista_id(Lista *li, int id, FUNCIONARIO *database){ // Consultando a lista através do ID
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *database = no->dados;
        return 1;
    }
}
int remove_lista(Lista *li, int id){ // Removendo funcionários da lista através do ID
    if(li == NULL){
        return 0;
    }

    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.id != id){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }

    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}
int alterarFuncionario(Lista *li, int id, ListaE *liE, FUNCIONARIO database){ // Alterando o Funcionário através do ID
  exibeFuncionarios(database);
  printf("\n\nEdição de Funcionario\n");
  ELEM *no = *li;
  while (no != NULL && no->dados.id != id) {
    no = no->prox;
  }

  if (no == NULL) {
    return 0;
  } else {
      FUNCIONARIO func = coletaDados(liE);
      no->dados = func;

      return 1;
  }
}
void exibeFuncionarios(FUNCIONARIO database){// Função essencial - sendo utilizada para visualizar os dados
    printf("\nID: %d", database.id);
    printf("\nNome: %s", database.nome);
    printf("\nEndereço: %s", database.endereco);
    printf("\nIdade: %d", database.idade);
    printf("\nSalario: %.2f", database.salario); //NÃO ESQUECE DO CARGO AINDA
    printf("\nCódigo cargo: %d\n\n", database.cargo);
}
void exibeTodosFuncionariosID(Lista *li){ //Exibe todos os funcionários por ordem do ID
  FUNCIONARIO database;
  ELEM *no = *li;
  while (no != NULL) {
    database = no->dados;
    exibeFuncionarios(database); //Chama função de exibição
    no = no->prox;
  }
}
int buscaFaixa(Lista *li, float minimo, float maximo){ // Buscar funcionário atraves do salario min e max
  if(li == NULL){
    return 0;
  }
  FUNCIONARIO database;
  ELEM *no = *li;
  int aux;
    while(no != NULL){
        if(no->dados.salario >= minimo && no->dados.salario <= maximo) {
            database = no->dados;
            printf("Faixa salarial de R$ %.2f à R$ %.2f", minimo, maximo);
            exibeFuncionarios(database);
            aux++;
    }
    no = no->prox;

  }
  if(aux == 0){
    return 0;
  }
  return 1;
}
void apagaLista(Lista *li){ // Antes de sair do menu a lista é apagada
    if(li != NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
int consulta_lista_nome(Lista *li, char *nome, FUNCIONARIO *database){ // Consulta a lista através do nome
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && (strcmp(no->dados.nome, nome) != 0)){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *database = no->dados;
        return 1;
    }
}
int alterarFuncionarioNome(Lista *li, char *nome, ListaE *liE, FUNCIONARIO database){ // Alterando o Funcionário através do ID
  exibeFuncionarios(database);
  printf("\n\nEdição de Funcionario\n");
  ELEM *no = *li;
  while (no != NULL && (strcmp(no->dados.nome, nome) != 0)) {
    no = no->prox;
  }

  if (no == NULL) {
    return 0;
  } else {
      FUNCIONARIO func = coletaDados(liE);
      no->dados = func;
      return 1;
  }
}
int opcaoPergunta(){ // Opção de pergunta 1 - ID 2 - Nome
    int pergunta;
    printf("Você deseja buscar pelo Nome ou pelo ID\n1 - ID\n2 - Nome\nDigite a opção:  ");
    scanf("%d", &pergunta);
    return pergunta;
}
void libera_lista(ListaE *liE){
    free(liE);
}
