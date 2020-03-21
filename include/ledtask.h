#ifndef LEDTASK_H
#define LEDTASK_H
typedef enum {OFF, ON, BLINK} led_state_t;
extern void init_leds_task();
extern void change_led_state(int led, char *param);
extern void blink_led(int led, int delay);
#endif