#pragma once

#define SCR_WIDTH   131 // display width
#define SCR_HEIGHT  175 // display height
#define SCR_COLUMS  16  // 8x8 text columns (16.5)
#define SCR_LINES   21  // 8x8 text lines



#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4
#define ESCAPE  5
#define SELECT  6
#define START   7
#define BTN_A   8
#define BTN_B   9
#define NO_ONE  0

#define PIN_BAT     35  // pin for ADC read voltage from BAT
#define PIN_BTN_A   25  // pin for btn left (pull up)
#define PIN_BTN_B   26  // pin for btn right (pull up)
#define PIN_BTN_ANALOG  12  // pin for 3 analog btns (1-4095, 2-2700, 3-2000, NC-0)

#define PIN_RES_LEFT_X  32  // pin for left horisontal resistor
#define PIN_RES_LEFT_Y  34  // pin for left vertical resistor
#define PIN_RES_RIGHT_X 27  // pin for right horisontal resistor
#define PIN_RES_RIGHT_Y 33  // pin for right vertical resistor

#define RES_MAP_MIN     -1000
#define RES_MAP_MAX     1000 
#define RES_CENTRE_ZONE 1000

#define BTN_ANALOG_0_1_BORDER   1000    // 0-2000
#define BTN_ANALOG_1_2_BORDER   2350    // 2000-2700
#define BTN_ANALOG_2_3_BORDER   3400    // 2700-4095

#define BTN_ANALOG_PRESSED_NO_ONE   0   //no analog btn pressed
#define BTN_ANALOG_PRESSED_ESCAPE   1   //escape analog btn pressed
#define BTN_ANALOG_PRESSED_SELECT   2   //select analog btn pressed
#define BTN_ANALOG_PRESSED_START    3   //start analog btn pressed

#define BTN_DIGITAL_PRESSED_NO_ONE  0   // no pressed btns

#define ON          1   // for ON
#define OFF         0   // for OFF

#define MODE_START              0
#define MODE_FILE_MANAGER       1
#define MODE_PLAYER             3
#define MODE_MENU               4

#define MODE_ERROR              9

#define OK                      0
#define ERROR_SD_MOUNT_FAILED   1
#define ERROR_NO_SD_MMC_CARD          2
#define ERROR_FAILED_TO_OPEN_DIR      3
#define ERROR_NOT_A_DIR               4

#define MENU_X  0
#define MENU_Y  0
#define MENU_WIDTH  16
#define MENU_HEIGHT 21
#define MENU_LINES 19
#define MENU_LOGO_TEXT  "ZX Player        "
