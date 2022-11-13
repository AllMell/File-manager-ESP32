#pragma once

class MENU{
    public:
        MENU(){
            _menu_x = MENU_X; _menu_width = MENU_WIDTH; _menu_y = MENU_Y; _menu_height = MENU_HEIGHT; _menu_color_ink = ZX_BLACK; 
            _menu_color_paper = ZX_WHITE_BR; uint16_t _menu_color_select_paper = ZX_CYAN_BR; _menu_color_back = ZX_WHITE;
            _menu_line_len = MENU_WIDTH;
        }
        MENU(uint8_t menu_x, uint8_t menu_width, uint8_t menu_y, uint8_t menu_height, uint16_t menu_color_ink,
        uint16_t menu_color_paper, uint16_t menu_color_select_paper, uint16_t menu_color_back, uint8_t menu_line_len)
        {
            _menu_x = menu_x; _menu_width = menu_width; _menu_y = menu_y; _menu_height = menu_height;  _menu_color_ink = menu_color_ink;
            _menu_color_paper = menu_color_paper; _menu_color_select_paper = menu_color_select_paper; _menu_color_back = _menu_color_back;
            _menu_line_len = menu_line_len;
        }
        void Set(uint8_t menu_x, uint8_t menu_width, uint8_t menu_y, uint8_t menu_height,  uint16_t menu_color_ink, 
        uint16_t menu_color_paper, uint16_t menu_color_select_paper, uint16_t menu_color_back, uint8_t menu_line_len)
        {
            _menu_x = menu_x; _menu_width = menu_width; _menu_y = menu_y; _menu_height = menu_height; _menu_color_ink = menu_color_ink;
            _menu_color_paper = menu_color_paper; _menu_color_select_paper = menu_color_select_paper; _menu_color_back = _menu_color_back;
            _menu_line_len = menu_line_len;
        }



        
        
        void Logo_Line(){
            
            LCD_Puts((char*)MENU_LOGO_TEXT, 8*_menu_x , 8*_menu_y, ZX_WHITE_BR, ZX_BLACK, 1, 1, 0);
            for (int i = 0; i < 5; i++) {
                LCD_Putchar( 255, 8*(10 +i) + 4, 0, logo[i][0], logo[i][1], 1, 1, 0);//не подстраивается под размеры окна. доработать по необходимости
            }
        }
       
        void File_Line(uint8_t line_number){
            //Weryfi_text_len(file_name[line_number], _menu_line_len);
            //LCD_Puts(_text_buffer2, 8*_menu_x, 8*(_menu_y + line_number + 2), _menu_color_ink, _menu_color_paper, 1, 1, 0);   
            
            LCD_Puts(Weryfi_text_len(file_name[line_number], _menu_line_len), 8*_menu_x, 8*(_menu_y + line_number + 2), _menu_color_ink, _menu_color_paper, 1, 1, 0);  
        }
        
        void Pointer_Line(uint8_t line_number){
            Debag();
            //Weryfi_text_len(file_name[line_number], _menu_line_len);
            //LCD_Puts(_text_buffer2, 8*_menu_x, 8*(_menu_y + line_number + 2), _menu_color_ink, ZX_CYAN_BR, 1, 1, 0);//log_d("point on name: %s\n", file_name[line_number]); log_d("color =  %d\n", _menu_color_select_paper);
            
            LCD_Puts(Weryfi_text_len(file_name[line_number], _menu_line_len), 8*_menu_x, 8*(_menu_y + line_number + 2), _menu_color_ink, ZX_CYAN_BR, 1, 1, 0);//log_d("point on name: %s\n", file_name[line_number]); log_d("color =  %d\n", _menu_color_select_paper);
        }
        
        void Empty_Line(uint8_t line_number){
           
            LCD_Puts((char*)"                 ", 8*_menu_x, 8*(_menu_y + line_number + 2), _menu_color_back, _menu_color_back, 1, 1, 0);
        }
        
        void Info_Line_Up(){
            
            LCD_Puts((char*)patf, 8*_menu_x, 8*(_menu_y + 1), _menu_color_ink, _menu_color_back, 1, 1, 0); 
        }

        void Scroll_bar(uint8_t current_page){

        } 

        void Info_Line_Bottom(){
            strcpy(_text_buffer, "");
            strcpy(_text_buffer3, "");
            itoa (current_position_in_dir + 1, (char*)_text_buffer , 10);
            strcat(_text_buffer, (char*)"/");
            itoa (total_files_in_dir, (char*)_text_buffer2 , 10);
            strcat(_text_buffer, _text_buffer2);
            strcat(_text_buffer, (char*)"  ");
            //Weryfi_text_len(_text_buffer, _menu_line_len);
            LCD_Puts((char*)_text_buffer, 8*_menu_x, 8*(_menu_height), _menu_color_ink, _menu_color_back, 1, 1, 0);         
        }

    private:
        
        char *Weryfi_text_len(char* text, uint8_t len){
            strcpy(_text_buffer, "");//log_d("_text_buffer clear = %s\n", _text_buffer);
            strcpy(_text_buffer2, "");//log_d("_text_buffer2 clear= %s\n", _text_buffer2);
            if(strlen(text) > len){
                strncat(_text_buffer2, text, len); //log_d("_text_buffer2 = %s\n", _text_buffer2); log_d("text = %s\n", text); log_d(" menu_len_line = %d\n", _menu_line_len);
                //strcat(_text_buffer2, " ");//log_d("+ \n");
                //strncpy(_text_buffer2, _text_buffer3, _menu_line_len);
                //return;  
            }else {
                strcpy(_text_buffer2, text);
                for (int i = 0; i <  (strlen(_text_buffer2) - len) ; i++) {
                    strcat(_text_buffer2, " ");
                }
            }
            return _text_buffer2;
        }
        
        uint8_t _menu_x;
        uint8_t _menu_width;
        uint8_t _menu_y;
        uint8_t _menu_height;
        uint16_t _menu_color_ink;
        uint16_t _menu_color_paper;
        uint16_t _menu_color_select_paper;
        uint16_t _menu_color_back;
        uint8_t _menu_line_len;
        char _text_buffer[64];
        char _text_buffer2[64];
        char _text_buffer3[64];
        
};
