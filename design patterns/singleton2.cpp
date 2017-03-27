 #include <iostream.h>                  
                                        
 class GlobalClass {                    
 public:                                
    int  getValue() {                   
       return value_; }                 
    void setValue( int v ) {            
       value_ = v; }                    
    static GlobalClass* inst() {        
       if ( ! globalObj_ )              
          globalObj_ = new GlobalClass; 
       return globalObj_; }             
 protected:                             
    GlobalClass( int v=0 ) {            
       value_ = v; }                    
    ~GlobalClass() { }                  
 private:                               
    int    value_;                      
    static GlobalClass* globalObj_;
 };                                     
                                        
 // Allocating and initializing         
 // GlobalClass's static data member    
 // (the ptr, not a GlobalClass inst)
 GlobalClass*                           
    GlobalClass::globalObj_ = 0;        
                                        
 void foo( void ) {                     
    GlobalClass::inst()->setValue( 1 ); 
    cout << "foo: globalObj is " <<     
       GlobalClass::inst()->getValue()  
       << endl;                         
 }                                      
 void bar( void ) {                     
    GlobalClass::inst()->setValue( 2 ); 
    cout << "bar: globalObj is " <<     
       GlobalClass::inst()->getValue()  
       << endl;                         
 }                                      
 void main( void ) {                    
    cout << "main: globalObj is " <<    
       GlobalClass::inst()->getValue()  
       << endl;                         
    foo();                              
    bar();
 }                                      
 