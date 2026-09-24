#define LED_AMARELO D2
#define LED_VERMELHO D3
#define BUZZER D4
#define PORTA D5
#define BOTAO_PARADA D6

bool solicitacaoAtiva = false;
bool botaoAnterior = HIGH;
bool portaAnterior = HIGH;

bool buzzerAtivo = false;
unsigned long inicioBuzzer = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(PORTA, INPUT_PULLUP);
  pinMode(BOTAO_PARADA, INPUT_PULLUP);

  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(BUZZER, LOW);

  Serial.println("Sistema iniciado");
  Serial.println("Aguardando solicitacao de parada");
}

void loop() {
  bool botaoAtual = digitalRead(BOTAO_PARADA);
  bool portaAtual = digitalRead(PORTA);

  // Registra a solicitacao ao pressionar o botao de parada
  if (botaoAtual == LOW && botaoAnterior == HIGH) {
    solicitacaoAtiva = true;

    buzzerAtivo = true;
    inicioBuzzer = millis();
    digitalWrite(BUZZER, HIGH);

    Serial.println("Parada solicitada");
  }

  // Desliga o buzzer depois de tres segundos
  if (buzzerAtivo && millis() - inicioBuzzer >= 3000) {
    buzzerAtivo = false;
    digitalWrite(BUZZER, LOW);

    Serial.println("Alerta sonoro finalizado");
  }

  // Cancela a solicitacao quando a porta e aberta
  if (portaAtual == LOW && portaAnterior == HIGH) {
    solicitacaoAtiva = false;
    buzzerAtivo = false;
    digitalWrite(BUZZER, LOW);

    Serial.println("Porta aberta - solicitacao atendida");
  }

  // Atualiza os LEDs conforme o estado do sistema
  if (solicitacaoAtiva) {
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
  } else {
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
  }

  botaoAnterior = botaoAtual;
  portaAnterior = portaAtual;

  delay(20);
}