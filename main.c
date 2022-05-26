#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int imprime_vetor(int *vet, int q) {
    if (q < 1)
        return 1;
    else {
        imprime_vetor(vet, q - 1);
        if (q > 1)
            printf(",");
        printf(" %d", vet[q-1]);
    }
}


int imprime_soma_vetor(int *vet, int q, int *soma) {
    if (q < 1)
        return 1;
    else {
        (*soma) += vet[q-1];
        imprime_soma_vetor(vet, q - 1, soma);
    }
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, vet[] = {4, 8, 1, 9, 3}, soma = 0;

    printf("[for] Os valores do vetor são:");
    for(i = 0; i < 5; i++) {
        printf(" %d", vet[i]);
        if (i < 4)
            printf(",");
    }

    printf("\n\n[recursividade] Os valores do vetor são:");
    imprime_vetor(vet, 5);

    printf("\n\n[recursividade] A soma dos valores do vetor é:");
    imprime_soma_vetor(vet, 5, &soma);
    printf(" %d\n", soma);

    return 0;
}
