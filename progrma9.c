#include <stdio.h>         //Importação da bibliotecas
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTES 5

struct s_cliente {        //Definindo variáveis 
    char nome[50];
    char rg[15];
    char cpf[15];
    int idade;
    char sexo;
};
 
struct s_cliente clientes[MAX_CLIENTES];  //Entrada de dados
int i;
int n_clientes = 0;

void cadastraCliente(struct s_cliente cliente) {
    clientes[n_clientes] = cliente;
    n_clientes++;
}

struct s_cliente leDados() {
    struct s_cliente auxiliar;
    printf("\n\n");
    printf("Nome: ");
    fflush(stdin);
    fgets(auxiliar.nome, 50, stdin);
    printf("RG: ");
    fflush(stdin);
    fgets(auxiliar.rg, 15, stdin);
    printf("CPF: ");
    fflush(stdin);
    fgets(auxiliar.cpf, 15, stdin);
    printf("Sexo: ");
    fflush(stdin);
    scanf("%c", &auxiliar.sexo);
    printf("Idade: ");
    fflush(stdin);
    scanf("%d", &auxiliar.idade);
    return auxiliar;
}

                                 
void imprimeClientes() {          //Entrada de dados
    for (i=0; i<n_clientes; i++) {
        printf("Codigo: %d\n", i+1);
        printf("Nome..: %s", clientes[i].nome);
        printf("RG....: %s", clientes[i].rg);
        printf("CPF...: %s", clientes[i].cpf);
        printf("Sexo..: %c", clientes[i].sexo);
        printf("\nIdade.: %d", clientes[i].idade);
        printf("\n+++++++++++++++++++\n");
    }
}

int menu() {             //main
    int opcao;

    printf("Cadastro de Clientes\n");
    printf("0 - Fim \n");
    printf("1 - Inclui \n");
    printf("2 - Altera \n");
    printf("3 - Exclui\n");
    printf("4 - Consulta \n");
    printf("Opção: ");
    scanf("%d", &opcao);

    return opcao;
}


void altera(int posicao) {
    int indice = posicao - 1;
    int i = 0;

    if ((posicao < 1) || (posicao > n_clientes)) {
        printf("\nPosicao invalida!\n");
        return;
    }

    for (i=indice; i<=n_clientes; i++) { //processamento de dados
        if(i == posicao){
            printf("Codigo: %d\n", i+1);
            printf("Nome..: %s", clientes[i].nome);
            printf("RG....: %s", clientes[i].rg);
            printf("CPF...: %s", clientes[i].cpf);
            printf("Sexo..: %c", clientes[i].sexo);
            printf("\nIdade.: %d", clientes[i].idade);
            printf("\n+++++++++++++++++++\n");
            printf("Nome: ");
            fflush(stdin);
            fgets(clientes[i].nome, 50, stdin);
            printf("RG: ");
            fflush(stdin);
            fgets(clientes[i].rg, 15, stdin);
            printf("CPF: ");
            fflush(stdin);
            fgets(clientes[i].cpf, 15, stdin);
            printf("Sexo: ");
            fflush(stdin);
            scanf("%c", &clientes[i].sexo);
            printf("Idade: ");
            fflush(stdin);
            scanf("%d", &clientes[i].idade);
            return;
        }
    }
}

void remover(int posicao) { //entrada
    int indice = posicao - 1;
    int i = 0;

    if ((posicao < 1) || (posicao > n_clientes)) {
        printf("\nPosicao invalida!\n");
        return;
    }

    if (posicao == n_clientes) {
        n_clientes--;
        return;
    }

    for (i=indice; i<n_clientes; i++) {
        clientes[i] = clientes[i+1];
    }
    n_clientes--;
}

int main()
{
    int opcao_selecionada;
    int rem = 0;
    struct s_cliente novo_cliente;
    int r;

    do {
        opcao_selecionada = menu();
        switch(opcao_selecionada) { //processamento
            case 0: break;
            case 1:
                if (n_clientes == MAX_CLIENTES) {
                    printf("\nBANCO DE DADOS LOTADO!\n");
                    break;
                }
                novo_cliente = leDados();
                cadastraCliente(novo_cliente);
                break;
            case 2:
                printf("Digite a posicao que deseja alterar: ");
                scanf("%d", &r);
                altera(r);
                break;
            case 3:
                printf("Digite a posicao que deseja excluir: ");
                scanf("%d", &r);
                remover(r);
                break;
            case 4:
                imprimeClientes();
                break;
            default:
                printf("----- OPCAO INVALIDA -----");
        }
    }
    while (opcao_selecionada != 0);
    return 0;
}
