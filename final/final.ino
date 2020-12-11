#define LED_R 5
#define LED_G 6
#define LED_B 9
#define SENS_L A0
#define SENS_R A1
float val_L = 0.0;
float val_R = 0.0;
float old_val_L = 0.0;

long i = 0;
int n = 100;
int cross[100];

void setup() {
  // put your setup code here, to run once:
  //set up the adc pins for the sensor
  //set up the digital out pins for the LEDs
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(SENS_L, INPUT_PULLUP);
  Serial.begin(9600);
  //
}


void loop() {
  val_L = analogRead(SENS_L);
  val_R = analogRead(SENS_R);

  // count the number of crossovers in the last 30 sec
  if ((val_L - old_val_L) > 400) {
    cross[i] = 1;
  } else {
    cross[i] = 0;
  }
  i++;
  if (i == n){
    i = 0;
  }
    

  int sum =0;
  for (int j = 0; j < n; j++)
    sum += cross[j];  
  
  
  Serial.println(sum);
  
  old_val_L = val_L;

  if (sum > 8){
    RGB_color(255, 0, 0);
  } else {
    RGB_color(0, 255, 255);
  }
  
  Serial.println(val_L);
//  Serial.print(",");
//  Serial.println(val_R);
  delay(100);
  
//  RGB_color(255, 0, 0); // Red
//  delay(1000);
//  RGB_color(0, 255, 0); // Green
//  delay(1000);
//  RGB_color(0, 0, 255); // Blue
//  delay(1000);
//  RGB_color(255, 255, 125); // Raspberry
//  delay(1000);
//  RGB_color(0, 255, 255); // Cyan
//  delay(1000);
//  RGB_color(255, 0, 255); // Magenta
//  delay(1000);
//  RGB_color(255, 255, 0); // Yellow
//  delay(1000);
//  RGB_color(255, 255, 255); // White
//  delay(1000);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(LED_R, red_light_value);
  analogWrite(LED_G, green_light_value);
  analogWrite(LED_B, blue_light_value);
}
