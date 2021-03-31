
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
