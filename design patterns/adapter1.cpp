#include<iostream.h>
#include<time.h>
#include<string.h>
#include<stdio.h>

class ManlyTime {                      
public:                                
   char* getTime() {                   
      static char buf[30];             
      time_t  lt;                      
      tm*     ltStruct;                
      time( &lt );                     
      ltStruct = localtime(&lt);
      strftime( buf, 30, "%H%M",       
         ltStruct );                   
      return buf;                      
   }                                   
};                                     
                                       
class WimpyTime {                      
public:                                
   char* getTime() {                   
      static char buf[30];             
      char *ptr, mi[3], am[3];         
      int  hr;                         
      ptr = imp_.getTime();            
      cout << "old interface time is " 
         << ptr << endl;               
      strcpy( mi, &(ptr[2]) );         
      ptr[2] = '\0';                   
      sscanf( ptr, "%d", &hr );        
      strcpy( am, "AM" );              
      if (hr > 12) {                   
         hr -= 12;                     
         strcpy( am, "PM" ); }         
      sprintf( buf, "%d:%s %s",
         hr, mi, am );                 
      return buf;                      
   }                                   
private:                               
   ManlyTime  imp_;                    
};                                     
                                       
void main( void )                      
{
   WimpyTime  newT;                    
   char*      ptr;                     
   ptr = newT.getTime();
   cout << "new interface time is "
      << ptr << endl;
}

