#include <stdio.h>
#include <math.h>
//
// Função f(x) = e^x - 3x²
double f(double x) {
    return exp(x) - 3 * x * x;
}

// Derivada f'(x) = e^x - 6x
double df(double x) {
    return exp(x) - 6 * x;
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
