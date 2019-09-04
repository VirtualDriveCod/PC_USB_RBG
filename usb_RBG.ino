int redPin = 3;
int greenPin = 5;
int bluePin = 6;
void next(){
  digitalWrite(3,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW);              // выход
   Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");
   start();
  
}
 
  
void setup() { 
Serial.begin(9600);
Serial.println("терминал управления RBG");
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
Serial.println("info press  'i'");
}
void info(){
   Serial.println("===============================================");
  Serial.println("ПОМОШЬ");
  
    Serial.println("Нажмите 'R' чтобы включить красный");
    Serial.println("Нажмите 'B' чтобы включить синий");
    Serial.println("Нажмите 'G' чтобы включить зеленый");
       Serial.println("Нажмите 'D' чтобы включить динамический режим");
        Serial.println("Нажмите 'S' чтобы включить статический режим");
}
void loop() {
start();
}

void blue(){
  int b; int i;
  delay(2); 
if (Serial.available() > 0) {
    i = Serial.parseInt();
    if (i>0){b=i;analogWrite(5,b);}
    if (i == 500){ b=0;analogWrite(5,b);
    Serial.println("ВЫШЕЛ из синего");
    Serial.println("===============================================");
      start();}}
 blue();
}
void green(){
  delay(2);
  int g;
  int i;
  if (Serial.available() > 0) {
    i = Serial.parseInt();
    if (i>0){g=i;analogWrite(6,g);}
    if (g == 500){g=0;analogWrite(6,g);
    Serial.println("ВЫШЕЛ из зеленого");
    Serial.println("===============================================");
      start();}}
 green();
}
void red(){
  delay(2);
  int i;int r;
  
  if (Serial.available() > 0) {
  i = Serial.parseInt();
  if (i>0){r=i;analogWrite(3,r);}
  if (i == 500){r=0;analogWrite(3,r); 
  Serial.println("ВЫШЕЛ из красного");
  Serial.println("===============================================");
      start();}}
  red();
}
void dop(){
  Serial.println("===============================================");
  Serial.println("задайте яркость 0-255");
  Serial.println("для выхода отправьте 500");
}

void statik(){
  delay(2);
 if (Serial.available() > 0) { 
int F = Serial.parseInt();
        if (F==1){ digitalWrite(3,HIGH);digitalWrite(5,LOW);digitalWrite(6,LOW); }            //красный
        if (F==2){ digitalWrite(5,HIGH);digitalWrite(3,LOW);digitalWrite(6,LOW); }            //синий
        if (F==3){ digitalWrite(6,HIGH);digitalWrite(3,LOW);digitalWrite(5,LOW); }            //зеленый
        if (F==4){ digitalWrite(3,HIGH);digitalWrite(5,LOW);digitalWrite(6,HIGH); }          //желтый
        if (F==5){ digitalWrite(3,HIGH);digitalWrite(5,HIGH);digitalWrite(6,LOW); }          //аквамарин
        if (F==6){ digitalWrite(3,HIGH);digitalWrite(5,HIGH);digitalWrite(6,HIGH); }         //белый
        if (F==0){ digitalWrite(3,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW); }             //выключить
        
        if (F==500){ digitalWrite(3,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW);              // выход
         Serial.println("ВЫШЕЛ из режима статический");Serial.println("===============================================");start();} 
}
statik();}
void mode(){
Serial.println("===============================================");
Serial.println("режим статический");
Serial.println("'1' для красного");
Serial.println("'2' для синего");
Serial.println("'3' для зеленого");
Serial.println("'4' для желтого");
Serial.println("'5' для аквамарин");
Serial.println("'6' для белый");
Serial.println("'0' для OFF");
Serial.println("'500' выход");
}

void mode2(){
  Serial.println("===============================================");  
Serial.println("динамический режим");
Serial.println("для выхода отправьте 500");
}
void start(){
 delay(2);
int F;
 if (Serial.available() > 0) {
    F = Serial.read();
if (F==66){ dop();blue();}  
if (F==71){ dop();green();}
if (F==82){ dop();red();}
if (F==68){mode2();dinam();}
if (F==83){ mode();statik();}
if(F==122){rbg();}
if(F==90){rbg_2();}
if (F == 105){info();}}

 start();} 
void dinam(){
 
  int r;
  int b;
  int g;
  int i = 20;
  for (r=0;r<200;r++){delay(i); analogWrite(3,r);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}// загорается красный
  for (g=200;g>0;g--){delay(i);analogWrite(6,g);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}//// тухнет зеленый
  for (b=0;b<200;b++){delay(i);analogWrite(5,b);;if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}// загорается синий
  for (r=200;r>0;r--){delay(i);analogWrite(3,r);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}//// тухнет красный
  for (g=0;g<200;g++){delay(i);analogWrite(6,g); if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}// загорается зеленый
  for (b=200;b>0;b--){delay(i);analogWrite(5,b);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}//// тухнет синий

dinam();
}
void rbg(){
  digitalWrite(3, HIGH);  delay(50);
   digitalWrite(3,LOW);
  digitalWrite(5, HIGH);  delay(50);
   digitalWrite(5,LOW);
    digitalWrite(6, HIGH);  delay(50);
   digitalWrite(6,LOW);
  if (Serial.available() > 0) { 
int F = Serial.parseInt();
   if (F==500){ digitalWrite(3,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW);   
   Serial.println("===============================================");start();}}// выход
   rbg();
   
}
void rbg_2(){
  int r;
  int b;
  int g;
  int d = 5;
  int w= 100;
   for (b=0;b<256;b++){delay(w);analogWrite(5,b);;if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}// загорается синий
     for (b=255;b>-1;b--){delay(d);analogWrite(5,b);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}//// тухнет синий
     for (g=0;g<256;g++){delay(w);analogWrite(6,g); if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}// загорается зеленый
       for (g=255;g>-1;g--){delay(d);analogWrite(6,g);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}//// тухнет зеленый
         for (r=0;r<256;r++){delay(w); analogWrite(3,r);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}// загорается красный
          for (r=255;r>-1;r--){delay(d);analogWrite(3,r);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){next();}}}//// тухнет красный
          rbg_2();
}
