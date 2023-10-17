#include <stdio.h>

int saldoAtual, saldoRestante, valorSaque;
int cedula100 = 0, cedula50 = 0, cedula20 = 0, cedula10 = 0, cedula5 = 0; // Todas as cédulas com valor 0.

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

        if(cedula100 != 0){
            printf("Voce recebeu %d notas de R$100.\n", cedula100);
        }

    }

}



