#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_CARTAS 10

// Estrutura da carta
typedef struct {
    char nome[50];
    int forca;
    int defesa;
    int magia;
    int velocidade;
} Carta;

// Função para gerar valores aleatórios de atributos (1 a 100)
int gerarAtributo() {
    return rand() % 100 + 1;
}

// Função para criar todas as cartas com atributos aleatórios
void criarCartas(Carta cartas[]) {
    char nomes[TOTAL_CARTAS][50] = {
        "Cavaleiro Sombrio",
        "Bruxa",
        "Goblins",
        "Golem de Pedra",
        "Mago",
        "Cavaleiro",
        "Princesa",
        "BB Dragao",
        "Dragao Eletrico",
        "Mago de Gelo"
    };
    
    for(int i = 0; i < TOTAL_CARTAS; i++) {
        strcpy(cartas[i].nome, nomes[i]);
        cartas[i].forca = gerarAtributo();
        cartas[i].defesa = gerarAtributo();
        cartas[i].magia = gerarAtributo();
        cartas[i].velocidade = gerarAtributo();
    }
}

// Função para mostrar os atributos de uma carta
void mostrarCarta(Carta c) {
    printf("Carta: %s\n", c.nome);
    printf("1. Forca: %d\n", c.forca);
    printf("2. Defesa: %d\n", c.defesa);
    printf("3. Magia: %d\n", c.magia);
    printf("4. Velocidade: %d\n", c.velocidade);
}

int main() {
    srand(time(NULL)); // inicializa gerador de aleatórios
    
    Carta cartas[TOTAL_CARTAS];
    criarCartas(cartas);

    int jogadorPontos = 0;
    int computadorPontos = 0;

    char jogarNovamente;
    
    do {
        // Escolhe cartas aleatórias para jogador e computador
        int idxJogador = rand() % TOTAL_CARTAS;
        int idxComputador;
        do {
            idxComputador = rand() % TOTAL_CARTAS;
        } while(idxComputador == idxJogador);

        Carta cartaJogador = cartas[idxJogador];
        Carta cartaComputador = cartas[idxComputador];

        printf("\nSua carta:\n");
        mostrarCarta(cartaJogador);

        int escolha;
        printf("\nEscolha o atributo para jogar (1-Forca, 2-Defesa, 3-Magia, 4-Velocidade): ");
        scanf("%d", &escolha);

        int valorJogador, valorComputador;

        switch(escolha) {
            case 1:
                valorJogador = cartaJogador.forca;
                valorComputador = cartaComputador.forca;
                break;
            case 2:
                valorJogador = cartaJogador.defesa;
                valorComputador = cartaComputador.defesa;
                break;
            case 3:
                valorJogador = cartaJogador.magia;
                valorComputador = cartaComputador.magia;
                break;
            case 4:
                valorJogador = cartaJogador.velocidade;
                valorComputador = cartaComputador.velocidade;
                break;
            default:
                printf("Opcao invalida! Valor escolhido sera Forca.\n");
                valorJogador = cartaJogador.forca;
                valorComputador = cartaComputador.forca;
        }

        printf("\nCarta do computador: %s\n", cartaComputador.nome);
        printf("Valor do atributo escolhido: %d\n", valorComputador);

        if(valorJogador > valorComputador) {
            printf("Você venceu esta rodada!\n");
            jogadorPontos++;
        } else if(valorJogador < valorComputador) {
            printf("Computador venceu esta rodada!\n");
            computadorPontos++;
        } else {
            printf("Empate!\n");
        }

        printf("\nPlacar: Jogador %d x Computador %d\n", jogadorPontos, computadorPontos);

        printf("\nDeseja jogar outra rodada? (s/n): ");
        scanf(" %c", &jogarNovamente);

    } while(jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nJogo encerrado! Placar final: Jogador %d x Computador %d\n", jogadorPontos, computadorPontos);
    
    if(jogadorPontos > computadorPontos)
        printf("Parabens! Voce venceu o jogo!\n");
    else if(jogadorPontos < computadorPontos)
        printf("O computador venceu o jogo!\n");
    else
        printf("O jogo terminou empatado!\n");

    return 0;
}