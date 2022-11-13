#include <Arduino.h>
#include "LPH91572.h"
#include "defines.h"
#include "variables.h"
#include "debag.h"
#include "ANALOG_STICK.h"
#include "ANALOG_BATTON.h"
#include "DIGITAL_BATTON.h"
#include "SD_MMC_FS_functions.h"
#include "MENU_LINE.h"
#include "MENU.h"
#include "MENU_LIST_LINE.h"
#include "calculations.h"


MENU File_Manager(MENU_X, MENU_WIDTH, MENU_Y,  MENU_HEIGHT, ZX_BLACK, ZX_WHITE_BR,  ZX_CYAN_BR,  ZX_WHITE, MENU_WIDTH);
//    MENU_LINE Line_Listing[MENU_LINES];
//    MENU_LINE Line_Info_Top;
//    MENU_LINE Line_Info_Bottom;
//    MENU F_Functions;
//        MENU_LINE FF_Delete_File;
//        MENU_LINE FF_Format_SD;
//        MENU_LINE FF_Create_Dir;

ANALOG_STICK Analog_Stick;
ANALOG_BATTON Analog_Batton;
DIGITAL_BATTON Digital_Batton_A(PIN_BTN_A);
DIGITAL_BATTON Digital_Batton_B(PIN_BTN_B);

void setup() {
    Serial.begin(921600);
    pinMode(2, INPUT_PULLUP); //for SD CARD
    pinMode(PIN_BTN_A, INPUT_PULLUP);
	pinMode(PIN_BTN_B, INPUT_PULLUP);
    LCD_init();
    LCD_set_font(SYMBOLS);
    LCD_FillScreen(ZX_WHITE);
}

uint8_t Get_Control(){
    if(Analog_Batton.Get_state() == BTN_ANALOG_PRESSED_ESCAPE)return ESCAPE;
    if(Analog_Batton.Get_state() == BTN_ANALOG_PRESSED_SELECT)return SELECT;
    if(Analog_Batton.Get_state() == BTN_ANALOG_PRESSED_START)return START;
    if(Digital_Batton_A.Get_state())return BTN_A;
    if(Digital_Batton_B.Get_state())return BTN_B;
    if(Analog_Stick.Get_dir_y() == 1)return UP;
    if(Analog_Stick.Get_dir_y() == -1)return DOWN;
    if(Analog_Stick.Get_dir_x() == 1)return RIGHT;
    if(Analog_Stick.Get_dir_x() == -1)return LEFT;
    return NO_ONE;
}

void Error_handler(){log_d("_error_ = %d\n", _error_);
    switch (_error_)
    {
    case ERROR_SD_MOUNT_FAILED:
        Serial.printf("SD Mount Failed");
        LCD_Puts_Shadow((char*)"SD Mount Failed", 0, 21, ZX_RED_BR, 0, 0, 0);
        break;
    case ERROR_NO_SD_MMC_CARD:
        Serial.printf("No SD_MMC card");
        LCD_Puts_Shadow((char*)"No SD_MMC card", 0, 21, ZX_RED_BR, 0, 0, 0);
        break;
    case ERROR_FAILED_TO_OPEN_DIR:
        Serial.println("Failed to open directory");
        LCD_Puts_Shadow((char*)"Failed open dir", 0, 21, ZX_RED_BR, 0, 0, 0);
        break;
    case ERROR_NOT_A_DIR:
        Serial.println("Not a directory");
        break;
    default:
        Serial.printf("Uncnown Error");
        LCD_Puts_Shadow((char*)"Uncnown Error", 0, 21, ZX_RED_BR, 0, 0, 0);
        break;
    }
    delay(3000);
    ESP.restart();
}

void Update_File_Manager(){
    File_Manager.Logo_Line();
    File_Manager.Info_Line_Up();
    for (int i = 0; i < MENU_LINES; i++) { 
        if(i < last_position_on_the_page){ 
            if(i == current_position_on_page){
                File_Manager.Pointer_Line(i);
            } else if (i != current_position_on_page){
                File_Manager.File_Line(i);
            }
        } else if (i >= last_position_on_the_page){
            File_Manager.Empty_Line(i);
        }
    }
    File_Manager.Info_Line_Bottom();
}

void Moove(uint8_t direction){
    switch (direction)
    {
    case UP:    
        if(current_position_on_page == 0 ){
            if(current_position_in_dir == 0)return;
            Page_up();
            List_Dir_Page(SD_MMC, patf, current_page);
            Update_File_Manager();
            return;
        }
        Position_up();
        File_Manager.File_Line(current_position_on_page_old);
        File_Manager.Pointer_Line(current_position_on_page);
        File_Manager.Info_Line_Bottom();
        break;  
    case DOWN:  
        if(current_position_on_page + 1 == last_position_on_the_page){
            if(current_position_in_dir + 1 == total_files_in_dir)return;
            Page_down();
            List_Dir_Page(SD_MMC, patf, current_page);
            Update_File_Manager();
            return;
        }
        Position_down();
        File_Manager.File_Line(current_position_on_page_old);
        File_Manager.Pointer_Line(current_position_on_page);
        File_Manager.Info_Line_Bottom();
        break;
    case LEFT:  
        if(current_page > 0){
            Page_left();
            List_Dir_Page(SD_MMC, patf, current_page);
            Update_File_Manager();
        }
        break;
    case RIGHT: 
        if(current_page + 1 < total_pages_in_dir){
            Page_right();
            List_Dir_Page(SD_MMC, patf, current_page);
            Update_File_Manager();
        }
        break;
    case BTN_A:  
        if(file_type[current_position_on_page] == (char*)"DIR"){

                strcat(patf, file_name[current_position_on_page]);
                List_all_Dir(SD_MMC, file_name[current_position_on_page]);

                List_Dir_Page(SD_MMC, patf, current_page);
        } 
        break;
    case BTN_B:  
        
        break;
    case ESCAPE: 
        
        break;
    case SELECT: 
        
        break;
    case START:  
        
        break;
    
    default:    //если приняли незнакомеое значение
        break;
    }
}      

void File_manager(){
    uint8_t direction = 0;
    uint8_t direction_old = 0;
    if(List_all_Dir(SD_MMC, patf)){//
        _mode_ = MODE_ERROR;//
        return;//
    }
    List_Dir_Page(SD_MMC, patf, current_page);
    Update_File_Manager();
    while (_mode_ = MODE_FILE_MANAGER)
    {
        direction = Get_Control();
        if(direction != direction_old){
            direction_old = direction;
            Moove(direction);
        }
        delay(100);
    }  
}

void loop() {
    switch (_mode_)
    {
    case MODE_START:
        Check_sd();
        break;
    case MODE_FILE_MANAGER:
        File_manager();
        break;
    case MODE_PLAYER:
      
        break;
    case MODE_MENU:

        break;
    case MODE_ERROR:
        Error_handler();
        break;
    }
}

