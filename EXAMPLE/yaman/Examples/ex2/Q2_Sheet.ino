int pinLED [4] ;
int no = 4 ; 


void setup() {
  for (int j = 0 ; j < 4 ; j++ ) 
{
  pinLED [j] = no ;
  no ++ ;   
}
pinMode ( pinLED[0] , OUTPUT ) ; 
pinMode ( pinLED[1] , OUTPUT ) ; 
pinMode ( pinLED[2] , OUTPUT ) ; 
pinMode ( pinLED[3] , OUTPUT ) ; 

digitalWrite ( pinLED [0] , 1 ) ;
  delay (1000) ;  
  digitalWrite ( pinLED [0] , 0 ) ;
  delay (1000) ;

}

void loop() {


for ( int i = 1 ; i < 4 ; i ++ ) 
 { digitalWrite ( pinLED [i] , 1 ) ;
  delay (1000) ;  
  digitalWrite ( pinLED [i] , 0 ) ;
  delay (1000) ; 
 }

for ( int i = 2 ; i >= 0 ; i -- ) 
 { digitalWrite ( pinLED [i] , 1 ) ;
  delay (1000) ;  
  digitalWrite ( pinLED [i] , 0 ) ;
  delay (1000) ; 
 }

  
}
