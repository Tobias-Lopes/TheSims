#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void emite_aviso(int hunger, int thirsty, int bathroom,int  sleep, int boring){
    if(hunger <= 15) printf("Alerta: fome está com valor baixo\n");
    if(thirsty <= 15) printf("Alerta: sede está com valor baixo\n");
    if(bathroom <= 15) printf("Alerta: banheiro está com valor baixo\n");
    if(sleep <= 15) printf("Alerta: sono está com valor baixo\n");
    if(boring <= 15) printf("Alerta: tédio está com valor baixo\n");
}
int simula_sims(int *hunger, int *thirsty, int *bathroom,int  *sleep, int *boring){
    char action[30] = {0};
    scanf(" %[^\n]", &action);
    if(strcmp(action,"comer") == 0){
        *hunger += 30;
        *bathroom -= 15;
        *thirsty -= 5;
        *sleep -= 5;
        *boring -= 5;
    }
    else if(strcmp(action,"beber") == 0){
        *hunger -= 5;
        *bathroom -= 20;
        *thirsty += 30;
        *sleep -= 5;
        *boring -= 5;
    }
    else if(strcmp(action,"dormir") == 0){
        *hunger -= 30;
        *bathroom -= 30;
        *thirsty -= 30;
        *sleep += 80;
        *boring += 30;
    }
    else if(strcmp(action,"se aliviar") == 0){
        *hunger -= 5;
        *bathroom += 100;
        *thirsty -= 5;
        *sleep -= 5;
        *boring -= 5;
    }
    else if(strcmp(action,"jogar videogame") == 0){
        *hunger -= 20;
        *bathroom -= 20;
        *thirsty -= 20;
        *sleep -= 20;
        *boring += 80;
    }
    if(*hunger > 100) *hunger = 100;
    if(*thirsty > 100) *thirsty = 100;
    if(*bathroom > 100) *bathroom = 100;
    if(*sleep > 100) *sleep = 100;
    if(*boring > 100) *boring = 100;

    if(*hunger <= 0){
        printf("Game Over! Morreu de fome\n");
        return 0;
    }
    else if(*thirsty <= 0){
        printf("Game Over! Morreu de sede\n");
        return 0;
    }
    else if(*bathroom <= 0){
        printf("Game Over! Morreu apertado...\n");
        return 0;
    }
    else if(*sleep <= 0){
        printf("Game Over! Morreu dormindo...\n");
        return 0;
    }
    else if(*boring <= 0){
        printf("Game Over! Morreu deprimido...\n");
        return 0;
    }
    else{
        emite_aviso(*hunger, *thirsty, *bathroom, *sleep, *boring);
        return 1;
    } 
}

void imprime_relatorio(int hunger, int thirsty, int bathroom,int sleep, int boring){ 
    printf("Status final:\n");
    printf("Fome: %d\n", hunger);
    printf("Sede: %d\n", thirsty);
    printf("Banheiro: %d\n", bathroom);
    printf("Sono: %d\n", sleep);
    printf("Tédio: %d\n", boring);
}

int main(){
    int fome, sede, banheiro, sono, tedio;
    int acoes;
    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d", &acoes);
    for(int i=0;i<acoes;i++){
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret == 0) break;
    }
    imprime_relatorio(fome, sede, banheiro, sono, tedio);

    return 0;
}
