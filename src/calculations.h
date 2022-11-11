#pragma ONCE

void Page_up(){
    current_page_old = current_page; current_page--;
    current_position_in_dir_old = current_position_in_dir; current_position_in_dir--;
    current_position_on_page_old = current_position_on_page; current_position_on_page = MENU_LINES - 1;
}

void Page_down(){
    current_page_old = current_page; current_page++;
    current_position_in_dir_old = current_position_in_dir; current_position_in_dir++;
    current_position_on_page_old = current_position_on_page; current_position_on_page = 0;
}

void Position_up(){
    current_position_in_dir_old = current_position_in_dir; current_position_in_dir--;
    current_position_on_page_old = current_position_on_page; current_position_on_page--;
}

void Position_down(){
    current_position_in_dir_old = current_position_in_dir; current_position_in_dir++;
    current_position_on_page_old = current_position_on_page; current_position_on_page++;
}

void Page_left(){
    current_page_old = current_page; current_page--;
    current_position_in_dir = current_position_in_dir - MENU_LINES;
    current_position_in_dir_old = current_position_in_dir;
}

void Page_right(){
    current_page_old = current_page; current_page++;
    current_position_in_dir = current_position_in_dir + MENU_LINES;
    if(current_position_in_dir > total_files_in_dir){
        current_position_in_dir = total_files_in_dir - 1;
        current_position_on_page = total_files_in_dir % MENU_LINES - 1;
        current_position_on_page_old = current_position_on_page;
    }
    current_position_in_dir_old = current_position_in_dir;
    
}