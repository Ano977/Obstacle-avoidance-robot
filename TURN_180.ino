void Turn_180()
{Forward
delay(1000);
   OCR2A=100; //pin10
 OCR2B=100; //pin9  
  
digitalWrite(8,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);
digitalWrite(7,LOW);
delay(1000);
  }
