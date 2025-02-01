#include "pico/stdlib.h" // Biblioteca padrão do Raspberry Pi Pico para controle de GPIO, temporização e comunicação serial.
#include "pico/time.h"   // Biblioteca para gerenciamento de temporizadores e alarmes.

#define LEDG_PIN 11    // Define o pino do LED verde.
#define LEDB_PIN 12   // Define o pino do LED azul
#define LEDR_PIN 13 // Define o pino do LED vermelho
#define BUTTON_PIN 5  // Define o pino GPIO 5 para ler o estado do botão.

bool led_active = false;    // Indica se o LED está atualmente aceso (para evitar múltiplas ativações).

absolute_time_t turn_off_time;  // Variável para armazenar o tempo em que o LED deve ser desligado (não utilizada neste código).

// Função de callback para desligar o LED verde após 3s
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    gpio_put(LEDG_PIN, false);

    // Atualiza o estado de 'led_active' para falso, desligando-o.
    led_active = false;
}

// Função de callback para desligar o LED azul após 3s
int64_t turn_off_callback2(alarm_id_t id, void *user_data) {
    gpio_put(LEDB_PIN, false);

    // Atualiza o estado de 'led_active' para falso, desligando-o.
    led_active = false;
}

// Função de callback para desligar o LED vermelho após 3s
int64_t turn_off_callback3(alarm_id_t id, void *user_data) {
    gpio_put(LEDR_PIN, false);

    // Atualiza o estado de 'led_active' para falso, desligando-o.
    led_active = false;
}

int main() {
    
    // Iniciação todos os pinos
    stdio_init_all();

    // Configura o pino LED_PIN (11) como saída digital.
    gpio_init(LEDR_PIN);
    gpio_init(LEDG_PIN);
    gpio_init(LEDB_PIN);
    gpio_set_dir(LEDR_PIN, GPIO_OUT);
    gpio_set_dir(LEDG_PIN, GPIO_OUT);
    gpio_set_dir(LEDB_PIN, GPIO_OUT);
    
    // Configura o pino BUTTON_PIN (5) como entrada digital.
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);

    // Habilita o resistor pull-up interno para o pino do botão.
    gpio_pull_up(BUTTON_PIN);

    while (true) {
    // Verifica se o botão foi pressionado (nível baixo no pino) e se o LED não está ativo.
   
    
    if (gpio_get(BUTTON_PIN) == 0 && !led_active) {
            // Adiciona um pequeno atraso para debounce, evitando leituras errôneas.
      sleep_ms(50);
 
    
    // Verifica novamente o estado do botão após o debounce.
        if (gpio_get(BUTTON_PIN) == 0) {
                          
          // Liga o LED configurando o pino LED_PIN para nível alto.
          gpio_put(LEDR_PIN, 1);
          gpio_put(LEDG_PIN, 1);
          gpio_put(LEDB_PIN, 1);

      led_active = true;    

      // Agenda um alarme para desligar cada LED após 3 segundo após o último ter sido apagado
      add_alarm_in_ms(3000, turn_off_callback, NULL, false);
      add_alarm_in_ms(6000, turn_off_callback2, NULL, false);
      add_alarm_in_ms(9000, turn_off_callback3, NULL, false);
            }
      }

        sleep_ms(10);
    }

    return 0;
}