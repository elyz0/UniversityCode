#include <stdio.h>
#include <math.h>
//
// Função f(x) = e^x - 3x²
double f(double x) {
    return exp(x) - 3 * x * x;
}

//Função para reescrever o input que é o polinomio. Tipo de entrada: 2+3x-4x^2+5x^3
double escreverPolinomio(char* polinomio, int grauMax) {
    int i = 0; //Para caminhar pela string 
    int grauMax = 0; 
     
    while(polinomio[i] != '\0'){  
         
        int sinal = 1;
        if (polinomio[i] == '+') { sinal = 1; i++; }
        else if (polinomio[i] == '-') { sinal = -1; i++; } 
         
        int coeficiente = 0, temNumero = 0; //Tem que guarda o número atual e ver tbm se ele existe e não é so X 
         
        //isdigit verifica se o caractere atual é um dígito (0–9) 
        //atoi converte direto a string para inteiro.
        //strtol também permite saber onde parou, o que ajuda a continuar lendo a string.
        while (isdigit(polinomio[i])) {  

        }

    }
}
 
double derivada(double* coef, int grau, int* novoGrau) {
    
     

} 

// Método de Newton-Raphson
void newton(double x0, double tolerancia, int max_iter) {
    int iteracoes = 0;
    double x1;

    while (iteracoes < max_iter) {
        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(dfx) < 1e-12) {
            printf("Derivada muito próxima de zero. Método de Newton falhou.\n");
            return;
        }

        x1 = x0 - fx / dfx;

        if (fabs(x1 - x0) < tolerancia || fabs(f(x1)) < tolerancia) {
            printf("Newton: raiz aproximada em x = %.6f após %d iterações.\n", x1, iteracoes + 1);
            return;
        }

        x0 = x1;
        iteracoes++;
    }

    printf("Newton: não convergiu após %d iterações.\n", max_iter);
}

// Método das Secantes
void secantes(double x0, double x1, double tolerancia, int max_iter) {
    int iteracoes = 0;
    double x2;

    while (iteracoes < max_iter) {
        double f0 = f(x0);
        double f1 = f(x1);

        if (fabs(f1 - f0) < 1e-12) {
            printf("Divisão por zero no método das Secantes.\n");
            return;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        if (fabs(x2 - x1) < tolerancia || fabs(f(x2)) < tolerancia) {
            printf("Secantes: raiz aproximada em x = %.6f após %d iterações.\n", x2, iteracoes + 1);
            return;
        }

        x0 = x1;
        x1 = x2;
        iteracoes++;
    }

    printf("Secantes: não convergiu após %d iterações.\n", max_iter);
}

int main() {
    double tolerancia = 1e-6;
    int max_iter = 100;

    // Testando Newton em pontos diferentes
    newton(0.5, tolerancia, max_iter);
    newton(5.0, tolerancia, max_iter);

    // Testando Secantes em intervalos diferentes
    secantes(0.0, 1.0, tolerancia, max_iter);
    secantes(3.0, 5.0, tolerancia, max_iter);

    return 0;
}
