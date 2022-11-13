#pragma ONCE
/*
log_d(" = %d\n", );
log_d(" = %s\n", );
log_d("RUN!\n");
*/

//Debag();

void Debag(){
log_d("RUN!\n");
log_d("================================================================================ #: %d\n", debug_counter);
log_d("file_name =                  %s\n", file_name[current_position_on_page]);
log_d("file_type =                  %s\n", file_type[current_position_on_page]);
//log_d("file_size = %d\n", file_size[current_position_on_page]);
log_d("file_position_in_dir =       %d\n", file_position_in_dir[current_position_on_page]);

log_d("last_position_on_the_page =  %d\n", last_position_on_the_page);
log_d("current_position_on_page =   %d\n", current_position_on_page);
//log_d("current_position_on_page_old = %d\n", current_position_on_page_old);
log_d("current_position_in_dir =    %d\n", current_position_in_dir);
//log_d("current_position_in_dir_old = %d\n", current_position_in_dir_old);
log_d("current_page =               %d\n", current_page);
//log_d("current_page_old = %d\n", current_page_old);
log_d("total_files_in_dir =         %d\n", total_files_in_dir);
log_d("total_pages_in_dir =         %d\n", total_pages_in_dir);
//log_d("current_patf_stack_point = %d\n", current_patf_stack_point);
//log_d("parent_dir_namber = %d\n", parent_dir_namber);
//log_d("parent_page_namber = %d\n", parent_page_namber);
//log_d("patf_stack = %d\n", patf_stack[current_patf_stack_point]);
//log_d("_mode_ = %d\n", _mode_);
log_d("_error_ = %d\n", _error_);
//log_d("patf = %s\n", patf);       

log_d("---------\n");
log_d("Total heap : %dB\n", ESP.getHeapSize());
log_d("Free heap  : %dB\n", ESP.getFreeHeap());
log_d("Total PSRAM: %dB\n", ESP.getPsramSize());
log_d("Free PSRAM : %dB\n", ESP.getFreePsram());
debug_counter++;
}

             


