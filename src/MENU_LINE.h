#pragma once

class MENU_LINE{
    public:
        MENU_LINE(){
            _line_y = 0; _line_x = 0; _message_len = 16; _line_len = 17; _color_ink = ZX_BLACK; _color_paper = ZX_WHITE_BR; _font = SYMBOLS;
        }

        MENU_LINE(uint8_t line_y, uint8_t line_x, uint8_t message_len, uint8_t line_len, uint16_t color_ink, uint16_t color_paper, uint8_t font){
            _line_y = line_y; _line_x = line_x; _message_len = message_len; _line_len = line_len;_color_ink = color_ink; _color_paper = color_paper; _font = font;
        }

        void Set(uint8_t line_y, uint8_t line_x, uint8_t message_len, uint8_t line_len, uint16_t color_ink, uint16_t color_paper, uint8_t font){
            _line_y = line_y; _line_x = line_x; _message_len = message_len; _line_len = line_len; _color_ink = color_ink; _color_paper = color_paper; _font = font;
        }

        void Show_const_message(uint8_t str_namber){
            _str_namber = str_namber;
            strcpy(_text_buffer, "");            
            strcpy_P(_text_buffer, (char*)(str_table[_str_namber]));
            Weryfi_text_len(_text_buffer);
            strcpy(_text_buffer, _text_buffer2);
            Show();
        }

        void Show_text(char *text){
            strcpy(_text_buffer, "");
            Weryfi_text_len(text);
            strcpy(_text_buffer, _text_buffer2);
            Show();
        }

        void Weryfi_text_len(char* text){
            strcpy(_text_buffer2, "");
            if(strlen(text) > _message_len){
                strncpy(_text_buffer2, text, _message_len);
                strcat(_text_buffer2, " ");
                return;
            }
            if(strlen(text) <= _message_len){
                strcat(_text_buffer2, text);
                for (int i = 0; i < (strlen(_text_buffer2) - _line_len); i++) {
                    strcat(_text_buffer2, " ");
                }
                return;
            }
            strcat(_text_buffer2, text);
            strcat(_text_buffer2, " ");
            return;
        }

        void Show(){
                _system_font_bufer = LCD_get_font();
                LCD_set_font(_font);
                LCD_Puts(_text_buffer, 8*_line_x, 8*_line_y, _color_ink, _color_paper, 1, 1, 0);
                LCD_set_font(_system_font_bufer);
        }

        void Hide(){
                _system_font_bufer = LCD_get_font();
                LCD_set_font(_font);
                LCD_Puts(_text_buffer, 8*_line_x, 8*_line_y, _color_paper, _color_paper, 1, 1, 0);
                LCD_set_font(_system_font_bufer);
        }

    private:
        
        uint8_t _line_len;
        uint8_t _line_y;
        uint8_t _line_x;
        uint8_t _message_len;
        uint16_t _color_ink;
        uint16_t _color_paper;
        uint8_t _font;
        uint8_t _system_font_bufer;
        char _text_buffer[64];
        char _text_buffer2[64];
        uint8_t _str_namber;
};


