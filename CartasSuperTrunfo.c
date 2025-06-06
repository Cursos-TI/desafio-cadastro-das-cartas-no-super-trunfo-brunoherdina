#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char codigo[4];              // Exemplo: A01, B02, etc
    char nome_cidade[100];       // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area;                 // Área da cidade em km²
    float pib;                  // PIB da cidade em bilhões
    int pontos_turisticos;       // Número de pontos turísticos
    float densidade_pop;         // Densidade populacional (hab/km²)
    float pib_per_capita;        // PIB per capita em reais
    float super_poder;           // Super poder da carta
} Carta;

// Função para calcular a densidade populacional
float calcular_densidade(unsigned long int populacao, float area) {
    return (float)populacao / area;
}

// Função para calcular o PIB per capita (PIB em bilhões convertido para reais)
float calcular_pib_per_capita(float pib, unsigned long int populacao) {
    // Convertendo PIB de bilhões para reais (multiplicando por 1.000.000.000)
    return (pib * 1000000000.0) / populacao;
}

// Função para calcular o super poder da carta
float calcular_super_poder(Carta carta) {
    // Convertendo população para float para evitar overflow
    float pop_normalizada = (float)carta.populacao / 1000000.0; // Convertendo para milhões
    
    // Calculando o inverso da densidade (quanto menor a densidade, maior o poder)
    float inverso_densidade = 10000.0 / carta.densidade_pop; // Multiplicando por 10000 para normalizar
    
    // Somando todos os atributos normalizados
    return pop_normalizada + 
           carta.area + 
           carta.pib * 1000.0 + // Multiplicando por 1000 para dar mais peso ao PIB
           (float)carta.pontos_turisticos * 100.0 + // Multiplicando por 100 para dar mais peso aos pontos turísticos
           carta.pib_per_capita / 1000.0 + // Dividindo por 1000 para normalizar
           inverso_densidade;
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
    scanf("%lu", &carta.populacao);
    
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta.area);
    
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta.pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontos_turisticos);
    
    // Calcula a densidade populacional e o PIB per capita
    carta.densidade_pop = calcular_densidade(carta.populacao, carta.area);
    carta.pib_per_capita = calcular_pib_per_capita(carta.pib, carta.populacao);
    
    // Calcula o super poder
    carta.super_poder = calcular_super_poder(carta);
    
    return carta;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("\n=== Dados da Carta %s ===\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_pop);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
    printf("==========================\n\n");
}

// Função para comparar as cartas e exibir os resultados
void comparar_cartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Cartas:\n\n");
    
    // População (maior vence)
    printf("População: Carta %d venceu (%d)\n", 
           (carta1.populacao > carta2.populacao) ? 1 : 2,
           (carta1.populacao > carta2.populacao) ? 1 : 0);
    
    // Área (maior vence)
    printf("Área: Carta %d venceu (%d)\n",
           (carta1.area > carta2.area) ? 1 : 2,
           (carta1.area > carta2.area) ? 1 : 0);
    
    // PIB (maior vence)
    printf("PIB: Carta %d venceu (%d)\n",
           (carta1.pib > carta2.pib) ? 1 : 2,
           (carta1.pib > carta2.pib) ? 1 : 0);
    
    // Pontos Turísticos (maior vence)
    printf("Pontos Turísticos: Carta %d venceu (%d)\n",
           (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 2,
           (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 0);
    
    // Densidade Populacional (menor vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           (carta1.densidade_pop < carta2.densidade_pop) ? 1 : 2,
           (carta1.densidade_pop < carta2.densidade_pop) ? 1 : 0);
    
    // PIB per Capita (maior vence)
    printf("PIB per Capita: Carta %d venceu (%d)\n",
           (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 2,
           (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 0);
    
    // Super Poder (maior vence)
    printf("Super Poder: Carta %d venceu (%d)\n",
           (carta1.super_poder > carta2.super_poder) ? 1 : 2,
           (carta1.super_poder > carta2.super_poder) ? 1 : 0);
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
    
    // Compara e exibe os resultados das comparações
    comparar_cartas(carta1, carta2);
    
    return 0;
}