class MENU_LIST_LINE: public MENU_LINE
{
public:

    MENU_LIST_LINE():MENU_LINE(){}
    MENU_LIST_LINE(uint8_t base_x, uint8_t base_y, uint8_t line_len, uint16_t color_ink, uint16_t color_paper):MENU_LINE(base_x, base_y, line_len)
    {
        _line_len = line_len; _color_ink = color_ink; _color_paper = color_paper; 
    }
    
    //void Show_text(char *text, uint8_t line_number){
    //    Show_text_colorized(text, line_number, _color_ink, _color_paper);
    //}

    //void Show_const_text(uint8_t str_number, uint8_t line_number){
    //        Show_const_text_colorized(str_number, line_number, _color_ink, _color_paper);
    //    }

    //void Hide(uint8_t line_number){
    //    Hide_colorized(line_number,_color_paper);
    //}



private:
    uint8_t _line_len;
    uint16_t _color_ink;
    uint16_t _color_paper;
};