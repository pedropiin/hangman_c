#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void cria_array_objetos(char objetos[][100])
{
    strcpy(objetos[0], "baralho");
    strcpy(objetos[1], "computador");
    strcpy(objetos[2], "lamparina");
    strcpy(objetos[3], "filtro");
    strcpy(objetos[4], "vuvuzela");
    strcpy(objetos[5], "bicicleta");
    strcpy(objetos[6], "chaveiro");
    strcpy(objetos[7], "garrafa");
    strcpy(objetos[8], "lapiseira");
    strcpy(objetos[9], "guidao");
    strcpy(objetos[10], "xilofone");
    strcpy(objetos[11], "narguile");
    strcpy(objetos[12], "webcam");
    strcpy(objetos[13], "ampulheta");
    strcpy(objetos[14], "despertador");
    strcpy(objetos[15], "saxofone");
    strcpy(objetos[16], "skate");
    strcpy(objetos[17], "candelabro");
    strcpy(objetos[18], "paquimetro");
    strcpy(objetos[19], "desfibrilador");
}

void cria_array_paises(char paises[][100])
{
    strcpy(paises[0], "brasil");
    strcpy(paises[1], "canada");
    strcpy(paises[2], "alemanha");
    strcpy(paises[3], "turquia");
    strcpy(paises[4], "afeganistao");
    strcpy(paises[5], "zimbabue");
    strcpy(paises[6], "turcomenistao");
    strcpy(paises[7], "china");
    strcpy(paises[8], "taiwan");
    strcpy(paises[9], "moldavia");
    strcpy(paises[10], "australia"); //19
    strcpy(paises[11], "butao");
    strcpy(paises[12], "bielorussia");
    strcpy(paises[13], "eritrea"); //14
    strcpy(paises[14], "kiribati");
    strcpy(paises[15], "espanha");
    strcpy(paises[16], "argentina");
    strcpy(paises[17], "venezuela");
    strcpy(paises[18], "egito");
    strcpy(paises[19], "liechtenstein"); //13
}

void cria_array_animais(char animais[][100]) {
    strcpy(animais[0], "albatroz");
    strcpy(animais[1], "cachorro");
    strcpy(animais[2], "bacalhau");
    strcpy(animais[3], "escaravelho");
    strcpy(animais[4], "hamster");
    strcpy(animais[5], "gato");
    strcpy(animais[6], "tuiuiu");
    strcpy(animais[7], "tapir");
    strcpy(animais[8], "ornitorrinco");
    strcpy(animais[9], "cachorro");
    strcpy(animais[10], "lhama");
    strcpy(animais[11], "gorila");
    strcpy(animais[12], "baleia");
    strcpy(animais[13], "tubarao");
    strcpy(animais[14], "gerbo");
    strcpy(animais[15], "morcego");
    strcpy(animais[16], "ocapi");
    strcpy(animais[17], "piranha");
    strcpy(animais[18], "hiena");
    strcpy(animais[19], "girafa");
}

int checa_espacos_faltantes(char *vetor_jogo, int tamanho_palavra) {
    int i, espacos_vazios = 0;
    for (i = 0; i < tamanho_palavra; i++) {
        if (vetor_jogo[i] == '_') {
            espacos_vazios++;
        }
    }
    if (espacos_vazios > 0) {
        return 1;
    } else {
        return 0;
    }
}

int escolhe_modo_jogo() {
    int modo_jogo;
    printf("Você gostaria de jogar no tema objetos (1), países (2) ou animais (3)?\n");
    scanf(" %d", &modo_jogo);
    return modo_jogo;
}

char recebe_letra() {
    char letra;
    printf("Digite uma tentativa de letra: ");
    scanf(" %c", &letra);
    return letra;
}

int checa_letra_digitada(char alfabeto[], char letra) {
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
    vetor_jogo[tamanho_palavra] = '\0';
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
    printf("Por enquanto, a palavra formada é: %s\n", vetor_jogo);
}


int main()
{
    char objetos[20][100], paises[20][100], animais[20][100], palavra[100], letra_input;
    int i, i_random, modo_jogo, num_erros = 5;
    cria_array_objetos(objetos);
    cria_array_paises(paises);
    cria_array_animais(animais);

    srand(time(NULL));
    i_random = rand() % 20;
    modo_jogo = escolhe_modo_jogo();

    if (modo_jogo == 1) {
        strcpy(palavra, objetos[i_random]);
    } else if (modo_jogo == 2) {
        strcpy(palavra, paises[i_random]);
    } else if (modo_jogo == 3) {
        strcpy(palavra, animais[i_random]);
    } else {
        printf("Esse modo de jogo não existe.\n");
        exit(1);
    }

    int tamanho_palavra = strlen(palavra);
    char *vetor_jogo;
    vetor_jogo = malloc(sizeof(tamanho_palavra + 1));
    if (vetor_jogo == NULL) {
        printf("Não há memória suficiente.\n");
        exit(1);
    }
    inicializa_jogo_zerado(vetor_jogo, tamanho_palavra);

    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    int bool_letra_riscada, esta_no_jogo, num_aparicoes_letra;
    int *indices_aparicao_letra;
    indices_aparicao_letra = malloc(sizeof(tamanho_palavra) * 4);

    /*
    A partir daqui, o jogo é inicializado.
    */
    printf("A palavra é da forma %s (%d letras)\n", vetor_jogo, tamanho_palavra);

    while (checa_espacos_faltantes(vetor_jogo, tamanho_palavra))
    {
        reseta_indices_aparicao(indices_aparicao_letra, tamanho_palavra);
        letra_input = recebe_letra();
        bool_letra_riscada = checa_letra_digitada(alfabeto, letra_input);
        if (bool_letra_riscada == 0) { // se = 0, não esta riscada, e portanto tentativa válida
            esta_no_jogo = checa_esta_jogo(letra_input, palavra, tamanho_palavra);
            if (esta_no_jogo == 1) {
                num_aparicoes_letra = retira_letra_palavra(palavra, tamanho_palavra, letra_input, indices_aparicao_letra);
                coloca_letra_vetor(indices_aparicao_letra, num_aparicoes_letra, vetor_jogo, letra_input);
                printa_vetor_jogo(vetor_jogo);
            } else {
                printf("Esta letra não faz parte da palavra.\n");
                num_erros--;
                printf("Você pode errar mais %d vezes.\n", num_erros);   
            }
        } else {
            printf("Você já tentou esta letra.\n");
        }

        if (num_erros <= 0) {
            printf("Puts, você perdeu. Tente jogar outra vez!\n");
            break;
        }
        
    }

    if (num_erros > 0) {
        printf("Parabéns! Você ganhou!\n");
    }
    free(vetor_jogo);
    free(indices_aparicao_letra);
}