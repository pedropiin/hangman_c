#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void cria_array_objetos(char objetos[][100])
{
    strcpy(objetos[], "baralho");
    strcpy(objetos[], "computador");
    strcpy(objetos[], "lamparina");
    strcpy(objetos[], "filtro");
    strcpy(objetos[], "caderno");
    strcpy(objetos[], "bicicleta");
    strcpy(objetos[], "chaveiro");
    strcpy(objetos[], "garrafa");
    strcpy(objetos[], "lapiseira");
    strcpy(objetos[], "porta");
}

void cria_array_paises(char paises[][100])
{
    strcpy(paises[], "brasil");
    strcpy(paises[], "canada");
    strcpy(paises[], "alemanha");
    strcpy(paises[], "turquia");
    strcpy(paises[], "afeganistao");
    strcpy(paises[], "zimbabue");
    strcpy(paises[], "turcomenistao");
    strcpy(paises[], "china");
    strcpy(paises[], "taiwan");
    strcpy(paises[], "moldavia");
}

int checa_espacos_faltantes() {

}

int escolhe_modo_jogo() {
    int modo_jogo;
    printf("Você gostaria de jogar no tema objetos (1) ou países (2)?");
    scanf("%d", &modo_jogo);
    return modo_jogo;
}

char recebe_letra() {
    char letra;
    printf("Digite uma tentativa de letra: ");
    scanf("%c", &letra);
    return letra;
}

int checa_letra_digitada(char alfabeto[27], char letra) {
    int i, esta_riscada = 1;
    for (i = 0; i < 26; i++) {
        if (letra == alfabeto[i]) {
            esta_riscada = 0;
            alfabeto[i] = '_';
        }
    }
    return esta_riscada;
}

/*
Função que devolve 1 caso a letra esteja no jogo
*/
int checa_esta_jogo(char letra, char palavra[], int tamanho_palavra) {
    int i, bool_existencia = 0;
    for (i = 0; i < tamanho_palavra; i++) {
        if (palavra[i] == letra) {
            bool_existencia = 1;
        }
    }
    return bool_existencia;
}

int retira_letra_palavra(char palavra[], int tamanho_palavra, char letra_input, int *indices_aparicoes_letra) {
    int i, contagem_aparicoes = 0;
    for (i = 0; i < tamanho_palavra; i++) {
        if (palavra[i] == letra_input) {
            palavra[i] = '_';
            indices_aparicoes_letra[contagem_aparicoes] = i;
            contagem_aparicoes++;
        }
    }
    return contagem_aparicoes;
}   

void inicializa_jogo_zerado(char *vetor_jogo, int tamanho_palavra){
    int i;
    for (i = 0; i < tamanho_palavra; i++)
    {
        vetor_jogo[i] = '_';
    }
}

void reseta_indices_aparicao(int *indices_aparicao_letra, int tamanho_palavra) {
    int i;
    for (i = 0; i < tamanho_palavra; i++) {
        indices_aparicao_letra[i] = -1;
    }
}

void coloca_letra_vetor(int *indices_aparicao_letra, int num_aparicoes_letra, char *vetor_jogo, char letra_input) {
    int i;
    for (i = 0; i < num_aparicoes_letra; i++) {
        vetor_jogo[indices_aparicao_letra[i]] = letra_input;
    }
}

void printa_vetor_jogo(char *vetor_jogo) {
    printf("Por enquanto, a palavra formada é: %s", vetor_jogo);
}

int main()
{
    char objetos[10][100], paises[10][100], palavra[100], letra_input;
    int i, i_random, modo_jogo, num_erros = 10;
    int *ptr_modo_jogo;
    cria_array_objetos(objetos);
    cria_array_paises(paises);

    srand(time(NULL));
    i_random = rand() % 10;
    modo_jogo = escolhe_modo_jogo();

    if (modo_jogo == 1) {
        ptr_modo_jogo = objetos;
    } else if (modo_jogo == 2) {
        ptr_modo_jogo = paises;
    } else {
        printf("Esse modo de jogo não existe.\n");
        exit(1);
    }

    palavra = *ptr_modo_jogo + i_random;
    int tamanho_palavra = strlen(palavra);
    char *vetor_jogo;
    vetor_jogo = malloc(sizeof(tamanho_palavra + 1));
    if (vetor_jogo == NULL) {
        printf("Não há memória suficiente.\n");
        exit(1);
    }

    inicializa_jogo_zerado(tamanho_palavra, vetor_jogo);

    char alfabeto = "abcdefghijklmnopqrstuvwxyz";
    int bool_letra_riscada, esta_no_jogo, num_aparicoes_letra;
    int *indices_aparicao_letra;
    indices_aparicao_letra = malloc(sizeof(tamanho_palavra) * 4);

    while (checa_espacos_faltantes == 1)
    {
        reseta_indices_aparicao(indices_aparicao_letra, tamanho_palavra);
        letra_input = recebe_letra();
        bool_letra_riscada = checa_letra_digitada(alfabeto, letra_input);
        if (bool_letra_riscada == 0) { // se = 0, não esta riscada, e portanto tentativa válida
            esta_no_jogo = checa_esta_jogo(letra_input, palavra, tamanho_palavra);
            if (esta_no_jogo == 1) {
                num_aparicoes_letra = retira_letra_palavra(palavra, tamanho_palavra, letra_input, indices_aparicao_letra);
                coloca_letra_vetor();
                printa_vetor_jogo(vetor_jogo);
            }
        } else {
            
        }
    }
    free(vetor_jogo);
    free(indices_aparicao_letra);
}