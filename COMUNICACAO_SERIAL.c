unsigned short i; //Variável para armazenamento do valor recebido pela serial.
void main ()
{
   trisd=0;
   portd=0;

usart_init(9600);  //Inicializa USART (8 bits, baund rate 9600,sem paridade...)
   while (1)
   {
      if(usart_data_ready())    //Se algum dado for recebido
      {
         i=usart_read();        //Lê o dado recebido
         usart_write(i);        //envia o dado pela serial novamente
         if (i=='a')
            portd.f0=1;         //Se o caracter for "a", acende o LED 1
         if (i=='b')
            portd.f0=0;         //Se o caracter for "b", apaga o LED 1
      }
   }
}