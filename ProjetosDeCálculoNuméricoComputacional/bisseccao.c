#include <stdio.h>
#include <math.h> 
   
//Implementar os métodos de Newton e das secantes e encontrar todas as raízes da função f(x) = ex - 3x2.

//f(x) = e^x - 3x^2
double f(double x) {
    return exp(x) - 3 * x * x;
} 
  
//Métodos como bisseção só funcionam se a função em ae b tiver sinais diferentes

void bissecao(double a, double b, double tolerancia, int max_iter) { 
    if (f(a) * f(b) > 0) {
        printf("Não há raiz no intervalo [%.6f, %.6f]\n", a, b);
        return;
    } 
     
    int iteracoes = 0;
    double c; 
     
    while ((b - a) / 2 > tolerancia && iteracoes < max_iter) {
        c = (a + b) / 2;

        if (fabs(f(c)) < tolerancia) {
            break; //è o criterio de parada
        }  
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iteracoes++;
    } 
     
    printf("Raiz encontrada em x = %.6f após %d iterações.\n\n", c, iteracoes);
} 
 
   
void regula_falsi(double a, double b, double tolerancia, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("O método da Regula Falsi falhou. A função tem o mesmo sinal nos extremos do intervalo.\n");
        return;
    }

    int iteracoes = 0;
    double c;

    printf("Buscando raiz no intervalo [%.2f, %.2f]...\n", a, b);

    while (iteracoes < max_iter) {
        // a formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (fabs(f(c)) < tolerancia) {
            break; //criterio da parada
        }

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        iteracoes++;
    }

    printf("Raiz encontrada em x = %.6f em %d iteracoes.\n\n", c, iteracoes);
}

int main() {  
    double tolerancia = 1e-6;
    int max_iter = 100; 
     
    bissecao(-1, 0, tolerancia, max_iter); 
    bissecao(0, 0.5, tolerancia, max_iter); 
    bissecao(2, 2.5, tolerancia, max_iter);  
     
    regula_falsi(-1, 0, tolerancia, max_iter);
    regula_falsi(0, 0.5, tolerancia, max_iter);
    regula_falsi(2, 2.5, tolerancia, max_iter);
}
 