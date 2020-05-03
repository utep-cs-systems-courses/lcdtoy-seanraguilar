#include <msp430.h>
#include <stdlib.h>
#include "stateMachine.h"
#include "led.h"
//#include "toggle.h"
#include "switches.h"
#include "lcddraw.h"
#include "lcdutils.h"


char state = 3, switch_state_change, cool_enable = 0, toggle_animation = 1;

char toggle_red()/* always toggle! */
{
  static char state = 0;

  switch (state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;/* always changes an led */
}

char toggle_green()/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

/*
void state_advance() // alternate between toggling red & green 
{
  char changed = 0;
  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }
  
  led_changed = changed;
  led_update();
}
*/

void state_advance() // Alternate between toggling red & green
{
  switch(state){

  case 0:
    if(switch_state_changed)
    {
      buzzer_set_period(0);
      clearScreen(COLOR_BLACK);
      drawString5x7(20,50, "Sean's Project", COLOR_YELLOW, COLOR_BLACK);
      drawString5x7(20,60, "Is On Fire!", COLOR_ORANGE, COLOR_BLACK);
      siren();
      switch_state_changed = 0;
    }
    toggle_red();
    break;

  case 1:
    if(switch_state_changed)
    {
	buzzer_set_period(0);
	clearScreen(COLOR_BLACK);
	awesomeShape();
	switch_state_changed = 0;
    }
    toggle_green();
    break;

  case 2:
    if(switch_state_changed)
      {
	buzzer_set_period(0);
	clearScreen(COLOR_BLACK);
	classicCoolShape();
	switch_state_changed = 0;
      }
    toggle_red();
    toggle_green();
    break;

  case 3:
    if(switch_state_changed)
      {
	buzzer_set_period(0);
	clearScreen(COLOR_BLACK);
	originalShape();
	switch_state_changed = 0;
      }
    toggle_red();
    toggle_green();
    //dim();
    break;
    //default:
  }
}

// Method to assign the state of the LEDS
void led_state(unsigned char g, unsigned char r) {
  green_on = g;
  red_on = r;
  led_changed = 1;
  led_update();
}


// Method to reset current state of LEDS
void reset_state() {
  red_on = 0;
  green_on = 0;
  led_update();
}

// Method to delay action for specific time
void delay(unsigned int t) {
  unsigned int i;
  for (i = t; i > 0; i--) {
    __delay_cycles(1);
  }
}

// Method to alternate and dim both LEDS
void dim() {
  while (dim_on) {
    unsigned int i;
    for (i = 1; i < 1200; i++) {
      led_state(1,0);
      delay(i);
      led_state(0,1);
      delay(1200-i);
    }
    for (i = 1200; i > 1; i--) {
      led_state(1,0);
      delay(i);
      led_state(0,1);
      delay(1200-i);
    }
  }
}

