#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcionario.h"
#include <ctype.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    //Lista est�tica contendo os cargos
    ListaE *liE;
    liE = cria_lista();
    ocupacoes(liE);

    //Lista sequencial
    float min, max;
    Lista *li = NULL;
    li = criaLista();
    FUNCIONARIO database;
    int opcao = 0;
    int pergunta, consulta, alterar, remover, inserir;
    int id;
    char resp[4], nome[30];


    while(opcao >= 0 && opcao <= 7){
        opcao = menuPrincipal();
        limpaTela();
        switch(opcao){
        case 1:
            printf("Voc� escolheu a op��o 1 - Adicionar funcion�rio\n");
            database = coletaDados(liE); // Coleta os dados do funcion�rio
            inserir = insere_lista_ordenada(li, database); // Insere de forma ordenada os dados coletados
            if(inserir){ // Verifica��o se deu certo ou errado
                printf("Funcionario adicionado com sucesso!!\n\n");
            }else{
                printf("Nao foi possivel adicionar o funcionario!!\n\n");
            }
        break;

        case 2:
            printf("Voc� escolheu a op��o 2 - Excluir funcion�rio\n");
            printf("Digite o ID do funcionario a ser removido: :  ");
            scanf("%d", &id); // a fun��o pede o ID para fazer a busca na fun��o
            consulta = consulta_lista_id(li, id, &database); // Ap�s consultar a lista atrav�s do ID agora ele verifica
            if(consulta){ // Verifica��o
                exibeFuncionarios(database); // Se o resultado retornou 1 ent�o ele exibe o funcion�rio
                fgetchar();
                printf("Digite 'sim' se voc� deseja excluir o funcionario:  "); // Confirma��o de deleta��o
                fgets(resp, 4, stdin);

                if(!strcmp(resp, "sim")){ // Verifica��o se deu certo
                    remover = remove_lista(li, id); // se sim ele � removido
                    if(remover){
                        limpaTela(); // Limpando a tela com system CLS para ajudar na verifica��o
                        printf("Funcionario removido com sucesso!!!\n\n");
                    }else{
                        printf("Funcionario nao removido!!!\n\n");
                    }}else{
                        printf("Funcionario n�o removido\n\n");
                    }
            }else{
                printf("Funcion�rio n�o encontrado!!!\n\n");
            }
        break;

        case 3:
            printf("Voc� escolheu a op��o 3 - Editar funcion�rio");
            pergunta = opcaoPergunta(); // Fun��o que retorna o valor 1 ou 2
            if(pergunta == 1){
            printf("Digite o ID do funcionario a ser alterado:  ");
            scanf("%d", &id);
            consulta = consulta_lista_id(li, id, &database); // Consulta a lista atrav�s do ID
            if(consulta){
                alterar = alterarFuncionario(li, id, liE, database); // Alterando os valores atrav�s do ID
                if(alterar){
                printf("Funcionario alterado com sucesso!!!\n\n");
                }
                else{
                    printf("N�o foi possivel alterar ");
                }
            }
            else{
                printf("N�o foi possivel alterar o funcionario, funcionario n�o encontrado!!!\n\n");
            }
            }
           else if(pergunta == 2){
                printf("Digite o nome do funcionario a ser alterado:  ");
                getchar();
                fgets(nome, 30, stdin);
                nome[strlen(nome)-1]='\0';
                consulta = consulta_lista_nome(li, nome, &database); // Consultando a lista atrav�s do nome
                if(consulta){
                    alterar = alterarFuncionarioNome(li, nome, liE, database); // Alterando a lista atrav�s do nome
                    if(alterar){ // Verificando
                    printf("Funcionario alterado com sucesso!!!\n\n");
                    }
                else{
                    printf("N�o foi possivel alterar ");
                }
                }
            else{
                printf("N�o foi possivel alterar o funcionario, funcionario n�o encontrado!!!\n\n");
                }
            }
            else{

                printf("Op��o invalida\n\n");
            }
        break;

        case 4:
            printf("Voc� escolheu a op��o 4 - Buscar funcion�rio\n");
            pergunta = opcaoPergunta(); // Fun��o que retornar o valor 1 - ID ou 2 - Nome
            if(pergunta == 1){
            printf("Digite o ID do funcionario a ser buscado:  ");
            scanf("%d", &id); // Ap�s os dados da pergunta ele pede o ID
            consulta = consulta_lista_id(li, id, &database); // Com ID ele consulta a lista
            limpaTela();
            if(consulta){
                printf("Funcion�rio encontrado com sucesso\n");
                exibeFuncionarios(database); // Exibindo funcion�rio
            }else{
                printf("Funcion�o n�o encontrado!!!\n\n");
            }
            }
            else if(pergunta == 2){
                printf("Digite o nome do funcionario a ser alterado:  ");
                getchar();
                fgets(nome, 30, stdin);
                nome[strlen(nome)-1]='\0';
                consulta = consulta_lista_nome(li, nome, &database);
                limpaTela();
                if(consulta){
                    printf("Funcion�rio encontrado com sucesso");
                    exibeFuncionarios(database);
                }else{
                    printf("Funcion�o n�o encontrado!!!\n\n");
                }
            }
            else{
                printf("Op��o invalida\n\n");
            }

        break;

        case 5:
            printf("Voc� escolheu a op��o 5 - Exibir funcion�rios ordenados por ID, com todos os seus dados\n");
            if(listaVazia(li)){
                printf("N�o foi possivel encontrar funcionarios, lista vazia\n\n");
            }else{
                exibeTodosFuncionariosID(li); // Fun��o que exibe todos os funcion�rios de ordem de ID
            }
        break;

        case 6:
            printf("Voc� escolheu a op��o 6 - Exibir uma lista de funcion�rios por faixa salarial\n");
            printf("Digite a faixa salarial com minimo e maximo:  ");
            printf("\nDigite o salario minimo:  ");
            scanf("%f", &min);
            printf("Digite o salario maximo:  ");
            scanf("%f", &max);
            limpaTela();
            int consulta = buscaFaixa(li, min, max); // Consulta a lista atrav�s da faixa salarial
            if(!consulta){
                printf("Faixa salarial n�o encontrado\n\n");
            }
        break;

        case 7:
            printf("Voc� escolheu a op��o 7 - Sair do menu\n");
            apagaLista(li); // Ao sair da lista limpa a lista ligada
            libera_lista(liE); // Ao sair da lista limpa a lista est�tica
            printf("Lista est�tica e Lista sequencial apagadas com sucesso\n\n\n");
            exit(1);
        break;

        default:
            printf("Erro op��o invalida"); // Caso o usu�rio digita uma op��o invalida ocorre esse erro
            exit(1);
        break;
}
}
}

