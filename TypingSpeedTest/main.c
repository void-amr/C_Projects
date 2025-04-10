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
 #include <stdlib.h> 

 /*
  *Function Proto-Type */

 void track_typing_speed(); 
 void user_requests_exit(); 

 int main(void) 
 { 
 	// Entry point function. 
	 
	 /**
	  * setlocale() -> tells the C runtime to read the data_item -> spark_emoji as unicode character
	  * 
	  * @LC_ALL (parameter) -> is category which affects the program 
	  * 
	  * @"" *locale -> this is what decides in what locale the entire program will act 
	  *  		       if null or ""(empty string is passed) it selects the systems default locale 
	  *  		       from environment variables
	  * 
	  *	On the basis of the *local -> we can set the category -> which can be used to decide whether this 
	  * will affect the entire C program functions or some set of functions which are defined in other libraries 
	  */
	 
	  setlocale(LC_CTYPE,""); 
 	
	 /**
	  * Here spark_emoji is allocated 4 bytes of memory because : 
	  * It uses UTF-8 (unicode 16 bits) as it is above the basic lingual plane 
	  * So the unicode bits will be stored in 4 bytes 
	 */ 
	 wchar_t spark_emoji = 0x1F4A5;		
	 wchar_t fire_emoji = 0x1F525; 
 	
	 int user_choice; 

	 //printf("\n"); can't use this function as the locale is updated we need to use the wprintf or related functions to print 
	
	 wprintf(L"\n"); 

	 wprintf(L"============= %lc WELCOME TO TYPYING SPEED TEST %lc =================\n\n",spark_emoji,spark_emoji);
 	 
	 wprintf(L"1] Start test %lc\n", fire_emoji);
	 wprintf(L"2] Exit \n"); 
	
	 scanf("%d",&user_choice);

	 if(user_choice == 1) {
		 track_typing_speed(); 
	 } 
	 else if(user_choice == 2) {
		 user_requests_exit(); 
	 } 
	 else {
		 printf("Invalid option: Please Enter again");
	 } 

	 return 0;
 }
  
 void track_typing_speed() 
 {
	char u_c;
/*
	wprintf(L"\n\nWelcome to TypingSpeedTest Checker:");
	wprintf(L"Want to know how does this work ?\n");
	wprintf(L"Press [Y/N] yes to continue,\nNo to start the test immediately"); 
*/ 
	wprintf(L"Enter your choice:"); 
	u_c = getchar();

	wprintf(L"\nReading some data");
	wprintf(L"%c",u_c);
	wprintf(L"Line wil be printed if it's taking new line as input");
	

/*	if(user_choice == 'y' || user_choice == 'Y') {
		wprintf(L"Opening docs wait...."); 
	} else if (user_choice == 'n' || user_choice == 'N') {
	char string_reference [] = "SQLite is a lightweight, serverless, self-contained, and zero-configuration database engine that is widely used in                                          Android for local data storage. It is embedded into Android applications and does not require a separate server or                                          network connection to function. SQLite is a relational database, meaning it stores data in tables and supports SQL                                          queries to perform CRUD (Create, Read, Update, Delete) operations.";
	wprintf(L"%s", string_reference);
	} else {
		wprintf(L"Invalid Option: Please enter valid one");
	}
*/ 
} 
 /**
  * 	Function Definition
  *
  * function_identifier	:- user_requests_exit
  * function_parameter	:- void (nothing) 
  * function_return_type:- void 
  *
  * abstract :- 
  *
  * 	This function while make sure that if the user enters the option of exit in the program they will 
  * 	be exited of the terminal from the program execution 
  **/ 
 
  void user_requests_exit()
  {
	  wprintf(L"Exiting.."); 
	  exit(0); 
  }	
