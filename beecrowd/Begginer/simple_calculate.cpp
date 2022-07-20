#include <iostream>

using std::cin;

int main(){
    int c1, n1, c2, n2;
    float p1, p2;
    cin >> c1 >> n1 >> p1;
    cin >> c2 >> n2 >> p2;
    printf("VALOR A PAGAR: R$ %.2f\n", (p1*n1+p2*n2));
    return 0;
}
