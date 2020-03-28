#ifndef LEDS_H
#define LEDS_H
typedef enum {OFF, ON, BLINK} led_state_t;
extern void init_leds_task();
extern void choice_led_state (int led, char *led_state, int delay);
#endif