#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

// Options Of Enable
/*
ENABLE
DISABLE
*/

// Options Of States
/*
LOW_LEVEL 0
ON_CHANGE 1
FALLING_EDGE 2
RISING_EDGE 3
*/

// INT0
#define INT0_ENABLE ENABLE
#define INT0_STATE ON_CHANGE

// INT1
#define INT1_ENABLE DISABLE
#define INT1_STATE RISING_EDGE

// INT2 (Only Falling and Rising Edge Allowed)
#define INT2_ENABLE DISABLE
#define INT2_STATE RISING_EDGE

#endif