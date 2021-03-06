int sensor_1= 0;
int sensor_2= 0;
int sensor_3= 0;
int sensor_4= 0;
int sensor_5= 0;



int rightA = 9;
int rightB = 8;
int rightPWM = 7;
int leftA = 12; 
int leftB = 11;
int leftPWM = 10; 
int count=0;
void setup() {
  
  pinMode(rightA,OUTPUT) ;
  pinMode(rightB,OUTPUT) ;
  pinMode(rightPWM,OUTPUT);

  pinMode(leftA,OUTPUT) ;  
  pinMode(leftB,OUTPUT) ;  
  pinMode(leftPWM,OUTPUT) ;
  delay(100);
  Serial.begin(9600);
}

void loop() {

 sensorRead();
  dir();
    //------------------------------> forward<-------------------------------//
  
if ((sensor_1==1) && (sensor_2==1) && (sensor_3==0) && (sensor_4==1) &&(sensor_5==1)){
  
    forward();
}



//-------------------------------->alignment<------------------------------//

else if (sensor_4==0&& sensor_5==1 && sensor_2==1 && sensor_1==1){
 
  
    analogWrite(rightPWM,100);
    analogWrite(leftPWM,120);
   
    digitalWrite(rightA,LOW);
    digitalWrite(rightB,LOW);
    digitalWrite(leftA,LOW);
    digitalWrite(leftB,HIGH);
  
}

else if ((sensor_2==0)&& sensor_1==1 &&sensor_4==1 && sensor_5==1)
 {
  
  analogWrite(rightPWM,100);
  analogWrite(leftPWM,120);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,HIGH);
  digitalWrite(leftA,LOW);
  digitalWrite(leftB,LOW);
    
}
//===============================>plus junction<============================//
else if ( sensor_5==0 && sensor_1==0 && sensor_4==0 && sensor_3==0 && sensor_2==0){
    count++;
  Serial.println(count);
  delay(70);
  switch(count){
     case (2):{
 
  analogWrite(rightPWM,80);
  analogWrite(leftPWM,90);
  digitalWrite(rightA,HIGH);
  digitalWrite(rightB,LOW);
  digitalWrite(leftA,LOW);
  digitalWrite(leftB,HIGH);
      delay(60);
  do{
  analogWrite(rightPWM,80);
  analogWrite(leftPWM,90);
  digitalWrite(rightA,HIGH);
  digitalWrite(rightB,LOW);
  digitalWrite(leftA,LOW);
  digitalWrite(leftB,HIGH);
      
  }
  while(digitalRead(33)!=0);
  analogWrite(rightPWM,80);
  analogWrite(leftPWM,90);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,HIGH);
  digitalWrite(leftA,HIGH);
  digitalWrite(leftB,LOW);
      delay(200);
    forward();
delay(800);
   
  do{
  analogWrite(rightPWM,80);
  analogWrite(leftPWM,90);
  digitalWrite(rightA,HIGH);
  digitalWrite(rightB,LOW);
  digitalWrite(leftA,LOW);
  digitalWrite(leftB,HIGH);
  }
  while(digitalRead(33)!=0); 
  break;
  }
  
  
  case (5):{
    do{
      forward();
    }
    while(digitalRead(33)!=1 &&digitalRead(29)!=1 && digitalRead(31)!=1 && digitalRead(35)!=1 && digitalRead(37)!=1);
 /* analogWrite(rightPWM,115); ///LEFT TURN
  analogWrite(leftPWM,80);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,HIGH);
  digitalWrite(leftA,HIGH);
  digitalWrite(leftB,LOW);
      delay(550);//*/
      right();
      delay(80);
      do{
        right();
      }
      while(digitalRead(33)!=0);
 break;}
 case (7):
 {
  
  analogWrite(rightPWM,115); ///LEFT TURN
  analogWrite(leftPWM,80);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,HIGH);
  digitalWrite(leftA,HIGH);
  digitalWrite(leftB,LOW);
  delay(80);
  do{
   analogWrite(rightPWM,115); ///LEFT TURN
  analogWrite(leftPWM,80);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,HIGH);
  digitalWrite(leftA,HIGH);
  digitalWrite(leftB,LOW);
  }
  while (digitalRead(33)!=0);                                                                                                      
  break;
 }
 default:
 forward();
  }

 }
  
//------------------------------->t-junction<-------------------------------//
else if (sensor_5==0 && sensor_4==0 && sensor_3==1 &&sensor_2==0 && sensor_1==0){
 do {
  left();
 }
 while(digitalRead(33)!=0);
 }
