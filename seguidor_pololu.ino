int m11 = 7; //pino 1 motor 1
int m12 = 6; //pino 2 motor 1
int m21 = 3; //pino 1 motor 2
int m22 = 2; //pino 2 motor 2

int m1 = 6; //pwm motor 1 - velocidade
int m2 = 8; //pwm motor 2 - velocidade
int s1 = 4; //sensor 1
int s2 = 12; //sensor 2

void setup() {
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // debug
  Serial.print(readQD(s1)); 
  Serial.print(" : "); 
  Serial.print(wb(readQD(s1), 1500)); 
  Serial.print(" : "); 
  Serial.print(readQD(s2)); 
  Serial.print(" : "); 
  Serial.println(wb(readQD(s2), 1500)); 
  
  boolean sen1 = wb(readQD(s1), 1500); //wb(valorSensor, precisao)
  boolean sen2 = wb(readQD(s2), 1500);
  if(sen1 && sen2){
    frente(255);
  }else if(sen1 && !sen2){
    direita(255);
  }else if(!sen1 && sen2){
    esquerda(255);
  }else{
    frente(175);
  }
}

void tras(int v) {
  analogWrite(m1, v); 
  analogWrite(m2, v); 
  digitalWrite(m11, HIGH);
  delay(10);             
  digitalWrite(m12, LOW); 
  delay(10);             
  digitalWrite(m21, LOW); 
  delay(10);        
  digitalWrite(m22, HIGH); 
  delay(10);        
}

void frente(int v) {
  analogWrite(m1, v); 
  analogWrite(m2, v); 
  digitalWrite(m11, LOW);
  delay(10);             
  digitalWrite(m12, HIGH); 
  delay(10);             
  digitalWrite(m21, HIGH); 
  delay(10);        
  digitalWrite(m22, LOW); 
  delay(10);        
}

void esquerda(int v) {
  analogWrite(m1, v); 
  analogWrite(m2, v); 
  digitalWrite(m11, HIGH);
  delay(10);             
  digitalWrite(m12, LOW); 
  delay(10);             
  digitalWrite(m21, HIGH); 
  delay(10);        
  digitalWrite(m22, LOW); 
  delay(10);        
}

void direita(int v) {
  analogWrite(m1, v); 
  analogWrite(m2, v); 
  digitalWrite(m11, LOW);
  delay(10);             
  digitalWrite(m12, HIGH); 
  delay(10);             
  digitalWrite(m21, LOW); 
  delay(10);        
  digitalWrite(m22, HIGH); 
  delay(10);        
}

int readQD(int QRE1113_Pin){
  pinMode( QRE1113_Pin, OUTPUT );
  digitalWrite( QRE1113_Pin, HIGH );  
  delayMicroseconds(10);
  pinMode( QRE1113_Pin, INPUT );

  long time = micros();
  while (digitalRead(QRE1113_Pin) == HIGH && micros() - time < 3000); 
  int diff = micros() - time;

  return diff;
}

boolean wb(int v, int m) {
  int i;
  if (v > m) {
    i = true; //black
  }else{
    i = false; //white
  }
 return i; 
}


