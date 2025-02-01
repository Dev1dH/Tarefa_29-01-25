


#include "pico/stdlib.h"    // Biblioteca padrão do Raspberry Pi Pico
#include "hardware/timer.h" // Biblioteca para de temporizadores de hardware
#include <stdio.h>          // Biblioteca padrão da linguagem C

// Definição dos pinos dos LEDs
#define LEDR_PIN 13 // Pino do LED vermelho
#define LEDB_PIN 12 // Pino do LED azul
#define LEDG_PIN 11 // Pino do LED verde

// Função de callback do temporizador para alternar os LEDs sequencialmente.
bool repeating_timer_callback(struct repeating_timer *t) {
    static int estado = 0;
    
    // Desliga todos os LEDs antes de acender o próximo
    gpio_put(LEDR_PIN, 0);
    gpio_put(LEDB_PIN, 0);
    gpio_put(LEDG_PIN, 0);
    
    // Liga o LED correspondente ao estado atual
    switch (estado) 
    {
     case 0:
            gpio_put(LEDB_PIN, 1);
            printf("LED azul ligado\n");
            break;
     case 1:
            gpio_put(LEDR_PIN, 1);
            printf("LED vermelho ligado\n");
            break;
     case 2:
            gpio_put(LEDG_PIN, 1);
            printf("LED verde ligado\n");
            break;
    }
    
    estado = (estado + 1) % 3;
    
    return true;
}

int main() {
    
    stdio_init_all(); // Inicializa a comunicação serial.
    
    // Inicializa os pinos GPIO e os define como saída.
    gpio_init(LEDR_PIN);
    gpio_init(LEDB_PIN);
    gpio_init(LEDG_PIN);
    gpio_set_dir(LEDR_PIN, GPIO_OUT);
    gpio_set_dir(LEDB_PIN, GPIO_OUT);
    gpio_set_dir(LEDG_PIN, GPIO_OUT);
    
    struct repeating_timer timer;
    
    // Temporizador em 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); 
    
    while (true) {
      
    }
  return 0;
}