#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int n = 0;
int idade[MAX];
char nome[MAX][50];
char diagnostico[MAX][100];
char sexo[MAX];

int validacao_numero(char entrada[])
{
    int i = 0;

    // Pula espaços em branco no começo
    while (entrada[i] == ' ')
    {
        i++;
    }

    // Verifica se a string está vazia
    if (entrada[i] == '\0')
    {
        return 0;
    }

    // Verifica se todos os caracteres são dígitos
    while (entrada[i] != '\0')
    {
        if (entrada[i] < '0' || entrada[i] > '9')
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int menu()
{
    int opcao;
    char validacao_opcao[MAX];

    do
    {

        printf("\nESCOLHA UMA DAS OPCOES DO MENU:\n");
        printf("\n1 - CADASTRO\n2 - BUSCAR REGISTROS\n3 - LISTAR REGISTROS\n4 - ALTERAR REGISTRO\n5 - REMOVER REGISTROS\n6 - SAIR\n");

        fgets(validacao_opcao, sizeof(validacao_opcao), stdin);

        validacao_opcao[strcspn(validacao_opcao, "\n")] = '\0';

        if (validacao_numero(validacao_opcao))
        {
            opcao = atoi(validacao_opcao);
        }

        else
        {
            opcao = 0;
        }

        if (opcao < 1 || opcao > 6)
        {
            printf("\nOPCAO INVALIDA! TENTE NOVAMENTE.\n");
        }

    } while (opcao < 1 || opcao > 6);

    return opcao;
}

int validacao_caracter(char entrada[])
{
    // Verifica se há exatamente um caractere (além do '\0')
    if (strlen(entrada) != 1)
    {
        return 0;
    }

    // Converte para maiúsculo
    char c = toupper(entrada[0]);

    // Verifica se é 'M' ou 'F'
    if (c == 'M' || c == 'F')
    {
        return 1;
    }

    return 0;
}
void cadastro()
{
    char validacao_idade[MAX];
    char validacao_sexo[MAX];
    int opcao;

    do
    {
        system("cls");

        printf("INICIALIZANDO O CADASTRO:\n");
        printf("DIGITE AS SEGUINTES INFORMACOES DO PACIENTE:\n");

        printf("\nNOME DO PACIENTE:\n");
        fgets(nome[n], 50, stdin);
        nome[n][strcspn(nome[n], "\n")] = '\0';

        // IDADE
        int idade_valida = 0;
        do
        {
            printf("IDADE DO PACIENTE:\n");
            fgets(validacao_idade, sizeof(validacao_idade), stdin);

            validacao_idade[strcspn(validacao_idade, "\n")] = '\0';

            if (validacao_numero(validacao_idade))
            {
                idade[n] = atoi(validacao_idade);

                if (idade[n] >= 0 && idade[n] <= 130)
                {
                    idade_valida = 1;
                }

                else
                {
                    printf("IDADE INVALIDA! DIGITE A IDADE NOVAMENTE.\n");
                }
            }

            else
            {
                printf("IDADE INVALIDA! DIGITE APENAS NUMEROS.\n");
            }
        } while (!idade_valida);

        // SEXO
        int sexo_valido = 0;
        do
        {
            printf("SEXO DO PACIENTE (M ou F):\n");
            fgets(validacao_sexo, sizeof(validacao_sexo), stdin);

            validacao_sexo[strcspn(validacao_sexo, "\n")] = '\0';

            if (validacao_caracter(validacao_sexo))
            {
                sexo[n] = toupper(validacao_sexo[0]);
                sexo_valido = 1;
            }
            else
            {
                printf("SEXO INVALIDO! DIGITE APENAS'M' OU 'F'.\n");
            }
        } while (!sexo_valido);

        // DIAGNÓSTICO
        printf("DIAGNOSTICO DO PACIENTE:\n");
        fgets(diagnostico[n], 100, stdin);

        diagnostico[n][strcspn(diagnostico[n], "\n")] = '\0';

        system("cls");

        printf("\nINFORMACOES CADASTRADAS:\n");
        printf("NOME: %s\n", nome[n]);
        printf("IDADE: %d\n", idade[n]);
        printf("SEXO: %c\n", sexo[n]);
        printf("DIAGNOSTICO: %s\n", diagnostico[n]);

        n++;

        printf("\nDESEJA REALIZAR OUTRO CADASTRO?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);

        getchar();

    } while (opcao == 1);
}
void buscarregistros()
{
    int opcao;
    char nomebusca[MAX];
    int encontrou;

    do
    {
        system("cls");

        for (int i = 0; i < n; i++)
        {
            printf("%d - %s\n", i + 1, nome[i]);
        }

        printf("\n");

        printf("DIGITE O REGISTRO QUE DESEJA BUSCAR:\n");
        getchar();
        fgets(nomebusca, sizeof(nomebusca), stdin);

        nomebusca[strcspn(nomebusca, "\n")] = '\0';

        printf("\n");

        encontrou = 0;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(nome[i], nomebusca) == 0) // nomes iguais
            {
                printf("\nREGISTRO ENCONTRADO:\n");
                printf("Nome: %s\n", nome[i]);
                printf("Idade: %d\n", idade[i]);
                printf("Sexo: %c\n", sexo[i]);
                printf("Diagnostico: %s\n", diagnostico[i]);

                encontrou = 1;
                break; // se quiser mostrar só o primeiro registro que bate, se quiser todos, remova o break
            }
        }

        if (!encontrou)
        {
            printf("\nNenhum registro encontrado para o nome: %s\n", nomebusca);
        }

        printf("\nDESEJA BUSCAR OUTRO REGISTRO?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);

    } while (opcao == 1);
}

void listarregistros()
{
    printf("REGISTROS CADASTRADOS:\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d - %s\n", i + 1, nome[i]);
    }
}

void alterarregistro()
{
    int op, opcion, encontrou = 0;
    char name[50], diagnostic[50], validacao_sexo[MAX];
    char alterarregistro[MAX], validacao_idade[MAX];

    do
    {
        system("cls");

        for (int i = 0; i < n; i++)
        {
            printf("%d - %s\n", i + 1, nome[i]);
        }

        printf("\nDIGITE O REGISTRO QUE DESEJA ALTERAR:\n");
        fgets(alterarregistro, sizeof(alterarregistro), stdin);

        alterarregistro[strcspn(alterarregistro, "\n")] = '\0';

        for (int i = 0; i < n; i++)
        {
            if (strcmp(nome[i], alterarregistro) == 0) // nomes iguais
            {
                encontrou = 1;

                printf("\nREGISTRO ENCONTRADO:\n");
                printf("Nome: %s\n", nome[i]);
                printf("Idade: %d\n", idade[i]);
                printf("Sexo: %c\n", sexo[i]);
                printf("Diagnostico: %s\n", diagnostico[i]);

                printf("O QUE VOCE DESEJA ALTERAR?\n1 - NOME\n2 - IDADE\n3 - SEXO\n4 - DIAGNOSTICO\n");
                scanf("%d", &op);

                getchar();

                switch (op)
                {
                 case 1:

                    printf("DIGITE O NOME QUE DESEJAR ADICIONAR:\n");
                    fgets(name, 50, stdin); // verificacao de nome

                    name[strcspn(name, "\n")] = '\0';

                    strcpy(nome[i], name);
                    break;

                 case 2:
                 {
                    int idade_valida = 0;

                    do
                    {

                        printf("DIGITE A IDADE QUE DESEJAR ADICIONAR:\n");
                        fgets(validacao_idade, sizeof(validacao_idade), stdin); // verifcacao de idade

                        validacao_idade[strcspn(validacao_idade, "\n")] = '\0';

                        if (validacao_numero(validacao_idade))
                        {
                            idade[i] = atoi(validacao_idade);

                            if (idade[i] >= 0 && idade[i] <= 130)
                            {
                                idade_valida = 1;
                            }

                            else
                            {
                                printf("IDADE INVALIDA! DIGITE AOENAS NUMEROS.\n");
                            }
                        }

                        else
                        {
                            printf("\nIDADE INVALIDA! DIGITE NOVAMENTE.\n");
                        }

                    }while(!idade_valida);
                    break;
                 }

                 case 3:
                 {

                    int sexo_valido = 0;

                    do
                    {

                        printf("DIGITE O SEXO QUE DESEJA ADICIONAR(M/F):");
                        fgets(validacao_sexo, sizeof(validacao_sexo), stdin); // verificacao de caracter

                        validacao_sexo[strcspn(validacao_sexo, "\n")] = '\0';

                        if (validacao_caracter(validacao_sexo))
                        {
                            sexo[i] = toupper(validacao_sexo[0]);
                            sexo_valido = 1;
                        }
                        else
                        {
                            printf("SEXO INVALIDO! DIGITE APENAS'M' OU 'F'.\n");
                        }
                    }while(!sexo_valido);
                    break;
                 }

                 case 4:
                 {
                    printf("DIGITE O DIAGNOSTICO QUE DESEJA ALTERAR:\n");
                    fgets(diagnostic, 50, stdin); // verificacao de nome

                    diagnostic[strcspn(diagnostic, "\n")] = '\0';

                    strcpy(diagnostico[i], diagnostic);
                    break;
                 }

                 default:

                    printf("OPCAO INVALIDA\nDIGITE UMA OPCAO VALIDA:\n");
                    break;
                }

                break; // se quiser mostrar só o primeiro registro que bate, se quiser todos, remova o break
            }
        }

        if (!encontrou)
        {
            printf("\nNENHUM REGISTRO COM O NOME '%s' FOI ENCONTRADO.\n", alterarregistro);
        }

        printf("DESEJA ALTERAR OUTRO REGISTRO?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcion);

        getchar();

    } while (opcion == 1);
}

void removerregistros()
{
    int opcion, encontrou;
    char nomeremover[MAX];

    do
    {
        listarregistros();

        printf("\nQUAL REGISTRO DESEJA REMOVER?\n");
        getchar();
        fgets(nomeremover, sizeof(nomeremover), stdin);

        nomeremover[strcspn(nomeremover, "\n")] = '\0';

        encontrou = 0;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(nome[i], nomeremover) == 0)
            {
                for (int j = i; j < n - 1; j++)
                {
                    strcpy(nome[j], nome[j + 1]);
                    idade[j] = idade[j + 1];
                    sexo[j] = sexo[j + 1];
                    strcpy(diagnostico[j], diagnostico[j + 1]);
                }

                n--;
                encontrou = 1;
                printf("REGISTRO REMOVIDO COM SUCESSO!\n");
                break;
            }
        }

        if (!encontrou)
        {
            printf("\nNENHUM REGISTRO COM O NOME '%s' FOI ENCONTRADO.\n", nomeremover);
        }

        printf("\nDESEJA REMOVER OUTRO REGISTRO?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcion);

    } while (opcion == 1);
}

int main()
{
    int opcao;
    int cont = 1;

    do
    {
        system("cls");
        opcao = menu();

        switch (opcao)
        {
        case 1:
            system("cls");
            cadastro();
            printf("\nCADASTRO REALIZADO COM SUCESSO!\n");
            break;

        case 2:
            system("cls");
            buscarregistros();
            break;

        case 3:
            system("cls");
            listarregistros();
            break;

        case 4:
            system("cls");
            alterarregistro();
            printf("\nREGISTRO ALTERADO COM SUCESSO!\n");
            break;

        case 5:
            system("cls");
            removerregistros();
            printf("O REGISTRO FOI REMOVIDO!\n");
            break;

        case 6:
            cont = 0;
            printf("PROGRAMA FINALIZANDO!\n");
            break;

        default:

            printf("OPCAO INVALIDA!\nTENTE NOVAMENTE.\n");
            break;
        }
    } while (cont);
}