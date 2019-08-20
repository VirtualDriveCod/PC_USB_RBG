
void setup() { 
  
  Serial.begin(9600);
Serial.println("терминал управления RBG");
 pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
Serial.println("info press  'i'");

}

void loop() {
start();
}
void st(){
  delay(2);
//int r; int b; int g;
  
  // int  F;
 
   if (Serial.available() > 0) {
 
int F = Serial.parseInt();
    if (F==1){analogWrite(3,255);analogWrite(5,0);analogWrite(6,0); }  //красный
     if (F==2){ analogWrite(5,255);analogWrite(3,0);analogWrite(6,0); }  //синий
      if (F==3){ analogWrite(6,255);analogWrite(3,0);analogWrite(5,0); }  //зеленый
       if (F==4){ analogWrite(3,255);analogWrite(5,0);analogWrite(6,255); }  //желтый
        if (F==5){ analogWrite(3,255);analogWrite(5,255);analogWrite(6,0); }  //аквамарин
      // if (F==6){ analogWrite(3,255);analogWrite(5,255);analogWrite(6,255); }  //белый
      if (F==6){ digitalWrite(3,HIGH);digitalWrite(5,HIGH);digitalWrite(6,HIGH); }  //белый
      if (F==0){ digitalWrite(3,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW); }  //выключить
         if (F==500){ analogWrite(3,0);analogWrite(5,0);analogWrite(6,0);// выход
         Serial.println("ВЫШЕЛ из режима статический");Serial.println("===============================================");start();} 
}
st();}
void blue(){int b; int i;
  delay(2);
 
  
  if (Serial.available() > 0) {
 
    i = Serial.parseInt();
   if (i>0){b=i;analogWrite(5,b);}
    if (i == 500){ b=0;analogWrite(5,b); Serial.println("ВЫШЕЛ из синего");
     Serial.println("===============================================");
      start();}
    }
    
  blue();
}
void dinam(){
  int r;
  int b;
  int g;
  int i = 20;
  for (r=0;r<200;r++){delay(i); analogWrite(3,r);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){r=0; b=0; g=0; Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");start();}Serial.println(i); } }// загорается красный
  for (g=200;g>0;g--){delay(i);analogWrite(6,g);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){r=0; b=0; g=0; Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");start();}Serial.println(i); } }// тухнет зеленый
  for (b=0;b<200;b++){delay(i);analogWrite(5,b);;if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){r=0; b=0; g=0; Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");start();}Serial.println(i); } }// загорается синий
  for (r=200;r>0;r--){delay(i);analogWrite(3,r);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){r=0; b=0; g=0; Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");start();}Serial.println(i); } }// тухнет красный
  for (g=0;g<200;g++){delay(i);analogWrite(6,g); if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){r=0; b=0; g=0; Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");start();}Serial.println(i); }}// загорается зеленый
  for (b=200;b>0;b--){delay(i);analogWrite(5,b);if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){r=0; b=0; g=0; Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");start();}Serial.println(i); } }// тухнет синий

 // if (Serial.available() > 0) {int i = Serial.parseInt();if (i == 500){Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");start();}Serial.println(i); }
   
dinam();
}
void dop(){
  Serial.println("===============================================");
  Serial.println("задайте яркость 0-255");
  Serial.println("для выхода отправьте 500");
}

void green(){
  delay(2);
  int g;
  int i;
  //analogWrite(6,g);
  if (Serial.available() > 0) {
  
    i = Serial.parseInt();
     if (i>0){g=i;analogWrite(6,g);}
    if (g == 500){g=0;analogWrite(6,g); Serial.println("ВЫШЕЛ из зеленого");
     Serial.println("===============================================");
      start();}
  // Serial.println(i); 
   }
    
 green();
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
void red(){
  delay(2);
  int i;int r;
  //analogWrite(3,r);
  if (Serial.available() > 0) {
  
    i = Serial.parseInt();
    if (i>0){r=i;analogWrite(3,r);}
    if (i == 500){r=0;analogWrite(3,r); Serial.println("ВЫШЕЛ из красного");
    Serial.println("===============================================");
      start();}
   //Serial.println(i);
   }
    
  red();
}


void start(){
 delay(2);
int F;
 if (Serial.available() > 0) {
 
    F = Serial.read();
if (F==66){ dop();blue();}  
if (F==71){ dop();green();}
if (F==82){ dop();red();}
if (F==68){ mode2();dinam();}
if (F==83){ mode();st();}

 
if (F == 105){info();}
   Serial.println(F);} // отлов команд 
 start();} 
