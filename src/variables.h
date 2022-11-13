#pragma once

char buffer[17];//for messages
const char str_0[] = "                 "; // 17 spaces
const char str_1[] = "";
const char str_2[] = "test";
const char str_3[] = "";
const char str_4[] = "";
const char str_5[] = "";
const char str_6[] = "";
const char str_7[] = "";
const char str_8[] = "";
const char str_9[] = "";
const char str_10[] = "";
const char str_11[] = "";
const char str_12[] = "";
const char str_13[] = "";
const char str_14[] = "";
const char* const str_table[] = {str_0, str_1, str_2, str_3, str_4, str_5, str_6, str_7, str_8, str_9, str_10, str_11, str_12, str_13, str_14};

const uint16_t logo[5][2]= {{ZX_BLACK, ZX_RED_BR},//ZX logo
                            {ZX_RED_BR, ZX_YELLOW_BR},
                            {ZX_YELLOW_BR, ZX_GREEN_BR},
                            {ZX_GREEN_BR, ZX_CYAN_BR},
                            {ZX_CYAN_BR, ZX_BLACK}};

const char *keys[3][4][10] =  {{{"1","2","3","4","5","6","7","8","9","0"},
                                {"Q","W","E","R","T","Y","U","I","O","P"},
                                {"A","S","D","F","G","H","J","K","L","e"},
                                {"c","Z","X","C","V","B","N","M","s"," "}},

                               {{"1","2","3","4","5","6","7","8","9","0"},
                                {"q","w","e","r","t","y","u","i","o","p"},
                                {"a","s","d","f","g","h","j","k","l","E"},
                                {"C","z","x","c","v","b","n","m","S"," "}},

                               {{"!","@","#","$","%","&","'","(",")","_"},
                                {" "," "," ","<",">"," "," "," ",";","\""},
                                {" "," "," "," "," ","^","-","+","=","E"},
                                {"C",":","f","?","/","*",",",".","S"," "}}};




    char file_name[MENU_LINES][64];
    char file_type[MENU_LINES][5];
    uint32_t file_size[MENU_LINES];
    uint16_t file_position_in_dir[MENU_LINES];


//Files_Struct *Files_table = (Files_Struct*)ps_malloc(MENU_LINES_NUMBER_MAX * sizeof(Files_Struct));

//Position
uint16_t last_position_on_the_page = 0;      
uint16_t current_position_on_page = 0;       
uint16_t current_position_on_page_old = 0;   

uint16_t current_position_in_dir = 0;       
uint16_t current_position_in_dir_old = 0;   
uint8_t current_page = 0;                   
uint8_t current_page_old = 0;               
uint16_t total_files_in_dir = 0;            
uint8_t total_pages_in_dir = 0;             
uint16_t current_patf_stack_point = 0;      
uint16_t parent_dir_number = 0;             
uint8_t parent_page_number = 0;             
uint16_t patf_stack[64];
char patf[256] = "/";         


uint8_t _mode_ = MODE_START;
uint8_t _error_ = OK;

uint32_t debug_counter = 0;
