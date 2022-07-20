#include <iostream>
#include <math.h>
#define PI 3.14159

using std::cin;

double volume;

int main(){
    int R; cin >> R;
    volume = (4.0/3.0)*PI*pow(R, 3);
    printf("VOLUME = %.3lf\n", volume);
    return 0;
}
