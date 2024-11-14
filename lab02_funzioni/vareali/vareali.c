/*Il seguente programma calcola la radice quadrata di 2 utilizzando una funzione 
che implementa il metodo di Newton e la libreria matematica del compilatore.
Cosa accade? Perché?
Provare a correggere il programma in modo che fornisca il risultato atteso*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Per la funzione fabs (valore assoluto)

double sqrt_newton(double a, double epsilon);

int main() {
    double number = 2.0;  
    double epsilon = 1e-10;  

    double result = sqrt_newton(number, epsilon);
    printf("La radice quadrata di %.2f è approssimativamente %.10f\n", number, result);
    return EXIT_SUCCESS;
}

double sqrt_newton(double a, double epsilon) {
    double x = a;  
    double x_next;

    
    do {
        x_next = 0.5 * (x + a / x);  
        if (fabs(x_next - x) < epsilon)  
            break;
        x = x_next;  
    } while (1);

    return x_next;  
}
