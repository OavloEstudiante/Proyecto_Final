#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion, cantidad, subtotal, total, pago, cambio;
    char continuar;
    int precioVIP = 1000;
    int precioPreferente = 700;
    int precioGeneral = 500;

    do {
        total = 0; 

        do {
            subtotal = 0; 

            do {
                printf("\nSeleccione el tipo de boleto:\n");
                printf("1. Zona VIP ($%d pesos)\n", precioVIP);
                printf("2. Zona Preferente ($%d pesos)\n", precioPreferente);
                printf("3. Zona General ($%d pesos)\n", precioGeneral);
                printf("Ingrese el numero de la opcion: ");

                if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3) { 
                    printf("Error, debe ingresar solo el numero de la opcion entre 1 y 3.\n");
                    fflush(stdin); 
                    opcion = 0; 
                }
            } while (opcion < 1 || opcion > 3);

            do {
                printf("Cuantos boletos desea?: ");
                if (scanf("%d", &cantidad) != 1 || cantidad <= 0) { 
                    printf("Error, solo se permiten numeros positivos para la cantidad de boletos.\n");
                    fflush(stdin); 
                    cantidad = 0; 
                }
            } while (cantidad <= 0);

            switch (opcion) {
                case 1:
                    subtotal = cantidad * precioVIP;
                    break;
                case 2:
                    subtotal = cantidad * precioPreferente;
                    break;
                case 3:
                    subtotal = cantidad * precioGeneral;
                    break;
            }

            total += subtotal; 
            printf("\nEl precio por los boletos seleccionados es: $%d pesos\n", subtotal);

            printf("\nDesea ingresar otro tipo de boleto? (s/n): ");
            scanf(" %c", &continuar);
            fflush(stdin); 

        } while (continuar == 's' || continuar == 'S');

        if (total > 0) {
            do {
                printf("\nEl valor total a pagar es: $%d pesos\n", total);
                printf("Ingrese el monto con el que pagara: ");
                if (scanf("%d", &pago) != 1 || pago < total) { 
                    if (pago < total) {
                        printf("Error, el monto es insuficiente.\n");
                    } else {
                        printf("Error, eso no es un monto valido.\n");
                    }
                    fflush(stdin); 
                    pago = 0; 
                }
            } while (pago < total);

            cambio = pago - total;

            if (cambio > 0) {
                printf("\nEl cambio a entregar es: $%d\n", cambio);

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
                printf("\nNo hay cambio.\n");
            }
        }

        printf("\nDesea realizar otra operacion? (s/n): ");
        scanf(" %c", &continuar);
        fflush(stdin); 

    } while (continuar == 's' || continuar == 'S');

    printf("\nGracias por su compra.\n");

    return 0;
}