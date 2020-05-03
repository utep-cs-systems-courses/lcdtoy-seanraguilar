#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "libTimer.h"
#include "stateMachine.h"
#include "lcddraw.h"
#include "lcdutils.h"


char switch_state_down, switch_state_changed, state, cool_enable, v1, v2, v3, v4;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE = SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  //switch_interrupt_handler();
  //led_update();
}

set_enables(char cool){
  cool_enable = cool;
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  v1 = (p2val & SW1) ? 0 : 1;
  v2 = (p2val & SW2) ? 0 : 1;
  v3 = (p2val & SW3) ? 0 : 1;
  v4 = (p2val & SW4) ? 0 : 1;
  switch_state_changed = 1;
  
  if (v1){ state = 0; set_enables(0); state_advance(); }
  if (v2){ state = 1; set_enables(0); state_advance();}
  if (v3){ state = 2; set_enables(1); state_advance();}
  if (v4){ state = 3; set_enables(0); state_advance();}
  if (!v1 && cool_enable){ state = 1; }
}
