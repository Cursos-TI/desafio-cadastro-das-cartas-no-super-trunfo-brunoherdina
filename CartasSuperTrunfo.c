#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char codigo[4];        // Exemplo: A01, B02, etc
    int populacao;         // População da cidade
    float area;           // Área da cidade
    float pib;            // PIB da cidade
    int pontos_turisticos; // Número de pontos turísticos
} Carta;

// Função para cadastrar uma carta
Carta cadastrar_carta() {
    Carta carta;
    char estado;
    int numero;
    
    // Leitura do código da carta (estado e número)
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &estado);
    printf("Digite o número da cidade (1-4): ");
    scanf("%d", &numero);
    
    // Formata o código da carta (exemplo: A01)
    sprintf(carta.codigo, "%c%02d", estado, numero);
    
    // Leitura dos atributos da carta
    printf("Digite a população da cidade: ");
    scanf("%d", &carta.populacao);
    
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta.area);
    
    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta.pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontos_turisticos);
    
    return carta;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("\n=== Dados da Carta %s ===\n", carta.codigo);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("==========================\n\n");
}

int main() {
    printf("=== Super Trunfo - Cadastro de Cartas ===\n\n");
    
    printf("Cadastro da primeira carta:\n");
    Carta carta1 = cadastrar_carta();
    
    printf("\nCadastro da segunda carta:\n");
    Carta carta2 = cadastrar_carta();
    
    printf("\nExibindo os dados das cartas cadastradas:\n");
    exibir_carta(carta1);
    exibir_carta(carta2);
    
    return 0;
}