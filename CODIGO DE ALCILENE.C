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
    char validacao_atributo[MAX];

    do
    {

        printf("\nESCOLHA UMA DAS OPCOES DO MENU:\n");
        printf("\n1 - CADASTRO\n2 - BUSCAR REGISTROS\n3 - LISTAR REGISTROS\n4 - ALTERAR REGISTRO\n5 - REMOVER REGISTROS\n6 - SAIR\n");

        fgets(validacao_atributo, sizeof(validacao_atributo), stdin);

        validacao_atributo[strcspn(validacao_atributo, "\n")] = '\0';

        if (validacao_numero(validacao_atributo))
        {
            opcao = atoi(validacao_atributo);
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
    char validacao_atributo[MAX];
    char validacao_sexo[MAX];
    int opcao;

    do
    {
        system("cls");

        printf("INICIALIZANDO O CADASTRO:\n");
        printf("DIGITE AS SEGUINTES INFORMACOES DO PACIENTE:\n");

        do
        {
            printf("\nNOME DO PACIENTE:\n");
            fgets(nome[n], 50, stdin);
            nome[n][strcspn(nome[n], "\n")] = '\0';

            if (strlen(nome[n]) == 0)
            {
                printf("NOME INVALIDO! O CAMPO NAO PODE SER VAZIO.\n");
            }
        } while (strlen(nome[n]) == 0);

        // IDADE
        int idade_valida = 0;
        do
        {
            printf("IDADE DO PACIENTE:\n");
            fgets(validacao_atributo, sizeof(validacao_atributo), stdin);

            validacao_atributo[strcspn(validacao_atributo, "\n")] = '\0';

            if (validacao_numero(validacao_atributo))
            {
                idade[n] = atoi(validacao_atributo);

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
        do
        {
            printf("DIAGNOSTICO DO PACIENTE:\n");
            fgets(diagnostico[n], 100, stdin);
            diagnostico[n][strcspn(diagnostico[n], "\n")] = '\0';

            if (strlen(diagnostico[n]) == 0)
            {
                printf("DIAGNOSTICO INVALIDO! O CAMPO NAO PODE SER VAZIO.\n");
            }
        } while (strlen(diagnostico[n]) == 0);

        system("cls");

        printf("\nINFORMACOES CADASTRADAS:\n");
        printf("NOME: %s\n", nome[n]);
        printf("IDADE: %d\n", idade[n]);
        printf("SEXO: %c\n", sexo[n]);
        printf("DIAGNOSTICO: %s\n", diagnostico[n]);

        n++;

        printf("\nCADASTRO REALIZADO COM SUCESSO!\n");

        printf("\nDESEJA REALIZAR OUTRO CADASTRO?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &opcao);

        getchar();

    } while (opcao == 1);
}

void buscarregistros()
{
    char validacao_atributo[MAX];
    int atributo_valido = 0;
    int atributo;
    int c = 0;
    char idade_busca[MAX];
    int idade_convertida;
    char nome_busca[MAX];
    char sexo_busca;
    char diagnostico_busca[MAX];

    if (n == 0)
    {
        printf("SEM REGISTROS CADASTRADOS\n");
        return;
    }

    system("cls");
    do
    {
        printf("\nDIGITE O NUMERO DO ATRIBUTO QUE DESEJA BUSCAR:\n");
        printf("1 - NOME\n2 - IDADE\n3 - SEXO\n4 - DIAGNOSTICO\n");
        fgets(validacao_atributo, sizeof(validacao_atributo), stdin);

        validacao_atributo[strcspn(validacao_atributo, "\n")] = '\0';

        if (validacao_numero(validacao_atributo))
        {
            atributo = atoi(validacao_atributo);
            atributo_valido = 1;
        }
        else
        {
            printf("DIGITE APENAS NUMEROS.\n");
        }

    } while (!atributo_valido);
    switch (atributo)
    {
    case 1:
        do
        {
            printf("\nDIGITE O NOME QUE DESEJA BUSCAR:\n");
            fgets(nome_busca, sizeof(nome_busca), stdin);
            nome_busca[strcspn(nome_busca, "\n")] = '\0';

            if (strlen(nome_busca) == 0)
            {
                printf("NOME INVALIDO! O CAMPO NAO PODE SER VAZIO.\n");
            }

        } while (strlen(nome_busca) == 0);

        for (int i = 0; i < n; i++)
        {
            if (strcmp(nome[i], nome_busca) == 0)
            {
                printf("\nREGISTRO %d\n", i + 1);
                printf("NOME: %s\nIDADE: %d\nSEXO: %c\nDIAGNOSTICO: %s\n", nome[i], idade[i], sexo[i], diagnostico[i]);
                c++;
            }
        }
        if (c == 0)
        {
            printf("\nNAO EXISTEM REGISTROS COM ESSE NOME!\n");
        }

        c = 0;
        break;

    case 2:
    {
        int idade_valida = 0;

        do
        {
            printf("DIGITE A IDADE QUE DESEJA BUSCAR:\n");
            fgets(idade_busca, sizeof(idade_busca), stdin);
            idade_busca[strcspn(idade_busca, "\n")] = '\0';

            if (validacao_numero(idade_busca))
            {
                idade_convertida = atoi(idade_busca);

                if (idade_convertida >= 0 && idade_convertida <= 130)
                {
                    idade_valida = 1;
                }
                else
                {
                    printf("IDADE FORA DO INTERVALO VALIDO!\n");
                }
            }
            else
            {
                printf("IDADE INVALIDA! DIGITE APENAS NUMEROS.\n");
            }

        } while (!idade_valida);

        for (int i = 0; i < n; i++)
        {
            if (idade[i] == idade_convertida)
            {
                printf("\nREGISTRO %d:\n", i + 1);
                printf("NOME: %s\nIDADE: %d\nSEXO: %c\nDIAGNOSTICO: %s\n", nome[i], idade[i], sexo[i], diagnostico[i]);
                c++;
            }
        }

        if (c == 0)
        {
            printf("NAO EXISTEM REGISTROS COM ESSA IDADE!\n");
        }

        c = 0;
        break;
    }

    case 3:
    {
        char validacao_sexo[MAX];
        int sexo_valido = 0;

        do
        {
            printf("DIGITE O SEXO QUE DESEJA BUSCAR (M OU F):\n");
            fgets(validacao_sexo, sizeof(validacao_sexo), stdin);
            validacao_sexo[strcspn(validacao_sexo, "\n")] = '\0';

            if (validacao_caracter(validacao_sexo))
            {
                sexo_busca = toupper(validacao_sexo[0]);
                sexo_valido = 1;
            }
            else
            {
                printf("SEXO INVALIDO! DIGITE APENAS 'M' OU 'F'.\n");
            }

        } while (!sexo_valido);

        for (int i = 0; i < n; i++)
        {
            if (sexo[i] == sexo_busca)
            {
                printf("\nREGISTRO %d:\n", i + 1);
                printf("NOME: %s\nIDADE: %d\nSEXO: %c\nDIAGNOSTICO: %s\n", nome[i], idade[i], sexo[i], diagnostico[i]);
                c++;
            }
        }

        if (c == 0)
        {
            printf("NAO EXISTEM REGISTROS COM ESSE SEXO!\n");
        }

        c = 0;
        break;
    }

    case 4:
        do
        {
            printf("DIGITE O DIAGNOSTICO QUE DESEJA BUSCAR:\n");
            fgets(diagnostico_busca, sizeof(diagnostico_busca), stdin);
            diagnostico_busca[strcspn(diagnostico_busca, "\n")] = '\0';

            if (strlen(diagnostico_busca) == 0)
            {
                printf("DIAGNOSTICO INVALIDO! O CAMPO NAO PODE SER VAZIO.\n");
            }

        } while (strlen(diagnostico_busca) == 0);

        for (int i = 0; i < n; i++)
        {
            if (strcmp(diagnostico[i], diagnostico_busca) == 0)
            {
                printf("\nREGISTRO %d :\n", i + 1);
                printf("\n\nNOME: %s\nIDADE: %d\nSEXO: %c\nDIAGNOSTICO: %s\n", nome[i], idade[i], sexo[i], diagnostico[i]);
                c++;
            }
        }

        if (c == 0)
        {
            printf("NAO EXISTEM REGISTROS COM ESSE DIAGNOSTICO!\n");
        }
        c = 0;
        break;

    default:
        printf("\nOPCAO INVALIDA! DIGITE UMA OPCAO DE 1 A 4.\n");
    }
}
void listarregistros()
{
    if (n == 0)
    {
        printf("SEM REGISTROS CADASTRADOS.\n");
        return;
    }

    printf("REGISTROS CADASTRADOS:\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nREGISTRO %d\n", i + 1);
        printf("NOME: %s\nIDADE: %d\nSEXO: %c\nDIAGNOSTICO: %s\n", nome[i], idade[i], sexo[i], diagnostico[i]);
    }
}

void alterarregistro()
{
    int op, opcion, confirmacao;
    char name[MAX], diagnostic[MAX], validacao_sexo[MAX];
    char validacao_atributo[MAX];

    if (n == 0)
    {
        printf("SEM REGISTROS CADASTRADOS\n");
        return;
    }

    do
    {
        system("cls");
        buscarregistros();

        printf("DIGITE O NUMERO DO REGISTRO QUE DESEJA ALTERAR:\n");
        scanf("%d", &op);
        op--;

        if (op < 0 || op > n)
        {
            printf("REGISTRO INVALIDO!\n");
            return;
        }

        do
        {

            printf("O QUE VOCE DESEJA ALTERAR?\n1 - NOME\n2 - IDADE\n3 - SEXO\n4 - DIAGNOSTICO\n");
            scanf("%d", &opcion);

            getchar();

            if (opcion < 1 || opcion > 4)
            {
                printf("OPCAO INVALIDA! DIGITE UM NUMERO ENTRE 1 E 4.\n\n");
            }

        } while (opcion < 1 || opcion > 4);

        switch (opcion)
        {
        case 1:

            do
            {
                printf("DIGITE O NOME QUE DESEJAR ADICIONAR:\n");
                fgets(name, 50, stdin); // verificacao de nome

                name[strcspn(name, "\n")] = '\0';

                if (strlen(name) == 0)

                {
                    printf("NOME INVALIDO! O CAMPO NAO PODE SER VAZIO.\n");
                }

            } while (strlen(name) == 0);

            strcpy(nome[op], name);

            printf("\nNOME ALTERADO COM SUCESSO!\n");
            break;

        case 2:
        {
            int idade_valida = 0;

            do
            {

                printf("DIGITE A IDADE QUE DESEJAR ADICIONAR:\n");
                fgets(validacao_atributo, sizeof(validacao_atributo), stdin); // verifcacao de idade

                validacao_atributo[strcspn(validacao_atributo, "\n")] = '\0';

                if (validacao_numero(validacao_atributo))
                {
                    idade[op] = atoi(validacao_atributo);

                    if (idade[op] >= 0 && idade[op] <= 130)
                    {
                        idade_valida = 1;
                    }
                    else
                    {
                        printf("IDADE INVALIDA! DIGITE APENAS NUMEROS.\n");
                    }
                }

                else
                {
                    printf("\nIDADE INVALIDA! DIGITE NOVAMENTE.\n");
                }

            } while (!idade_valida);

            printf("\nIDADE ALTERADO COM SUCESSO!\n");
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
                    sexo[op] = toupper(validacao_sexo[0]);
                    sexo_valido = 1;
                }
                else
                {
                    printf("SEXO INVALIDO! DIGITE APENAS'M' OU 'F'.\n");
                }
            } while (!sexo_valido);

            printf("\nSEXO ALTERADO COM SUCESSO!\n");
            break;
        }

        case 4:
        {
            do
            {

                printf("DIGITE O DIAGNOSTICO QUE DESEJA ALTERAR:\n");
                fgets(diagnostic, 50, stdin); // verificacao de nome

                diagnostic[strcspn(diagnostic, "\n")] = '\0';

                if (strlen(diagnostic) == 0)
                {
                    printf("DIAGNOSTICO INVALIDO! O CAMPO NAO PODE SER VAZIO.\n");
                }

            } while (strlen(diagnostic) == 0);

            strcpy(diagnostico[op], diagnostic);

            printf("\nDIAGNOSTICO ALTERADO COM SUCESSO!\n");
            break;
        }
        }

        printf("DESEJA ALTERAR OUTRO REGISTRO:\n1 - SIM\n2 - NAO\n");
        scanf("%d", &confirmacao);

        getchar();

    } while (confirmacao == 1);
}

void removerregistros()
{
    int encontrou;
    char validacao_remover[MAX];
    int opcao_remover;
    int atributo_valido = 0;

    if (n == 0)
    {
        printf("SEM REGISTROS CADASTRADOS\n");
        return;
    }

    buscarregistros();

    do
    {

        printf("\nDIGITE O NUMERO DO REGISTRO QUE DESEJA REMOVER:\n");

        fgets(validacao_remover, sizeof(validacao_remover), stdin);
        validacao_remover[strcspn(validacao_remover, "\n")] = '\0';

        if (validacao_numero(validacao_remover))
        {
            opcao_remover = atoi(validacao_remover);
            atributo_valido = 1;
        }
        else
        {
            printf("OPCAO INVALIDA!! POR FAVOR TENTE NOVAMENTE");
        }

    } while (!atributo_valido);

    if (opcao_remover > n || opcao_remover < n)
    {
        printf("REGISTRO NAO ENCONTRADO");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (nome[i] == nome[opcao_remover - 1] && idade[i] == idade[opcao_remover - 1] && sexo[i] == sexo[opcao_remover - 1] && diagnostico[i] == diagnostico[opcao_remover - 1])
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
    }
    if (!encontrou)
    {
        printf("\nNENHUM REGISTRO FOI ENCONTRADO");
    }
}

int main()
{
    int opcao;
    int cont = 1;

    do
    {

        opcao = menu();

        switch (opcao)
        {
        case 1:
            system("cls");
            cadastro();

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
            break;

        case 5:
            system("cls");
            removerregistros();
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