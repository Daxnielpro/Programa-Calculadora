// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'
// This demo code returns raw readings, public domain

#include <stdint.h>
#include "TouchScreen.h"
#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h>

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin
#define LCD_RESET A4


#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BLAUCLAR 0x07B6
#define VERDCLAR 0x07A8
#define	TARONGACLAR 0xF750
#define MAGENTACLAR 0xF71F

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint p;
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

int nums[10][2];
char carac[10][2];
int ocupats[5] = {0};
int numPitjat;
//nums[0] = '3'; ocupats ++;



/*
  * esriure el número a la posició 1.
  * acumular el número en un array del número máx
  * el següent s'afegeix a l'array. S'escru l'array
*/
void setup() {
  Serial.begin(9600);
  tft.begin(tft.readID());


  //dibuixa pantalla
  pantalla1();
  delay(500);
// forma de dibuix en pantalla
}
bool tornarselexponencial(void){
  while(true){
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        selexponencial();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    } 
  }
}
bool seexponencial(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        exponencial();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        exponencialfraccio();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        grafic1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    }
  }
}
void selexponencial(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.setRotation(45);
  tft.setCursor(20, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("f(x)=2");
  tft.setCursor(127, 119); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("x");
  tft.setCursor(162, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("f(x)=0.5");
  tft.setCursor(305, 119); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("x");
  tft.setCursor(85, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina de les dues?");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  seexponencial();
}
void exponencial(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(85, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio exponencial");
  delay(500);
  tft.setRotation(0); 
  tft.drawCircle(200, 130, 100, GREEN);
  tft.fillRect(102, 0, 99, 118, BLACK);
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.setRotation(45);
  tft.setCursor(85, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio exponencial");
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(95, 10);
  tft.setRotation(0);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 150, GREEN);
  tornarselexponencial();
}
void exponencialfraccio(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(85, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio exponencial");
  delay(500);
  tft.setRotation(0); 
  tft.drawCircle(200, 130, 100, GREEN);
  tft.fillRect(102, 122, 99, 120, BLACK);
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.setRotation(45);
  tft.setCursor(85, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio exponencial");
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(95, 10);
  tft.setRotation(0);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(100, 120, 2, 200, GREEN);
  tornarselexponencial();
}
void logaritme(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(95, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio logaritme");
  delay(500);
  tft.setRotation(0); 
  tft.drawCircle(0, 271, 180, GREEN);
  tft.fillRect(160, 270, 40, 60, BLACK);
  tft.fillRect(181, 270, 1, 60, GREEN);
  tornargrafic();
}
bool retornseltrigonometrica(void){
  while(true){
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        seltrigonometrica();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    } 
  }
}
bool setrigonometrica(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 341 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        sinusgrafic();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 341 && p.x <= 682 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        cosinusgrafic();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 682 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        tangentgrafic();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        grafic1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    }
  }
}
void seltrigonometrica(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 106, 200, 2, WHITE);
  tft.fillRect(0, 212, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.setRotation(45);
  tft.setCursor(5, 100); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(20, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("sin(x)");

  tft.setCursor(85, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina de les tres?");
  tft.setCursor(110, 100); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(125, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("cos(x)");

  tft.setCursor(216, 100); // 65 40 110
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(230, 125); // 65 40 110
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("tan(x)");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  setrigonometrica();
}
void tangentgrafic(){
  tft.fillScreen(BLACK);

  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 

  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);

  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(105, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio tangent");
  delay(500);
  tft.setRotation(0);
  tft.drawCircle(120, 10, 30, GREEN);  
  tft.fillRect(120, 0, 31, 60, BLACK);
  tft.fillRect(90, 0, 9, 30, BLACK);
  tft.drawCircle(80, 53, 30, GREEN);
  tft.fillRect(100, 39, 11, 40, BLACK);
  tft.fillRect(50, 23, 30, 60, BLACK);
  tft.fillRect(70, 75, 35, 30, BLACK);

  tft.drawCircle(120, 70, 30, GREEN);  
  tft.fillRect(120, 60, 31, 60, BLACK);
  tft.fillRect(90, 41, 60, 50, BLACK);
  tft.drawCircle(80, 113, 30, GREEN);
  tft.fillRect(100, 99, 11, 40, BLACK);
  tft.fillRect(50, 83, 30, 60, BLACK);
  tft.fillRect(70, 135, 35, 30, BLACK);

  tft.drawCircle(120, 130, 30, GREEN);  
  tft.fillRect(120, 120, 31, 60, BLACK);
  tft.fillRect(90, 101, 60, 50, BLACK);
  tft.drawCircle(80, 173, 30, GREEN);
  tft.fillRect(100, 159, 11, 40, BLACK);
  tft.fillRect(50, 143, 30, 60, BLACK);
  tft.fillRect(70, 195, 35, 30, BLACK);

  tft.drawCircle(120, 190, 30, GREEN);  
  tft.fillRect(120, 180, 31, 60, BLACK);
  tft.fillRect(90, 161, 60, 50, BLACK);
  tft.drawCircle(80, 233, 30, GREEN);
  tft.fillRect(100, 219, 11, 40, BLACK);
  tft.fillRect(50, 203, 30, 60, BLACK);
  tft.fillRect(70, 255, 35, 30, BLACK);

  tft.drawCircle(120, 250, 30, GREEN);  
  tft.fillRect(120, 240, 31, 60, BLACK);
  tft.fillRect(90, 221, 60, 50, BLACK);
  tft.drawCircle(80, 293, 30, GREEN);
  tft.fillRect(100, 279, 11, 40, BLACK);
  tft.fillRect(50, 263, 30, 60, BLACK);
  tft.fillRect(70, 315, 35, 30, BLACK);

  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);

  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(0, 23, 80, 1, GREEN);
  tft.fillRect(120, 40, 80, 1, GREEN);

  tft.fillRect(0, 83, 80, 1, GREEN);
  tft.fillRect(120, 100, 80, 1, GREEN);

  tft.fillRect(0, 143, 80, 1, GREEN);
  tft.fillRect(120, 160, 80, 1, GREEN);

  tft.fillRect(0, 203, 80, 1, GREEN);
  tft.fillRect(120, 220, 80, 1, GREEN);

  tft.fillRect(0, 263, 80, 1, GREEN);
  tft.fillRect(120, 280, 80, 1, GREEN);
  retornseltrigonometrica();
}
void cosinusgrafic(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(105, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio cosinus");
  delay(500);
  tft.setRotation(0);
  tft.drawCircle(100, 0, 30, GREEN);  
  tft.drawCircle(100, 60, 30, GREEN);
  tft.drawCircle(100, 120, 30, GREEN);
  tft.drawCircle(100, 180, 30, GREEN);
  tft.drawCircle(100, 240, 30, GREEN);
  tft.drawCircle(100, 300, 30, GREEN);
  tft.drawCircle(100, 360, 30, GREEN);
  tft.fillRect(100, -30, 31, 60, BLACK);
  tft.fillRect(70, 30, 30, 60, BLACK); 
  tft.fillRect(100, 90, 31, 60, BLACK);
  tft.fillRect(70, 150, 30, 60, BLACK); 
  tft.fillRect(100, 210, 31, 60, BLACK);  
  tft.fillRect(70, 270, 30, 60, BLACK); 
  tft.fillRect(100, 330, 30, 60, BLACK); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  retornseltrigonometrica();
}
void sinusgrafic(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(120, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio sinus");
  delay(500);
  tft.setRotation(0);  
  tft.drawCircle(100, 30, 30, GREEN);
  tft.drawCircle(100, 90, 30, GREEN);
  tft.drawCircle(100, 150, 30, GREEN);
  tft.drawCircle(100, 210, 30, GREEN);
  tft.drawCircle(100, 270, 30, GREEN);
  tft.drawCircle(100, 330, 30, GREEN);
  tft.fillRect(70, 0, 30, 60, BLACK); 
  tft.fillRect(100, 60, 30, 60, BLACK);
  tft.fillRect(70, 120, 30, 60, BLACK); 
  tft.fillRect(100, 180, 31, 60, BLACK);  
  tft.fillRect(70, 240, 30, 60, BLACK); 
  tft.fillRect(100, 300, 30, 60, BLACK); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  retornseltrigonometrica();
}
void racional(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(100, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio racional");
  delay(500);
  tft.setRotation(0);  
  tft.drawCircle(70, 120, 30, GREEN);
  tft.drawCircle(130, 180, 30, GREEN);
  tft.fillRect(70, 90, 30, 30, BLACK); 
  tft.fillRect(40, 90, 30, 60, BLACK);
  tft.fillRect(100, 180, 70, 40, BLACK); 
  tft.fillRect(130, 150, 40, 40, BLACK);
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(99, 0, 2, 125, GREEN);
  tft.fillRect(0, 150, 70, 2, GREEN);
  tft.fillRect(101, 170, 2, 150, GREEN);
  tft.fillRect(130, 150, 70, 2, GREEN);
  tornargrafic();
}
bool retornselradical(void){
  while(true){
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        selradical();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    } 
  }
}
bool seradical(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 341 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        radicalpos();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 341 && p.x <= 682 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        radicalneg();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 682 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        radicalposneg();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        grafic1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    }
  }
}
void selradical(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 106, 200, 2, WHITE);
  tft.fillRect(0, 212, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.setRotation(45);
  tft.setCursor(5, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(70, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("V");
  tft.setCursor(80, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(84, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("x");
  tft.setCursor(85, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina de les tres?");
  tft.setCursor(110, 100); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(130, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-V");
  tft.setCursor(150, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(160, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(170, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(180, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(154, 127); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("x+1");
  tft.setCursor(216, 100); // 65 40 110
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(236, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("V");
  tft.setCursor(246, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(256, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(266, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(276, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(286, 118); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(250, 127); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-x+5");
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  seradical();
}
void radicalposneg(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(100, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio radical");
  delay(500);
  tft.setRotation(0);  
  tft.drawCircle(100, 135, 30, GREEN);
  tft.fillRect(100, 105, 30, 30, BLACK); 
  tft.fillRect(70, 90, 30, 90, BLACK);
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(130, 0, 2, 130, GREEN);
  retornselradical();
}
void radicalneg(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(100, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio radical");
  delay(500);
  tft.setRotation(0);  
  tft.drawCircle(100, 90, 30, GREEN);
  tft.fillRect(100, 60, 30, 60, BLACK); 
  tft.fillRect(70, 90, 30, 30, BLACK);
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(70, 80, 2, 240, GREEN);
  retornselradical();
}
void radicalpos(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(100, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio radical");
  delay(500);
  tft.setRotation(0);  
  tft.drawCircle(100, 120, 30, GREEN);
  tft.fillRect(70, 90, 30, 60, BLACK); 
  tft.fillRect(100, 120, 30, 30, BLACK); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(130, 120,2, 200, GREEN);
  retornselradical();
}
bool continuados(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        continuapos();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        continuaneg();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        grafic1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    }
  }
}
bool retornselcontinua(void){
  while(true){
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        selcontinua();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    } 
  }
}
void selcontinua(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.setRotation(45);
  tft.setCursor(10, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=x");
  tft.setCursor(81, 122); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(88, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("+2x+1");
  tft.setCursor(85, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina de les dues?");
  tft.setCursor(165, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=-x");
  tft.setCursor(250, 122); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(258, 125); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("+2x+1");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  continuados();
}
void continuaneg(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(100, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio continua");
  delay(500);
  tft.setRotation(2);  
  tft.drawCircle(85, 140, 40, GREEN);
  tft.fillRect(70, 100, 60, 100, BLACK); 
  tft.setRotation(4);
  tft.setCursor(160, 200); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(140, 220); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(120, 240); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(100, 260); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(80, 280); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(60, 300); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(40, 320); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");

  tft.setRotation(3);
  tft.setCursor(300, 20); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(280, 40); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(260, 60); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(240, 80); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(220, 100); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(200, 120); // 65 240 160
  tft.setRotation(3);
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(180, 140); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(170, 150); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  retornselcontinua();
}
void continuapos(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(100, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio continua");
  delay(500);
  tft.setRotation(0);  
  tft.drawCircle(45, 180, 40, GREEN);
  tft.fillRect(30, 140, 60, 100, BLACK); 
  tft.setRotation(2);
  tft.setCursor(200, 160); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(180, 180); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(160, 200); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(140, 220); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(120, 240); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(100, 260); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(80, 280); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(60, 300); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");

  tft.setRotation(45);
  tft.setCursor(360, 40); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(340, 60); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(320, 80); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(300, 100); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(280, 120); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(260, 140); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(240, 160); // 65 40
  tft.setRotation(45);
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(220, 180); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(210, 190); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  retornselcontinua();
}
bool linialdos(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        linialpos();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        tft.setRotation(0);
        linialneg();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        grafic1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    }
  }
}
void sellinial(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.setCursor(10, 125); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("f(x)=x+1");
  tft.setCursor(85, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina de les dues?");
  tft.setCursor(170, 125);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("f(x)=x-1");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  linialdos();
}
bool retornsellinial(void){
  while(true){
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        sellinial();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    } 
  }
}
void linialneg(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(110, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio linial");
  delay(500);
  tft.setRotation(2);
  tft.setCursor(220, 40); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(200, 60); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(180, 80); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(160, 100); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(140, 120); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(120, 140); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(100, 160); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(80, 180); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(60, 200); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(40, 220); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  retornsellinial();
}
void linialpos(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(110, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio linial");
  delay(500);
  tft.setCursor(220, 40); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(200, 60); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(180, 80); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(160, 100); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(140, 120); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(120, 140); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(100, 160); // 65 40
  tft.setRotation(45);
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(80, 180); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(60, 200); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  tft.setCursor(40, 220); // 65 40
  tft.setTextColor(GREEN);  tft.setTextSize(5);
  tft.println("/");
  retornsellinial();
}
bool tornargrafic(void){
  while(true){
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        grafic1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    } 
  }
}
void constant(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(201, 64, 39, 320, MAGENTACLAR); 
  tft.fillRect(0, 90, 200, 2, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(90, 30, 20, 2, WHITE);
  tft.fillRect(90, 60, 20, 2, WHITE);
  tft.fillRect(90, 90, 20, 2, WHITE);
  tft.fillRect(90, 120, 20, 2, WHITE);
  tft.fillRect(90, 150, 20, 2, WHITE);
  tft.fillRect(90, 180, 20, 2, WHITE);
  tft.fillRect(90, 210, 20, 2, WHITE);
  tft.fillRect(90, 240, 20, 2, WHITE);
  tft.fillRect(90, 270, 20, 2, WHITE);
  tft.fillRect(90, 300, 20, 2, WHITE);
  tft.fillRect(70, 80, 2, 20, WHITE);
  tft.fillRect(40, 80, 2, 20, WHITE);
  tft.fillRect(10, 80, 2, 20, WHITE);
  tft.fillRect(130, 80, 2, 20, WHITE);
  tft.fillRect(160, 80, 2, 20, WHITE);
  tft.fillRect(190, 80, 2, 20, WHITE);
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(100, 10);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Funcio constant");
  delay(500);
  tft.setRotation(0);
  tft.fillRect(145, 0, 2, 320, GREEN);
  tornargrafic();
}
bool numgrafic(void){
  while(true){
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        pantalla1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 384) {
        Serial.println("Constant");
        tft.setRotation(0);
        constant();
        break;
      }
      //linial
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 384) {
        Serial.println("Linial");
        tft.setRotation(0);
        sellinial();
        break;
      }
      //Cuadràtica
      if (p.x >= 0 && p.x <= 512 && p.y >= 384 && p.y <= 598) {
        Serial.println("Cuadràtica");
        tft.setRotation(0);
        selcontinua();
        break;
      }
      //Polinomial
      if (p.x >= 512 && p.x <= 1024 && p.y >= 384 && p.y <= 598) {
        Serial.println("radical");
        tft.setRotation(0);
        selradical();
      }
      //Racional
      if (p.x >= 0 && p.x <= 512 && p.y >= 598 && p.y <= 811) {
        Serial.println("Racional");
        tft.setRotation(0);
        racional();
      }
      //Trigonometrica
      if (p.x >= 512 && p.x <= 1024 && p.y >= 598 && p.y <= 811) {
        Serial.println("Trigonometrica");
        tft.setRotation(0);
        seltrigonometrica();
      }
      //Logaritmica
      if (p.x >= 0 && p.x <= 512 && p.y >= 811 && p.y <= 1024) {
        Serial.println("Logarítmica");
        tft.setRotation(0);
        logaritme();
      }
      //Exponencial
      if (p.x >= 512 && p.x <= 1024 && p.y >= 811 && p.y <= 1024) {
        Serial.println("Exponencial");
        tft.setRotation(0);
        selexponencial();
      }
      delay(500);
    }
  }
}

void grafic1(){
  tft.fillScreen(BLACK);
  tft.fillRect(200, 0, 40, 320, BLACK);
  tft.fillRect(200, 0, 40, 64, RED); 
  tft.fillRect(0, 0, 200, 320, TARONGACLAR);
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(50, 0, 2, 320, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(150, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.fillRect(77, 85, 1, 47, BLACK);
  //constant
  tft.setCursor(40, 55); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=3");
  //lineal
  tft.setCursor(190, 55); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=x+1");
  //cuadratica
  tft.setCursor(10, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=x");
  tft.setCursor(81, 102); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(88, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("+2x+1");
  //radical
  tft.setRotation(45);
  tft.setCursor(190, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(255, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("V");
  tft.setCursor(265, 98); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-");
  tft.setCursor(269, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("x");
  /*
  tft.setCursor(165, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=x");
  tft.setCursor(236, 102); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("3");
  tft.setCursor(243, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-x");
  tft.setCursor(265, 102); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(270, 105); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("+x-7");
  */
  //racional
  tft.setCursor(20, 155); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=");
  tft.setCursor(90, 145); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("x+4");
  tft.setCursor(83, 167); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("x");
  tft.setCursor(93, 164); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(98, 167); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("-16");
  //trigonometrica
  tft.setCursor(175, 155); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=sin(x)");
  //logaritmica
  tft.setCursor(15, 205); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=log(x)");
  //exponencial
  tft.setCursor(200, 205); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("f(x)=2");
  tft.setCursor(270, 200); // 65 40
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("x");

  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  tft.setCursor(80, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("A quina s'assembla?");
  numgrafic();
}

bool readNum(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  double operador1 = 0; //en número que quedarà.
  double operador2 = 0; //en número que quedarà.
  
  while(true){
  
    int numPitjat = -1;
    bool suma;
    bool resta;
    bool multiplicacio;
    bool divisio;
    bool exponencial;
    bool arrel;
    bool logaritme;
    bool neperia;
    
    p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    
  
    // 320 x 240
    // 1024 x 1024
    // we have some minimum pressure we consider 'valid'
    // pressure of 0 means no pressing!
    if (p.z > ts.pressureThreshhold) {
      // condicionar la posició del pitjament llargada 0.3125
      // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
      //posible relació alçada de 0.2343
      //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
          
          Serial.println("<-");
          numPitjat = -1;
          suma = false;
          resta = false;
          multiplicacio = false;
          divisio = false;
          exponencial = false;
          arrel = false;
          logaritme = false;
          neperia = false;
          /************** reiniciar els dos números *************/
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          tft.setRotation(0);
          pantalla1();
          break;
          // cridar funció per al <-
          // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
          Serial.println("7");
          numPitjat = 7;
          // cridar funció per al AC
          // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
          Serial.println("4");
          numPitjat = 4;
          // cridar funció per al AC
          // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
          Serial.println("1");
          numPitjat = 1;
          // cridar funció per al AC
          // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
          Serial.println("0");
          numPitjat = 0;
          // cridar funció per al AC
          // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
          Serial.println("DEL");
          // cridar funció per al DEL
          // posa número de pantalla
          //ocupats[0] = 0;
          //ocupats[1] = 0;
          //ocupats[2] = 0;
          /*
          
          */
          numPitjat = -1;
          suma = false;
          resta = false;
          multiplicacio = false;
          divisio = false;
          exponencial = false;
          arrel = false;
          logaritme = false;
          neperia = false;
          /************** reiniciar els dos números *************/
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;


          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla

      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
          Serial.println("8");
          numPitjat = 8;
          // cridar funció per al 8
          // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
          Serial.println("5");
          numPitjat = 5;
          // cridar funció per al 5
          // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
          Serial.println("2");
          numPitjat = 2;
          // cridar funció per al 2
          // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
          Serial.println(".");
          // cridar funció per al .
          // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
          Serial.println("9");
          numPitjat = 9;
          // cridar funció per al 9
          // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
          Serial.println("6");
          numPitjat = 6;
          // cridar funció per al 6
          // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
          Serial.println("3");
          numPitjat = 3;
          // cridar funció per al 3
          // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
          Serial.println("=");
          // cridar funció per al =
          // posa número de pantalla

          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.

          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat

          if(suma == true){
          tft.setCursor(100, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(operador1 + operador2);
          }

          if(resta == true){
          tft.setCursor(100, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(operador1 - operador2);  
          }
          if(multiplicacio == true){
          tft.setCursor(100, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(operador1 * operador2);  
          }
          if(divisio == true){
          tft.setCursor(100, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(operador1 / operador2);  
          }
          if(exponencial == true){
          tft.setCursor(120, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(pow(operador1,operador2));  
          }
          if(arrel == true){
          tft.setCursor(140, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(pow(operador2,1/operador1));  
          }
          if(logaritme == true){
          tft.setCursor(200, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(log(operador2) / log(operador1));  
          }
          if(neperia == true){
          tft.setCursor(200, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(log(operador2));  
          }
           /******************* condicionar la operació *********************///
          //ocupats[2] = 0;

          //reiniciar els dos números
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;


      }
      if (p.x >= 615 && p.x <= 820 && p.y >= 342 && p.y <= 513) {
          Serial.println("+");
          // cridar funció per al +
          // posa número de pantalla
          
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(267, 10); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("+");
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);

          suma = true;
          resta = false;
          multiplicacio = false;
          divisio = false;
          exponencial = false;
          arrel = false;
          logaritme = false;
          neperia = false; //significa que suma
          operador = 1;
      }
      if (p.x >= 615 && p.x <= 820 && p.y >= 513 && p.y <= 684) {
          Serial.println("-");
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(267, 10); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("-");
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);

          resta = true;
          suma = false;
          multiplicacio = false;
          divisio = false;
          exponencial = false; 
          arrel = false;
          logaritme = false;
          neperia = false;//significa que suma
          operador = 1;
          // cridar funció per al -
          // posa número de pantalla
      }
      if (p.x >= 615 && p.x <= 820 && p.y >= 684 && p.y <= 855) {
          Serial.println("x");
          // cridar funció per al x
          // posa número de pantalla
          
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(267, 10); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("x");
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);

          multiplicacio = true;
          divisio = false;
          suma = false;
          resta = false;
          exponencial = false; 
          arrel = false;
          logaritme = false;
          neperia = false;//significa que suma
          operador = 1;
      }
      if (p.x >= 615 && p.x <= 820 && p.y >= 855 && p.y <= 1024) {
          Serial.println("/");
          // cridar funció per al /
          // posa número de pantalla
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(267, 10); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("/");
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);

          divisio = true;
          resta = false;
          suma = false;
          multiplicacio = false;
          exponencial = false; 
          arrel = false;
          logaritme = false;
          neperia = false;//significa que suma
          operador = 1;
      }
      if (p.x >= 820 && p.x <= 1024 && p.y >= 342 && p.y <= 513) {
          Serial.println("elevat");
          // cridar funció per al elevat
          // posa número de pantalla
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(267, 15); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("^");
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);
          
          exponencial = true;
          resta = false;
          suma = false;
          multiplicacio = false;
          divisio = false; 
          arrel = false;
          logaritme = false;
          neperia = false;//significa que suma
          operador = 1;
      }
      if (p.x >= 820 && p.x <= 1024 && p.y >= 513 && p.y <= 684) {
          Serial.println("arrel");
          // cridar funció per al arrel
          // posa número de pantalla
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(267, 10); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("V");
          tft.setCursor(285, -4); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("-");
          
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);
          
          
          exponencial = false;
          resta = false;
          suma = false;
          multiplicacio = false;
          divisio = false; 
          arrel = true;
          logaritme = false;
          neperia = false;//significa que suma
          operador = 1;
      }
      if (p.x >= 820 && p.x <= 1024 && p.y >= 684 && p.y <= 855) {
          Serial.println("log");
          // cridar funció per al log
          // posa número de pantalla
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(245, 5); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("log");
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);
          
          exponencial = false;
          resta = false;
          suma = false;
          multiplicacio = false;
          divisio = false; 
          arrel = false;
          logaritme = true;
          neperia = false;//significa que suma
          operador = 1;
      }
      if (p.x >= 820 && p.x <= 1024 && p.y >= 855 && p.y <= 1024) {
          Serial.println("ln");
          // cridar funció per al ln
          // posa número de pantalla
          tft.fillRect(66, 0, 290, 38, BLACK); //esborrem els números de pantalla pots fer segona fila.
          tft.setCursor(267, 10); // 65 40  276 125
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println("ln");
          
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador1 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador1);
          
          
          exponencial = false;
          resta = false;
          suma = false;
          multiplicacio = false;
          divisio = false; 
          arrel = false;
          logaritme = false;
          neperia = true;//significa que suma
          operador = 1;
      }

      //pintar número
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        

        tft.fillRect(66, 0, 290, 38, BLACK);
        int pos = 285; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 5); // 65 40
          tft.setRotation(45);
          tft.setTextColor(WHITE);  tft.setTextSize(4);
          tft.println(nums[i][operador]);
          pos = pos - 30;
        }

      }

      
      delay(100);
    }
    
  }// fi  while


  pantalla1();
}


void pantalla1(){

  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 100, 160, MAGENTA);
  tft.fillRect(0, 160, 100, 160, BLUE);
  tft.fillRect(100, 0, 100, 160, GREEN);
  tft.fillRect(100, 160, 100, 160, RED);
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  
  tft.setCursor(45, 85); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("BASIC");
  tft.setCursor(200, 85);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("COMPLEX");
  tft.setCursor(40, 180);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("EQUACIO");
  tft.setCursor(205, 180);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("GRAFIC");
  tft.setCursor(60, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("CALCULADORA");

  seleccio();
}

bool seleccio(void){
   while(true){

    
    TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
    // 320 x 240
    // 1024 x 768
    // we have some minimum pressure we consider 'valid'
    // pressure of 0 means no pressing!
        // tft.fillRect(0, 0, 100, 160, MAGENTA); // 320 i 512
      // condicionar la posició del pitjament 0.3125
      // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
      //posible relació alçada de 0.2343
      //Equació
    if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 512 && p.y >= 598 && p.y <= 1024) {
          tft.setRotation(0);
          equacio();
          break;
          // posa número de pantalla
      }
      //Basic
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 598) {
          tft.setRotation(0);
          simples();
          break;
      }
      //Complexes
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 598) {
          tft.setRotation(0);
          complexes();
          break;
      }
      //Gràfic
      if (p.x >= 512 && p.x <= 1024 && p.y >= 598 && p.y <= 1024) {
          tft.setRotation(0);
          grafic1();
          break;
      }
      //Serial.print("X = "); Serial.print(p.x);
      //Serial.print("\tY = "); Serial.print(p.y);
      //Serial.print("\tPressure = "); Serial.println(p.z);
    }

  }
  
}
// dibuixa la pantalla del números
void simples(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 160, 192, VERDCLAR);
  tft.fillRect(160, 0, 40, 128, VERDCLAR);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(0, 192, 160, 128, BLAUCLAR);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 160, 2, BLACK);
  tft.fillRect(0, 192, 160, 2, BLACK);
  tft.fillRect(0, 256, 160, 2, BLACK);
  tft.fillRect(40, 0, 2, 320, BLACK);
  tft.fillRect(80, 0, 2, 320, BLACK);
  tft.fillRect(120, 0, 2, 320, BLACK);
  tft.fillRect(160, 0, 2, 128, BLACK);
  tft.fillRect(200, 0, 2, 64, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //+
  tft.setCursor(217, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("+");
  //-
  tft.setCursor(217, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  //X
  tft.setCursor(217, 165); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("x");
  // /
  tft.setCursor(217, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("/");
  //exponent
  tft.setCursor(281, 95); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("^");
  //arrel
  tft.setCursor(276, 125); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("v");
  tft.setCursor(285, 122); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  //logaritme
  tft.setCursor(260, 167); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("log");
  //ln
  tft.setCursor(270, 207); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("ln");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  readNum();
}

void complexes(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 100, 160, TARONGACLAR);
  tft.fillRect(0, 160, 100, 160, TARONGACLAR);
  tft.fillRect(100, 0, 100, 160, TARONGACLAR);
  tft.fillRect(100, 160, 100, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  
  //Primer
  tft.setCursor(45, 83); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("SINUS");
  //Segon
  tft.setCursor(200, 83);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("COSINUS");
  //Tercer
  tft.setCursor(35, 183);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("TANGENT");
  //Quart
  tft.setCursor(205, 183);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("ALTRES");
  // quina accio
  tft.setCursor(72, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina operacio vols?");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  selecciocomplexes();
}

bool selecciocomplexes(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        pantalla1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 512 && p.y >= 598 && p.y <= 1024) {
        //tangent
        tft.setRotation(0);
        seltangent();
        break;
        // cridar funció per al magenta
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 598) {
        //sinus
        tft.setRotation(0);
        selsinus();
        break;
        // cridar funció per al verd
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 598) {
        //cosinus
        tft.setRotation(0);
        selcosinus();
        break;
        // cridar funció per al vermell
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 598 && p.y <= 1024) {
        //altres
        // cridar funció per al blau
        // posa número de pantalla
        tft.setRotation(0);
        altres();
        break;
      }
    }
  }  
}

bool retornselecciocomplexes(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        complexes();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    }
  }
}
void altres(){
  tft.fillScreen(BLACK);
  tft.setRotation(0);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.setCursor(5, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("Espai destinat a posibles millores en un futur");
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  retornselecciocomplexes();
}
bool selecciosinus(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 1024) {
        Serial.println("Sinus");
        tft.setRotation(0);
        sinus();
        tft.setRotation(0);
        sinuscomplex();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        Serial.println("Arcsin");
        tft.setRotation(0);
        arcsinus();
        tft.setRotation(0);
        arcsinuscomplex();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        complexes();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
    }
  }
}

bool selecciocosinus(void){
  while(true){
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 1024) {
        Serial.println("Cosinus");
        tft.setRotation(0);
        cosinus();
        tft.setRotation(0);
        cosinuscomplex();
        break;
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        Serial.println("Arccos");
        tft.setRotation(0);
        arccosinus();
        tft.setRotation(0);
        arccosinuscomplex();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        complexes();
        break;
      }
    }
  }
}

bool selecciotangent(void){
  while(true){
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //Sinus
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 1024) {
        Serial.println("tangent");
        tft.setRotation(0);
        tangent();
        tft.setRotation(0);
        tangentcomplex();
        break;
        // posa número de pantalla
      }
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 1024) {
        Serial.println("Arctangent");
        tft.setRotation(0);
        arctangent();
        tft.setRotation(0);
        arctangentcomplex();
        break;
        // cridar funció per al Sinus
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        tft.setRotation(0);
        complexes();
        break;
      }
    }
  }
}

void selsinus(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);
  //sinus
  tft.setCursor(35, 125); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("SINUS");
  // quina accio
  tft.setCursor(90, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina accio vols?");
  // arcsin
  tft.setCursor(185, 125);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("ARCSIN");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  selecciosinus();
}

void selcosinus(){
  tft.fillScreen(BLACK);
  
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);

  
  //cosinus
  tft.setCursor(15, 125); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("COSINUS");
  // quina accio
  tft.setCursor(90, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina accio vols?");
  // arccos
  tft.setCursor(185, 125);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("ARCCOS");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  selecciocosinus();
}

void seltangent(){
  tft.fillScreen(BLACK);
  
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 200, 160, TARONGACLAR);
  tft.fillRect(0, 160, 200, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);  
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  tft.fillRect(200, 64, 40, 2, WHITE);

  
  //tangent
  tft.setCursor(15, 125); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("TANGENT");
  // quina accio
  tft.setCursor(90, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quina accio vols?");
  // arctan
  tft.setCursor(185, 125);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("ARCTAN");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  selecciotangent();
}

bool selecnumsinuscomplex(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  int operador1 = 0; //en número que quedarà.
  int operador2 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        selsinus();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 43, 128, TARONGACLAR);
        tft.fillRect(0, 195, 83, 128, BLAUCLAR);
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println(".");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat
          tft.setCursor(210, 180); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(sin(operador2 * (M_PI / 180)));
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool selecnumarcsinuscomplex(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  int operador1 = 0; //en número que quedarà.
  double operador2 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        selsinus();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 43, 128, TARONGACLAR);
        tft.fillRect(0, 195, 83, 128, BLAUCLAR);
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println(".");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat
          tft.setCursor(210, 180); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(asin(operador2/100)*(180 / M_PI));
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool selecnumcosinuscomplex(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  int operador1 = 0; //en número que quedarà.
  int operador2 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        selcosinus();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 43, 128, TARONGACLAR);
        tft.fillRect(0, 195, 83, 128, BLAUCLAR);
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println(".");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat
          tft.setCursor(210, 180); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(cos(operador2 * (M_PI / 180)));
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool selecnumarccosinuscomplex(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  int operador1 = 0; //en número que quedarà.
  double operador2 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        selcosinus();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 43, 128, TARONGACLAR);
        tft.fillRect(0, 195, 83, 128, BLAUCLAR);
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println(".");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat
          tft.setCursor(210, 180); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(acos(operador2/100)*(180 / M_PI));
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool selecnumtangentcomplex(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  int operador1 = 0; //en número que quedarà.
  int operador2 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        seltangent();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 43, 128, TARONGACLAR);
        tft.fillRect(0, 195, 83, 128, BLAUCLAR);
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println(".");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat
          tft.setCursor(210, 180); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(tan(operador2 * (M_PI / 180)));
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool selecnumarctangentcomplex(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  int operador1 = 0; //en número que quedarà.
  double operador2 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        seltangent();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 43, 128, TARONGACLAR);
        tft.fillRect(0, 195, 83, 128, BLAUCLAR);
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println(".");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat
          tft.setCursor(210, 180); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(atan(operador2/100)*(180 / M_PI));
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

void sinus(){
  tft.fillScreen(BLACK);
  tft.setCursor(84, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("Sinus");
}

void arcsinus(){
  tft.fillScreen(BLACK);
  tft.setCursor(80, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Arcsinus");
}

void cosinus(){
  tft.fillScreen(BLACK);
  tft.setCursor(68, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("Cosinus");
}

void arccosinus(){
  tft.fillScreen(BLACK);
  tft.setCursor(72, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Arccosinus");
}

void tangent(){
  tft.fillScreen(BLACK);
  tft.setCursor(68, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("Tangent");
}

void arctangent(){
  tft.fillScreen(BLACK);
  tft.setCursor(72, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Arctangent");
}

void sinuscomplex(){
  tft.fillRect(0, 0, 200, 192, VERDCLAR);
  
  tft.fillRect(120, 192, 120, 192, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);

  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 360, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 64, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");

  tft.setCursor(200, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Angle");
  tft.setCursor(260, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  tft.setCursor(210, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Resultat");
  selecnumsinuscomplex();
}

void arcsinuscomplex(){
  tft.fillRect(0, 0, 200, 192, VERDCLAR);
  
  tft.fillRect(120, 192, 120, 192, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);

  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 360, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 64, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");

  tft.setCursor(200, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Numero=");
  tft.setCursor(200, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Angle");
  selecnumarcsinuscomplex();
}

void cosinuscomplex(){
  tft.fillRect(0, 0, 200, 192, VERDCLAR);
  
  tft.fillRect(120, 192, 120, 192, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);

  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 360, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 64, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");

  tft.setCursor(200, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Angle");
  tft.setCursor(260, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  tft.setCursor(210, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Resultat");
  selecnumcosinuscomplex();
}

void arccosinuscomplex(){
  tft.fillRect(0, 0, 200, 192, VERDCLAR);
  
  tft.fillRect(120, 192, 120, 192, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);

  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 360, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 64, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");

  tft.setCursor(200, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Numero=");
  tft.setCursor(200, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Angle");
  selecnumarccosinuscomplex();
}

void tangentcomplex(){
  tft.fillRect(0, 0, 200, 192, VERDCLAR);
  
  tft.fillRect(120, 192, 120, 192, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);

  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 360, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 64, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");

  tft.setCursor(200, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Angle");
  tft.setCursor(260, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  tft.setCursor(210, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Resultat");
  selecnumtangentcomplex();
}

void arctangentcomplex(){
  tft.fillRect(0, 0, 200, 192, VERDCLAR);
  
  tft.fillRect(120, 192, 120, 192, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);

  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 360, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 64, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");

  tft.setCursor(200, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Numero=");
  tft.setCursor(200, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Angle");
  selecnumarctangentcomplex();
}

void equacio(){
  tft.fillScreen(BLACK);
  
  tft.fillRect(0, 0, 200, 320, BLACK);
  tft.fillRect(0, 0, 100, 160, TARONGACLAR);
  tft.fillRect(0, 160, 100, 160, TARONGACLAR);
  tft.fillRect(100, 0, 100, 160, TARONGACLAR);
  tft.fillRect(100, 160, 100, 160, TARONGACLAR);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(200, 64, 40, 2, WHITE);
  tft.fillRect(200, 0, 2, 320, WHITE);
  tft.fillRect(100, 0, 2, 320, WHITE);
  tft.fillRect(0, 160, 200, 2, WHITE);
  
  //Primer
  tft.setCursor(45, 83); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("PRIMER");
  //Segon
  tft.setCursor(210, 83);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("SEGON");
  //Tercer
  tft.setCursor(45, 183);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("TERCER");
  //Quart
  tft.setCursor(210, 183);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("QUART");
  // quina accio
  tft.setCursor(90, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("Quin grau vols?");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  seleccioequacio();
}

bool numprimergrau(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  double operador1 = 0; //en número que quedarà.
  double operador2 = 0;
  bool resta;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        resta = false;
        numPitjat = -1;
        tft.setRotation(0);
        equacio();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        operador = 0;
        resta = false;
        tft.setRotation(0);
        tft.fillRect(170, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X");
        tft.setCursor(220, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        tft.setRotation(0);
        tft.fillRect(0, 200, 40, 128, BLAUCLAR);
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 171 && p.y <= 342){
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("n");
        tft.setCursor(220, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        for (int i = 0; i < ocupats[operador] ; i++ ){
          int espaiOcupat;
          int calcul = (int) pow(10, i);
          if (i > 1) calcul ++;
          espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
          operador1 += espaiOcupat;

          Serial.print("numero: ");
          Serial.print(nums[ocupats[operador] - i - 1][operador]);

          Serial.print(" calcul: ");
          Serial.print(calcul);

          Serial.print(" parcial: ");
          Serial.println(espaiOcupat);
        }
        Serial.print("numero escrit: ");
        Serial.println(operador1);
        operador = 1;
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println("-");
        tft.setRotation(45);
        tft.setCursor(200,40);
        tft.setTextColor(BLACK);  tft.setTextSize(3);
        tft.println("-");
        resta = true;
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);

          //escriure el resultat
          tft.setCursor(200, 200); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(2);
          if (resta == false){
          tft.println(- operador2 / operador1);
          }
          if (resta == true){
          tft.println(operador2 / operador1);
          }
          ocupats[0] = 0;
          ocupats[1] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool numsegongrau(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  double operador1 = 0; //en número que quedarà.
  double operador2 = 0;
  double operador3 = 0;
  bool resta;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        ocupats[2] = 0;
        operador = 0;
        resta = false;
        numPitjat = -1;
        tft.setRotation(0);
        equacio();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 171 && p.y <= 342) {
        Serial.println("AC");
        // cridar funció per al AC
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        ocupats[2] = 0;
        operador = 0;
        resta = false;
        tft.setRotation(0);
        tft.fillRect(170, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X");
        tft.setCursor(217, 8); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(1);
        tft.println("2");
        tft.setCursor(225, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        tft.setRotation(0);
        tft.fillRect(0, 240, 90, 128, BLAUCLAR);
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        tft.setRotation(0);
        tft.fillRect(170, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X=");
        for (int i = 0; i < ocupats[operador] ; i++ ){
          int espaiOcupat;
          int calcul = (int) pow(10, i);
          if (i > 1) calcul ++;
          espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
          operador1 += espaiOcupat;

          Serial.print("numero: ");
          Serial.print(nums[ocupats[operador] - i - 1][operador]);

          Serial.print(" calcul: ");
          Serial.print(calcul);

          Serial.print(" parcial: ");
          Serial.println(espaiOcupat);
        }
        Serial.print("numero escrit: ");
        Serial.println(operador1);
        operador = 1;
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 171 && p.y <= 342){
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("n");
        tft.setCursor(220, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador2);
          operador = 2;
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println("-");
        tft.setRotation(45);
        tft.setCursor(200,40);
        tft.setTextColor(BLACK);  tft.setTextSize(3);
        tft.println("-");
        resta = true;
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador3 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador3);

          //escriure el resultat
        if(resta == false){
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 - sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 + sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(-operador3 / operador2);
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ (1 * sqrt(-operador3 / operador1))); 
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- (1 * sqrt(-operador3 / operador1)));
          }
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 - sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 + sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
        }
        if(resta == true){
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 - sqrt(pow(operador2,2)- 4 * operador1 * -operador3)) / (2*operador1));
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 + sqrt(pow(operador2,2)- 4 * operador1 * -operador3)) / (2*operador1));
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(operador3 / operador2);
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ (1 * sqrt(operador3 / operador1))); 
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- (1 * sqrt(operador3 / operador1)));
          }
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 - sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 + sqrt(pow(operador2,2)- 4 * operador1 * -operador3)) / (2*operador1));
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }  
        }
          /*
          if (resta == false){
          tft.println(- operador2 / operador1);
          }
          if (resta == true){
          tft.println(operador2 / operador1);
          }
          */
          ocupats[0] = 0;
          ocupats[1] = 0;
          ocupats[2] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
          operador3 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool numtercergrau(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  double operador1 = 0; //en número que quedarà.
  double operador2 = 0;
  double operador3 = 0;
  double operador4 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        ocupats[2] = 0;
        ocupats[3] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        equacio();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 171 && p.y <= 342) {
        Serial.println("AC");
        // cridar funció per al AC
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        ocupats[2] = 0;
        ocupats[3] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40 // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X");
        tft.setCursor(217, 8); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(1);
        tft.println("3");
        tft.setCursor(225, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        tft.setRotation(0);
        tft.fillRect(0, 240, 90, 128, BLAUCLAR);
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        tft.setRotation(0);
        tft.fillRect(170, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X");
        tft.setCursor(217, 8); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(1);
        tft.println("2");
        tft.setCursor(225, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        for (int i = 0; i < ocupats[operador] ; i++ ){
          int espaiOcupat;
          int calcul = (int) pow(10, i);
          if (i > 1) calcul ++;
          espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
          operador1 += espaiOcupat;

          Serial.print("numero: ");
          Serial.print(nums[ocupats[operador] - i - 1][operador]);

          Serial.print(" calcul: ");
          Serial.print(calcul);

          Serial.print(" parcial: ");
          Serial.println(espaiOcupat);
        }
        Serial.print("numero escrit: ");
        Serial.println(operador1);
        operador = 1;
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 171 && p.y <= 342){
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X=");
        for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
        }
          Serial.print("numero escrit: ");
          Serial.println(operador2);
          operador = 2;
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 0 && p.y <= 171){
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("n");
        tft.setCursor(220, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador3 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador3);
          operador = 3;
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println("-");
        tft.setRotation(45);
        tft.setCursor(200,40);
        tft.setTextColor(BLACK);  tft.setTextSize(3);
        tft.println("-");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador4 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador4);

          //escriure el resultat
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no es");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("resol");
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("segon");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("primer");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");  
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("nan");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no es");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("resol");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ pow((-operador4 / operador1), 1/3));
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- pow((-operador4 / operador1), 1/3));
            tft.setCursor(240, 200); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 200); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 - sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
            tft.setCursor(240, 200); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 + sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
          }
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 == 0.0 && operador4 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 200); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(-operador2 / operador1);
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(sqrt(-operador3));
            tft.setCursor(240, 200); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(-sqrt(-operador3));
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 == 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("segon");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");
          }
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 == 0.0 && operador4 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no es");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("resol");
          }
          /*
          if (resta == false){
          tft.println(- operador2 / operador1);
          }
          if (resta == true){
          tft.println(operador2 / operador1);
          }
          */
          ocupats[0] = 0;
          ocupats[1] = 0;
          ocupats[2] = 0;
          ocupats[3] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
          operador3 = 0;
          operador4 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

bool numquartgrau(void){
  int sortir = 0;
  int operador = 0; //si som al primer número o al segon.

  double operador1 = 0; //en número que quedarà.
  double operador2 = 0;
  double operador3 = 0;
  double operador4 = 0;
  double operador5 = 0;
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    int numPitjat = -1;
    if (p.z > ts.pressureThreshhold) {
    // condicionar la posició del pitjament llargada 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
    //<-
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        Serial.println("<-");
        ocupats[0] = 0;
        ocupats[1] = 0;
        ocupats[2] = 0;
        ocupats[3] = 0;
        ocupats[4] = 0;
        operador = 0;
        numPitjat = -1;
        tft.setRotation(0);
        equacio();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 171 && p.y <= 342) {
        Serial.println("AC");
        // cridar funció per al AC
        // posa número de pantalla
        numPitjat = -1;
        ocupats[0] = 0;
        ocupats[1] = 0;
        ocupats[2] = 0;
        ocupats[3] = 0;
        ocupats[4] = 0;
        operador = 0;
        tft.setRotation(0);
        tft.fillRect(170, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X");
        tft.setCursor(217, 8); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(1);
        tft.println("4");
        tft.setCursor(225, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        tft.setRotation(0);
        tft.fillRect(0, 240, 100, 128, BLAUCLAR);
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 342 && p.y <= 513) {
        Serial.println("7");
        numPitjat = 7;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 513 && p.y <= 684) {
        Serial.println("4");
        numPitjat = 4;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 684 && p.y <= 855) {
        Serial.println("1");
        numPitjat = 1;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 205 && p.y >= 855 && p.y <= 1024) {
        Serial.println("0");
        numPitjat = 0;
        // cridar funció per al AC
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 171 && p.y <= 342) {
        Serial.println("DEL");
        // cridar funció per al DEL
        // posa número de pantalla
        tft.setRotation(0);
        tft.fillRect(170, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40 // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X");
        tft.setCursor(217, 8); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(1);
        tft.println("3");
        tft.setCursor(225, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        for (int i = 0; i < ocupats[operador] ; i++ ){
          int espaiOcupat;
          int calcul = (int) pow(10, i);
          if (i > 1) calcul ++;
          espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
          operador1 += espaiOcupat;

          Serial.print("numero: ");
          Serial.print(nums[ocupats[operador] - i - 1][operador]);

          Serial.print(" calcul: ");
          Serial.print(calcul);

          Serial.print(" parcial: ");
          Serial.println(espaiOcupat);
        }
        Serial.print("numero escrit: ");
        Serial.println(operador1);
        operador = 1;
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 171 && p.y <= 342){
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X");
        tft.setCursor(217, 8); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(1);
        tft.println("2");
        tft.setCursor(225, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
        for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador2 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
        }
          Serial.print("numero escrit: ");
          Serial.println(operador2);
          operador = 2;
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 0 && p.y <= 171){
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("X=");
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador3 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador3);
          operador = 3;
      }
      if(p.x >= 410 && p.x <= 615 && p.y >= 0 && p.y <= 171){
        tft.setRotation(0);
        tft.fillRect(122, 195, 120, 128, TARONGACLAR);
        tft.setCursor(205, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("n");
        tft.setCursor(220, 10); // 65 40
        tft.setRotation(45);
        tft.setTextColor(BLACK);  tft.setTextSize(2);
        tft.println("=");
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador4 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador4);
          operador = 4;
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 342 && p.y <= 513) {
        Serial.println("8");
        numPitjat = 8;
        // cridar funció per al 8
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 513 && p.y <= 684) {
        Serial.println("5");
        numPitjat = 5;
        // cridar funció per al 5
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 684 && p.y <= 855) {
        Serial.println("2");
        numPitjat = 2;
        // cridar funció per al 2
        // posa número de pantalla
      }
      if (p.x >= 205 && p.x <= 410 && p.y >= 855 && p.y <= 1024) {
        Serial.println("-");
        tft.setRotation(45);
        tft.setCursor(200,40);
        tft.setTextColor(BLACK);  tft.setTextSize(3);
        tft.println("-");
        // cridar funció per al .
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 342 && p.y <= 513) {
        Serial.println("9");
        numPitjat = 9;
        // cridar funció per al 9
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 513 && p.y <= 684) {
        Serial.println("6");
        numPitjat = 6;
        // cridar funció per al 6
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 684 && p.y <= 855) {
        Serial.println("3");
        numPitjat = 3;
        // cridar funció per al 3
        // posa número de pantalla
      }
      if (p.x >= 410 && p.x <= 615 && p.y >= 855 && p.y <= 1024) {
        Serial.println("=");
          //esborrem els números de pantalla pots fer segona fila.
          // guardem el primer operador a la variable.
          for (int i = 0; i < ocupats[operador] ; i++ ){
            int espaiOcupat;
            int calcul = (int) pow(10, i);
            if (i > 1) calcul ++;
            espaiOcupat = nums[ocupats[operador] - i - 1][operador] * calcul;
            operador5 += espaiOcupat;

            Serial.print("numero: ");
            Serial.print(nums[ocupats[operador] - i - 1][operador]);

            Serial.print(" calcul: ");
            Serial.print(calcul);

            Serial.print(" parcial: ");
            Serial.println(espaiOcupat);
          }
          Serial.print("numero escrit: ");
          Serial.println(operador5);

          //escriure el resultat
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 != 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no es");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("resol");
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 != 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("tercer");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 != 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("segon");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");  
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 != 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("primer");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 == 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("nan");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 != 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no es");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("resol");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 != 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no es");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("resol");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 == 0.0 && operador5 != 0.0){
            tft.setCursor(240, 140); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ pow((- operador5 / operador1), 1/4));
            tft.setCursor(240, 165); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- pow((- operador5 / operador1), 1/4));
            tft.setCursor(240, 190); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 215); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 == 0.0 && operador5 == 0.0){
            tft.setCursor(240, 140); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 165); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 190); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 215); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 != 0.0 && operador5 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no es");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("resol");
          }
          if(operador1 == 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 != 0.0 && operador5 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("tercer");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 == 0.0 && operador5 != 0.0){
            tft.setCursor(240, 140); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ sqrt(((-operador3 + sqrt(pow(operador3,2)- 4 * operador1 * operador5)) / (2*operador1))));
            tft.setCursor(240, 165); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- sqrt(((-operador3 + sqrt(pow(operador3,2)- 4 * operador1 * operador5)) / (2*operador1))));
            tft.setCursor(240, 190); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ sqrt(((-operador3 - sqrt(pow(operador3,2)- 4 * operador1 * operador5)) / (2*operador1))));
            tft.setCursor(240, 215); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- sqrt(((-operador3 - sqrt(pow(operador3,2)- 4 * operador1 * operador5)) / (2*operador1))));
          }
          if(operador1 != 0.0 && operador2 != 0.0 && operador3 != 0.0 && operador4 == 0.0 && operador5 == 0.0){
            tft.setCursor(240, 140); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 165); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 190); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 + sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
            tft.setCursor(240, 215); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println((-operador2 - sqrt(pow(operador2,2)- 4 * operador1 * operador3)) / (2*operador1));
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 == 0.0 && operador5 != 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("segon");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 == 0.0 && operador4 == 0.0 && operador5 != 0.0){
            tft.setCursor(240, 140); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ (1 * pow((-operador5/operador1),1/4)));
            tft.setCursor(240, 165); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- (1 * pow((-operador5/operador1),1/4)));
            tft.setCursor(240, 190); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
            tft.setCursor(240, 215); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 != 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 == 0.0 && operador5 == 0.0){
            tft.setCursor(240, 140); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(+ (1 * sqrt(-operador3)));
            tft.setCursor(240, 165); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println(- (1 * sqrt(-operador3)));
            tft.setCursor(240, 190); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("0.00");
            tft.setCursor(240, 215); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("no");
          }
          if(operador1 == 0.0 && operador2 == 0.0 && operador3 != 0.0 && operador4 == 0.0 && operador5 == 0.0){
            tft.setCursor(240, 150); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("segon");
            tft.setCursor(240, 175); // 65 40
            tft.setRotation(45);
            tft.setTextColor(BLACK);  tft.setTextSize(2);
            tft.println("grau");
          }
          /*
          if (resta == false){
          tft.println(- operador2 / operador1);
          }
          if (resta == true){
          tft.println(operador2 / operador1);
          }
          */
          ocupats[0] = 0;
          ocupats[1] = 0;
          ocupats[2] = 0;
          ocupats[3] = 0;
          ocupats[4] = 0;
          operador = 0;
          operador1 = 0;
          operador2 = 0;
          operador3 = 0;
          operador4 = 0;
          operador5 = 0;
        // cridar funció per al =
        // posa número de pantalla
      }
      if (numPitjat != -1){

        if (numPitjat >= 0 && numPitjat < 10){
          nums[ocupats[operador]][operador] = numPitjat;
          ocupats[operador] ++;
        }
        
        tft.setRotation(0);
        tft.fillRect(125, 195, 87, 128, TARONGACLAR);
        int pos = 302; 
        for (int i = ocupats[operador] -1; i >= 0; i--){
          tft.setCursor(pos, 40); // 65 40
          tft.setRotation(45);
          tft.setTextColor(BLACK);  tft.setTextSize(3);
          tft.println(nums[i][operador]);
          pos = pos - 18;
        }

      }

      
      delay(100);
    }
  }
}

void primergrau(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 160, 192, VERDCLAR);
  tft.fillRect(160, 0, 40, 128, VERDCLAR);
  tft.fillRect(120, 192, 120, 128, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(160, 128, 40, 64, MAGENTACLAR);
  tft.fillRect(0, 64, 160, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 320, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 192, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //X
  tft.setCursor(205, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(220, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //resultat
  tft.setCursor(210, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Resultat");
  //x resultat
  tft.setCursor(205, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("X");
  tft.setCursor(225, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //AC
  tft.setCursor(10, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("BORRAR");
  //i
  tft.setCursor(145, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("->");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  //primer
  tft.setCursor(78, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("Primer");
  numprimergrau();
}
void segongrau(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 160, 192, VERDCLAR);
  tft.fillRect(160, 0, 40, 128, VERDCLAR);
  tft.fillRect(120, 192, 120, 128, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(160, 128, 40, 64, MAGENTACLAR);
  tft.fillRect(160, 64, 40, 64, MAGENTACLAR);
  tft.fillRect(0, 64, 200, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 320, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 192, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //X2
  tft.setCursor(205, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(217, 8); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(225, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //resultat
  tft.setCursor(210, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Resultat");
  //x1 resultat
  tft.setCursor(205, 150); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 158); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("1");
  tft.setCursor(225, 150); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //x2 resultat
  tft.setCursor(205, 175); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 183); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(225, 175); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //AC
  tft.setCursor(15, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("AC");
  //DEL
  tft.setCursor(80, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1r");
  //i
  tft.setCursor(145, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2n");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  //segon
  tft.setCursor(84, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("Segon");
  numsegongrau();
}

void tercergrau(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 160, 192, VERDCLAR);
  tft.fillRect(160, 0, 40, 128, VERDCLAR);
  tft.fillRect(120, 192, 120, 128, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);
  tft.fillRect(200, 64, 40, 64, MAGENTACLAR);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(160, 128, 40, 64, MAGENTACLAR);
  tft.fillRect(160, 64, 40, 64, MAGENTACLAR);
  tft.fillRect(0, 64, 240, 2, BLACK);
  tft.fillRect(0, 128, 200, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 320, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 192, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //X3
  tft.setCursor(205, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(217, 8); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("3");
  tft.setCursor(225, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //resultat
  tft.setCursor(210, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Resultat");
  //x1 resultat
  tft.setCursor(205, 150); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 158); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("1");
  tft.setCursor(225, 150); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //x2 resultat
  tft.setCursor(205, 175); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 183); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(225, 175); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //x3 resultat
  tft.setCursor(205, 200); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 208); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("3");
  tft.setCursor(225, 200); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //AC
  tft.setCursor(15, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("AC");
  //DEL
  tft.setCursor(75, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1r");
  //i
  tft.setCursor(145, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2n");
  //3r
  tft.setCursor(75, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3r");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  numtercergrau();
}

void quartgrau(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 160, 192, VERDCLAR);
  tft.fillRect(160, 0, 40, 128, VERDCLAR);
  tft.fillRect(120, 192, 120, 128, TARONGACLAR);
  tft.fillRect(0, 192, 120, 128, BLAUCLAR);
  tft.fillRect(200, 64, 40, 128, MAGENTACLAR);
  tft.fillRect(200, 0, 40, 64, RED);
  tft.fillRect(160, 128, 40, 64, MAGENTACLAR);
  tft.fillRect(160, 64, 40, 64, MAGENTACLAR);
  tft.fillRect(0, 64, 240, 2, BLACK);
  tft.fillRect(0, 128, 240, 2, BLACK);
  tft.fillRect(0, 192, 240, 2, BLACK);
  tft.fillRect(40, 0, 2, 192, BLACK);
  tft.fillRect(80, 0, 2, 192, BLACK);
  tft.fillRect(120, 0, 2, 320, BLACK);
  tft.fillRect(160, 0, 2, 192, BLACK);
  tft.fillRect(200, 0, 2, 192, BLACK);
  
  //7
  tft.setCursor(25, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("7");
  //8
  tft.setCursor(89, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("8");
  //9
  tft.setCursor(153, 90); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("9");
  //4
  tft.setCursor(25, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4");
  //5
  tft.setCursor(89, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("5");
  //6
  tft.setCursor(153, 130); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("6");
  //1
  tft.setCursor(25, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1");
  //2
  tft.setCursor(89, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2");
  //3
  tft.setCursor(153, 170); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3");
  //0
  tft.setCursor(25, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("0");
  //.
  tft.setCursor(89, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println(".");
  //=
  tft.setCursor(153, 210); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("=");
  //X4
  tft.setCursor(205, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(217, 8); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("4");
  tft.setCursor(225, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //resultat
  tft.setCursor(210, 123); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("Resultat");
  //x1 resultat
  tft.setCursor(205, 140); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 148); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("1");
  tft.setCursor(225, 140); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //x2 resultat
  tft.setCursor(205, 165); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 173); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("2");
  tft.setCursor(225, 165); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //x3 resultat
  tft.setCursor(205, 190); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 198); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("3");
  tft.setCursor(225, 190); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //x4 resultat
  tft.setCursor(205, 215); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("X");
  tft.setCursor(218, 222); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(1);
  tft.println("4");
  tft.setCursor(225, 215); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("=");
  //AC
  tft.setCursor(15, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("AC");
  //DEL
  tft.setCursor(75, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("1r");
  //i
  tft.setCursor(145, 50); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("2n");
  //3r
  tft.setCursor(75, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("3r");
  //4t
  tft.setCursor(145, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("4t");
  // <-
  tft.setCursor(17, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("<");
  tft.setCursor(23, 10); // 65 40
  tft.setRotation(45);
  tft.setTextColor(BLACK);  tft.setTextSize(3);
  tft.println("-");
  numquartgrau();
}

bool seleccioequacio(void){
  while(true){
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);    
    // 320 x 240
    // 1024 x 768
    // we have some minimum pressure we consider 'valid'
    // pressure of 0 means no pressing!
    // tft.fillRect(0, 0, 100, 160, MAGENTA); // 320 i 512
    // condicionar la posició del pitjament 0.3125
    // magenta per al touchpad = 140 / 0.3125 al 240 / 0.3125
    //posible relació alçada de 0.2343
      //Tercer grau
    if (p.z > ts.pressureThreshhold) {
      if (p.x >= 0 && p.x <= 205 && p.y >= 0 && p.y <= 171) {
        tft.setRotation(0);
        pantalla1();
        break;
        // cridar funció per al <-
        // posa número de pantalla
      }
      if (p.x >= 0 && p.x <= 512 && p.y >= 598 && p.y <= 1024) {
        tft.setRotation(0);
        tercergrau();
        break;
        // cridar funció per al magenta
        // posa número de pantalla
      }
      //Primer grau
      if (p.x >= 0 && p.x <= 512 && p.y >= 171 && p.y <= 598) {
        tft.setRotation(0);
        primergrau();
        break;
        // cridar funció per al verd
        // posa número de pantalla
      }
      //Segon grau
      if (p.x >= 512 && p.x <= 1024 && p.y >= 171 && p.y <= 598) {
        tft.setRotation(0);
        segongrau();
        break;
        // cridar funció per al vermell
        // posa número de pantalla
      }
      //Quart grau
      if (p.x >= 512 && p.x <= 1024 && p.y >= 598 && p.y <= 1024) {
        tft.setRotation(0);
        quartgrau();
        break;
        // cridar funció per al blau
        // posa número de pantalla
      }
     //Serial.print("X = "); Serial.print(p.x);
     //Serial.print("\tY = "); Serial.print(p.y);
     //Serial.print("\tPressure = "); Serial.println(p.z);
    }
    }
  }


void loop(void) {
  // nothing here.
}