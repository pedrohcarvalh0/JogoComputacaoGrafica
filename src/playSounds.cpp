#include <windows.h> 
#include <playSounds.h>
#include <tela.h>
#include <playsoundapi.h>

// Variável global para rastrear a tela atual com música tocando
int currentPlayingScreen = -1;
bool isPaused = false; // Mova esta definição para outro lugar onde você deseja inicializá-la

void playSounds(int telaID) {
    if (telaID == currentPlayingScreen && !isPaused) {
        // Se a música já estiver tocando para esta tela e o jogo não estiver pausado, não faça nada
        return;
    }

    const char* musicPath;
    switch (telaID) {
        case TELA_INICIAL:
        case TELA_COMO_JOGAR:
        case TELA_SOBRE_JOGO:
            musicPath = "../assets/sounds/musicTelaInicial.wav";
            break;
        case TELA_GAMEPLAY:
            musicPath = "../assets/sounds/musicTelaGameplay.wav";
            break;
        case TELA_GAME_OVER:
            musicPath = "../assets/sounds/gameover.wav";
            break;
        default:
            return;
    }

    if (!isPaused) {
        PlaySound(TEXT(musicPath), NULL, SND_FILENAME | SND_ASYNC);
    } else {
        // Se o jogo estiver pausado, pare o som
        PlaySound(NULL, NULL, SND_FILENAME); // Parar o som atual
    }

    currentPlayingScreen = telaID; // Atualiza a tela atual com música tocando
}

// Função para pausar ou retomar o som
void togglePauseSound() {
    isPaused = !isPaused; // Inverte o estado de pausa
    if (isPaused) {
        PlaySound(NULL, NULL, SND_FILENAME); // Para o som quando pausado
    }
}
