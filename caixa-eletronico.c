#include <stdio.h>

char novoSaque ='n';
int saldoAtual, saldoRestante, valorSaque, contador, saqueRecalculado, aux, saldoFinal;
int Numerocedulas = 6;

int quantidadeCedulas[6] = {0};
int valorCedulas[6] = {100, 50, 20, 10, 5, 2};

// Funções para o programa.

// Função para saldo:
int saldo(void){
    printf("Digite o seu saldo: ");
    scanf("%d", &saldoAtual);
    getchar();
    // Impossível sacar um valor negativo.
    while(saldoAtual < 0){
        printf("Digite um valor valido para saldo: ");
        scanf("%d", &saldoAtual);
        getchar();
    }
    // Impossível sacar sem saldo em conta.
    while(saldoAtual==0){
        printf("Nao e possivel sacar sem saldo em conta.\n\n");
        printf("Digite seu novo saldo: ");
        scanf("%d", &saldoAtual);
        getchar();
    }

}

// Função para saque:
int sacar(void){
    printf("\nQuanto voce quer sacar?: ");
    scanf("%d", &valorSaque);
    getchar();
    aux = valorSaque;

    // Impossivel sacar um valor negativo.
    while(valorSaque < 0){
        printf("Nao e possivel sacar um valor negativo. Ensira um valor valido.\n");
        printf("\nQuanto voce quer sacar?: ");
        scanf("%d", &valorSaque);
        getchar();
    }
    // Impossivel sacar sem saldo em conta.
    while(valorSaque==0){
        printf("Nao e possivel sacar 0 reais. Ensira um valor valido.\n");
        printf("\nQuanto voce quer sacar?: ");
        scanf("%d", &valorSaque);
        getchar();
    }
    // Não existe notas de 1 e 3 reais.
    while(valorSaque == 1 || valorSaque == 3){
        printf("Nao e possivel sacar esse valor. Ensira um valor valido.\n");
        printf("\nQuanto voce quer sacar?: ");
        scanf("%d", &valorSaque);
        getchar();
    }
    // Impossivel sacar um valor que maior que o saldo.
    while(saldoAtual < valorSaque){
        printf("Saldo insuficiente, saque outro valor: ");
        scanf("%d", &valorSaque);
        getchar();
    }
}

// Função para a retirada do dinheiro:
int saldoRetirado(int saldoAtual, int valorSaque){
    saldoRestante = saldoAtual - valorSaque;
    return saldoRestante;
}

// Função para calcular as notas:
int calculadora(int ValorSaque){
    quantidadeCedulas[0]= valorSaque / 100;
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

// Função para poder sacar valor impar (143 por exemplo):
int recalculadora(int saqueRecalculado){
    if (aux % 2 == 0 && valorSaque ==1){
        saqueRecalculado = aux - 6;
    }
    else if (aux % 2 != 0 && valorSaque==1){
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
    else if (aux%2==0 && valorSaque==1){
        quantidadeCedulas[5] = quantidadeCedulas[5] + 3;
    }
}

// Função para contar as cedulas:
void cedulas(){
    for (contador = 0; contador < Numerocedulas; contador++){
        printf("Voce recebeu %d notas de R$%d.\n", quantidadeCedulas[contador], valorCedulas[contador]);
    }
}

int main(){

    printf("\nSeja bem vindo(a) a nossa agencia!\n");
    printf("----------------------------------\n");

    saldo();
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





}

