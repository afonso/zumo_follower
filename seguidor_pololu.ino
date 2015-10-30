int m11 = 7;
int m12 = 6;
int m21 = 3;
int m22 = 2;
int m1 = 8;
int m2 = 5;
int s1, s2;
extern int v = 0;

void setup() {
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  Serial.begin(9600);
}

void loop() {
  s1 = wb(readQD1(11), 2500);
  s2 = wb(readQD2(10), 1500);
  if(s1 && s1){
    frente(255);
  }else if(s1 && !s2){
    direita(255);
  }else if(!s1 && s2){
    esquerda(255);
  }else{
    frente(120);
  }

  Serial.print(readQD1(11));
  Serial.print(" : ");
  Serial.println(readQD2(10));
  /*
  frente(255);
  delay(2000);
  tras(255);
  delay(2000);
  direita(255);
  delay(2000);
  esquerda(255);
  delay(2000);
  */
  delay(10);
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

int readQD2(int s){
  pinMode(s, OUTPUT);
  digitalWrite(s, HIGH);  
  delayMicroseconds(10);
  pinMode(s, INPUT);

  long time = micros();

  //time how long the input is HIGH, but quit after 3ms as nothing happens after that
  while (digitalRead(s) == HIGH && micros() - time < 3000); 
  int diff = micros() - time;

  return diff;
}

int readQD1(int s){
  pinMode(s, OUTPUT);
  digitalWrite(s, HIGH);  
  delayMicroseconds(10);
  pinMode(s, INPUT);

  long time = micros();

  //time how long the input is HIGH, but quit after 3ms as nothing happens after that
  while (digitalRead(s) == HIGH && micros() - time < 3000); 
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

