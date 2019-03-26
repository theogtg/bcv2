#define SYM_DEBUG 0  //used to turn on/off debug messages in 
                     //symbol table methods
#define TABLE_SIZE 211   //Studies show it should be a prime number
#define MAX_ID_LENGTH 6  //Indicates the maximum number of characters
//to make the id's unique
#ifndef V_TYPE
#define V_TYPE
typedef union {
   int ivalue;
   char cvalue;
   double dvalue;
} VALUE;
#endif
