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
	  * setlocale() -> installs the new locale and makes the execution influnced based on the specified locale by default uses C locale. 
	  * 
	  * @LC_ALL (parameter) -> is category which affects the locale sensitive functions C-type here means all the functions used to manipulate
	  * 			   character type will be influenced and executed based on new locale. 
	  * 
	  * @"" *locale -> this is what decides in what locale the entire program will act 
	  *  		       if null or ""(empty string is passed) it selects the user's system default locale 
	  * 
	  * On the basis of the *local -> we can set the category -> which can be used to decide whether this 
	  * will affect the entire C program functions or some set of functions which are defined in C libraries 
	  *
	  * The program starts up with execution of setlocale(LC_ALL,"C") as it's default locale. 
	  * Later the manipulation of locale changes the locale. 
	  */
	 
	  setlocale(LC_CTYPE,""); 
 	
	 /**
	  * Here spark_emoji is allocated 4 bytes of memory because the program is compiled on linux
	  * If the program was to be compiled on windows. It would've allocated 2 bytes to wchar_t  
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
		wprintf(L"Invalid option: Please Enter again");
	 } 

	 return 0;
 }

/**
 * 	Function definition 
 * 
 * function_identifier	:- track_typing_speed 
 * function_paramters	:- none 
 * function_return_type	:- void 
 *
 * abstract :- 
 * 		This function is the actual worker which tracks down the time required by user to complete the 
 * 		typing test. This function is modular and can be altered based on needs. 
 */ 
  
 void track_typing_speed() 
 {
	 char u_c;
	//short u_c; 

	wprintf(L"\nWelcome to TypingSpeedTest Checker:\n");
	wprintf(L"______________________________________\n\n");
	wprintf(L"Want to know how does this work ?\n======================================\n");
	wprintf(L"Press [Y] to continue\n");
	wprintf(L"Press [N] to start the test immediately\n");
 
	wprintf(L"Enter your choice: "); 
	scanf(" %c", &u_c);  
	wprintf(L"\n");

	if(u_c == 'y' || u_c == 'Y') {
		wprintf(L"Opening docs wait...."); 
	} 
	else if (u_c == 'n' || u_c == 'N') {
		wprintf(L"Start typing once you're ready don't worry timer will start counting once your start typing.\n\n");
		wprintf(L"------------------------------------------------------------------------------------------------\n\n");
		char string_reference []= {
			"The sun was shining brightly in the clear blue sky. Birds were singing their sweet melodies from the trees. A gentle breeze rustled through the leaves, creating a soothing sound. It was a perfect day to go for a walk in the park. The smell of fresh grass filled the air as children played happily on the swings."
		};
 
		/**
		 * size_of_reference_data -> Integer type 
		 *
		 * Used in Calculating the size of vla -> string_reference 
		 * This let's us change the size of string_reference (data_item) 
		 * without havin to worry to manually set the character array size to read and store what user types 
		 */ 
		const int size_of_reference_data = sizeof(string_reference);

		char input_reference[size_of_reference_data]; 
/* 
		wprintf(L"%ld\n", sizeof string_reference);
		wprintf(L"%ld", sizeof input_reference);
*/ 
		wprintf(L"%s\n==========================================================================================================================\n", 			    string_reference);  
		
		/**
		 * 	So I tried doing this space thing as well 
		 *	
		 *	scanf(" %[^ ]");
		 *		
		 *	Here ^ -> negate character ignores the characters mentioned in the sequence and reads everything 
		 *	except space but the question is i
		 */ 

		for(int le = 0; (input_reference[le] = getchar()) != '\n'; le++) {
			// clear the buffer.
			/**
			 * 	At times what happens is, The previous inputs character like new line or some misc character 
			 * 	is feed to the buffer of our new input. 
			 * 	So stdin fills the misc data to the memory. 
			 * 
			 * 	To avoid new line feed to fill our new memory we perform this for loop to clear the buffer by doing nothing. 
			 */ 
		} 

		/* counter keeps track of number of character entered */ 
		int counter; 
 
		for(int le = 0; (input_reference[le] = getchar()) != '\n'; le++) {
			counter++; 
		}

		wprintf(L"\n %s \n counter: %d ",input_reference,counter);

		int character_per_minute = counter/1; 
		int word_per_minute = character_per_minute/5; 
		
		wprintf(L"\n\n=========================Generating reports===========================\n\n");
		
		wprintf(L"Character per minute -> %d\n", character_per_minute);
		wprintf(L"Words per minute-> %d", word_per_minute);
	} 	
	else {
		wprintf(L"Invalid Option: Please enter valid option");
	} 
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
  * 	be exited of the terminal from the program execution. 
  **/ 
 
  void user_requests_exit()
  {
	  wprintf(L"Exiting.."); 
	  exit(0); 
  }	
