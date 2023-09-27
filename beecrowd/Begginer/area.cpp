#include <iostream>
#include <math.h>
#define PI 3.14159

using namespace std;

double a, b, c;
double triangulo, circulo, trapezio, quadrado, retangulo;

void solve() {
    cin >> a >> b >> c;
    triangulo = (a * c) / 2;
    circulo = pow(c, 2) * PI;
    trapezio = (a + b) * c / 2;
    quadrado = pow(b, 2);
    retangulo = a * b;
    printf("TRIANGULO: %.3lf\n", triangulo);
    printf("CIRCULO: %.3lf\n", circulo);
    printf("TRAPEZIO: %.3lf\n", trapezio);
    printf("QUADRADO: %.3lf\n", quadrado);
    printf("RETANGULO: %.3lf\n", retangulo);
}

int main() {
    solve();
    return 0;
}
