#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcionario.h"
#include <ctype.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    //Lista estática contendo os cargos
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
            printf("Você escolheu a opção 1 - Adicionar funcionário\n");
            database = coletaDados(liE); // Coleta os dados do funcionário
            inserir = insere_lista_ordenada(li, database); // Insere de forma ordenada os dados coletados
            if(inserir){ // Verificação se deu certo ou errado
                printf("Funcionario adicionado com sucesso!!\n\n");
            }else{
                printf("Nao foi possivel adicionar o funcionario!!\n\n");
            }
        break;

        case 2:
            printf("Você escolheu a opção 2 - Excluir funcionário\n");
            printf("Digite o ID do funcionario a ser removido: :  ");
            scanf("%d", &id); // a função pede o ID para fazer a busca na função
            consulta = consulta_lista_id(li, id, &database); // Após consultar a lista através do ID agora ele verifica
            if(consulta){ // Verificação
                exibeFuncionarios(database); // Se o resultado retornou 1 então ele exibe o funcionário
                fgetchar();
                printf("Digite 'sim' se você deseja excluir o funcionario:  "); // Confirmação de deletação
                fgets(resp, 4, stdin);

                if(!strcmp(resp, "sim")){ // Verificação se deu certo
                    remover = remove_lista(li, id); // se sim ele é removido
                    if(remover){
                        limpaTela(); // Limpando a tela com system CLS para ajudar na verificação
                        printf("Funcionario removido com sucesso!!!\n\n");
                    }else{
                        printf("Funcionario nao removido!!!\n\n");
                    }}else{
                        printf("Funcionario não removido\n\n");
                    }
            }else{
                printf("Funcionário não encontrado!!!\n\n");
            }
        break;

        case 3:
            printf("Você escolheu a opção 3 - Editar funcionário");
            pergunta = opcaoPergunta(); // Função que retorna o valor 1 ou 2
            if(pergunta == 1){
            printf("Digite o ID do funcionario a ser alterado:  ");
            scanf("%d", &id);
            consulta = consulta_lista_id(li, id, &database); // Consulta a lista através do ID
            if(consulta){
                alterar = alterarFuncionario(li, id, liE, database); // Alterando os valores através do ID
                if(alterar){
                printf("Funcionario alterado com sucesso!!!\n\n");
                }
                else{
                    printf("Não foi possivel alterar ");
                }
            }
            else{
                printf("Não foi possivel alterar o funcionario, funcionario não encontrado!!!\n\n");
            }
            }
           else if(pergunta == 2){
                printf("Digite o nome do funcionario a ser alterado:  ");
                getchar();
                fgets(nome, 30, stdin);
                nome[strlen(nome)-1]='\0';
                consulta = consulta_lista_nome(li, nome, &database); // Consultando a lista através do nome
                if(consulta){
                    alterar = alterarFuncionarioNome(li, nome, liE, database); // Alterando a lista através do nome
                    if(alterar){ // Verificando
                    printf("Funcionario alterado com sucesso!!!\n\n");
                    }
                else{
                    printf("Não foi possivel alterar ");
                }
                }
            else{
                printf("Não foi possivel alterar o funcionario, funcionario não encontrado!!!\n\n");
                }
            }
            else{

                printf("Opção invalida\n\n");
            }
        break;

        case 4:
            printf("Você escolheu a opção 4 - Buscar funcionário\n");
            pergunta = opcaoPergunta(); // Função que retornar o valor 1 - ID ou 2 - Nome
            if(pergunta == 1){
            printf("Digite o ID do funcionario a ser buscado:  ");
            scanf("%d", &id); // Após os dados da pergunta ele pede o ID
            consulta = consulta_lista_id(li, id, &database); // Com ID ele consulta a lista
            limpaTela();
            if(consulta){
                printf("Funcionário encontrado com sucesso\n");
                exibeFuncionarios(database); // Exibindo funcionário
            }else{
                printf("Funcionão não encontrado!!!\n\n");
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
                    printf("Funcionário encontrado com sucesso");
                    exibeFuncionarios(database);
                }else{
                    printf("Funcionão não encontrado!!!\n\n");
                }
            }
            else{
                printf("Opção invalida\n\n");
            }

        break;

        case 5:
            printf("Você escolheu a opção 5 - Exibir funcionários ordenados por ID, com todos os seus dados\n");
            if(listaVazia(li)){
                printf("Não foi possivel encontrar funcionarios, lista vazia\n\n");
            }else{
                exibeTodosFuncionariosID(li); // Função que exibe todos os funcionários de ordem de ID
            }
        break;

        case 6:
            printf("Você escolheu a opção 6 - Exibir uma lista de funcionários por faixa salarial\n");
            printf("Digite a faixa salarial com minimo e maximo:  ");
            printf("\nDigite o salario minimo:  ");
            scanf("%f", &min);
            printf("Digite o salario maximo:  ");
            scanf("%f", &max);
            limpaTela();
            int consulta = buscaFaixa(li, min, max); // Consulta a lista através da faixa salarial
            if(!consulta){
                printf("Faixa salarial não encontrado\n\n");
            }
        break;

        case 7:
            printf("Você escolheu a opção 7 - Sair do menu\n");
            apagaLista(li); // Ao sair da lista limpa a lista ligada
            libera_lista(liE); // Ao sair da lista limpa a lista estática
            printf("Lista estática e Lista sequencial apagadas com sucesso\n\n\n");
            exit(1);
        break;

        default:
            printf("Erro opção invalida"); // Caso o usuário digita uma opção invalida ocorre esse erro
            exit(1);
        break;
}
}
}

