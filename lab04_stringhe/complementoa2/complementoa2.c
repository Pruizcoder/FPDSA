#include <stdio.h>
#include <stdlib.h>
void complemento_a_due(char *bin, char *complemento) {
    int i = 0;

    while (bin[i] != '\0') {
        if (bin[i] == '0') {
            complemento[i] = '1';
        } else {
            complemento[i] = '0';
        }
        i++;
    }
    complemento[i] = '\0';  

    int carry = 1;  
    for (int j = i - 1; j >= 0; j--) {
        if (complemento[j] == '0' && carry == 1) {
            complemento[j] = '1';
            carry = 0;  
            break;
        } else if (complemento[j] == '1' && carry == 1) {
            complemento[j] = '0';
            carry = 1;  
        }
    }
}

int main() {
    char binario[32];
    char complemento[32];

    fgets(binario, 32, stdin);

    int i = 0;
    while (binario[i] != '\0') {
        if (binario[i] == '\n') {
            binario[i] = '\0';
            break;
        }
        i++;
    }

    complemento_a_due(binario, complemento);
    puts(complemento);  

    return 0;
}
