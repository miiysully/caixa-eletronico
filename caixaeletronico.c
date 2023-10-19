#include <stdio.h>

int saldoAtual, saldoRestante, valorSaque;
int cedula100 = 0, cedula50 = 0, cedula20 = 0, cedula10 = 0, cedula5 = 0, cedula2 = 0; // Todas as cédulas com valor 0.

int main(){
    printf("Digite o seu saldo: ");
    scanf("%d", &saldoAtual);

    printf("\nQuanto voce quer sacar?: ");
    scanf("%d", &valorSaque);

    saldoRestante = saldoAtual - valorSaque; // Retirando o dinheiro.

    printf("\nSaldo restante: R$%d\n", saldoRestante);

    while(valorSaque != 0){
        cedula100 = valorSaque / 100; // Calculando a quantidade de cédulas de 100.
        valorSaque = valorSaque % 100; // Resto da divisão do valorSaque divido por 100.

        cedula50 = valorSaque / 50;
        valorSaque = valorSaque % 50;

        cedula20 = valorSaque / 20;
        valorSaque = valorSaque % 20;

        cedula10 = valorSaque / 10;
        valorSaque = valorSaque % 10;

        cedula5 = valorSaque / 5;
        valorSaque = valorSaque % 5;

        cedula2 = valorSaque / 2;
        valorSaque = valorSaque % 2;

        if(cedula100 != 0)
            printf("Voce recebeu %d notas de R$100.\n", cedula100);

        if(cedula50 != 0)
            printf("Voce recebeu %d notas de R$50.\n", cedula50);

        if(cedula10 != 0)
            printf("Voce recebeu %d notas de R$10.\n", cedula10);

        if(cedula5 != 0)
            printf("Voce recebeu %d notas de R$5.\n", cedula5);

        if(cedula2 != 0)
            printf("Voce recebeu %d notas de R$2", cedula2);

    }

}
