/** \file lcddraw.c
 *  \brief Adapted from RobG's EduKit
 */
#include "lcdutils.h"
#include "lcddraw.h"


/** Draw single pixel at x,row 
 *
 *  \param col Column to draw to
 *  \param row Row to draw to
 *  \param colorBGR Color of pixel in BGR
 */
void drawPixel(u_char col, u_char row, u_int colorBGR)
{
  lcd_setArea(col, row, col, row);
  lcd_writeColor(colorBGR);
}


void classicCoolShape(){
  for (int r = 0; r <= 50; r++){
    int colLeft = 50 - r;
    int colRight = r;
    for (int c = colRight; c<= colLeft; c+=2) {
      drawPixel(40+c, 70+r, COLOR_RED);
      drawPixel(40+c,70-r, COLOR_BLUE);
      drawPixel(40-c, 70+r, COLOR_GREEN);
      drawPixel(40-c, 70-r, COLOR_YELLOW);
      drawPixel(60+c, 75+r, COLOR_RED);
      drawPixel(60+c, 75-r, COLOR_BLUE);
      drawPixel(60-c, 75+r, COLOR_GREEN);
      drawPixel(60-c, 75-r, COLOR_YELLOW);
      drawPixel(80+c, 80+r, COLOR_RED);
      drawPixel(80+c, 80-r, COLOR_BLUE);
      drawPixel(80-c, 80+r, COLOR_GREEN);
      drawPixel(80-c, 80-r, COLOR_YELLOW);
    }
  }
}

void awesomeShape(){
  for (int r = 0; r <= 50; r++){
    int colLeft = 50 - r;
    int colRight = r;
    for (int c = colRight; c<= colLeft; c+=4) {
      drawPixel(20+c, 20+r, COLOR_RED);
      drawPixel(20+c, 20-r, COLOR_BLUE);
      drawPixel(20-c, 20+r, COLOR_GREEN);
      drawPixel(20-c, 20-r, COLOR_YELLOW);
      drawPixel(20+c, 60+r, COLOR_RED);
      drawPixel(20+c, 60-r, COLOR_BLUE);
      drawPixel(20-c, 60+r, COLOR_GREEN);
      drawPixel(20-c, 60-r, COLOR_YELLOW);
      drawPixel(20+c, 100+r, COLOR_RED);
      drawPixel(20+c, 100-r, COLOR_BLUE);
      drawPixel(20-c, 100+r, COLOR_GREEN);
      drawPixel(20-c, 100-r, COLOR_YELLOW);
      drawPixel(20+c, 140+r, COLOR_RED);
      drawPixel(20+c, 140-r, COLOR_BLUE);
      drawPixel(20-c, 140+r, COLOR_GREEN);
      drawPixel(20-c, 140-r, COLOR_YELLOW);

      drawPixel(120+c, 20+r, COLOR_RED);
      drawPixel(120+c, 20-r, COLOR_BLUE);
      drawPixel(120-c, 20+r, COLOR_GREEN);
      drawPixel(120-c, 20-r, COLOR_YELLOW);
      drawPixel(120+c, 60+r, COLOR_RED);
      drawPixel(120+c, 60-r, COLOR_BLUE);
      drawPixel(120-c, 60+r, COLOR_GREEN);
      drawPixel(120-c, 60-r, COLOR_YELLOW);
      drawPixel(120+c, 100+r, COLOR_RED);
      drawPixel(120+c, 100-r, COLOR_BLUE);
      drawPixel(120-c, 100+r, COLOR_GREEN);
      drawPixel(120-c, 100-r, COLOR_YELLOW);
      drawPixel(120+c, 140+r, COLOR_RED);
      drawPixel(120+c, 140-r, COLOR_BLUE);
      drawPixel(120-c, 140+r, COLOR_GREEN);
      drawPixel(120-c, 140-r, COLOR_YELLOW);
      
    }
  }

  /*
  int j;
  for (j = 10; j < 50; j++)
    drawPixel(j, j, COLOR_RED);
  for (j = 10; j < 50; j++)
    drawPixel(j, 50, COLOR_BLUE);
  for (j = 10; j < 50; j++)
    drawPixel(10, j, COLOR_YELLOW);

  for (j = 25; j < 40; j++) // Slope
    drawPixel(j, j, COLOR_RED);
  for (j = 25; j < 40; j++) // Horizontal
    drawPixel(j, 40, COLOR_BLUE);
  for (j = 25; j < 40; j++) // Vertical
   drawPixel(25, j, COLOR_YELLOW);

   for (j = 25; j < 40; j++) // Slope
    drawPixel(j-15, j, COLOR_RED);
  for (j = 25; j < 40; j++) // Vertical
    drawPixel(10, j, COLOR_BLUE);
  for (j = 10; j < 25; j++) // Horizontal
    drawPixel(j, 40, COLOR_YELLOW);
  */
  
}

