int dataPin  = A0;  
int oePin    = A1;
int latchPin = A2;  
int clockPin = A3;  
int weRomPin = 2;   
int oeRomPin = 3;   
int RomAddr  = 0;
int RomData  = 0;
int RomDataPins[8]={4,5,6,7,8,9,10,11}; // ROM D7-D0



//A12-A8: MDLDL 
int DisplayDigitPosition = 0; 
int DisplayControlAddr[8] = {10,2,8,0,26,18,24,16};
int DisplayDigitsArray[16] = {
//E D DP C G B F A
0b11010111,
0b00010100,
0b11001101,
0b01011101,
0b00011110,
0b01011011,
0b11011011,
0b00010101,
0b11011111,
0b01011111,
0b10011111,
0b11011010,
0b11000011,
0b11011100,
0b11001011,
0b10001011};



void DisplayRegisterProgram(){
 
    for(int i=0;i<256;i++){
      int nr=i;
      int n=3;
      do{
        WriteRomData(DisplayDigitsArray[nr%10], DisplayControlAddr[n]*256 + i);
        n--;
        nr/=10;
      }while(nr!=0);
      while(n>=0){
        WriteRomData(0b00000000, DisplayControlAddr[n]*256 + i);
        n--;
    }}




    

      for(int i=0;i<128;i++){
        int nr=i;
        int n=7;
        do{
          WriteRomData(DisplayDigitsArray[nr%10], DisplayControlAddr[n]*256 + i);
          n--;
          nr/=10;
        }while(nr!=0);
        while(n>=4){
          WriteRomData(0b00000000, DisplayControlAddr[n]*256 + i);
          n--;
        }
      }

      WriteRomData(DisplayDigitsArray[0], DisplayControlAddr[7]*256 + 128);
      WriteRomData(DisplayDigitsArray[0], DisplayControlAddr[6]*256 + 128);
      WriteRomData(DisplayDigitsArray[0], DisplayControlAddr[5]*256 + 128);
      WriteRomData(0b00001000, DisplayControlAddr[4]*256 + 128);

    


      for(int i=256;i>128;i--){
        int nr=256-i;
        int n=7;
        do{
          WriteRomData(DisplayDigitsArray[nr%10], DisplayControlAddr[n]*256 + i);
          n--;
          nr/=10;
        }while(nr!=0);
        while(n>=5){
          WriteRomData(0b00000000, DisplayControlAddr[n]*256 + i);//DisplayDigitsArray[0]
          n--;
        }

          WriteRomData(0b00001000, DisplayControlAddr[4]*256 + i);//0b00001000   minus
}








}



int BaseConverter(int Base1, int Base2, int nr1){
  int nr2=0, p=1;
  if(Base1<Base2)// from Base1 var value to Base10
    while(nr1){
      nr2=nr2 + p *(nr1 % 10);
      nr1/=10;
      p*=Base1;}
  return nr2;}
void SetRomAddr(int nr){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nr/256); //Shift_Q0 == ROM_A0
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nr%256); //Shift_Q0 == ROM_A0
  digitalWrite(latchPin, HIGH);}

int ReadRomData(int addr){
  int nr=0;
  digitalWrite(oeRomPin, LOW);
  SetRomAddr(addr);
  for (int i=0;i<8;i++) pinMode(RomDataPins[i], INPUT);   
  delay(50);
  Serial.print("Read(");
  Serial.print(addr);
  Serial.print("): ");
  for (int i=0;i<8;i++){
    if(digitalRead(RomDataPins[i])){
      nr= 2*nr + 1;
      Serial.print(1);
    }
    else{
      nr= 2*nr + 0;
      Serial.print(0);
    }
  }
  Serial.print("-");
  Serial.println(nr);
  digitalWrite(oeRomPin, HIGH);
  delay(30);//delay
  return nr;}


void WriteRomData(int nr, int addr){
  int p = 128, nrc = nr;
  SetRomAddr(addr);
  for (int i=0;i<8;i++) pinMode(RomDataPins[i], OUTPUT);  
  Serial.print("Write(");
  Serial.print(addr);
  Serial.print("): ");
  for (int i=0;i<8;i++){
      if(nr>=p){
        Serial.print(1);
        digitalWrite(RomDataPins[i], 1);
        nr-=p;
      }
      else{
        Serial.print(0);
        digitalWrite(RomDataPins[i], 0);}
    p/=2;
  }
  Serial.print("-");
  Serial.println(nrc);
  digitalWrite(weRomPin, LOW);
  delay(80);
  digitalWrite(weRomPin, HIGH);
  delay(20);//delay
  }



















void setup() {
  pinMode(latchPin,  OUTPUT);
  pinMode(clockPin,  OUTPUT);
  pinMode(dataPin,   OUTPUT);
  pinMode(oePin,     OUTPUT);
  pinMode(weRomPin,  OUTPUT);
  pinMode(oeRomPin,  OUTPUT);

  digitalWrite(weRomPin, HIGH);
  digitalWrite(oeRomPin, HIGH);
  digitalWrite(latchPin, LOW);
  digitalWrite(oePin,    LOW);
  Serial.begin(9600);


  DisplayRegisterProgram();

}

void loop() 
{


}

























