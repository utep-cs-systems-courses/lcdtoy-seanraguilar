#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  int j;
  for (j = 10; j < 25; j++)
    drawPixel(j, j, COLOR_WHITE);
  for (j = 10; j < 25; j++)
    drawPixel(j, 25, COLOR_WHITE);
  for (j = 10; j < 25; j++)
    drawPixel(10, j, COLOR_WHITE);

}
