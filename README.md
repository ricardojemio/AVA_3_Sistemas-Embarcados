# AVA_3_Sistemas-Embarcados
# 🚌 Sistema de Sinalização de Parada para Ônibus
 
![Platform](https://img.shields.io/badge/platform-Wokwi-blue)
![Board](https://img.shields.io/badge/board-STM32%20Nucleo--32%20L031K6-orange)
![Language](https://img.shields.io/badge/language-C%2B%2B%20(Arduino)-00979D)
 
Projeto da disciplina **Sistemas Embarcados** — Atividade Avaliativa 3 — Universidade Veiga de Almeida.
 
---
 
## 📋 Descrição
 
Sistema embarcado que automatiza a sinalização de solicitação de parada em ônibus urbanos. Ao pressionar o botão de parada, o sistema aciona um LED indicativo e um alerta sonoro temporizado. A sinalização permanece ativa até que a porta do veículo seja aberta, indicando que a solicitação foi atendida.
 
---
 
## ⚙️ Funcionamento
 
| Estado | Gatilho | Resultado |
|---|---|---|
| 🔴 **Repouso** | Estado inicial | LED vermelho aceso, sistema aguardando |
| 🟡 **Solicitação ativa** | Botão de parada pressionado | LED amarelo acende, buzzer soa por 3s |
| 🔴 **Atendido** | Porta aberta | Solicitação cancelada, volta ao repouso |
 
O código utiliza detecção de borda (transição HIGH → LOW) nas entradas digitais e controle de tempo não bloqueante com `millis()`, evitando o uso de `delay()` longo no loop principal.
 
---
 
## 🔌 Hardware / Simulação
 
- 🧠 Placa STM32 Nucleo-32 L031K6
- 🔘 2 botões (botão de parada e sensor de porta), com pull-up interno
- 💡 1 LED amarelo + 1 LED vermelho, cada um com resistor de 220Ω
- 🔊 1 buzzer
- 🖥️ Simulado no [Wokwi](https://wokwi.com/)
 
---
 
## 📌 Pinagem
 
| Componente      | Pino |
|-----------------|:----:|
| 💡 LED Amarelo     | D2   |
| 💡 LED Vermelho    | D3   |
| 🔊 Buzzer          | D4   |
| 🚪 Sensor de Porta | D5   |
| 🔘 Botão de Parada | D6   |
 
---
 
## ▶️ Como executar
 
1. Acesse o projeto no [Wokwi](https://wokwi.com/).
2. Abra o arquivo `sketch.ino` e o `diagram.json` deste repositório.
3. Clique em **play** para iniciar a simulação.
4. Abra o **Monitor Serial** para acompanhar as mensagens de status.
5. Pressione o botão de parada para simular a solicitação; pressione o botão de porta para simular a abertura.
 
---
 
## 👤 Autor
 
**Julio Ricardo Jemio Sanchez**
