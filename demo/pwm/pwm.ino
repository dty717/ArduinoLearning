void setup()
{
  pinMode(12, OUTPUT);
}
int n=1000;
double p=0.01;
void loop()
{
    
    // n% pHz
  digitalWrite(12, HIGH);
  delayMicroseconds(n*p); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(12, LOW);
  delayMicroseconds(n*(1-p));
}