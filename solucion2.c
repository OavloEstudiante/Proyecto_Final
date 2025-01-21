#include <stdio.h>
#include <stdlib.h>

int main() {
    int vip, preferente, general, totalVIP, totalPreferente, totalGeneral, total, pago, cambio;
    char continuar;
    int precioVIP = 1000;
    int precioPreferente = 700;
    int precioGeneral = 500;
    
    do {
        totalVIP = 0;
        totalPreferente = 0;
        totalGeneral = 0;
        total = 0;
        cambio = 0;

        printf("Bienvenido.\n");
        printf("Los tipos de boleto son:\n");
        printf("1. Zona VIP ($%d pesos)\n", precioVIP);
        printf("2. Zona Preferente ($%d pesos)\n", precioPreferente);
        printf("3. Zona General ($%d pesos)\n", precioGeneral);

        do {
            printf("Ingrese el numero de entradas a Zona VIP: ");
            if (scanf("%d", &vip) != 1 || vip < 0) {
                printf("Error, solo se permiten numeros positivos para la cantidad de boletos.\n");
                fflush(stdin); 
                vip = -1; 
            }
        } while (vip < 0);

        do {
            printf("Ingrese el numero de entradas a Zona Preferente: ");
            if (scanf("%d", &preferente) != 1 || preferente < 0) {
                printf("Error, solo se permiten numeros positivos para la cantidad de boletos.\n");
                fflush(stdin); 
                preferente = -1; 
            }
        } while (preferente < 0);

        do {
            printf("Ingrese el numero de entradas a Zona General: ");
            if (scanf("%d", &general) != 1 || general < 0) {
                printf("Error, solo se permiten numeros positivos para la cantidad de boletos.\n");
                fflush(stdin); 
                general = -1; 
            }
        } while (general < 0);

        totalVIP = vip * precioVIP;
        totalPreferente = preferente * precioPreferente;
        totalGeneral = general * precioGeneral;

        printf("\nEl total de las entradas a Zona VIP es: $%d pesos\n", totalVIP);
        printf("El total de las entradas a Zona Preferente es: $%d pesos\n", totalPreferente);
        printf("El total de las entradas a Zona General es: $%d pesos\n", totalGeneral);

        total = totalVIP + totalPreferente + totalGeneral;
        printf("\nEl monto total a pagar es: $%d pesos\n", total);

        do {
            printf("Ingrese el monto con el que pagara: ");
            if (scanf("%d", &pago) != 1 || pago < total) {
                if (pago < total) {
                    printf("Error, dinero insuficiente.\n");
                } else {
                    printf("Error, eso no es dinero.\n");
                }
                fflush(stdin); 
                pago = 0;
            }
        } while (pago < total);

        cambio = pago - total;

        if (cambio > 0) {
            printf("\nEl vuelto es de: $%d\n", cambio);
            printf("%d billete(s) de 100 pesos\n", cambio / 100);
            cambio %= 100;
            printf("%d billete(s) de 50 pesos\n", cambio / 50);
            cambio %= 50;
            printf("%d moneda(s) de 10 pesos\n", cambio / 10);
            cambio %= 10;
            printf("%d moneda(s) de 5 pesos\n", cambio / 5);
            cambio %= 5;
            printf("%d moneda(s) de 2 pesos\n", cambio / 2);
            cambio %= 2;
            printf("%d moneda(s) de 1 peso\n", cambio);
        } else {
            printf ("No hay cambio\n");
        }

        printf("\nDesea realizar otra operacion? (s/n): ");
        getchar(); 
        scanf("%c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("\nGracias por su compra.\n");

    return 0;
}
