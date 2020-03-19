#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Pedro Antonio Estévez Pérez

// Ejercicio 6

/* Escribir el código de una función que obtenga un nº entero aleatorio A
 * entre 0 y 255 y devuelva un vector de caracteres que contenga la conversión
 * en binario de A. Además, se debe mostrar en pantalla los milisegundos que
 * tarda esta función en hacer su trabajo (consultar funciones de librería estándar).
 * ¿Llega a tardar algún milisegundo? ¿qué podrías añadir a tu programa para que
 * tarde más, de forma que tarde algún milisegundo o fracción de milisegundo (aunque no
 * haga nada útil)?*/

int main(void)
{
    int n, i, resto, longitud=0;
    int vector[500];
    double secs;
    clock_t t_ini, t_fin;

    /* Para realizar el programa, solo iremos dividiendo entre 2 y almacenando los
     * restos y el último cociente. Tener en cuenta que el vector resultante está
     * al revés y hay que imprimirlo de final a principio. En cuanto al tiempo,
     * ponemos el inicial, el final, vemos la diferencia y la imprimimos.*/

    t_ini = clock();

    srand(time(NULL));
    n = rand()%255;
    printf("El numero decimal es: %d\n",n);

    i = -1;
    while (n >= 2)
    {
        resto = n % 2;
        n = n / 2;
        i++;
        vector[i] = resto;
        longitud++;
    }
    vector[i+1] = n;
    longitud++;

    char vector_caracter[longitud];

    printf("En binario es: ");
    for (i=longitud-1; i>=0; i--)
    {
        vector_caracter[i] = vector[i] + '0';
        printf("%c", vector_caracter[i]);
    }
    printf("b\n");

    t_fin = clock();

    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.16g milisegundos\n\n", secs * 1000.0);

    /* Normalmente, todo algoritmo contiene sentencias condicionales, haciendo que el resto de
     * sentencias ejecutadas dependan de la condición lógica. El tiempo de ejecución de un
     * programa no será, por tanto, constante. Se definen dos tiempos, llamados el mejor caso
     * y el peor caso, y entre ambos, está el caso promedio, el más frecuente.
     *
     * En este código, el tiempo de ejecución dependerá del tamaño del número decimal que se
     * cree, pues habrá dos bucles que aumentarán el número de iteraciones. Según todas las
     * ejecuciones realizadas y para las especificaciones de mi ordenador, el mejor caso
     * son 0 milisegundos (obviamente el código no es intantáneo, sino que su tiempo es menor
     * a 0 milisegundos) y el peor caso son 2 milisegundos.
     *
     * El tiempo de ejecución depende del orden de complejidad del programa. Los órdenes
     * de complejidad van desde O(1), complejidad constante, en el que las intrucciones
     * sólo se ejecutan una vez, pasando por los órdenes de bucles anidados, que aumentan
     * el tiempo de ejecución de forma alarmante, hasta llegar al orden O(2n), complejidad
     * exponencial. Se da en subprogramas recursivos que contengan dos o más llamadas internas.
     * El tiempo de ejecución de éstos (pudiendo llegar a millones de milenios para un código
     * que un algoritmo más eficiente resolvería en un minuto) los hacen prácticamente
     * inviables.
     *
     * Para aumentar el tiempo de ejecución del código, aparte de poder usar sentencias
     * que "paralizarían" la ejecución del programa, se podrían usar, por ejemplo, bucles
     * anidados, que en esencia hagan lo mismo que un bucle simple.*/

}
