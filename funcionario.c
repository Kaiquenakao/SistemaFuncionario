#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcionario.h"
#include <string.h>


//Lista est�tica
struct lista{
    int qtd;
    struct cargo dados[15];
};
ListaE *cria_lista(){ //Cria��o da lista est�tica
    ListaE *liE;
    liE = (ListaE*) malloc(15 * sizeof(struct lista));
    if(liE != NULL){
        liE->qtd = 0;
    }
    return liE;
}
void ocupacoes(ListaE *liE){ //Lista est�tica sendo implantada com os cargos e os c�digos
    struct cargo CBO[15];
    int i;

    //Cargos
    strcpy(CBO[0].nomeCargo, "Cirurgi�o dentista - cl�nico geral");
    CBO[0].cargoID = 223208;


    strcpy(CBO[1].nomeCargo, "Colorista de papel ");
    CBO[1].cargoID = 311705;

    strcpy(CBO[2].nomeCargo, "Citot�cnico");
    CBO[2].cargoID = 324215;

    strcpy(CBO[3].nomeCargo, "En�logo");
    CBO[3].cargoID = 325005;

    strcpy(CBO[4].nomeCargo, "Aromista");
    CBO[4].cargoID = 325010;


    strcpy(CBO[5].nomeCargo, "Atendente de ag�ncia");
    CBO[5].cargoID = 413205;

    strcpy(CBO[6].nomeCargo, "Compensador de banco");
    CBO[6].cargoID = 413215;

    strcpy(CBO[7].nomeCargo, "Conferente de servi�os banc�rios");
    CBO[7].cargoID = 413220;

    strcpy(CBO[8].nomeCargo, "Escritur�rio de banco");
    CBO[8].cargoID = 413225;

    strcpy(CBO[9].nomeCargo, "Agente de prote��o de aeroporto");
    CBO[9].cargoID = 517305;

    strcpy(CBO[10].nomeCargo, "Ajudante de motorista");
    CBO[10].cargoID = 783225;

    strcpy(CBO[11].nomeCargo, "Engarrafador");
    CBO[11].cargoID = 784120;

    strcpy(CBO[12].nomeCargo, "Encarregado de acabamento de chapas e metais (t�mpera)");
    CBO[12].cargoID = 821405;

    strcpy(CBO[13].nomeCargo, "Escarfador");
    CBO[13].cargoID = 821410;

    strcpy(CBO[14].nomeCargo, "Extrusor de fios ou fibras de vidro");
    CBO[14].cargoID = 823210;



    for(i = 0; i < 15; i++){
        insere_listaE_ordenada(liE, CBO[i]);
    }

}
int insere_listaE_ordenada(ListaE *liE, struct cargo CBO){ //Inser��o de dados ordenados da lista est�tica
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
int consulta_listaE_pos(ListaE *liE, int cargo){ //Consulta da lista estatica atraves da posi��o que no caso � o CODCARGO
    return liE->dados[cargo - 1].cargoID;
}
int menuPosto(ListaE *liE){ //Menu posto usado na hora de selecionar qual profiss�o o funcion�rio atua
    int cargo, x;
    printf("            Menu Postos de trabalho\n");
    printf("1 - Cirurgi�o dentista - cl�nico geral\n");
    printf("2 - Colorista de papel\n");
    printf("3 - Citot�cnico\n");
    printf("4 - En�logo\n");
    printf("5 - Aromista\n");
    printf("6 - Atendente de ag�ncia\n");
    printf("7 - Compensador de banco\n");
    printf("8 - Conferente de servi�os banc�rios\n");
    printf("9 - Escritur�rio de banco\n");
    printf("10 - Agente de prote��o de aeroporto\n");
    printf("11 - Ajudante de motorista\n");
    printf("12 - Engarrafador\n");
    printf("13 - Encarregado de acabamento de chapas e metais (t�mpera)\n");
    printf("14 - Escarfador\n");
    printf("15 - Extrusor de fios ou fibras de vidro\n");
    printf("Digite o n�mero correspodente ao cargo desejado:  ");
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
int menuPrincipal(){ //Menu principal onde escolhe a op��o da lista sequencial
    int opcao;
    printf("1 - Adicionar funcion�rio\n");
    printf("2 - Excluir funcion�rio\n");
    printf("3 - Editar funcion�rio\n");
    printf("4 - Buscar funcion�rio\n");
    printf("5 - Exibir funcion�rios ordenados por ID, com todos os seus dados\n");
    printf("6 - Exibir uma lista de funcion�rios por faixa salarial\n");
    printf("7 - Sair do menu\n");
    printf("Digite a op��o:  ");
    scanf("%d", &opcao);

    return opcao;
}
FUNCIONARIO coletaDados(ListaE *liE){ // o coleta dados dos funcion�rios como por exemplo nome, salario...
    FUNCIONARIO func;
    printf("Informe o no. de identifica��o do funcionario:  ");
    scanf("%d", &func.id);
    getchar();
    printf("Informe o nome do funcionario:  ");
    fgets(func.nome, 64, stdin);
    func.nome[strlen(func.nome)-1]='\0';
    printf("Informe o endere�o do funcionario:  ");
    fgets(func.endereco, 64, stdin);
    func.endereco[strlen(func.endereco)-1]='\0';
    printf("Informe a idade do funcionario:  ");
    scanf("%d", &func.idade);
    printf("Informe o sal�rio do funcionario:  ");
    scanf("%f", &func.salario);
    limpaTela();
    func.cargo = menuPosto(liE);
    return func;
}
int tamanhoLista (Lista *li) { // Fun��o para saber o tamanho da lista, fundamental para aplicar em outras fun��es
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
Lista *criaLista(){ // Cria��o da lista sequencial
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
int listaVazia(Lista *li){ // Verificar se a lista est� vazia, sendo essencial para outras fun��es
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}
int insere_lista_ordenada(Lista *li, FUNCIONARIO database){ // Inserindo dados de forma ordenadada atrav�s do ID
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
int consulta_lista_id(Lista *li, int id, FUNCIONARIO *database){ // Consultando a lista atrav�s do ID
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
int remove_lista(Lista *li, int id){ // Removendo funcion�rios da lista atrav�s do ID
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
int alterarFuncionario(Lista *li, int id, ListaE *liE, FUNCIONARIO database){ // Alterando o Funcion�rio atrav�s do ID
  exibeFuncionarios(database);
  printf("\n\nEdi��o de Funcionario\n");
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
void exibeFuncionarios(FUNCIONARIO database){// Fun��o essencial - sendo utilizada para visualizar os dados
    printf("\nID: %d", database.id);
    printf("\nNome: %s", database.nome);
    printf("\nEndere�o: %s", database.endereco);
    printf("\nIdade: %d", database.idade);
    printf("\nSalario: %.2f", database.salario); //N�O ESQUECE DO CARGO AINDA
    printf("\nC�digo cargo: %d\n\n", database.cargo);
}
void exibeTodosFuncionariosID(Lista *li){ //Exibe todos os funcion�rios por ordem do ID
  FUNCIONARIO database;
  ELEM *no = *li;
  while (no != NULL) {
    database = no->dados;
    exibeFuncionarios(database); //Chama fun��o de exibi��o
    no = no->prox;
  }
}
int buscaFaixa(Lista *li, float minimo, float maximo){ // Buscar funcion�rio atraves do salario min e max
  if(li == NULL){
    return 0;
  }
  FUNCIONARIO database;
  ELEM *no = *li;
  int aux;
    while(no != NULL){
        if(no->dados.salario >= minimo && no->dados.salario <= maximo) {
            database = no->dados;
            printf("Faixa salarial de R$ %.2f � R$ %.2f", minimo, maximo);
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
void apagaLista(Lista *li){ // Antes de sair do menu a lista � apagada
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
int consulta_lista_nome(Lista *li, char *nome, FUNCIONARIO *database){ // Consulta a lista atrav�s do nome
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
int alterarFuncionarioNome(Lista *li, char *nome, ListaE *liE, FUNCIONARIO database){ // Alterando o Funcion�rio atrav�s do ID
  exibeFuncionarios(database);
  printf("\n\nEdi��o de Funcionario\n");
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
int opcaoPergunta(){ // Op��o de pergunta 1 - ID 2 - Nome
    int pergunta;
    printf("Voc� deseja buscar pelo Nome ou pelo ID\n1 - ID\n2 - Nome\nDigite a op��o:  ");
    scanf("%d", &pergunta);
    return pergunta;
}
void libera_lista(ListaE *liE){
    free(liE);
}
