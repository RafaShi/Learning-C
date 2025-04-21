#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int numerador;
    int denominador;
} Fracao;

// Função para calcular o MDC usando o algoritmo de Euclides
int mdc(int a, int b) 
{
    if (b == 0) 
        return a;
    
    return mdc(b, a % b);
}

// Função para simplificar a fração
Fracao simplificar(Fracao f) 
{
    int m = mdc(abs(f.numerador), abs(f.denominador));
    f.numerador /= m;
    f.denominador /= m;

    // Ajustar o sinal para manter o denominador positivo
    if (f.denominador < 0) 
    {
        f.numerador *= -1;
        f.denominador *= -1;
    }

    return f;
}

int main() 
{
    int n;
    scanf("%d", &n);

    while (n--) 
    {
        Fracao f1, f2, resultado;
        char operador;

        // Entrada no formato: N1 / D1 op N2 / D2
        scanf("%d / %d %c %d / %d", &f1.numerador, &f1.denominador, &operador, &f2.numerador, &f2.denominador);

        // Operações
        switch (operador) 
        {
            case '+':
                resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
                resultado.denominador = f1.denominador * f2.denominador;
                break;
            case '-':
                resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
                resultado.denominador = f1.denominador * f2.denominador;
                break;
            case '*':
                resultado.numerador = f1.numerador * f2.numerador;
                resultado.denominador = f1.denominador * f2.denominador;
                break;
            case '/':
                resultado.numerador = f1.numerador * f2.denominador;
                resultado.denominador = f1.denominador * f2.numerador;
                break;
        }

        Fracao simplificado = simplificar(resultado);

        // Saída no formato: X/Y = A/B
        printf("%d/%d = %d/%d\n", resultado.numerador, resultado.denominador, simplificado.numerador, simplificado.denominador);
    }

    return 0;
}
