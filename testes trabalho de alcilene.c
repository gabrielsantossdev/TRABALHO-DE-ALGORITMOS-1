#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int n = 0;
int idade[MAX];
char nome[MAX][50];
char diagnostico[MAX][100];
char sexo[MAX];

int menu()
{
    int opcao;

    printf("\nESCOLHA UMA DAS OPCOES DO MENU:\n");
    printf("\n1 - CADASTRO\n2 - BUSCAR REGISTROS\n3 - LISTAR REGISTROS\n4 - ALTERAR REGISTRO\n5 - REMOVER REGISTROS\n6 - SAIR\n");

    scanf("%d", &opcao);

    return opcao;
}

void cadastro()
{

    printf("INICIALIZANDO O CADASTRO:\n");
    printf("DIGITE AS SEGUINTES INFORMACOES DO PACIENTE:\n\n");

    getchar();

    printf("NOME DO PACIENTE:\n");
    fgets(nome[n], 50, stdin);

    nome[n][strcspn(nome[n], "\n")] = '\0';

    printf("IDADE DO PACIENTE:\n");
    scanf("%d", &idade[n]);

    printf("SEXO DO PACIENTE (M ou F):\n");
    scanf(" %c", &sexo[n]);

    getchar();

    printf("DIAGNOSTICO DO PACIENTE:\n");
    fgets(diagnostico[n], 100, stdin);

    diagnostico[n][strcspn(diagnostico[n], "\n")] = '\0';

    n++;
}

void buscarregistros()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d - %s\n", i + 1, nome[i]);
    }

    printf("\n");

    int registro;

    printf("DIGITE O REGISTRO QUE DESEJA BUSCAR:\n");
    scanf("%d", &registro);

    printf("\n");

    if (registro > n || registro < 1)
    {
        printf("REGISTRO INVALIDO!\n");
        return;
    }

    int i = registro - 1;

    printf("Nome: %s\n", nome[i]);
    printf("Idade: %d\n", idade[i]);
    printf("Sexo: %c\n", sexo[i]);
    printf("Diagnostico: %s\n", diagnostico[i]);
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
    int alterar, op, id;
    char name[50], diagnostic[50], sex;

    printf("DIGITE O REGISTRO QUE DESEJA ALTERAR:\n");
    scanf("%d", &alterar);

    if (alterar < 1 || alterar > n)
    {
        printf("REGISTRO INVALIDO!\n");
        return;
    }

    printf("INFORMACOES DO REGISTRO ATUAL:\n");

    printf("NOME: %s\n", nome[alterar - 1]);
    printf("IDADE: %d\n", idade[alterar - 1]);
    printf("SEXO: %c\n", sexo[alterar - 1]);
    printf("DIAGNOSTICO: %s\n", diagnostico[alterar - 1]);

    printf("\nQUAL INFORMACAO VOCE DESEJA ALTERAR?\n");
    printf("1 - NOME\n2 - IDADE\n3 - SEXO\n4 - DIAGNOSTICO\n");
    scanf("%d", &op);

    getchar();

    switch (op)
    {
    case 1:
        printf("DIGITE O NOME QUE DESEJAR ADICIONAR:\n");
        fgets(name, 50, stdin);

        name[strcspn(name, "\n")] = '\0'; 

        strcpy(nome[alterar - 1], name);
        break;

    case 2:
        printf("DIGITE A IDADE QUE DESEJAR ADICIONAR:\n");
        scanf("%d", &id);

        getchar();

        idade[alterar - 1] = id;
        break;

    case 3:
        printf("DIGITE O SEXO QUE DESEJA ADICIONAR(M/F):");
        scanf(" %c", &sex);

        getchar();

        sexo[alterar - 1] = sex;
        break;

    case 4:
        printf("DIGITE O DIAGNOSTICO QUE DESEJA ALTERAR:\n");
        fgets(diagnostic, 50, stdin);

        diagnostic[strcspn(diagnostic, "\n")] = '\0'; 

        strcpy(diagnostico[alterar - 1], diagnostic);
        break;

    default:
        printf("OPCAO INVALIDA\nDIGITE UMA OPCAO VALIDA:\n");
        break;
    }
}

void removerregistros()
{
    int remo;
    
    printf("QUAL REGISTRO DESEJA REMOVER?\n\n");

    listarregistros();

    scanf("%d", &remo);

    if (remo >= 1 && remo <= n)
    {
        for (int i = 0; i < n; i++)
        {
            if (remo - 1 == i)
            {
                for (int j = i; j < n - 1; j++)
                {
                    strcpy(nome[j], nome[j + 1]);
                    idade[j] = idade[j + 1];
                    sexo[j] = sexo[j + 1];
                    strcpy(diagnostico[j], diagnostico[j + 1]);
                }

                n--;
                break;
            }
        }
    }

    else
    {
        printf("REGISTRO INVALIDO!\nDIGITE UM REGISTRO VALIDO!\n");
        return;
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