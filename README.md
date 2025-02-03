# Tarefa_29-01-25
## Atividade 1: Temporizador periódico
Com emprego da função add_repeating_timer_ms(), presente na ferramenta Pico SDK, foi projetado com um semáforo com temporização de 3 segundos, ou seja, cada LED fica aceso por 3 segundos e em seguida é apagado, de maneira alternada entre os LEDs azul, vermelho e verde.
## Instruções de uso
Com a placa conectada a entrada USB do computador, ative o bootsel da placa. Compile o projeto no VSCode e rode o programa (run).
Com todo os LEDs apagados, inicialmente, após 3 segundo o primeiro LEDs é aceso, apagando-se e em seguida acendendo o próximo, repetindo este ciclo periódico. É exibida uma mensagem informando quando LED está aceso no momento.

Vídeo de demonstração: https://youtu.be/apxjOKTaPKU

Simulação do Wokwi: https://wokwi.com/projects/421620391317351425

## Atividade 2: Temporizador de um disparo
Com o emprego da função add_alarm_in_ms(), presente na ferramenta Pico SDK, foi projetado um sistema de temporização 
para o acionamento de LEDs, que atua a partir do clique no botão, Todos os LEDs acendem. Em seguida, 
## Instruções de uso
Com a placa conectada a entrada USB do computador, ative o bootsel da placa. Compile o projeto no VSCode e rode o programa (run).
Com todo os LEDs apagados, inicialmente, clique no botão e perceba que todos os LEDs se acendem. Após o atraso de 3 segundos o primeiro LED se apaga, em seguida o segundo e o terceiro, até que todos estejam apagados. É importante salientar que durante o disparo, não importa quantas vezes o botão seja pressionado, a contagem so será reiniciada quando todos eles se apagarem.

Vídeo de demonstração: https://youtu.be/S4nvxA4uWHg

Simulação do Wokwi: https://wokwi.com/projects/421629419317553153
