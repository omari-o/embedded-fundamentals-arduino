**Non-Blocking Timing with Concurrent Tasks on Arduino**

**Overview:**
This project demonstrates how to manage multiple time-dependent tasks on a resource-constrained microcontroller without using blocking delays. Each task operates independently while sharing the main execution loop

**Hardware:** Arduino Uno, two LEDs with current limiting resistors

**Key Concepts Demonstrated:**
– Multitasking using millis() instead of delay()
– Independent task timing and state management
– State-based GPIO control

**Why This Matters:**
Blocking delays prevent responsive systems and don’t scale to real embedded applications.

**Design Notes:**
Each LED maintains its own timer + state, allowing independent behavior without interrupts or RTOS support, although it does poll the elapsed time each trip through the main loop

**Limitations/Future Work:**
- Timing precision is limited by millis() and loop execution times
- Future iterations could explore swapping to interrupts or hardware timers.