//================================>right turn<=============================//
else if (sensor_5==0 && sensor_4==0 && sensor_3==1 && sensor_2==1 && sensor_1==1 ){   
   do {right();
   }                             
  while ( /*sensor_3=*/digitalRead(33)!=0);
  analogWrite(rightPWM,115); ///LEFT TURN
  analogWrite(leftPWM,80);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,LOW);
  digitalWrite(leftA,LOW);
  digitalWrite(leftB,LOW);
 
}
// ===============================>left turn<=============================//
else    if (sensor_1==0 && sensor_2==0 && sensor_3==1 && sensor_4==1 && sensor_5==1){
  
 do{ 
  left();
 }
  while( ( /*sensor_3 =*/ digitalRead(33)) !=0 );
  analogWrite(rightPWM,115); ///LEFT TURN
  analogWrite(leftPWM,80);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,LOW);
  digitalWrite(leftA,LOW);
  digitalWrite(leftB,LOW);
}

//================================>dead end<==============================//
 else if (sensor_1==1 && sensor_2==1 && sensor_3==1 && sensor_4==1 && sensor_5==1){
    do{
      dead();
    }
    while(digitalRead(33)!=0 );
  }
 else{
  
  analogWrite(rightPWM,115);//stop
  analogWrite(leftPWM,80);
  digitalWrite(rightA,LOW);
  digitalWrite(rightB,LOW);
  digitalWrite(leftA,LOW);
  digitalWrite(leftB,LOW);
  
}
}





// Codes for Colour Sensor

#define lmf 4
#define lmr 5
#define rmf 6
#define rmr 7

const int s000 = 32;  
const int s111 = 33;  
const int s222 = 34;  
const int s333 = 35;  
const int out2 = 36;

const int s0 = 28;  
const int s1 = 29;  
const int s2 = 31;  
const int s3 = 30;  
const int out = 27; 
 
const int s00 = 22;  
const int s11 = 23;  
const int s22 = 25;  
const int s33 = 24;  
const int out1 = 26; 

    

int red = 0;  
int green = 0;  
int blue = 0;  

int red1 = 0;  
int green1 = 0;  
int blue1 = 0; 

int red2 = 0;  
int green2 = 0;  
int blue2 = 0; 


void setup()   
{ pinMode(lmf,OUTPUT);
pinMode(lmr,OUTPUT);
pinMode(rmf,OUTPUT);
pinMode(rmr,OUTPUT);
  Serial.begin(9600);
 
  pinMode(s00, OUTPUT);  
  pinMode(s11, OUTPUT);  
  pinMode(s22, OUTPUT);  
  pinMode(s33, OUTPUT);  
  pinMode(out1, INPUT);  
    
  digitalWrite(s00, HIGH);  
  digitalWrite(s11, HIGH);
 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
    
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  


   pinMode(s000, OUTPUT);  
  pinMode(s111, OUTPUT);  
  pinMode(s222, OUTPUT);  
  pinMode(s333, OUTPUT);  
  pinMode(out2, INPUT);  
    
  digitalWrite(s000, HIGH);  
  digitalWrite(s111, HIGH);
}  

