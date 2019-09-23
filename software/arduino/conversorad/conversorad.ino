float leitura;
 int anaUmAnt;
 int anaDoisAnt;

 int reservaum = 0;
int reservadois = 0;
int reservatres = 0;

 int reservaumB = 0;
int reservadoisB = 0;
int reservatresB = 0;

int analiseUm = 1;
int analiseDois = 1;
int valorenvioUm = 500;
int valorenvioDois = 500;

int enviaA = -1;
int enviaB = -1;

 void setup() 
{ 
  Serial.begin(9600);
  Serial.println("Leitura do potenciometro");
  Serial.println("Valor        Volts");
}
 
void loop() {
  int anaUm = analogRead(A0);
  int anaDois = analogRead(A1);

  if(anaDois != anaDoisAnt || anaUm != anaDoisAnt){
  
  if(anaUm != anaUmAnt){
    if(analiseUm == 1){
      reservaum = anaUm;
    }else if(analiseUm == 2){
      
      reservadois = anaUm;
    }else{
      reservatres = anaUm;
      analiseUm = 1;

      valorenvioUm = reservaum + reservadois + reservatres;
      valorenvioUm = valorenvioUm/3;
      
      
    }
    
    analiseUm++;
  
  }

  if(anaDois != anaDoisAnt){
    if(analiseDois == 1){
      reservaumB = anaDois;
    }else if(analiseDois == 2){
      reservadoisB = anaDois;
    }else{
      reservatresB = anaDois;
      analiseDois = 1;

      valorenvioDois = reservaumB + reservadoisB + reservatresB;
      valorenvioDois = valorenvioDois/3;
      
    }


    
    
    analiseDois++;
  
  }

  if(valorenvioUm > 650){
        enviaA = 2;
      }else if(valorenvioUm < 473){
        enviaA = 0;
      }else{
        enviaA = 1;
      }

      if(valorenvioDois > 650){
        enviaB = 2;
      }else if(valorenvioDois < 450){
        enviaB = 0;
      }else{
        enviaB = 1;
      }
    //Serial.print(valorenvioUm);
    Serial.print("k");
    delay(1);
    Serial.print(enviaA);
    delay(1);
    Serial.print(enviaB);
    delay(1);
    Serial.print("h");
    delay(1);
    Serial.print("\n");
    
  
  }


  delay(100);
    
}
