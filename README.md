# AVA_3_Sistemas-Embarcados
Descrição

Sistema embarcado que automatiza a sinalização de solicitação de parada em ônibus urbanos. Ao pressionar o botão de parada, o sistema aciona um LED indicativo e um alerta sonoro temporizado. A sinalização permanece ativa até que a porta do veículo seja aberta, indicando que a solicitação foi atendida.

Funcionamento
Estado inicial: LED vermelho aceso, sistema aguardando solicitação.
Solicitação de parada: ao pressionar o botão, o LED amarelo acende e o buzzer soa por 3 segundos.
Porta aberta: ao detectar a abertura da porta, o sistema cancela a solicitação, apaga o LED amarelo e volta ao estado de repouso (LED vermelho).

O código utiliza detecção de borda (transição HIGH → LOW) nas entradas digitais e controle de tempo não bloqueante com millis(), evitando o uso de delay() longo no loop principal.

Hardware / Simulação
Placa STM32 Nucleo-32 L031K6
2 botões (botão de parada e sensor de porta), com pull-up interno
1 LED amarelo + 1 LED vermelho, cada um com resistor de 220Ω
1 buzzer
Simulado no Wokwi
Pinagem
Componente	Pino
LED Amarelo	D2
LED Vermelho	D3
Buzzer	D4
Sensor de Porta	D5
Botão de Parada	D6
Como executar
Acesse o projeto no Wokwi.
Abra o arquivo sketch.ino e o diagram.json deste repositório.
Clique em play para iniciar a simulação.
Abra o Monitor Serial para acompanhar as mensagens de status.
Pressione o botão de parada para simular a solicitação; pressione o botão de porta para simular a abertura.
Autor

Julio Ricardo Jemio Sanchez
