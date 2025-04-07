/**
 * 	@Author	:- Aryan Mahesh Ranjane <ranjanearyan82@gmail.com> 
 * 	
 * 	@project_start_date :- 7/4/25 
 * 	@project_end_date   :- 
 *
 * 	@abstract of the project is give in the readme file about.md 
 * 
 */ 
 
 
 // Header Files 
 #include <stdio.h> 
 #include <wchar.h> 
 #include <locale.h> 
 
 int main(void) 
 { 
	 // Entry point function. 
	 
	 /**
	  * setlocale() -> tells the operating system to read the data_item -> spark_emoji as unicode character
	  * @LC_ALL (parameter) -> is category which affects the program 
	  * @"" *locale -> this is what decides in what locale the entire program will act 
	  *  		   if null or ""(empty string is passed) it selects the systems default locale 
	  *  		   from environment variables
	  *
	  * On the basis of the *local -> we can set the category -> which can be used to decide whether this 
	  * will affect the entire C program functions or some set of functions which are defined in other libraries 
	  */
	 
	  setlocale(LC_ALL,""); 
 	
	 /**
	  * Here spark_emoji is allocated 4 bytes of memory because : 
	  * It uses UTF-8 (unicode 16 bits) as it is above the basic lingual plane 
	  * So the unicode bits will be stored in 4 bytes 
	 */ 
	 wchar_t spark_emoji = 0x1F4A5;				
  	
	 wprintf(L"============= %lc WELCOME TO TYPYING SPEED TEST %lc =================",spark_emoji,spark_emoji);
	
	 return 0; 
 } 
