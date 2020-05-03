#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
unsigned char dim_on = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

// Initialize LEDS
void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  switch_state_changed = 1;
  led_changed = 1;
  dim_on = 1;
  led_update();
}

// Method for updating and outputing LEDS
void led_update(){
  if (switch_state_changed ){//| led_changed | dim_on) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
  led_changed = 0;
  dim_on = 0;
}
