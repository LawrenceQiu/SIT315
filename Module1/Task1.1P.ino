// Define pin numbers
const int tempSensorPin = A0;  // TMP36 output connected to analog pin A0
const int ledPin = 5;          // LED connected to digital pin 5

// Define the temperature threshold in Celsius
const float temperatureThreshold = 25.0;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Initial status message
  Serial.println("Temperature Sensor System Initialized.");
}

void loop() {
  // Read the value from the temperature sensor
  int sensorValue = analogRead(tempSensorPin);
  
  // Convert the sensor reading to a temperature in Celsius
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Print the temperature value to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  // Check if the temperature exceeds the threshold
  if (temperatureC > temperatureThreshold) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Temperature exceeded threshold! LED turned ON.");
  } 
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("Temperature below threshold. LED turned OFF.");
  }
  
  // Small delay to avoid spamming the serial monitor
  delay(1000);
}
