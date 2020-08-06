/* 
 *  Programa para criptografar e descriptografar mensagens de texto
 *  através da tabela ASCII
 *
 *  Author: Niiick013
 *  GitHub: https://github.com/Niiick013
 *
 */

#include <stdio.h>
#include <string.h>
#define Tam_chave 4
#define Tam_texto 100000

void Menu();
int Criptografar();
void Menu_Criptografar();
void Recebe_texto();
void Receber_Arquivo(); // Chamada de funções externas

int Op;
char Op_char;
char CHAVE[] = "AbCd"; // Chave de criptografia
char Texto[Tam_texto]; // Vetor do texto a ser criptografado

FILE *DB; // Ponteio para arquivos externos
char palavra[Tam_texto];

int main() {
    Menu();

    return 0;

} // Fim da função main

void Menu() {
    while(1) {
        system("clear"); // Limpa a tela
        printf("==========\n");
        printf(" EL CRIPT\n");
        printf("==========\n\n");

        printf("[1] - Criptografar texto ou arquivo\n");
        printf("[2] - Receber arquivo\n");
        printf("[3] - Sair\n\n");

        printf("========\n");
        printf("Opção: ");
        scanf("%d", &Op);
        getchar(); // Limpa o buffer do teclado

        switch(Op) {
            case 1:
                Menu_Criptografar();
            
                break;

            case 2:
                Receber_Arquivo();

                break;

            case 3:
                system("clear");
                exit(0);

                break;

        }

    }

} // Fim da função Menu

void Menu_Criptografar() {
    system("clear");
    printf("=======================\n");
    printf(" CRIPTOGRAFIA DE DADOS\n");
    printf("=======================\n\n");

    printf("[1] - Digitar mensagem\n");
    printf("[2] - Importar arquivo de texto\n");
    printf("[3] - Voltar ao menu principal\n\n");

    printf("========\n");
    printf("Opção: ");
    scanf("%d", &Op);
    getchar();

    switch(Op) {
        case 1:
            Recebe_texto("msg");
            
            break;

        case 2:
            Recebe_texto("arquivo");

            break;

        case 3:
            Menu();

            break;

        default:
            system("clear");
            printf("Tente novamente...\n");
            sleep(1);
            Menu_Criptografar();

            break;

    }        

} // Fim da função Criptografar

void Recebe_texto(char tipo[]) {
    char aux[Tam_texto];
    if(strcmp(tipo, "msg") == 0) { // Se tipo == "msg"
        system("clear");
        printf("=======================\n");
        printf(" CRIPTOGRAFAR MENSAGEM\n");
        printf("=======================\n\n");

        printf("Digite o texto: \n\n");
        gets(aux); // Recebe o texto a ser criptografado

        if(strlen(aux) <= Tam_texto) {
            strcpy(Texto,aux); // Copia dados de aux para Texto
            system("clear");
            printf("Criptografando...\n\n");

            sleep(1);
            Criptografar();

            if(Criptografar() == 0) { // Retorna verdadeiro
                printf("Mensagem criptografada com sucesso!\n\n");

                printf("O arquivo foi salvo na pasta 'generated_files'.\n");
                printf("Voltar ao menu principal? [s/n]: ");
                scanf("%c", &Op_char);

                if(Op_char == 'n') {
                    system("clear");
                    printf("Fim da execução...\n\n");
                    exit(0);

                }

            } else { // Retorna falso
                printf("Não foi possível criptografar...\n\n");

            }


        } else {
            printf("Tamanho do texto excede o limite de caracteres...\n");

        } // Verificação de caracteres

        sleep(1);

    } else if(strcmp(tipo, "arquivo") == 0) { // Se tipo == "arquivo"
        system("clear");
        printf("===========================\n");
        printf(" IMPORTAR ARQUIVO DE TEXTO\n");
        printf("===========================\n\n");

        printf("1 - Mova o arquivo para a pasta 'original_files'\n");
        printf("2 - Renomeie o arquivo para 'original.txt'\n\n");

        printf("Continuar? [s/n]: ");
        scanf("%c", &Op_char);

        if(Op_char == 's') {
            printf("Importando arquivo...\n");

            DB = fopen("original_files//original.txt", "r"); // Abertura do arquivo

            if(DB == NULL) {
                system("clear");
                printf("Erro ao abrir arquivo...\n");

            } else {
                while(!feof(DB)) {
                    fscanf(DB, "%s", palavra);
                    strcat(aux, " ");
                    strcat(aux, palavra);

                } // Varredura do arquivo

                if(strlen(aux) <= Tam_texto) {
                    strcpy(Texto,aux); // Copia dados de aux para Texto
                    system("clear");
                    printf("Criptografando...\n\n");

                    sleep(1);
                    Criptografar();

                    if(Criptografar() == 0) { // Retorna verdadeiro
                        printf("Mensagem criptografada com sucesso!\n\n");

                        printf("O arquivo foi salvo na pasta 'generated_files'.\n");
                        printf("Voltar ao menu principal? [s/n]: ");
                        scanf("%c", &Op_char);

                        if(Op_char == 'n') {
                            system("clear");
                            printf("Fim da execução...\n\n");
                            exit(0);

                        }

                    } else { // Retorna falso
                        printf("Não foi possível criptografar...\n\n");

                    }

                } else {
                    printf("Tamanho do texto excede o limite de caracteres...\n");

                } // Verificação de caracteres

            fclose(DB); // Arquivo é encerrado

            }

            sleep(1);

        }

        sleep(1);

    } else {
        printf("Erro ao receber texto...\n");

    }

} // Fim da função Recebe_texto

void Receber_Arquivo() {

} // Fim da função Receber_Arquivo

int Criptografar() {

    return 0;
} // Fim da função Criptografar