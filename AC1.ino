//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7

bool estadoLedVermelho = false;

const int botao1 = 2;
unsigned long lastDebounceTime1 = 0;
const int botaoDelay = 100;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, saida);
  
  Serial.begin(9600);
	
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: NOME AQUI               ");
}

void loop()
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
  	Serial.println("botao 1 apertado");
    ledVermelho();
  	lastDebounceTime1 = millis();
  }
	
  if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){ //se o "botao2" for pressionado:
    Serial.println("Producao encerrada"); //"imprimir" no monitor Serial:"Producao encerrada"
    digitalWrite(vermelho, LOW); //desligar o Led vermelho
    lastDebounceTime2 = millis(); //redefinir o "lastDebounceTime2"
  }
  if(getLuminosidade() > 5){ //adicionada as linhas com a função de ligar o Led verde (se a luminosidade maior que 5:)
  digitalWrite (verde, HIGH); //ligar o Led verde
  }else{ //se a luminosidade menor ou igual a 5:
  digitalWrite (verde, LOW); //desligar o Led verde
  }
	
  if(getTemperatura() > 30){
    ledAzul(true);
  }else{
  	ledAzul(falso); 
  }
  	
  delay(10);
}

void ledVermelho(){
  estadoLedVermelho = !estadoLedVermelho;
  digitalWrite(vermelho,estadoLedVermelho);
}
void ledVerde(){
 //precisa fazer  
}
void ledAzul(bool estado){
	digitalWrite(azul,estado);
}

int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
} 

int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
