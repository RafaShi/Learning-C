#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Fracao;

// Função para calcular o MDC (algoritmo de Euclides)
int mdc(int a, int b) 
{
    while (b != 0) 
    {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

// Função para simplificar a fração
Fracao simplificar(Fracao f) 
{
    int divisor = mdc(f.numerador, f.denominador);
    f.numerador /= divisor;
    f.denominador /= divisor;
    return f;
}

// Função para somar duas frações
Fracao somarFracoes(Fracao f1, Fracao f2) 
{
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return simplificar(resultado);
}

int main() 
{
    Fracao f1, f2, resultado;
    scanf("%d %d %d %d", &f1.numerador, &f1.denominador, &f2.numerador, &f2.denominador);

    resultado = somarFracoes(f1, f2);

    printf("%d %d\n", resultado.numerador, resultado.denominador);

    return 0;
}
