# LDR Library Integration Guide

This guide provides instructions on how to integrate the LDR library into your STM32 project using STM32Cube IDE or any other compatible IDE.

## Step 1: Download the library files

Download the following LDR library files:

1. `ldr.h` - The header file containing the function prototypes and necessary definitions.
2. `ldr.c` - The source file containing the function implementations.

## Step 2: Add the library files to your project

Follow these steps to add the LDR library files to your project:

### STM32Cube IDE

1. In STM32Cube IDE, open your STM32 project.
2. Navigate to the project tree in the "Project Explorer" tab.
3. Place the `ldr.h` file into the "Inc" folder (or the folder where header files are stored in your project).
4. Place the `ldr.c` file into the "Src" folder (or the folder where source files are stored in your project).

### Other IDEs

1. Open your STM32 project in the IDE you are using.
2. Place the `ldr.h` file in the folder where header files are stored in your project (usually an "include" or "inc" folder).
3. Place the `ldr.c` file in the folder where source files are stored in your project (usually a "source" or "src" folder).

## Step 3: Include the library header in main.c

In the `main.c` file of your project, add the following include statement at the beginning of the file, along with other include statements:

```c
#include "ldr.h"
```

## Step 4: Initialize the LDR in main.c(sets the calibration constants)

In the`main.c` function of your project, call the `LDR_Init()` function to initialize the LDR:
```c

int main(void)
{
    // Initialize peripherals, system clock, etc.

    // Initialize LDR
    LDR_Init();

    // Other code
}
```

## Step 5: Read analog light intensity in main.c

To read the analog light intensity using the LDR, call the `LDR_ReadAnalogLightIntensity()` function in your code:
```c

int main(void)
{
    // Initialize peripherals, system clock, etc.

    // Initialize LDR
    LDR_Init();

    // Read analog light intensity
    float light_intensity = LDR_ReadAnalogLightIntensity(&hadc);

    // Other code
}

```
Again, `hadc` is a handle to the ADC peripheral that you should have already initialized in your project.
