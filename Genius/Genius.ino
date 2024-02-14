// Código de Funcionamento Genius
// Traduzido e adaptado por Usinainfo
// www.usinainfo.com.br

//Definindo as notas de cada som
#define NOTE_D4  262
#define NOTE_G4  294
#define NOTE_A4  330
#define NOTE_A5  349
 
int tons[4] = { NOTE_A5, NOTE_A4, NOTE_G4, NOTE_D4 };    // Sortea os sons utilizados
int sequencia[6] = {};                                 // Inicia sequencial de até 6 variáveis
int rodada_atual = 0;                                    // Indica a rodada do jogo
int passo_atual_na_sequencia = 0;                        // Indica a situação atual da sequecia
 
int pinoAudio = 6;                       // Define o pino de áudio
int pinosLeds[4] = { 8, 9, 10, 11 };     // Define os pinos dos LEDs
int pinosBotoes[4] = { 2, 3, 4, 5 };     // Define os pinos dos buttons
 
int botao_pressionado = 0;  // Inicializa botão em 0
int perdeu_o_jogo = false;  // Variável fim de jogo
int fim = false;  // fim das tentativas

int contador=0; // Contagem de rodadas
 
void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(pinosLeds[i], OUTPUT);   // Define o pino dos LEDs como saída
  }
 
  for (int i = 0; i <= 3; i++) {
    pinMode(pinosBotoes[i], INPUT);  // Define o pino dos botões como entrada
  }
 
  pinMode(pinoAudio, OUTPUT);        // Define o pino de áudio como saída
  randomSeed(analogRead(0));         // Gera um valor entre 0 e 1023
}
 
void loop() {
    if (perdeu_o_jogo) {            // Se acabar o jogo reinicia todas as variáveis
    int sequencia[6] = {};
    rodada_atual = 0;
    passo_atual_na_sequencia = 0;
    perdeu_o_jogo = false;
    fim = false;
    contador = 0;
  }
 
  if (rodada_atual == 0) {  // Som para inicialização da rodada
    tocarSomDeInicio();
    delay(500);
  }
  
  proximaRodada();        // Inicia a próxima rodada
  if(!fim){
    reproduzirSequencia();  // Reproduz a sequencia atual
    aguardarJogador();      // Aguarda jogadas
    delay(1000);            // 1 segundo de uma jogada a outra
  }
  else{
    perdeu_o_jogo = true;
    fim = false;
  }
}
 
void proximaRodada() {  // Sorteia o novo item da rodada
  contador++;
  if(contador <= 5){
    int numero_sorteado = random(0, 4);
    sequencia[rodada_atual++] = numero_sorteado;
  }
  else{
    decode_pontuacao(contador);
    fim = true;
  }
 
}
 
void reproduzirSequencia() {  // Reproduz a sequencia selecionada
   if(fim){
    return;
   }
  for (int i = 0; i < rodada_atual; i++) {
    tone(pinoAudio, tons[sequencia[i]]);
    digitalWrite(pinosLeds[sequencia[i]], HIGH);
    delay(500);
    noTone(pinoAudio);
    digitalWrite(pinosLeds[sequencia[i]], LOW);
    delay(100);
  }
  noTone(pinoAudio);
}
 
void aguardarJogador() {  // Aguarda o inicio do jogo
  if(fim){
    return;
   }
  for (int i = 0; i < rodada_atual; i++) {
    aguardarJogada();
    verificarJogada();
 
    if (perdeu_o_jogo) {
     return;
    }
 
    passo_atual_na_sequencia++;
  }
 
  passo_atual_na_sequencia = 0;  // Redefine a variável
}
 
void aguardarJogada() {
  boolean jogada_efetuada = false;
  while (!jogada_efetuada) {
    for (int i = 0; i <= 3; i++) {
      if (digitalRead(pinosBotoes[i]) == HIGH) {
        botao_pressionado = i; // Indica o botão pressionado
        tone(pinoAudio, tons[i]);
        digitalWrite(pinosLeds[i], HIGH);
        delay(300);
        digitalWrite(pinosLeds[i], LOW);
        noTone(pinoAudio);
 
        jogada_efetuada = true;
      }
    }
    delay(10);
  }
}
 
void verificarJogada() {
  if (sequencia[passo_atual_na_sequencia] != botao_pressionado) {
    decode_pontuacao(contador);
    fim = true;
    perdeu_o_jogo = true;
  }
}
 
void tocarSomDeInicio() {
  tone(pinoAudio, tons[0]);
  digitalWrite(pinosLeds[0], HIGH);
  digitalWrite(pinosLeds[1], HIGH);
  digitalWrite(pinosLeds[2], HIGH);
  digitalWrite(pinosLeds[3], HIGH);
  delay(500);
  digitalWrite(pinosLeds[0], LOW);
  digitalWrite(pinosLeds[1], LOW);
  digitalWrite(pinosLeds[2], LOW);
  digitalWrite(pinosLeds[3], LOW);
  delay(500);
  noTone(pinoAudio);
}

void decode_pontuacao(int cont){
  digitalWrite(pinosLeds[0], HIGH);
  digitalWrite(pinosLeds[1], HIGH);
  digitalWrite(pinosLeds[2], HIGH);
  digitalWrite(pinosLeds[3], HIGH);
  delay(700);  
  digitalWrite(pinosLeds[0], LOW);
  digitalWrite(pinosLeds[1], LOW);
  digitalWrite(pinosLeds[2], LOW);
  digitalWrite(pinosLeds[3], LOW);
  
  cont--;   // acerto para decodificação
  
  if(cont & 1){
    digitalWrite(pinosLeds[0], HIGH);
  }
   if(cont & 2){
    digitalWrite(pinosLeds[1], HIGH);
  } 

  if(cont & 4){
    digitalWrite(pinosLeds[2], HIGH);
  }  
   delay(2000);
  
}
