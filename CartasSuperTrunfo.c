#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char codigo[4];           // Exemplo: A01, B02, etc
    char nome_cidade[100];    // Nome da cidade
    int populacao;            // População da cidade
    float area;              // Área da cidade em km²
    float pib;               // PIB da cidade em bilhões
    int pontos_turisticos;    // Número de pontos turísticos
    float densidade_pop;      // Densidade populacional (hab/km²)
    float pib_per_capita;     // PIB per capita em reais
} Carta;

// Função para calcular a densidade populacional
float calcular_densidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita (PIB em bilhões convertido para reais)
float calcular_pib_per_capita(float pib, int populacao) {
    // Convertendo PIB de bilhões para reais (multiplicando por 1.000.000.000)
    return (pib * 1000000000.0) / populacao;
}

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
    
    // Limpa o buffer do teclado
    getchar();
    
    // Leitura do nome da cidade
    printf("Digite o nome da cidade: ");
    fgets(carta.nome_cidade, 100, stdin);
    // Remove o \n do final da string
    carta.nome_cidade[strcspn(carta.nome_cidade, "\n")] = 0;
    
    // Leitura dos atributos da carta
    printf("Digite a população da cidade: ");
    scanf("%d", &carta.populacao);
    
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta.area);
    
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta.pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontos_turisticos);
    
    // Calcula a densidade populacional e o PIB per capita
    carta.densidade_pop = calcular_densidade(carta.populacao, carta.area);
    carta.pib_per_capita = calcular_pib_per_capita(carta.pib, carta.populacao);
    
    return carta;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("\n=== Dados da Carta %s ===\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_pop);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
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