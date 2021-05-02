/* Autor: Sergio Dantas
 * Este código pode usado para bounce de botão. Pode   
 * ser usado para contar um valor inteiro menor que reset, caso queira
 * mudar basta mudar na linha #define reset 4 o número pelo número que 
 * se quer contar
 */
#define pinVermelho 13
#define botao 7
#define reset 4
byte estado_botao;
byte contador = 0;
byte liga_led_vermelho=HIGH;
byte desliga_led_vermelho=LOW;
byte controla_botao=HIGH;

void setup(){ 
  pinMode(pinVermelho, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    estado_botao = digitalRead(botao);
    if ((estado_botao == LOW)&&(controla_botao == HIGH)){
        contador = contador + 1;
        if (contador > reset){contador = 1;}
        Serial.print(" botao apertado ");
        Serial.print(contador);
        Serial.print(" ");Serial.println(" vezes");
        if (contador == 1){
            digitalWrite(pinVermelho, liga_led_vermelho);
        }else{digitalWrite(pinVermelho, desliga_led_vermelho);}
    
    }  
    controla_botao = estado_botao;
   delay(100);
  }

  
