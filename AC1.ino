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
	
  Serial.println("AC1 - Meu Primeiro Projeto 2021"); //imprimir texto
  Serial.println("                           V1.0"); //imprimir texto
  Serial.println("Grupo: BRIGHTSIDE               "); //imprimir texto
}

void loop() //repetir o que está dentro
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){ //quando clicar no botao1
  	Serial.println("Producao iniciada"); //imprimir o texto
        digitalWrite(vermelho, HIGH); //ligar o led vermelho
  	lastDebounceTime1 = millis(); //redefinir o lastDebounceTime1
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
