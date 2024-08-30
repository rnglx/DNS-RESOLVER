// espero que essa ferramenta te ajude! abs.  :)


#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Função para buscar subdomínios
void buscarSubdominio(char *subdominio, char *dominio) {
    char alvo[100];
    struct hostent *host;

    sprintf(alvo, "%s%s", subdominio, dominio);

    // Mensagem de loading
    printf(YELLOW "Procurando subdomínio: %s...\r" RESET, alvo);
    fflush(stdout);

    host = gethostbyname(alvo);

    if (host != NULL) {
        printf(GREEN "\n[+] Subdomínio encontrado: %s -> IP: %s\n" RESET, alvo, inet_ntoa(*((struct in_addr *)host->h_addr)));
    }
}

int main(int argc, char *argv[]) {
    FILE *wordlist;
    char linha[50];
    char *dominio;
    char *wordlist_path;

    if (argc < 3) {
        printf(RED "Uso: %s <domínio> <wordlist>\n" RESET, argv[0]);
        return 1;
    }

    dominio = argv[1];
    wordlist_path = argv[2];

    wordlist = fopen(wordlist_path, "r");

    if (wordlist == NULL) {
        printf(RED "Erro ao abrir a wordlist: %s\n" RESET, wordlist_path);
        return 1;
    }

    printf(GREEN "Iniciando busca por subdomínios em %s...\n" RESET, dominio);

    while (fgets(linha, sizeof(linha), wordlist)) {
        linha[strcspn(linha, "\n")] = 0;  // Remove newline
        buscarSubdominio(linha, dominio);
    }

    fclose(wordlist);

    printf(GREEN "\nBusca concluída!\n" RESET);

    return 0;
}
