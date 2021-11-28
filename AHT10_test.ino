#include <Wire.h>                                  // Стандартная библиотека шины I2C
#include <AHT10.h>                                 // Библиотека датчика

AHT10Class AHT10;                                  // Создаем объект AHT10

void setup() {
   Serial.begin(9600);                             // Инициализируем монитор порта на скорости 9600
   Wire.begin();                                   // Инициализируем шину I2C
  if(AHT10.begin(0x38))                            // Инициализируем датчик с адресом 0x38
    Serial.println("AHT10 подключен.");            // Если удачно печатаем "AHT10 подключен."
  else{
    Serial.println("AHT10 не подключен.");         // Если не удачно печатаем "AHT10 не подключен."
    while(1);                                      // Заканчиваем выполнение
  }
  Serial.println();                                // Печатаем пустую строку
  delay(3000);                                     // Пауза в 8 секунды
}

void loop() {
  float T = AHT10.GetTemperature();                // Считываем показание температуры
  float H = AHT10.GetHumidity();                   // Считываем показание влажности
  float D = AHT10.GetDewPoint();                   // Считываем значение точки росы для данной влажности
  Serial.print("Температура: ");                   // Печатаем "Температура: "
  Serial.print(T);                                 // Печатаем показание температуры
  Serial.println(" *C");                           // Печатаем " *C"

  Serial.print("Влажность: ");                     // Печатаем "Влажность: "
  Serial.print(H);                                 // Печатаем показание влажности
  Serial.println(" %");                            // Печатаем " %"

  Serial.print("Точка росы при этой влажности: "); // Печатаем "Точка росы при этой влажности: "
  Serial.print(D);
  Serial.println("*C");
  
  Serial.println();
  delay(3000);
}
