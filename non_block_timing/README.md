Non-Blocking Timing with Concurrent Tasks on Arduino

Purpose:
This project demonstrates how to manage multiple time-dependent tasks on a resource-constrained MCU without using blocking delays.

Key Concepts Demonstrated:
– Multitasking using millis() instead of delay()
– Independent task timing
– State-based GPIO control

Why This Matters:
Blocking delays prevent responsive systems and don’t scale to real embedded applications.

Design Notes:
Each LED maintains its own timer + state, allowing independent behavior without interrupts or RTOS support.

Limitations:
First time through so limited knowledge base; thoughts about swapping to interrupts or hardware timers in future iterations.