void originalShape(){
  int c, r;  
  for (c = 0; c <= 40; c+=1){
    for (r = 0; r <= 40; r+=1){
      drawPixel(c+25,r+25,COLOR_RED); 
      drawPixel(c+30,r+30,COLOR_BLUE); 
      drawPixel(c+35,r+35,COLOR_YELLOW);
      drawPixel(c+40,r+40,COLOR_RED); 
      drawPixel(c+45,r+45,COLOR_BLUE); 
      drawPixel(c+50,r+50,COLOR_YELLOW);
      drawPixel(c+55,r+55,COLOR_RED);
      drawPixel(c+60,r+60,COLOR_BLUE); 
      drawPixel(c+65,r+65,COLOR_YELLOW);
      drawPixel(c+70,r+70,COLOR_RED);  
      drawPixel(c+75,r+75,COLOR_BLUE); 
      drawPixel(c+80,r+80,COLOR_YELLOW);
    }
  }
}






/** Fill rectangle
 *
 *  \param colMin Column start
 *  \param rowMin Row start
 *  \param width Width of rectangle
 *  \param height height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height,
		   u_int colorBGR)
{
  u_char colLimit = colMin + width, rowLimit = rowMin + height;
  lcd_setArea(colMin, rowMin, colLimit - 1, rowLimit - 1);
  u_int total = width * height;
  u_int c = 0;
  while ((c++) < total) {
    lcd_writeColor(colorBGR);
  }
}

/** Clear screen (fill with color)
 *  
 *  \param colorBGR The color to fill screen
 */
void clearScreen(u_int colorBGR)
{
  u_char w = screenWidth;
  u_char h = screenHeight;
  fillRectangle(0, 0, screenWidth, screenHeight, colorBGR);
}

/** 5x7 font - this function draws background pixels
 *  Adapted from RobG's EduKit
 */
void drawChar5x7(u_char rcol, u_char rrow, char c,
		 u_int fgColorBGR, u_int bgColorBGR)
{
  u_char col = 0;
  u_char row = 0;
  u_char bit = 0x01;
  u_char oc = c - 0x20;

  lcd_setArea(rcol, rrow, rcol + 4, rrow + 7); /* relative to requested col/row */
  while (row < 8) {
    while (col < 5) {
      u_int colorBGR = (font_5x7[oc][col] & bit) ? fgColorBGR : bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
    }
    col = 0;
    bit <<= 1;
    row++;
  }
}

/** Draw string at col,row
 *  Type:
 *  FONT_SM - small (5x8,) FONT_MD - medium (8x12,) FONT_LG - large (11x16)
 *  FONT_SM_BKG, FONT_MD_BKG, FONT_LG_BKG - as above, but with background color
 *  Adapted from RobG's EduKit
 *
 *  \param col Column to start drawing string
 *  \param row Row to start drawing string
 *  \param string The string
 *  \param fgColorBGR Foreground color in BGR
 *  \param bgColorBGR Background color in BGR
 */
void drawString5x7(u_char col, u_char row, char *string,
		   u_int fgColorBGR, u_int bgColorBGR)
{
  u_char cols = col;
  while (*string) {
    drawChar5x7(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 6;
  }
}


/** Draw rectangle outline
 *  
 *  \param colMin Column start
 *  \param rowMin Row start 
 *  \param width Width of rectangle
 *  \param height Height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 **/
void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height,
		     u_int colorBGR)
{
  /**< top & bot */
  fillRectangle(colMin, rowMin, width, 1, colorBGR);
  fillRectangle(colMin, rowMin + height, width, 1, colorBGR);

  /**< left & right */
  fillRectangle(colMin, rowMin, 1, height, colorBGR);
  fillRectangle(colMin + width, rowMin, 1, height, colorBGR);
}
