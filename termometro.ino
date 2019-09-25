#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 13 //
#define DHTTYPE DHT11 //Definir el sensor como un DHT22. Si se usa un DHT11, cambiarlo por #define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Variables para almacenar las lecturas del sensor DHT22
float temperatura;
float humedad;

//Variables asociadas a la fotocelda (sensor de luz)
int sensor_luz = A0;
int lectura_luz;
int valor_luz;

void setup() {

  pinMode(sensor_luz, INPUT);
  Serial.begin(9600);
}

void loop() {

  temperatura = dht.readTemperature();  //Lee y almacena la temperatura del sensor DHT22
  humedad = dht.readHumidity();         //Lee y almacena la humedad del sensor DHT22
  lectura_luz = analogRead(A0);        //Lee y almacena de los valores que puede tomar la fotocelda
  valor_luz = map(lectura_luz, 0, 1023, 0, 100);  //Mapeo de los valores de la fotocelda en un rango de 0 a 100

  Serial.print(temperatura);       //Muestra la temperatura en el puerto serie (Bluetooth)
  Serial.print(" °C");
  Serial.print("|");
  Serial.print(humedad);          //Muestra la humedad relativa en el puerto serie (Bluetooth)
  Serial.print(" %");
  Serial.print("|");
  Serial.print(valor_luz);       //Muestra los niveles de luminosidad en el puerto serie (Bluetooth)
  Serial.print(" %");
  delay(1000);                   //El DHT22 manda datos cada dos segundos. Si se usa un DHT11, cambiarlo por delay(1000)

}
