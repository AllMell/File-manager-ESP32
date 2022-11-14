#pragma once

class MENU_LINE{
    public:
        MENU_LINE(){};

        MENU_LINE(uint8_t base_x, uint8_t base_y, uint8_t line_len)
        {
            _base_y = base_x; _base_x = base_y; _line_len = line_len; 
        }

        void virtual Set_dimensions(uint8_t base_x, uint8_t base_y, uint8_t line_len)
        {
            _base_y = base_x; _base_x = base_y; _line_len = line_len;
        }

        void virtual Set_colors(uint16_t color_ink, uint16_t color_paper){
            _color_ink = color_ink; _color_paper = color_paper;
        }

        void virtual Show_const_text(uint8_t str_number, uint8_t line_number){
            _line_number = line_number;
            Clear_text_buffers();            
            strcpy_P(_text_buffer_in, (char*)(str_table[str_number]));
            Weryfi_text_len(_text_buffer_in, _line_len);
            Show();
        }

        void virtual Show_const_text_colorized(uint8_t str_number, uint8_t line_number, uint16_t color_ink, uint16_t color_paper){
            _color_ink = color_ink; 
            _color_paper = color_paper;
            Show_const_text(str_number, line_number);//<-------
        }

        void virtual Show_text(char *text, uint8_t line_number){
            _line_number = line_number;
            Clear_text_buffers();
            Weryfi_text_len(text, _line_len);
            Show();
        }

        void virtual Show_text_colorized(char *text, uint8_t line_number, uint16_t color_ink, uint16_t color_paper){
            _color_ink = color_ink; 
            _color_paper = color_paper;
            Show_text(text, line_number);//<-------
        }

        void virtual Show(){
                LCD_Puts(_text_buffer_out, 8*_base_x, 8 * _base_y * _line_number, _color_ink, _color_paper, 1, 1, 0);
        }

        void virtual Hide_colorized(uint8_t line_number, uint16_t color_paper){
                _color_paper = color_paper;
                //LCD_Puts(_text_buffer_out, 8*_base_x, 8 * _base_y * line_number, _color_paper, _color_paper, 1, 1, 0);
                LCD_FillRect(8*_base_x, 8 * _base_y * line_number, 8 * _line_len, 8, _color_paper);
        }



    private:
        char virtual *Weryfi_text_len(char* text, uint8_t len){
            Clear_text_buffers();
            if(strlen(text) > len){
                strncat(_text_buffer_out, text, len);     
            }else {
                strcpy(_text_buffer_out, text);
                for (int i = 0; i <  (strlen(_text_buffer_out) - len) ; i++) {
                    strcat(_text_buffer_out, " ");
                }  
            }
            return _text_buffer_out;  
        }    

        void Clear_text_buffers(){
            strcpy(_text_buffer_in, "");
            strcpy(_text_buffer_out, "");
        }
        uint8_t _base_x; 
        uint8_t _base_y;
        uint8_t _line_len;
        uint8_t _line_number;
        uint16_t _color_ink;
        uint16_t _color_paper;
        char _text_buffer_in[64];
        char _text_buffer_out[64];
        uint8_t _str_number;
};


