#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLACK);

  // First Triangle in Lab Coordanates (10, 10), (10, 25), (25, 25)
  int j;
  for (j = 10; j < 25; j++)
    drawPixel(j, j, COLOR_WHITE);
  for (j = 10; j < 25; j++)
    drawPixel(j, 25, COLOR_WHITE);
  for (j = 10; j < 25; j++)
    drawPixel(10, j, COLOR_WHITE);

  for (j = 25; j < 40; j++) // Slope
    drawPixel(j, j, COLOR_WHITE);
  for (j = 25; j < 40; j++) // Horizontal
    drawPixel(j, 40, COLOR_WHITE);
  for (j = 25; j < 40; j++) // Vertical
    drawPixel(25, j, COLOR_WHITE);

  for (j = 25; j < 40; j++) // Slope 
    drawPixel(j-15, j, COLOR_WHITE);
  for (j = 25; j < 40; j++) // Vertical
    drawPixel(10, j, COLOR_WHITE);
  for (j = 10; j < 25; j++) // Horizontal
    drawPixel(j, 40, COLOR_WHITE);
  
  clearScreen(COLOR_BLACK); // To Clear and Show...
  
  // Second Triangle in Lab
  for (j = 0; j < 40; j++)
    drawPixel(0, j, COLOR_RED);
  for (j = 0; j < 40; j++)
    drawPixel((j/2), 40, COLOR_RED);
  for (j = 0; j < 40; j++)
    drawPixel((j/2), j, COLOR_RED);

  // Third Triangle in Lecture
  int c, r;
  for (c = 0; c <= 10; c++){
    for (r = c; r<=10; r++) {
      drawPixel(50+c, 50+r, COLOR_RED);
      drawPixel(50+c, 50-r, COLOR_BLUE);
      drawPixel(50-c, 50+r, COLOR_GREEN);
      drawPixel(50-c, 50-r, COLOR_YELLOW);
    }
  }

  clearScreen(COLOR_BLACK); // To Clear and Show...

  
  // In Lab Trapezoid
  for (c = 0; c <= 10; c++){
    for (r = c; r<=10; r++){
      drawPixel(20-c, 20+r, COLOR_WHITE); // Triangle
      drawPixel(40+c, 20+r, COLOR_WHITE); // Triangle
    }
  }
  //Rectangle
  for (c = 0; c <= 20; c++){
    for (r = 0; r <= 10; r++){
      drawPixel(c+20,r+20,COLOR_WHITE); // Rectangle
    }
  }
  
}
