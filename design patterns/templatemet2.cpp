#include <iostream>
#include <string>
using namespace std;

class StandardAlgorithm {
   // 3. Steps requiring peculiar implementations are "placeholders" in base class
   virtual string preprocess( char* ) = 0;
   virtual bool   validate( char )    = 0;
public:
   // 1. Standardize the skeleton of algorithm in base class "template method"
   string process( char* in ) {
      string str = preprocess( in );
      for (int i=0; i < str.size(); i++)
         if ( ! validate( str[i] )) return "not valid";
      return str;
}  };

class Alphabetic : public StandardAlgorithm {
   /*virtual*/ string preprocess( char* in ) {
      string s( in );
      for (int i=0; i < s.size(); i++)
         if (s[i] >= 'A' && s[i] <= 'Z' || s[i] == ' ') /* empty */ ;
         else if (s[i] >= 'a' && s[i] <= 'z')           s[i] = s[i] - 32;
         else                                           s[i] = '_';
      return s;
   }
   /*virtual*/ bool validate( char ch ) {
      if (ch >= 'A' && ch <= 'Z' || ch == ' ') return true;
      else return false;
}  };

class Numeric : public StandardAlgorithm {
   /*virtual*/ string preprocess( char* in ) { return in; }
   /*virtual*/ bool validate( char ch ) {
      if (ch >= '0' && ch <= '9') return true;
      else return false;
}  };

void main( void ) {
   StandardAlgorithm* types[] = { &Alphabetic(), &Numeric() };
   char buf[20];
   while (true) {
      cout << "Input: ";
      cin.getline( buf, 20 );
      if ( ! strcmp( buf, "quit" )) break;
      for (int i=0; i < 2; i++)
         cout << "   " << types[i]->process( buf ) << '\n';
}  }
