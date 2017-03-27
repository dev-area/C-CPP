 #include <iostream.h>                   
                                         
 class GlobalClass {                     
 public:                                 
    GlobalClass( int v=0 ) {             
       value_ = v; }                     
    int  getValue() {                    
       return value_; }                  
    void setValue( int v ) {             
       value_ = v; }                     
 private:                                
    int  value_;                         
 };                                      
                                         
 // Initializing a global ptr to class   
 // GlobalClass                          
 GlobalClass*   globalObj = 0;           

 void foo( void )                        
 {                                       
    if ( ! globalObj )                   
       globalObj = new GlobalClass;      
    globalObj->setValue( 1 );            
    cout << "foo: globalObj is " <<
       globalObj->getValue() << endl;    
 }                                       
                                         
 void bar( void )                        
 {                                       
    if ( ! globalObj )                   
       globalObj = new GlobalClass;      
    globalObj->setValue( 2 );
    cout << "bar: globalObj is " <<      
       globalObj->getValue() << endl;    
 }                                       
                                         
 void main( void )                       
 {                                       
    if ( ! globalObj )                   
       globalObj = new GlobalClass;
    cout << "main: globalObj is " <<     
       globalObj->getValue() << endl;    
    foo();                               
    bar();                               
 }                                       
