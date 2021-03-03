#include <font4x6.h>
#include <fontALL.h>

#include <TVout.h>
#include <video_gen.h>

// ------------------------------------------------
// Global Variables (In Memory)
// ------------------------------------------------
TVout TV;
int incomingByte; // a variable to read incoming serial data into
int point[2];
int idx_point=0;
// ------------------------------------------------
// Setup
// ------------------------------------------------
void setup() {
  Serial.begin(9600);
  incomingByte = 0;
  TV.begin(NTSC,120,96);
  TV.select_font(font4x6);
  TV.clear_screen();
  randomSeed(analogRead(0));
  Serial.println();
}
// ------------------------------------------------
// Main Loop
// ------------------------------------------------
void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    if (incomingByte == 'E') {
     TV.draw_rect(point[1],point[0],10,10,WHITE,WHITE);
    }else if(incomingByte == 'S'){
      TV.clear_screen();
    }else{
      if(idx_point<2){
        point[idx_point]=incomingByte;
        idx_point++;
      }else{
        idx_point=0;
      }


      //TV.draw_rect(pObj[X],pObj[Y],pObj[XSIZE] ,pObj[YSIZE],WHITE,WHITE);
    }
  }

}