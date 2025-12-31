# ADC to PWM Control Loop on Arduino

## Overview: This project implements a simple control loop that samples an analog input, applies basic digital filtering, and drives a PWM output, all while operating with non-blocking delays.

## Hardware: Arduino Uno, potentiometer connected to analog input A0, LED with current-limiting resistor connected to PWM pin D9

## System Behavior: An analog voltage from a potentiometer is sampled using the onboard ADC. The sampled data is filtered to reduce noise and scaled to drive a PWM output that controls LED brightness. Sampling and output updates occur periodically using non-blocking timing based on `millis()`.

## Key Concepts Demonstrated:

* Periodic ADC sampling with non-blocking delays
* Timing using millis() instead of delay()
* Simple digital filtering (moving average)
* Scaling between ADC and PWM domains

## Why This Matters: This project demonstrates how time-based sampling and actuation can be implemented predictably on a resource-constrained microcontroller without interrupts or an RTOS.

## Design Notes

* The ADC produces a 10-bit value (0–1023), which is filtered using a moving average to reduce analog noise.
* The averaged value is then scaled to an 8-bit PWM duty cycle (0–255).
* PWM generation runs continuously in hardware, while the duty cycle is updated at the sampling interval.
* Software-driven timing allows additional tasks to be added to the main loop without blocking execution.
