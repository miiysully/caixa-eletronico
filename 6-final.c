#include <stdio.h>

char novoSaque;
int saldoAtual, saldoRestante, valorSaque, contador, saqueRecalculado, aux, saldoFinal;
int numeroCedulas = 6;

int quantidadeCedulas[6] = {0};
int valorCedulas[6] = {100, 50, 20, 10, 5, 2};

int saldo(void);
int sacar(void);
int saldoRetirado(int saldoAtual, int valorSaque);
int calculadora(int ValorSaque);
void recalculadora(int saqueRecalculado);
void cedulas();

int main(){

    printf("\nSeja bem vindo(a) a nossa agencia!\n");
    printf("----------------------------------\n");

    saldo();

    do{
        sacar();

        saldoFinal = saldoRetirado(saldoAtual, valorSaque);
        calculadora(valorSaque);

        if(valorSaque != 1){
            cedulas();
        }
        else{
            recalculadora(saqueRecalculado);
            cedulas();
}
        printf("\nSaldo restante: R$%d.\n", saldoFinal);

        saldoAtual = saldoFinal;

        printf("Voce quer realizar um novo saque? 's' ou 'n':\n");
        scanf(" %c", &novoSaque);
        getchar();

        while(novoSaque != 's' && novoSaque != 'S' && novoSaque != 'n' && novoSaque != 'N'){
            printf("Opcao invalida, digite 's' ou 'n':\n");
            scanf(" %c", &novoSaque);
            getchar();
        }

        if(novoSaque == 'n' || novoSaque == 'N'){
            printf("Obrigado por usar a nossa agencia!\n");
            break;
        }
        else if (saldoFinal == 0){
            printf("Saldo insuficiente. Obrigado por usar a nossa agencia!\n");
            break;
        }

    } while (1);

    return 0;
}

int saldo(void){
    printf("Digite o seu saldo: ");
    if(scanf("%d", &saldoAtual) != 1){
        printf("\nDigite um valor valido para saldo!\n");
        while(getchar() != '\n');
            return saldo();
    }

    // Impossível sacar um valor negativo.
    while(saldoAtual < 0){
        printf("\nNao podemos ter saldo negativo. Digite um valor valido para saldo!\n");
        return saldo();
    }
    // Impossível sacar sem saldo em conta.
    while(saldoAtual == 1 || saldoAtual == 3){
        printf("\nDigite um valor valido para saldo!\n");
        return saldo();
    }

    while(saldoAtual == 0){
        printf("\nNao e possivel sacar sem saldo em conta!\n");
        return saldo();
    }

    return 0;
}

int sacar(void){
    printf("\nQuanto voce quer sacar?: ");
    if(scanf("%d", &valorSaque) != 1){
        printf("Digite um valor valido para saque!\n");
        while(getchar() != '\n');
            return sacar();
    }
    aux = valorSaque;

    // Impossivel sacar um valor negativo.
    while(valorSaque < 0){
        printf("Nao e possivel sacar um valor negativo. Insira um valor valido!\n");
        return sacar();
    }
    // Impossivel sacar sem saldo em conta.
    while(valorSaque == 0){
        printf("Nao e possivel sacar 0 reais. Insira um valor valido!\n");
        return sacar();
    }
    // Não existe notas de 1 e 3 reais.
    while(valorSaque == 1 || valorSaque == 3){
        printf("Nota inexistente. Digite um valor valido!\n");
        return sacar();
    }
    // Impossivel sacar um valor que maior que o saldo.
    while(saldoAtual < valorSaque){
        printf("Saldo insuficiente, saque um valor compativel com o seu saldo: ");
        return sacar();
    }

    return 0;
}

int saldoRetirado(int saldoAtual, int valorSaque){
    saldoRestante = saldoAtual - valorSaque;
    return saldoRestante;
}

int calculadora(int ValorSaque){
    quantidadeCedulas[0] = valorSaque / 100;
    valorSaque = valorSaque % 100;

    quantidadeCedulas[1] = valorSaque / 50;
    valorSaque = valorSaque % 50;

    quantidadeCedulas[2] = valorSaque / 20;
    valorSaque = valorSaque % 20;

    quantidadeCedulas[3] = valorSaque / 10;
    valorSaque = valorSaque % 10;

    quantidadeCedulas[4] = valorSaque / 5;
    valorSaque = valorSaque % 5;

    quantidadeCedulas[5] = valorSaque / 2;
    valorSaque = valorSaque % 2;

    return valorSaque;
}

void recalculadora(int saqueRecalculado){
    if (aux % 2 == 0 && valorSaque == 1){
        saqueRecalculado = aux - 6;
    }
    else if (aux % 2 != 0 && valorSaque == 1){
        saqueRecalculado = aux - 7;
    }

    quantidadeCedulas[0] = saqueRecalculado / 100;
    saqueRecalculado = saqueRecalculado % 100;

    quantidadeCedulas[1] = saqueRecalculado / 50;
    saqueRecalculado = saqueRecalculado % 50;

    quantidadeCedulas[2] = saqueRecalculado / 20;
    saqueRecalculado = saqueRecalculado % 20;

    quantidadeCedulas[3] = saqueRecalculado / 10;
    saqueRecalculado = saqueRecalculado % 10;

    quantidadeCedulas[5] = saqueRecalculado / 2;
    saqueRecalculado = saqueRecalculado % 2;

    quantidadeCedulas[4] = saqueRecalculado / 5;
    saqueRecalculado = saqueRecalculado % 5;

    if (aux % 2 != 0 && valorSaque == 1){
        quantidadeCedulas[4] = quantidadeCedulas[4] + 1;
        quantidadeCedulas[5] = quantidadeCedulas[5] + 1;
    }
    else if (aux % 2 == 0 && valorSaque == 1){
        quantidadeCedulas[5] = quantidadeCedulas[5] + 3;
}
    return;
}

void cedulas(){
    for(contador = 0; contador < numeroCedulas; contador++){
        if(quantidadeCedulas[contador] > 1){
            printf("Voce recebeu %d notas de R$%d.\n", quantidadeCedulas[contador], valorCedulas[contador]);
            }

        if(quantidadeCedulas[contador] == 1){
            printf("Voce recebeu %d nota de R$%d.\n", quantidadeCedulas[contador], valorCedulas[contador]);
    }
    }
    return;
}
