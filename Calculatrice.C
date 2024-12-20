#include <stdio.h>
#include <string.h>

//Declaration des variables

//Fonction addition Moustapha
int somme (int a, int b) {
return a+b;
}

//Fonction multiplication AMY
float multiplication (float a, float b)
{ float r = a*b
  return 1;
}

//Fonction division Maurice

void division(int a, int b, int *quotient, int *reste) {
    if (b == 0) {
        printf("Erreur : Division par zéro.\n");
        return;
    }
    *quotient = a / b;  // Calcul du quotient
    *reste = a % b;     // Calcul du reste
}
    return 0;
    
}