void loop() 
{ 
 
 Color(); 
 color1();
 color11();
  
// leftsen();


 leftsensor();


 Serial.println("===================================================");
  
  rightestsensor();
 //rightsen(); 
 rightsensor();

// Serial.println("===================================================");



 /*
 //FOR RED LINE SENSING
 
 
 //LEFT SENSOR=WHITE 1   *********MIDDLE SENSOR= RED *****************  RIGHT SENSOR= WHITE 2
 
if(((green1 <= red1 || green1 >= red1 && blue1<red1 && blue1<green1 && green1<15 && blue1<15 && red1<15))&&(red < blue && red < green && red < 20)&&((green2 <= red2 || green2 >= red2) && blue2<red2 && blue2<green2 && green2<15 && blue2<15 && red2<15))
 {forward();}


//left SENSOR= red 1 **************middle SENSOR= RED **************** RIGHT SENSOR= WHITE 2
  if((red1 < blue1 && red1 < green1 && red1 < 20)&&(red < blue && red < green && red < 20)&&((green2 <= red2 || green2 >= red2) && blue2<red2 && blue2<green2 && green2<15 && blue2<15 && red2<15))
  {left();
 // delay(400);
  }


//left SENSOR= WHITE 1 **************middle SENSOR= RED **************** RIGHT SENSOR= RED 2
  if(((green1 <= red1 || green1 >= red1) && blue1<red1 && blue1<green1 && green1<15 && blue1<15 && red1<15)&&(red < blue && red < green && red < 20)&&(red2 < blue2 && red2 < green2 && red2 < 20))
  {right();
 // //delay(400);
  }

 //left SENSOR= RED 1 **************middle SENSOR= WHITE **************** RIGHT SENSOR= WHITE 2
  if((red1 < blue1 && red1 < green1 && red1 < 20)&&((green <= red || green >= red) && blue<red && blue<green && green<15 && blue<15 && red<15)&&((green2 <= red2 || green2 >= red2) && blue2<red2 && blue2<green2 && green2<15 && blue2<15 && red2<15))
  {slowleft();
 // //delay(400);
  }

 //left SENSOR= RED 1 **************middle SENSOR= WHITE **************** RIGHT SENSOR= WHITE 2
  if(((green1 <= red1 || green1 >= red1) && blue1<red1 && blue1<green1 && green1<15 && blue1<15 && red1<15)&&((green <= red || green >= red) && blue<red && blue<green && green<15 && blue<15 && red<15)&&(red2 < blue2 && red2 < green2 && red2 < 20))
  {slowright();
 // //delay(400);
  }
  */
//FOR BLUE LINE SENSING

 //LEFT SENSOR=WHITE 1   *********MIDDLE SENSOR= RED *****************  RIGHT SENSOR= WHITE 2
 
if(((green1 <= red1 || green1 >= red1 && blue1<red1 && blue1<green1 && green1<15 && blue1<15 && red1<15))&&(blue < red && blue < green)&&((green2 <= red2 || green2 >= red2) && blue2<red2 && blue2<green2 && green2<15 && blue2<15 && red2<15))
 {forward();}
/*

//left SENSOR= red 1 **************middle SENSOR= RED **************** RIGHT SENSOR= WHITE 2
  if((blue1 < red1 && blue1 < green1)&&(blue1 < red1 && blue1 < green1)&&((green2 <= red2 || green2 >= red2) && blue2<red2 && blue2<green2 && green2<15 && blue2<15 && red2<15))
  {left();
 // delay(400);
  }


//left SENSOR= WHITE 1 **************middle SENSOR= RED **************** RIGHT SENSOR= RED 2
  if(((green1 <= red1 || green1 >= red1) && blue1<red1 && blue1<green1 && green1<15 && blue1<15 && red1<15)&&(blue < red && blue < green)&&(blue2 < red2 && blue2 < green2))
  {right();
 // //delay(400);
  }
*/
 //left SENSOR= RED 1 **************middle SENSOR= WHITE **************** RIGHT SENSOR= WHITE 2
  if((blue1 < red1 && blue1 < green1)&&((green <= red || green >= red) && blue<red && blue<green && green<15 && blue<15 && red<15)&&((green2 <= red2 || green2 >= red2) && blue2<red2 && blue2<green2 && green2<15 && blue2<15 && red2<15))
  {slowleft();
 // //delay(400);
  }

 //left SENSOR= RED 1 **************middle SENSOR= WHITE **************** RIGHT SENSOR= WHITE 2
  if(((green1 <= red1 || green1 >= red1) && blue1<red1 && blue1<green1 && green1<15 && blue1<15 && red1<15)&&((green <= red || green >= red) && blue<red && blue<green && green<15 && blue<15 && red<15)&&(blue2 < red2 && blue2 < green2))
  {slowright();
 // //delay(400);
  }

  
}




//(blue < red && blue < green)
void Color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  //digitalWrite(s2,LOW);
  
}



