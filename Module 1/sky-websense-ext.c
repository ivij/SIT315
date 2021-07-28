#include <stdio.h>
#include "dev/button-sensor.h"
#include "dev/sht11-sensor.h"
#include "dev/light-sensor.h"
#include "dev/leds.h"
#include "contiki.h"
PROCESS(send_sensor_info_process, "Print the sensor information");
AUTOSTART_PROCESSES(&send_sensor_info_process);

static int
get_light(void)
{
return 10*light_sensor.value(LIGHT_SENSOR_PHOTOSYNTHETIC)/7;
}

//PROCESS(press_button_process, "Test button");
//AUTOSTART_PROCESSES(&press_button_process);

static uint8_t flag;
PROCESS_THREAD(send_sensor_info_process,ev,data)
{
PROCESS_BEGIN();
flag=0;
SENSORS_ACTIVATE(button_sensor);
while(1)
{
PROCESS_WAIT_EVENT_UNTIL(ev == sensors_event && data == &button_sensor);
leds_toggle(LEDS_ALL);
if(!flag)
{
leds_on(LEDS_BLUE);
SENSORS_ACTIVATE(light_sensor);
printf("Light: %d\n", get_light());
}
else
{
printf("Light: %d\n", get_light());
leds_off(LEDS_BLUE);
SENSORS_DEACTIVATE(light_sensor);
}
flag ^=1;
leds_toggle(LEDS_ALL);
}
PROCESS_END();
}



