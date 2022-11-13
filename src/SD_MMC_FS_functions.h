#pragma once

#include <FS.h>
#include <SD_MMC.h>

void Check_sd(){
    if(!SD_MMC.begin("/sdcard",true)){
        _error_ = ERROR_SD_MOUNT_FAILED; _mode_ = MODE_ERROR; return;
    }
    if(SD_MMC.cardType() == CARD_NONE){
        _error_ = ERROR_NO_SD_MMC_CARD; _mode_ = MODE_ERROR; return;
    }
    _mode_= MODE_FILE_MANAGER;
}

bool List_all_Dir(fs::FS &fs, const char * dirname){
    uint16_t counter = 0;//log_d("counter = %d\n", counter);
    File root = fs.open(dirname);
    if(!root){_error_ = ERROR_FAILED_TO_OPEN_DIR; return true;}//log_d("ERROR_FAILED_TO_OPEN_DIR");}
    if(!root.isDirectory()){_error_ = ERROR_NOT_A_DIR; return true;}//log_d("ERROR_NOT_A_DIR");}
    File file = root.openNextFile();
    while(file){
        file = root.openNextFile();
        counter++;
    }
    total_files_in_dir = counter;
    total_pages_in_dir = total_files_in_dir / MENU_LINES;
    if(total_files_in_dir % MENU_LINES > 0) total_pages_in_dir++;
    //log_d("total_files_in_dir = %d\n", total_files_in_dir);log_d("total_pages_in_dir = %d\n", total_pages_in_dir);
    return false;
}

bool List_Dir_Page(fs::FS &fs, const char * dirname, uint8_t page){
    uint16_t counter_pos_in_dir = 0;
    File root = fs.open(patf);
    if(!root){_error_ = ERROR_FAILED_TO_OPEN_DIR; return true;} 
    if(!root.isDirectory()){_error_ = ERROR_NOT_A_DIR; return true;}
    File file; 
    for(uint8_t i = 0; i <= page*MENU_LINES; i++){ 
        file = root.openNextFile();
        counter_pos_in_dir++;
    }

    last_position_on_the_page = 0; 
    for(uint16_t counter = 0 ; counter < MENU_LINES; counter++){ 
        if(!file){
            strcpy(file_name[counter],(char*)"");
            strcpy(file_type[counter],(char*)"");
            file_size[counter] = 0;
            continue;
        }
    //strcspn(str1, str2)Ищет символ symb в строке str и возвращает указатель на последнее совпадение.
    //
        if(file.isDirectory()){
            //strcpy(file_name[counter],file.name());
            strcpy(file_type[counter],(char*)"DIR");     
        } else {
            //strcpy(file_name[counter],file.name());

            file_type[counter],
            file_size[counter] = file.size();
        }
        //log_d("counter =        %d\n", counter);
        //log_d("file_name =      %s\n", file_name[counter]);
        strcpy(file_name[counter],file.name());
        file_position_in_dir[counter] = counter_pos_in_dir;
        counter_pos_in_dir++;
        last_position_on_the_page++;
        file = root.openNextFile();    
    }
    
    return false;
}
