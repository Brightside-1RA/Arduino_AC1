
const int vermelho = 5; //definindo as portas dos leds
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false; //definindo o estado dos leds
bool estadoLedVerde = false;
bool estadoLedAzul = false;

const int botao1 = 2; //definindo as "portas" dos botões
const int botao2 = 3;

unsigned long lastDebounceTime1 = 0; //definindo o lastDebounceTime para cada botão
unsigned long lastDebounceTime2 = 0;

const int botaoDelay = 100; //delay para o clique do botão

void setup()
{
   pinMode(A0, INPUT); //definindo que o pino do sensor de temperatura é um INPUT (receberá informação)
  pinMode(A1, INPUT); //definindo que o pino do ''sensor'' de luminosidade é um INPUT (receberá informação)
	
  pinMode(botao1, INPUT); //linha adicionada, definindo que o pino do botão1 ''receberá informação''
  pinMode(botao2, INPUT); //linha adicionada, definindo que o pino do botão2 ''receberá informação''
  
  pinMode(vermelho, OUTPUT); //definindo que o pino em que está o led receberá energia
  pinMode(verde, OUTPUT); //definindo que o pino em que está o led receberá energia
  pinMode(azul, OUTPUT); //mudança de ''saída'' para ''output'', definindo que o pino em que está o led receberá energia
  
  Serial.begin(9600); //iniciando o Serial
	
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
  
  if(getTemperatura() >= 15){//>=15graus
digitalWrite(azul, HIGH);//  digitalWrite e azul HIGH
Serial.println("a Iuminosidade do ambiente esta muito alta"); }else{
	  
digitalWrite(azul,  LOW);//  digitalWrite e azul  LOW
Serial.println("a Iuminosidade do ambiente esta adequada"); } 
  delay(10);
}

 void ledVermelho(bool estado){ //"redefinindo" o estado do led vermelho
  estadoLedVermelho = !estadoLedVermelho;
  digitalWrite(vermelho,estadoLedVermelho);
}
void ledVerde(bool estado){ //"redefinindo" o estado do led verde
  estadoLedVerde = !estadoLedVerde;
  digitalWrite(verde,estadoLedVerde); 
}
void ledAzul(bool estado){ //"redefinindo" o estado do led azul
  estadoLedAzul = !estadoLedAzul;
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
