/*
Copyright (C) Samuel Ginsberg 2004
Porting to STM32F0 dev board by James Gowans, 2014
LCD lines are as follows:
LCD_RS = PC14
LCD_E = PC15
LCD_D4 = PB8
LCD_D5 = PB9
LCD_D6 = PA12
LCD_D7 = PA15
*/

#include "lcd_stm32f0.h"

enum TypeOfCharacter {
  COMMAND = 0,
  TEXT = 1
};


static void delay (uint32_t microseconds);
static void pulse_strobe (void);
static void lcd_put (uint8_t character, enum TypeOfCharacter ch_type);
static void lcd_write4bits(uint8_t value);

//============================================================================

void lcd_string(uint8_t *string_to_print) {
  uint32_t count=0;
  while (string_to_print[count] != 0) {
    lcd_put (string_to_print[count], TEXT);
    delay(43); // a DRAM write requires at least 43 us execution time
    count++;
  }
}
void lcd_two_line_write(uint8_t* line1, uint8_t* line2) {
  lcd_command(LCD_CLEAR_DISPLAY);
  lcd_string(line1);
  lcd_command(LCD_GOTO_LINE_2);
  lcd_string(line2);
}

//============================================================================

void lcd_init () {
  /*This function sets up the port lines for the LCD and initializes
  the LCD module for use.*/
  // set the relevant pins to outputs
  RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN; 
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; 
  GPIOC->MODER |= GPIO_MODER_MODER14_0;
  GPIOC->MODER |= GPIO_MODER_MODER15_0;
  GPIOB->MODER |= GPIO_MODER_MODER8_0;
  GPIOB->MODER |= GPIO_MODER_MODER9_0;
  GPIOA->MODER |= GPIO_MODER_MODER12_0;
  GPIOA->MODER |= GPIO_MODER_MODER15_0;

  delay(30000); //allow the LCD 30 ms power up time
  // in case in 2nd nibble of 4 bit tansfer, this goes to 1st nibble
  // if byte in 8-bit mode, keeps in 8-bit mode
  lcd_write4bits(0x03);   
  delay(4100);
  lcd_write4bits(0x03);  // garanteed to be byte of 8-bit data for first byte of 4-bit.
  delay(39);
  lcd_write4bits(0x03); // necessary in case this is the 2nd nibble of 4-bit transfer.
  delay(39);
  // switch to 4-bit. This will latch in a byte as it's garanteed to now be in 8-bit
  lcd_write4bits(0x02);   
  delay(39);
  lcd_command(LCD_FOUR_BIT_TWO_LINE_MODE); //0x28
  lcd_command(LCD_DISPLAY_OFF); // 0x08
  lcd_command(LCD_CLEAR_DISPLAY); // 0x01
  lcd_command(LCD_DISPLAY_ON); // 0x0C
}

//============================================================================

void lcd_command (enum LcdCommand command) {
  //This function sends a command to the LCD. 
  //Care is taken not to interfere with the other lines on the port.
  lcd_put((uint8_t)command, COMMAND);
  delay(1530); // 1.53 ms is the maximum delay we should need for any command.
  // TODO: fix the above to have variable lengths as required by different commands.
}

//============================================================================

static void lcd_put (uint8_t character, enum TypeOfCharacter ch_type) {
    //Puts a single character on the LCD at the next position on the screen.
    //The character to be printed is in the input parameter. For numbers, letters 
    //and other common characters the ASCII code will produce correct display.
    //Refer to the Hitachi HD44780 datasheet for full character set information.
    if (ch_type == TEXT) {
        GPIOC->BSRR |= GPIO_BSRR_BS_14;// pull RS (PC14) high
    } else if (ch_type == COMMAND) {
        GPIOC->BSRR |= GPIO_BSRR_BR_14;// pull RS (PC14) low
    }
    // write upper nibble
    lcd_write4bits(character >> 4);
    // write lower nibble
    lcd_write4bits(character);
}

// This function outputs the lower 4 bits onto the data lines
static void lcd_write4bits(uint8_t character) {
  // lower nibble to data lines
  if ((character & 0x08) != 0) {
    GPIOA->BSRR |= GPIO_BSRR_BS_15;
  } else {
    GPIOA->BSRR |= GPIO_BSRR_BR_15;
  }
  if ((character & 0x04) != 0) {
    GPIOA->BSRR |= GPIO_BSRR_BS_12;
  } else {
    GPIOA->BSRR |= GPIO_BSRR_BR_12;
  }
  if ((character & 0x02) != 0) {
    GPIOB->BSRR |= GPIO_BSRR_BS_9;
  } else {
    GPIOB->BSRR |= GPIO_BSRR_BR_9;
  } 
  if ((character & 0x01) != 0) {
    GPIOB->BSRR |= GPIO_BSRR_BS_8;
  } else {
    GPIOB->BSRR |= GPIO_BSRR_BR_8;
  }
  pulse_strobe ();
}

//============================================================================


static void delay(uint32_t microseconds) {
  /* Hangs for specified number of microseconds. */
  volatile uint32_t counter = 0;
  microseconds *= 3;
  for(; counter<microseconds; counter++) {
    __asm("nop");
    __asm("nop");
  }
}

static void pulse_strobe (void) {
  //Pulse the strobe line of the LCD to indicate that data is ready.
  delay(1);
  GPIOC->BSRR |= GPIO_BSRR_BS_15;// pull E (PC15) high
  delay(1);
  GPIOC->BSRR |= GPIO_BSRR_BR_15;// pull E (PC15) low
  delay(1);
}                     

//============================================================================
