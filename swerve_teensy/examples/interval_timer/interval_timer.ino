/* @file interval_timer.ino
 * @brief Example on how to use interval timers on Teensy 3.6
 * @author Frederick Wachter - wachterfreddy@gmail.com
 * @date Created: 2017-12-20
 */

// Variable Definitions
IntervalTimer interval_timer; /*<< timer object */

volatile unsigned long counter; /*<< counter object, volatile to allow for use in interrupt */
int interval_timer_exec = 1000; /*<< timer execution rate in microseconds */

// Function Definitions
void counterCallback(void);

void setup() {
  Serial.begin(115200);
  
  interval_timer.begin(counterCallback, interval_timer_exec);
}

void loop() {
  unsigned long counter_copy;
  
  noInterrupts(); // block interrupt calls during assignment
  counter_copy = counter;
  interrupts(); // allow interrupt calls after assignment
  
  Serial.println(counter_copy);
  delay(100);
}

void counterCallback(void) {
  counter++;
}



