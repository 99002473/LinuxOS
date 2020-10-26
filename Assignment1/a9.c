
// C implementation of digital clock 
#include <stdio.h> 
#include <time.h> 
  
// driver code 
int main() 
{ 
    time_t sec, value = 1; 
    struct tm* present_time; 
  
    // time in seconds 
    sec = time(NULL); 
  
    // to get current time 
    present_time = localtime(&sec); 
  
    // print time in minutes, 
    // hours and seconds 
    printf("%02d:%02d:%02d", 
           present_time->tm_hour, 
           present_time->tm_min, 
           present_time->tm_sec); 
  
    return 0; 
} 