void color1()  
{    
  digitalWrite(s22, LOW);  
  digitalWrite(s33, LOW);  
  //count OUT, pRed, RED  
  red1 = pulseIn(out1, digitalRead(out1) == HIGH ? LOW : HIGH);  
  digitalWrite(s33, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue1 = pulseIn(out1, digitalRead(out1) == HIGH ? LOW : HIGH);  
  digitalWrite(s22, HIGH);  
  //count OUT, pGreen, GREEN  
  green1 = pulseIn(out1, digitalRead(out1) == HIGH ? LOW : HIGH);
  //digitalWrite(s2,LOW);
  
}


void color11()  
{    
  digitalWrite(s222, LOW);  
  digitalWrite(s333, LOW);  
  //count OUT, pRed, RED  
  red2 = pulseIn(out2, digitalRead(out2) == HIGH ? LOW : HIGH);  
  digitalWrite(s333, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue2 = pulseIn(out2, digitalRead(out2) == HIGH ? LOW : HIGH);  
  digitalWrite(s222, HIGH);  
  //count OUT, pGreen, GREEN  
  green2 = pulseIn(out2, digitalRead(out2) == HIGH ? LOW : HIGH);
  //digitalWrite(s2,LOW);
  
}



void rightsensor()
{
  if (red<green<blue&&red<13&&green<20&&blue<23)

{Serial.println(" - (yellow1 Color)");}
 //RED COLOR
  else if (red < blue && red < green && red < 20)
  {
   Serial.println(" - (Red1 Color)");  
//   digitalWrite(redLed, HIGH); // Turn RED LED ON 
 //  digitalWrite(greenLed, LOW);  
  // digitalWrite(blueLed, LOW);  
  } 
   

  //WHITE color
 else if ((green <= red || green >= red) && blue<red && blue<green && green<15 && blue<15 && red<15)  
  {
   Serial.println(" -   (WHITE1 Color)");  
//   digitalWrite(redLed, LOW);  
   //digitalWrite(greenLed, LOW); // Turn GREEN LED ON 
 //  digitalWrite(blueLed, LOW);  
  }  

  //BLUE COLOR
  else if (blue < red && blue < green)   
  { 
   Serial.println(" -   (Blue1 Color)");  
  // digitalWrite(redLed, LOW);  
  // digitalWrite(greenLed, LOW);  
  // digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
  } 


   //GREEN COLOR
  else if (green < red && green <= blue&&red>35)  
  {  
   Serial.println(" -   (Green1 Color)");  
   //digitalWrite(redLed, LOW);  
   //digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   //digitalWrite(blueLed, LOW);  
  } 
   else{
  //Serial.println();  
}}


void leftsensor()
{
  if (red1<green1<blue1&&red1<13&&green1<20&&blue1<23)

{Serial.println(" - (yellow2 Color)");}
    
    else if (red1 < blue1 && red1 < green1 && red1 < 20)
  {
   Serial.println("-  (Red2 Color)");  
//   digitalWrite(redLed, HIGH); // Turn RED LED ON 
 //  digitalWrite(greenLed, LOW);  
  // digitalWrite(blueLed, LOW);  
  }  

  //WHITE color
 else if ((green1 <= red1 || green1 >= red1) && blue1<red1 && blue1<green1 && green1<15 && blue1<15 && red1<15)  
  {
   Serial.println("-   WHITE2 Color)");  
//   digitalWrite(redLed, LOW);  
   //digitalWrite(greenLed, LOW); // Turn GREEN LED ON 
 //  digitalWrite(blueLed, LOW);  
  }  

  //BLUE COLOR
  else if (blue1 < red1 && blue1 < green1)   
  { 
   Serial.println(" -   (Blue2 Color)");  
  // digitalWrite(redLed, LOW);  
  // digitalWrite(greenLed, LOW);  
  // digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
  } 


   //GREEN COLOR
  else if (green1 < red1 && green1 < blue1)  
  {  
   Serial.println(" -   (Green2 Color)");  
   //digitalWrite(redLed, LOW);  
   //digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   //digitalWrite(blueLed, LOW);  
  } 
   else{
  //Serial.println();  
}
 
  }


void rightestsensor()
{
  if (red2<green2<blue2&&red2<13&&green2<20&&blue2<23)
{Serial.println(" - (yellow3 Color)");}
 //RED COLOR
  else if (red2 < blue2 && red2 < green2 && red2 < 20)
  {
   Serial.println(" - (Red3 Color)");  
//   digitalWrite(redLed, HIGH); // Turn RED LED ON 
 //  digitalWrite(greenLed, LOW);  
  // digitalWrite(blueLed, LOW);  
  } 
   

  //WHITE color
 else if ((green2 <= red2 || green2 >= red2) && blue2<red2 && blue2<green2 && green2<15 && blue2<15 && red2<15)  
  {
   Serial.println(" -   (WHITE3 Color)");  
//   digitalWrite(redLed, LOW);  
   //digitalWrite(greenLed, LOW); // Turn GREEN LED ON 
 //  digitalWrite(blueLed, LOW);  
  }  

  //BLUE COLOR
  else if (blue2 < red2 && blue2 < green2)   
  { 
   Serial.println(" -   (Blue3 Color)");  
  // digitalWrite(redLed, LOW);  
  // digitalWrite(greenLed, LOW);  
  // digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
  } 


   //GREEN COLOR
  else if (green2 < red2 && green2 < blue2)  
  {  
   Serial.println(" -   (Green3 Color)");  
   //digitalWrite(redLed, LOW);  
   //digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   //digitalWrite(blueLed, LOW);  
  } 
   else{
  //Serial.println();  
}}


void forward()
  {
    analogWrite(lmf,180);
    analogWrite(lmr,0); 
    analogWrite(rmf,180);
    analogWrite(rmr,0); 
    }
    
void right()
  {
    analogWrite(lmf,180);
    analogWrite(lmr,0); 
    analogWrite(rmf,0);
    analogWrite(rmr,180); 
    }
    void slowright()
  {
    analogWrite(lmf,100);
    analogWrite(lmr,0); 
    analogWrite(rmf,0);
    analogWrite(rmr,100); 
    }

void left() 
   {
    analogWrite(lmf,0);
    analogWrite(lmr,180); 
    analogWrite(rmf,180);
    analogWrite(rmr,0); 
    }
  void slowleft() 
   {
    analogWrite(lmf,0);
    analogWrite(lmr,100); 
    analogWrite(rmf,100);
    analogWrite(rmr,0); 
    }
