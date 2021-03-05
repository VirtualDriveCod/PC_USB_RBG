#define R 6           // 6 пин красный
#define G 5           // 5 пин зеленый
#define B 3           // 3 пин синй


int r, g, b;      // переменные хранения заполнения ШИМ для цветов грильянда
 int tim = 20;
  int tim2= 100;

int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void next(){
  if (Serial.available() > 0) { 
int F = Serial.parseInt();
  digitalWrite(3,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW);              // выход
   Serial.println("ВЫШЕЛ из режима");Serial.println("===============================================");
   start();}
  
}
 
  
void setup() { 
Serial.begin(9600);
Serial.println("терминал управления RBG");

  pinMode(R, OUTPUT);      // пин R на выход
  pinMode(G, OUTPUT);      // пин G на выход
  pinMode(B, OUTPUT);      // пин B на выход

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
		Serial.println("Нажмите 'Z' чтобы включить одиночный режим нормально");
    Serial.println("Нажмите 'z' чтобы включить одиночный режим быстро");
    Serial.println("Нажмите 'W' чтобы включить грильянду");
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
if (F==87){gril();}
if (F == 105){info();}}

 start();} 
void dinam(){
 
  int r;
  int b;
  int g;
  int i = 20;
  for (r=0;r<200;r++){delay(i); analogWrite(3,r);next();}// загорается красный
  for (g=200;g>0;g--){delay(i);analogWrite(6,g);next();}//// тухнет зеленый
  for (b=0;b<200;b++){delay(i);analogWrite(5,b);next();}// загорается синий
  for (r=200;r>0;r--){delay(i);analogWrite(3,r);next();}//// тухнет красный
  for (g=0;g<200;g++){delay(i);analogWrite(6,g); next();}// загорается зеленый
  for (b=200;b>0;b--){delay(i);analogWrite(5,b);next();}//// тухнет синий

dinam();
}
void rbg(){
  digitalWrite(3, HIGH);  delay(1000);
   digitalWrite(3,LOW);
  digitalWrite(5, HIGH);  delay(1000);
   digitalWrite(5,LOW);
    digitalWrite(6, HIGH);  delay(1000);
   digitalWrite(6,LOW);
  next();
   rbg();
   
}
void rbg_2(){
  int r;
  int b;
  int g;
  int d = 5;
  int w= 100;
   for (b=0;b<256;b++){delay(w);analogWrite(5,b);next();}// загорается синий
     for (b=255;b>-1;b--){delay(d);analogWrite(5,b);next();}//// тухнет синий
     for (g=0;g<256;g++){delay(w);analogWrite(6,g);next();}// загорается зеленый
       for (g=255;g>-1;g--){delay(d);analogWrite(6,g);next();}//// тухнет зеленый
         for (r=0;r<256;r++){delay(w); analogWrite(3,r);next();}// загорается красный
          for (r=255;r>-1;r--){delay(d);analogWrite(3,r);next();}//// тухнет красный
           // next();
          rbg_2();
}

  void prog1(){
    
  for (r = 0; r < 255; r++) { 
    analogWrite(R, r);
      next();
  delay(tim);}
for (r =255; r >= 0; r--) { 
    analogWrite(R, r);
      next();
  delay(tim);}
delay(tim+500);
  
for (r = 0; r < 255; r++) { 
    analogWrite(B, r);  next();
  delay(tim);}
for (r = 255; r >= 0; r--) { 
    analogWrite(B, r);  next();
  delay(tim);}
delay(tim+500);
  
  for (r = 0; r < 255; r++) { 
    analogWrite(R, r);
    analogWrite(G, r);  next();
    delay(tim);}
for (r = 255; r >= 0; r--) { 
    analogWrite(R, r);
    analogWrite(G, r);  next();
  delay(tim);}
  delay(tim+500);
  
for (r = 0; r < 255; r++) { 
    analogWrite(G, r);  next();
  delay(tim);}
for (r = 255; r >= 0; r--) { 
    analogWrite(G, r);  next();
  delay(tim);}
  delay(tim+500);
  
   for (r = 0; r < 255; r++) { 
    analogWrite(R, r);
    analogWrite(B, r);  next();
    delay(tim);}
for (r = 255; r >= 0; r--) { 
    analogWrite(R, r);
    analogWrite(B, r);  next();
  delay(tim);}
  delay(tim+500);
  
  for (r = 0; r < 255; r++) { 
    analogWrite(G, r);
    analogWrite(B, r);  next();
    delay(tim);}
for (r = 255; r >= 0; r--) { 
    analogWrite(G, r);
    analogWrite(B, r);  next();
  delay(tim);}
  delay(tim+500);

  }
 void prog2(){
  for (r = 0; r < 255; r++) { 
    analogWrite(R, r);  next();
  delay(tim);
  }
 
  //от фиолетового к красному
 for (b = 255; b > 0; b--) { 
    analogWrite(B, b);  next();
   delay(tim);
  } 
  // от красного к желтому
  for (g = 0; g < 256; g++) { 
    analogWrite(G, g);  next();
    delay(tim);
  } 
  // от желтого к зеленому
  for (r = 255; r > 0; r--) { 
    analogWrite(R, r);  next();
    delay(tim);
  } 
  //  от зеленого к зеленовато-голубому
  for (b = 0; b < 256; b++) { 
    analogWrite(B, b);  next();
   delay(tim);
  } 
  // от зеленовато-голубого к голубому
  for (g = 255; g > 0; g--) { 
    analogWrite(G, g);  next();
    delay(tim);
  }
 }
void prog3(){
  digitalWrite(R,HIGH);
   delay(tim2);
  digitalWrite(R,LOW);
   delay(tim2);
  digitalWrite(R,HIGH);
   delay(tim2);
  digitalWrite(R,LOW);
   delay(tim2);
   digitalWrite(G,HIGH);
   delay(tim2);
  digitalWrite(G,LOW);
   delay(tim2);
    digitalWrite(G,HIGH);
   delay(tim2);
  digitalWrite(G,LOW);
   delay(tim2);
      digitalWrite(B,HIGH);
   delay(tim2);
  digitalWrite(B,LOW);
   delay(tim2);
    digitalWrite(B,HIGH);
   delay(tim2);
  digitalWrite(B,LOW);
   delay(tim2);
}
void gril(){//грильянда
  
   int i;
prog1();
prog2();
for (i=0 ; i<100; i++){
    next();
   prog3();}
for (i=0 ; i<5; i++){
 digitalWrite(3, HIGH);  delay(2000);
   digitalWrite(3,LOW);
  digitalWrite(5, HIGH);  delay(2000);
   digitalWrite(5,LOW);
    digitalWrite(6, HIGH);  delay(2000);
   digitalWrite(6,LOW);
next();}

  gril(); 
  }
