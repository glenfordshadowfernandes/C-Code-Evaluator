/*
 *   Author:             1.Glenford 
 *                       2.Diker
 *                                      
 *   Purpose:            Evaluating a 'c' program..
 *   Date:               20/09/2010
 *   Date Modified:      21/10/2010                                                
 */ 

#define len 30

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int checkc(char str[]);
int comment_check(char str[]);
int executer(char str[],float *user_exe, float *exe2);
int indentation(char str[], int *t_braces);
int doc_check(char str[]);
int modula(char str[]);
int line_count(char str[]);



int float_valid(char str[]);
char get_response();

int hold_exe_check=0;

struct data{
	int rollno;
	char name[len];
	float d_doc,d_comm,d_indent,d_modula,d_logic,d_exe,d_total,d_upon;
};

int main(void)
{
	char back, single_ch;
	int menu_option,ln,pass_flag=0;
	char usr[len]="a";
	//char usr[len]="Teacher_Jyoti";
	char get_usr[len],get_pass[len];
	char pass_string[len],ch,name_str[len];
	char curr_pass[len],new_pass[len],conf_pass[len];
	int new_pass_length;
	
	char eval_res;
	int start_eval_option;
	
	typedef struct data data1;
	data1 details;
	
	float user_exe1,user_logic1;
	char user_logic[len];
	//exe2 = &exe;
	int hold_comm, hold_doc, hold_indent, hold_modula, hold_lines, hold_exe;
	float doc_marks, comm_marks, indent_marks, modula_marks, logic_marks, exe_marks=0, sum_marks,final_marks=0;
	//system("clear");
	char answer,ow_ans,re_run,display_option,input_file_option=0,display_return,menu_return,logic_option,logic_option_res,up_logic_choice;
	
	char total_marks[len], doc[len], comm[len], indent[len], modu[len], logic[len], exe[len];
	int flag_int,press_one, next_menu_option, roll_not_exist=0,display_menu_option=0,view_result_choice=0,user_logic_valid,count_braces=0;
	
	int temp, eval_comm_flag=0,invalid_option_flag=0;
	float total_marks1=0, doc1=0, comm1=0, indent1=0, modu1=0, logic1=0, exe1=0, total_sum1=0;
	int total_marks_flag=0, doc_flag=0, comm_flag=0, indent_flag=0, modu_flag=0, exe_flag=0,logic_flag=0,hold_logic_flag=0,menu_return_flag=0;
	char total_marks_res, doc_res, comm_res, indent_res, modu_res, exe_res, logic_res,up_logic_res,user_logic_res,user_logic1_res,user_man_res;
	
	char source_file[15], valid_file_res, e_answer, start_eval_res,view_eval_res,menu_next_res,exit_display_menu_res,invalid_menu_res;
	char input_file_res,exit_res,exit_menu_res,pass_res,new_pass_length_res,user_manual_option,user_manual_return;
        int get_valid_file=0, f_flag=0, e_flag, re_eflag=0,re_run_flag=0,go_to_menu_flag=0,res_no_flag=0,new_pass_length_flag=0,logic_menu_flag=0;
     //   float user_exe;
        void wait ( double seconds )
        {
          clock_t endwait;
          endwait = clock () + seconds * CLOCKS_PER_SEC ;
          while (clock() < endwait) {}
        }
	
	FILE *file_pointer;
	FILE *fpp;
	FILE *fprn;
	FILE *fp_logic;
	
	do
	{
	  back='\0';
  	  system("clear");
	
	  printf("(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)\n\n");

	  printf("**********************************************************   WELCOME TO 'C' PROGRAM EVALUATOR  ************************************************************\n\n\n");
          printf("        MENU (Choose option)\n");
	  printf("      ------------------------\n\n");
	  printf("        1 -> Login\n\n");
	  printf("        2 -> User Manual\n\n");
	  printf("        3 -> Change Password\n\n");
	  printf("        4 -> Quit\n\n");
  	  printf("        Enter your option: ");
	  scanf("%d",&menu_option);
	  if(menu_option==1)
	  {
	    header();
	    printf("        USER AUTHENTICATION\n");
   	    printf("      -----------------------\n");
            do
	    {
	      strcmp(get_usr,usr)==0;
	      printf("\n	User Name: ");
	      scanf("%s", get_usr);
	      if((strcmp(get_usr,usr)==1))
	      {
		printf("\n\n        'Invalid' User name. Do you want to re-enter User name? ---- Press 'Y' -> Yes (or) 'N' -> No\n");
		get_response();
              }
				
	    }while((strcmp(get_usr,usr)==1));
	    do
	    {	
	      pass_flag=0;
	      printf("\n	Password: ");
	      scanf("%s", get_pass);
	      fpp=fopen("pass.txt","r");
	      fgets(pass_string, 5, fpp);
	      if(!(strcmp(get_pass,pass_string)==0))
	      {
		printf("\n\n        'Invalid' Password. Do you want to re-enter Password? ---- Press 'Y' -> Yes (or) 'N' -> No\n");	
		get_response();
		pass_flag=1;
	      }
	      else
	      {
		pass_flag=0;
	      }
	      fclose(fpp);
					
	    }while(!(strcmp(get_pass,pass_string)==0));
	    header();
	    printf("\n       'AUTHENTICATION ACCEPTED'");
	    printf("\n\n        Press '1' to start evaluation proccess\n");
	    do
	    {
	      eval_res=='\0';
	      printf("\n        Enter here: ");
	      scanf("%d", &start_eval_option);
	      if(start_eval_option!=1)
	      {
		printf("\n\n        'Invalid' option, Do you want to re-enter the option? ---- Press 'Y'-> Yes   'N'-> No");
		eval_res = get_response();		
	      }
	      if(start_eval_option==1)
	      {
		break;
	      }
	    }while(eval_res=='Y'||eval_res=='y');
	    /*
	    do
	    {
	      re_run_flag=0;
	      do
	      {
	        header();
	        ow_ans = '\0';
		printf("\n        Enter the student Roll no: ");
		scanf("%d",&details.rollno);
		temp = details.rollno;
		
		if((fprn = fopen("report.txt","rb")) == NULL)
		{
		  printf(" Cannot open file");
		}
		while((fread(&details,sizeof(details),1,fprn)) == 1)
		{
		  if(ow_ans=='n' || ow_ans=='N')
		  {
		    break;
		  }
	    	  if(temp==details.rollno)
		  {
		    printf("\n\n       'Warning' Entered Roll no already exists!  Do you want to overwrite? ---- press 'y'-> yes    'N'-> No\n");
		    ow_ans=get_response();
		    break;
		  }			
		  else
		  {
	            roll_not_exist=1;
	            break;
		  }
		} 
		if(ow_ans=='y' || ow_ans=='Y')
		{		
		  break;
		}
		//break;
		if(roll_not_exist==1)
		{	
		  break;
		}
	      }while(ow_ans=='n' || ow_ans== 'N');*/
	      do
	      {	
	        header();		
		printf("\n\n    INPUTING MARKS ON WHICH EVALUATION TO BE DONE.");	//input grade marks.
		printf("\n    ----------------------------------------------");
		do
		{
		  printf("\n\n  -How much marks do you want to assign for this 'C' Program?");
		  printf("\n  -Enter here: ");
		  scanf("%s", total_marks);	// Reading the total marks.
		  total_marks_flag=float_valid(total_marks);
		  total_marks1=atof(total_marks);
		  if(total_marks_flag==1)
		  {
		    invalid_msg();
		    total_marks_res=get_response();
		  }
		  else
		  {
		    break;
		  }				
		}while(total_marks_res == 'y' || total_marks_res == 'Y');
	        printf("\n  -And How do you want to divide these marks for each following categories?");
	        printf("\n\n    Enter the marks below:");
		printf("\n    -----------------------");
		do
		{
		  printf("\n    1 -Documentaion:     ");
		  scanf("%s", doc);				// input marks for documantaion.
		  doc_flag=float_valid(doc);
		  doc1=atof(doc);
		  if(doc_flag==1)
		  {
		    invalid_msg();
		    doc_res=get_response();
		  }
		  else
		  {
		    break;
		  }				
		}while(doc_res == 'y' || doc_res == 'Y');
		do
		{
		  printf("\n    2 -Comments:         ");
		  scanf("%s", comm);   				// comments
		  comm_flag=float_valid(comm);
		  comm1=atof(comm);
		  if(comm_flag==1)
		  {
		    invalid_msg();
		    comm_res=get_response();
		  }
		  else
		  {
		    break;
	    	  }	
		}while(comm_res == 'y' || comm_res == 'Y');
		do
		{
		  printf("\n    3 -Indentation:      ");		
		  scanf("%s", indent);				// Indentation
	          indent_flag=float_valid(indent);
		  indent1=atof(indent);
		  if(indent_flag==1)
		  {
		    invalid_msg();
		    indent_res=get_response();
		  }
		  else
		  {
		    break;
		  }			
	        }while(indent_res == 'y' || indent_res == 'Y');
		do
		{
		  printf("\n    4 -Modularity:       ");
		  scanf("%s", modu);				// Modularity
		  modu_flag=float_valid(modu);
		  modu1=atof(modu);
		  if(modu_flag==1)
		  {
		    invalid_msg();
		    modu_res=get_response();
		  }
		  else 
		  {
		    break;
		  }
		}while(modu_res == 'y' || modu_res == 'Y');
		do
		{
		  printf("\n    5 -Logic:            ");
		  scanf("%s", logic);				// Logic
		  logic_flag=float_valid(logic);
		  logic1=atof(logic);
		  if(logic_flag==1)
		  {
		    invalid_msg();
		    logic_res=get_response();
		  }
		  else
		  {
	    	    break;
		  }	
		}while(logic_res == 'y' || logic_res == 'Y');
		do
		{
		  printf("\n    6 -Execution:        ");
		  scanf("%s", exe);			// Execution
	          exe_flag=float_valid(exe);
		  exe1=atof(exe);
		  if(exe_flag==1)
		  {
		    invalid_msg();
		    exe_res=get_response();
		  }
		  else
		  {
		    break;
		  }		
		}while(exe_res == 'y' || exe_res == 'Y');	
		total_sum1=doc1+comm1+indent1+modu1+exe1+logic1;     // Making the sum total of each categories.
	        printf("\n    ______________________");
		printf("\n      -Total=           %.2f\n", total_sum1);  
	        if(total_sum1==total_marks1)         // Checking if sum total is equal to assigned marks to the program.
		{
		  break;
		}
		else
		{
		  printf("\n  'Error'\n  --------\n  -Check if you have given the marks correctly!");
                  printf("\n  -The sum total of each categories is not equal to the \'%.2f\' marks assigned above!\n", total_marks1);
                  printf("\n  -Whould like to re-input the marks?    'y'-> re-input    'n'-> exit");
                  printf("\n  -Type your answer here: ");
		  getchar();
                  scanf("%c",&answer);
		  system("clear");
	        }
	      }while(answer=='y'||answer=='Y');        // while the sum total is not equal to assigned marks, then take the inputs again from the user.				
	      
	    do
	    {
	      //re_run_flag=0;
	      do
	      {
	        header();
	        ow_ans = '\0';
	        if(re_run_flag==0)
	        {
	          printf("\n  'Marks assigned successfuly'\n\n");
	        }
		printf("\n        Enter the student Roll no: ");
		scanf("%d",&temp);
		details.rollno=temp;
		
		if((fprn = fopen("report.txt","rb")) == NULL)
		{
		  printf(" Cannot open file");
		}
		while((fread(&details,sizeof(details),1,fprn)) == 1)
		{
		  /*if(ow_ans=='n' || ow_ans=='N')
		  {
		    break;
		  }*/
	    	  if(temp==details.rollno)
		  {
		    printf("\n\n       'Warning' Entered Roll no already exists!  Do you want to overwrite? ---- press 'y'-> yes    'N'-> No\n");
		    ow_ans=get_response();
		    break;
		  }			
		  else
		  {
	            roll_not_exist=1;
	            break;
		  }
		} 
		if(ow_ans=='y' || ow_ans=='Y')
		{		
		  break;
		}
		//break;
		/*if(roll_not_exist==1)
		{	
		  break;
		}*/
	      }while(ow_ans=='n' || ow_ans== 'N');
	      ////////
	      
	      header();
	      printf("    Evaluating program code of the student's Roll no: %04d",temp);
	      printf("\n\n**********************************************************************************************************************************************************\n\n");
	      
	      ///////
	      printf("\n  -Now you have to input the name of the 'C' Program file to be evaluated.");
	      printf("\n  -press '1' for inputing the source file name.");  
	      do
	      {
	        input_file_option=0;
		input_file_res ='\0';
		printf("\n   Enter here: ");
		scanf("%d", &input_file_option);
		if(input_file_option!=1)
		{
		  printf("\n\n        'Invalid' option, Do you want to re-enter the option? ---- Press 'Y'-> Yes   'N'-> No");
		  input_file_res = get_response();			
		}
		  if(input_file_option==1)
		  {
		    break;
		  }
	        }while(input_file_res=='Y'||input_file_res=='y');				
		do
		{
		  header();
		  printf("\n    INPUTING THE SOURCE FILE TO BE EVALUATED");
		  printf("\n   --------------------------------------------");
		  do
		  {
		    valid_file_res='\0';		
		    printf("\n\n    -Enter name of the Source file");
		    if(f_flag==1)
		    {
		      printf(" again: ");
		    }
		    else
		    {
		      printf(": ");
		    }
		    scanf("%s", source_file);	// Reading source file name.
	            get_valid_file = checkc(source_file);
		    if(get_valid_file==0)
		    {
		      printf("\n     The filename entered is not a valid '.c' filetype.. Do you want re-input the source file name? ---- 'Y' -> Yes   'N' -> No\n");
		      valid_file_res=get_response();
		    }
		    else
		    {
		      break;
		    }	
		  }while(valid_file_res=='y'||valid_file_res=='Y');
                  file_pointer=fopen(source_file, "r");		// Open source file for reading
		  if(file_pointer==NULL)		// Checking if file exists or not
		  {
		  f_flag=1;
		  printf("\n\n    -Hey 'Sorry' There is no such file.\n  -Please check the entered file name.");
		  printf("\n\n    -You can re-enter the file name.    'y'-> re-enter   'n'-> exit");
		  printf("\n    -Type your answer here: ");
		  getchar();
		  scanf("%c", &answer);
		  system("clear");
		  }
		  else
		  {
		    printf("\n    'File is accepted for Evaluation'\n");
		    fclose(file_pointer);
		    do
		    {
		      start_eval_res=='\0';				
		      printf("\n\n    -Press '1'- To start Evaluation ");
		      printf("\n    -Press here: ");
		      getchar();
		      scanf("%c", &answer);
		      if(answer=='1')
		      {
		        header();
			printf("\n\n      COMPILING AND CHECKING FOR ERRORS....\n\n");		
			hold_exe=executer(source_file,&user_exe1,&exe1);
			e_flag=1;
			do
			{
			  header();
			  up_logic_choice='\0';
			  logic_menu_flag=0;
		   	  printf("\n\n	  CHECKING FOR PROGRAM CODE LOGIC\n");
			  printf("      ------------------------------------------\n");
			  printf("\n        Do you want to check the logic of the code? or have you already checked the code file\n\n");
			  printf("\n     Choose Option\n");
			  printf("   -------------------\n");
			  printf("\n	* Note: If you choose option 'C' before choosing option 'B', Evaluator will give marks thinking that the logic is correct\n\n");
			  printf("        A -> To view the Source code file\n\n");
			  printf("        B -> To give marks for logic of the code\n\n");
			  printf("        C -> Continue Evaluation Process: ");
			  getchar();
			  scanf("%c", &logic_option);
			  if(logic_option=='A'||logic_option=='a')
			  {
			    if((file_pointer=fopen(source_file,"r"))==NULL)
			    {
			      printf("\nCannot open file for reading \n");
			      return 1;
			    }
			  if((fp_logic=fopen("logic.txt","w"))==NULL)
			  {
			    printf("\nCannot open file for reading \n");
			    return 2;
			  }
			  while((single_ch=getc(file_pointer))!=EOF)
			  {
			    putc(single_ch,fp_logic);
			  }
			  fclose(file_pointer);
			  fclose(fp_logic);
			  header();
			  printf("\n>>  DISPLAYING SOURCE CODE FILE");
			  printf("\n\n****************************************************************************************************************************************************\n");
			  system("cat logic.txt");
			  printf("\n\n****************************************************************************************************************************************************\n\n");
			  do
			  {
			    logic_menu_flag=0;
			    up_logic_res='\0';
			    printf("       Press 'U' to go one leve up.\n");
			    printf("       Enter here: ");
			    getchar();
			    scanf("%c", &up_logic_choice);
			    if(up_logic_choice=='u'||up_logic_choice=='U')
			    {
			      logic_menu_flag=1;
			    }
			    else
			    {
			      printf("\n	'Invalid' option. Do you want to enter it again? ---- Press 'Y' -> Yes     'N' -> No\n");
			      up_logic_res=get_response();
			    }
			  }while(up_logic_res=='y'||up_logic_res=='Y');
			}
			if(logic_option=='B'||logic_option=='b')
			{
			header();
			printf("\n	ACCEPTING LOGIC MARKS FROM USER\n");
			printf("      ------------------------------------\n\n");
			do
			{
			  user_logic_res='\0';
			  do
			  {
			    hold_logic_flag=0;
			    user_logic1_res='\0';
			    printf("	How many marks do you want to give for logic out of %2.f: ", logic1);
			    scanf("%s", &user_logic);
			    hold_logic_flag=1;
			    user_logic_valid=float_valid(user_logic);
			    user_logic1=atof(user_logic);
			    if(user_logic1>logic1)
			    {
			      printf("\n\n	  Entered marks are greater than the %2.f entered for logic.");
			      printf("\n      Do you enter the marks again? ---- Press  'Y' -> Yes    'N' -> No\n");
			      user_logic1_res=get_response();
			    }
			  }while(user_logic1_res=='y'||user_logic1_res=='Y');
			  if(user_logic_valid==1)
			  {
			    invalid_msg();
			    user_logic_res=get_response();
			  }
		          else
			  {
			    break;
			  }
			}while(user_logic_res=='y'||user_logic_res=='Y');
			printf("\n\n	  'Marks for logic Accepted'\n\n");
			do
			{
			  logic_menu_flag=0;
			  up_logic_res='\0';
			  printf("\n\n\n\n\n\n\n\n******************************************************************************************************************************************************\n\n");
			  printf("       Press 'U' to go one leve up.\n");
			  printf("       Enter here: ");
			  getchar();
			  scanf("%c", &up_logic_choice);
			  if(up_logic_choice=='u'||up_logic_choice=='U')
			  {
			     logic_menu_flag=1;
			     break;
			  }
			  else
			  {
			     printf("\n	'Invalid' option. Do you want to enter it again? ---- Press 'Y' -> Yes     'N' -> No\n");
			     up_logic_res=get_response();
			  }
		        }while(up_logic_res=='y'||up_logic_res=='Y');
		      }
		      if(logic_option=='C'||logic_option=='c')
		      {
                         printf("\n\n       'OK' Marks for logic wlill be give by Evaluator! \n\n");									
			 break;
		      }
		    }while(logic_menu_flag==1);
		    header();
		    printf("\n\n	    CHECKING FOR DOCUMENTATION...\n\n");
		  //  printf("	        ---------------------------\n");
		    wait(3);
		    hold_doc = doc_check(source_file);
		    if(hold_doc==1)
		    {
		       printf("   	    >>There is documentation.\n");
		       doc_marks=doc1;
		    }
		    if(hold_doc==2)
		    {
		       printf("   	    >>There is documentation. but purpose is not specified.\n");
		       doc_marks=doc1/2;
		    }
		    if(hold_doc==3)
		    {
		       printf("   	    >>There is documentation. but Author name is not written.\n");
		       doc_marks=doc1/2;
		    }
		    if(hold_doc==0)
		    {
		       printf("   	    >>There is no documentation.\n");
		       doc_marks=0;
		    }
		    wait(1);
		    printf("\n\n	    CHECKING FOR NO OF COMMENTS IN THE PROGRAM...\n\n");
		   // printf("	------------------------------------------\n");
		    wait(3);
		    hold_comm = comment_check(source_file);
		    printf("   	    >>The no of comments in this program are: %d\n", hold_comm);
		    hold_lines = line_count(source_file);
		    if(hold_comm > (hold_lines * 40/100));
		    {
		       comm_marks=comm1;
		       eval_comm_flag=1;
		    }
		    if(hold_comm <= (hold_lines * 40/100));
		    {
		       comm_marks=comm1/2;
		       eval_comm_flag=2;
		    }
		    if(hold_comm <= (hold_lines * 20/100));
		    {
		       comm_marks= (comm1/2)/2;
		       eval_comm_flag=3;
		    }
		    wait(1);
		    printf("\n\n	    CHECKING FOR NO OF USER MADE FUNCTIONS...\n\n");
		    //printf("	---------------------------------------\n");
		    wait(3);
		    hold_modula = modula(source_file);
		    printf("   	    >>The no of user made functions found: %d\n", hold_modula);
		    if(hold_modula > 8)
		    {
		      modula_marks=modu1;
		    }
		    if(hold_modula < 8)
		    {
		      modula_marks=modu1/2;
		    }
		    if(hold_modula < 4)
		    {
		      modula_marks=(modu1/2)/2;
		    }
		    wait(1);
		    printf("\n\n	    CHECKING FOR INDENTATION...\n\n");
		    //printf("	------------------------");
		    wait(3);
	            hold_indent = indentation(source_file,&count_braces);
		    printf("            >> No of proper indentations are: %d out of %d\n", hold_indent, count_braces);
		    wait(1);
		    if(hold_indent > (count_braces * 80/100))
		    {
		      indent_marks=comm1;
		    }
		    else if(hold_indent <= ((count_braces * 80)/100) && hold_indent > ((count_braces * 60)/100))
		    {
		      indent_marks=indent1/2;
		    }
		    else if(hold_indent <= ((count_braces * 60)/100) && hold_indent > ((count_braces * 40)/100))
		    {
		      indent_marks= (indent1/2)/2;
		    }
		    else
		    {
		      indent_marks= ((indent1/2)/2)/2;
		    }
		    if(hold_exe!=1)
		    {
		       if(hold_exe_check==1)
		       {
			  exe_marks=exe1;
		       }
		    }
		    if(hold_exe==1)
		    {
		      exe_marks=user_exe1;
		    }
		    if(hold_logic_flag==1)
		    {
		      logic_marks=user_logic1;
		    }
		    if(hold_logic_flag!=1)
		    {
		      logic_marks=logic1;
		    }
		    final_marks=doc_marks+comm_marks+indent_marks+modula_marks+logic_marks+exe_marks;
		    do
	            {
		       view_eval_res=='\0';
		       printf("\n\n\n\n        Press '1' to get the result: ");
		       scanf("%d", &view_result_choice);
		       if(view_result_choice==1)
		       {
			  header();
			  printf("	AS PER THE EVALUATOR THE MARKS FOR THE CODE IS AS FOLLOWS:\n");
			  printf("	----------------------------------------------------------\n\n");
			  printf("  	      >> Documentation:  %.2f\n\n", doc_marks);
			  printf("  	      >> Comment:        %.2f\n\n", comm_marks);
			  printf("            >> Indentation:    %.2f\n\n", indent_marks);
			  printf("  	      >> Modularity:     %.2f\n\n", modula_marks);
			  printf("	      >> logic:          %.2f\n\n", logic_marks);
			  printf("	      >> Execution:      %.2f\n\n", exe_marks);
			  printf("              -----------------------\n\n");
			  printf("              >> Total =         %.2f\n\n", final_marks);
		       }
		       else
		       {
			  printf("\n	'Invalid' option. Do you want to enter it again? ---- Press 'Y' -> Yes     'N' -> No\n");	
			  view_eval_res=get_response();
		       }
	             }while(view_eval_res=='Y'||view_eval_res=='y');
		   }
	         }while(start_eval_res=='y'||start_eval_res=='Y');	
	       }
	     }while(answer=='y'||answer=='Y');
	     details.rollno = temp;
	     details.d_doc = doc_marks;
	     details.d_comm = comm_marks;
	     details.d_indent = indent_marks;
	     details.d_modula = modula_marks;
	     details.d_logic = logic_marks;
	     details.d_exe = exe_marks;
	     details.d_total = final_marks;
	     details.d_upon = total_marks1;
	     
	     FILE *fpr;		
	     if((fpr = fopen("report.txt","ab")) == NULL)
	     {
		printf("\ncannot open file\n");
	     }
	     fwrite(&details,sizeof(details),1,fpr);
	     fclose(fpr);
	     do
	     {
		printf("\n\n\n\n	Press '1' to go to the MENU: ");
		scanf("%d", &next_menu_option);
		do
		{
		  go_to_menu_flag==0;
		  menu_return=='\0';
		  menu_return_flag==0;
		  if(next_menu_option==1);
		  {
		     header();
		     printf("\n        MENU\n");
		     printf("      -------------------------------\n");
		     printf("\n     	Press:\n\n              '1' -> To Display Students Record menu.\n\n");
		     printf("              '2' -> See evaluator's comment on the evaluated program  \n\n");
		     printf("              '3' -> Evaluate a program of another student\n\n");
		     printf("              '4' -> Exit\n\n");
		     printf("              Enter your option: ");
		     scanf("%d", &display_option);
		     if(display_option==1)
		     {
			do
			{
			   header();
			   printf("\n\n        STUDENTS RECORD MENU");
			   printf("\n    ------------------------------");
			   printf("\n\n        1 -> Records of all students");
			   printf("\n\n        2 -> Record of particular student");
			   printf("\n\n        3 -> Delete a record");
			   printf("\n\n        4 -> Go back");
			   printf("\n\n        5 -> Exit");
			   printf("\n\n        Enter option: ");
			   scanf("%d", &display_menu_option);
			   if(display_menu_option==1)
			   {
			      header();
			      printf("        LISTING THE RECORDS OF STUDENTS\n\n");
			      printf("****************************************************************************************************************************************************\n");
							
			     if((fpr = fopen("report.txt","rb")) == NULL)
			     {
			        printf("\ncannot open file\n");
			     }
			     printf("|*|    |  ROLL NO |     | DOCUMENTATION |   COMMENTS    |  INDENTATION |  MODULARITY  |    LOGIC   |  EXECUTION  |       |  MARKS / OUT OF  |    |*|\n");	
			     printf("****************************************************************************************************************************************************");
			     while((fread(&details,sizeof(details),1,fpr)) == 1)
			     {
			        printf("\n|*|    |   %04d   ",details.rollno);
			        //printf("\nNAME : %s\n",details.name);
			        printf("|     |         %2.2f  ",details.d_doc);
			        printf("|         %2.2f  ",details.d_comm);
			        printf("|        %2.2f  ",details.d_indent);
			        printf("|        %2.2f  ",details.d_modula);
			        printf("|      %2.2f  ",details.d_logic);
			        printf("|       %2.2f  ",details.d_exe);
	    		        printf("|       |  %2.2f ",details.d_total);
	    		        printf("  / %2.2f  |    |*|\n", details.d_upon);
	    		        printf("----------------------------------------------------------------------------------------------------------------------------------------------------");
			      }
			      fclose(fpr);
		              printf("\n\n****************************************************************************************************************************************************");
			      printf("\n\n        Press 'R' to return to the display menu: ");
			      getchar();
			      scanf("%c", &display_return);
			    }	
			    if(display_menu_option==2)
			    {
			       int temp1;
			       header();
			       printf("        DISPLAYING RECORD OF A PARTICULAR STUDENT \n\n");
			      // printf("    ---------------------------------------------------\n\n");		
			       printf("\nEnter Students Roll no: ");
			       scanf("%d",&temp1);
			       if((fpr = fopen("report.txt","rb")) == NULL)
			       {
				  printf("cannot open file");
			       }	
			       printf("\n********************************************************************************************************************************************************\n");
				printf("|*|  |  ROLL NO  |     | DOCUMENTATION |   COMMENTS   | INDENTATION |  MODULARITY  |    LOGIC    |   EXECUTION   |      |    MARKS / OUT OF    |     |*|\n");	
				printf("********************************************************************************************************************************************************\n");
			       while((fread(&details,sizeof(details),1,fpr)) == 1)
			       {
			         if(temp1==details.rollno)
			         {
				    break;
			         }
			       }	
			       printf("\n|*|  |    %04d   ",details.rollno);
			       //printf("\nNAME : %s\n",details.name);
			       printf("|     |         %2.2f  ",details.d_doc);
			       printf("|        %2.2f  ",details.d_comm);
			       printf("|       %2.2f  ",details.d_indent);
			       printf("|        %2.2f  ",details.d_modula);
			       printf("|       %2.2f  ",details.d_logic);
			       printf("|         %2.2f  ",details.d_exe);
			       printf("|      |       %2.2f",details.d_total);
			       printf(" / %2.2f   |     |*|\n",details.d_upon);
			       fclose(fpr);
			       printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n*********************************************************************************************************************************************************");
										
			       printf("        	Press 'R' to return to the display menu: ");
			       getchar();
			       scanf("%c", &display_return);
			     }
			     if(display_menu_option==3)
			     {
			        header();
				printf("        DELETING A RECORD OF PERTICULAR STUDENT\n");
				printf("      ---------------------------------------------\n\n");
				printf("        	Press 'R' to return to the display menu: ");
				getchar();
				scanf("%c", &display_return);
			     }
			     if(display_menu_option==4)
			     {	
				menu_return_flag=1;
				break;
			     }
			     if(display_menu_option==5)
			     {
			       printf("\n	    Are you sure you want to exit? ---- Press 'Y'-> Yes    'N'-> No\n");
			       exit_display_menu_res=get_response();
			       if(exit_display_menu_res=='y'||exit_display_menu_res=='Y');
			       {
			       	  ////////////////////////////////////
			       	  system("clear");
                                  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tT H E R E     W E R E    M A N Y    P E O P L E     W H O    H E L P E D     U S    IN    A C C O M P L I S H I N G     T H E     P R O J E C T\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait (4);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t   W E    W O U L D    L I K E    T O     T H A N K     T H E M     F O R     T H I E R    K I N D     S U P P O R T\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait (3);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    O U R   S P E C I A L   T H A N K S   G O E S   T O\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  
                                 wait (4);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t      T E A C H E R   J O Y T I   M A D A M\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait(2);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   A T U L   K U M A R   Y A D A V   \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait(2);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t        D A V I D   V A Z\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait(2);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    A R P I T   P A N D A Y (SY)\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait(2);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       T A R U N   S I N G H\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait(2);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t          F R I E N D S\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait(2);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t             A N D\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                 wait(2);
                                 system("clear");
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       O N E   A N O T H E R\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                wait(2);
                                system("clear");
    
                                wait(2);
    
                                system("clear");
                             	 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    T H A N K   Y O U\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
			       	  
			       	  ////////////////////////////////////
				  thank_you();
				  exit(1);
			       }
			       if(exit_display_menu_res=='n'||exit_display_menu_res=='n');
			       {
				  menu_return='m';
			       }	
			      }
			    }while(display_return=='r'||display_return=='R');
			  }
			  
			  
			  if(display_option==2)
			  {
			     header();
			     printf("        DISPLAYING 'EVALUATORS' COMMENTS ON ROLL NO %04d\'s PROGRAM \n\n", temp);
			     printf("**********************************************************************************************************************************************************\n\n");
			     
				 if(hold_doc==1)
		   		 {
	       				printf("        >>  Good! Roll_no %04d\'s code found with full documentation..   \n\n", temp);
		       
		   		 }
		    		 if(hold_doc==2)
				 {
		      			 printf("        >>  In Roll_no %04d\'s code, There is documentation. but the purpose of the program is not specified.\n            When writing a program, purpose need to be specified to know what the program is doing. Because of that the evaluator has deducted some marks. \n\n", temp);
		       
		    		}
		    		if(hold_doc==3)
		    		{
		       			printf("        >>  There is documentation. but Author name was not written.\n            Full marks would have been given if the student had written his name wile documenting.\n\n", temp);
		       
		   		}
		    		if(hold_doc==0)
		    		{
		       			printf("        >>  Poor! The student has not documented the code. Documentation intruduces the author of the program and purpose of the written program.\n            Hence disclusion of the documentation int the program, results in evaluator giving 0 marks for the documentation.\n\n", temp);
		       
		    		}
		    
		     		printf("\n        >>  The no of comments in this program are: %d\n", hold_comm);
		    		hold_lines = line_count(source_file);
		   		if(eval_comm_flag==1)
		    		{
		       			printf("\n            Good! The student has commented the program very well.  There were maximum no of comments found in this program and program was very readable.. \n\n");
		    		}
		   		if(eval_comm_flag==2)
		    		{
		       			printf("\n            Comments were found in the program, but There were some comments missing.\n            The code would have been understood properly if student had commented the code properly..\n            Thus Resulting the evaluator to deduct some marks for commenting.. \n\n");
		    		}
		    		if(eval_comm_flag==3)
		    		{
		       			printf("\n            Bad! The student has not commented the program code. Program lacks readability..\n            There were maximum no of comments missing in this program.\n\n");
		    		}
		    
		    
		    		 printf("\n        >>  The no of user made functions were: %d\n", hold_modula);
		    		if(hold_modula > 8)
		    		{
		      			printf("\n            Good! The program was modular, Good Uses of functions. \n\n");
		    		}
		    		if(hold_modula < 8 && hold_modula >= 4)
		    		{
		     			 printf("\n            Good! The program was modular, But there is still need for improvement. Could have made the program more modular.\n\n");
		    		}
		    		if(hold_modula < 4)
		    		{
		      			printf("\n            Bad! The program was not modular, The no. of user made functions were very less as showned above.  \n\n");
		    		}
		    
		     		printf("\n        >>  No of proper indentations are: %d\n", hold_indent);
		    		if(hold_indent > ((count_braces * 80)/100))
		    		{
		     			 printf("\n            Execellent! The program code was readable. Program was nicely indented. \n");
		    		}
		    		if(hold_indent <= ((count_braces * 80)/100) && hold_indent > ((count_braces * 60)/100))
		    		{
		      			printf("\n            Good! The program was readable. Indentations were proper. but still need to do exact indentations. Hence some marks are deducted.\n");
		    		}
		    		if(hold_indent <= ((count_braces * 60)/100) && hold_indent > ((count_braces * 40)/100))
		    		{
		     			 printf("\n            Bad! The program was not that readable. Indentations were not proper. Need for improvement.\n            Some marks are deducted by the Evaluator. \n");
		    		}
		    		if(hold_indent <= ((count_braces * 40)/100))
		    		{
		      			printf("\n            Very Bad! The program was not at all readable. Pooverly indented by the student. Proper indentation is required to give marks for indentation.\n            Because the code was not readable the Evaluator has deducted marks. \n");
		    		}
		    
		    		if(hold_exe!=1)
		    		{
		    			printf("\n\n        >>  There were errors found in this code, so program could not be executed.  \n\n");
		    		}
		    		else
		    		{
		    			printf("\n\n        >>  There were no errors were found in this program code..");
		    		}
		    		printf("\n\n***************************************************************************************************************************************************\n\n");
			     printf("        Press 'M' to go to MENU: ");
			     getchar();
			     scanf("%c", &menu_return);
			   }
			   if(display_option==3)
			   {
			      re_run_flag=1;
			      break;
			   }
			   if(display_option==4)
			   {
			      printf("\n               Are u sure You want to exit?  ---- Press 'Y'-> Yes     'N'-> No\n");
			      exit_res=get_response();
			      if(exit_res=='y'||exit_res=='Y')
			      {
				thank_you();
				exit(1);
			      }
		             if(exit_res=='n'||exit_res=='N')
			     {
		      	       menu_return=='m';
		      	     }
		           }
		           
		           
		        }
	     	     /*
		      else
		      {
			 printf("\n	'Invalid' option. Do you want to enter it again? ---- Press 'Y' -> Yes     'N' -> No\n");	
			 menu_next_res=get_response();	
		      }
		      
		      */
						
		    }while(menu_return=='m'||menu_return=='M'||menu_return_flag==1);
		  }while(menu_next_res=='y'||menu_next_res=='Y');
		}while(re_run_flag==1);
	     }
	     else if(menu_option==2)
	     {
	        do
	        {
	          user_manual_return='\0';
	          header();
	          printf("        USER MANUAL                                                             This program is built by Glenford Fernandes and Diker Pagui..\n");
	          printf("**********************************************************************************************************************************************************\n\n");
	          intro();
	          getchar();
		  scanf("%c", &user_manual_option);
		  if(user_manual_option=='1')
		  {
		  	user_manual_return='\0';
			header();
			printf("	WORKING OF THE PROGRAM\n");
			line_print();
			working_of_program();
			line_print();
			printf("Press 'R' to return to User manual: ");
			getchar();
			scanf("%c",&user_manual_return);
					
		  }
		  else if(user_manual_option=='2')
		  {
		  	user_manual_return='\0';
		  	header();
		  	printf("SHOWING HOW CATEGORIES ARE CHECKED AND ASSIGNED MARKS\n");
		  	line_print();
		  	categories_details();
			printf("Press 'R' to return to User manual: ");
			getchar();
			scanf("%c",&user_manual_return);
		  }
		  else if(user_manual_option=='b'||user_manual_option=='B')
		  {
		  	back='b';
		  	break;
		  }
		  else
		  {
		  	printf("\n	  Invalid Option! Do you want to select it again? ---- 'Y' -> Yes     'N' -> No");
		  	user_man_res=get_response();
		  	if(user_man_res=='y'||user_man_res=='Y')
		  	{
		  		user_manual_return='r';
		  	}
		  	else
		  	{
		  		user_manual_option='b';
		  		break;
		  	}
		  }
		}while(user_manual_return=='r'||user_manual_return=='r');  
	     }
	     else if(menu_option==3)
	     {
	      	header();
		printf("       	  CHANGING PASSWORD\n");
		printf("        ----------------------\n");
		do
		{
		   pass_flag=0;
		   res_no_flag=0;
	           pass_res=='\0';
		   printf("\n        Enter Current password: ");
		   scanf("%s", curr_pass);
		   fpp=fopen("pass.txt","r");
		   int m=0;
		   fgets(pass_string, 5, fpp);
		   
		   if(!(strcmp(curr_pass,pass_string)==0))
		   {
		       printf("\n\n        'Invalid' Password. Do you want to re-enter Password? ---- Press 'Y' -> Yes (or) 'N' -> No\n");	
		       pass_res=get_response();
		       if(pass_res=='y'||pass_res=='Y')
		       {
			  pass_flag=1;
		       }
		      // if(pass_res=='n'||pass_res=='N')
		       else
		       {
		         res_no_flag=1;
		         break;
		       }
		  }
		  else
		  {
		     pass_flag=0;
		     break;
		  }
		  fclose(fpp);
		}while(pass_flag==1||res_no_flag!=1);
		if(res_no_flag!=1&&pass_flag!=1)
		{
		  do
		  {
		     do
		     {
			new_pass_length_flag=0;
			printf("\n\n        Enter New Password: ");
			scanf("%s", new_pass);
			new_pass_length=strlen(new_pass);
			if(new_pass_length!=4)
			{
			  printf("\n         'Incorrect' Please enter password of '4' characters only.\n\n         Do you want to re-enter the new password? ----  Press 'Y' -> Yes    'N' -> No \n");
			  new_pass_length_res=get_response();
			  if(new_pass_length_res=='y'||new_pass_length_res=='Y')
			  {
			    new_pass_length_flag=1;
			  }
			  if(new_pass_length_res=='N'||new_pass_length_res=='n')
			  {
			    new_pass_length_flag=2;
			  }
			}
		      }while(new_pass_length_flag==1);
		      printf("\n\n        Confirm Password: ");
		      scanf("%s", conf_pass);
		      if((strcmp(new_pass,conf_pass)==1))
		      {
			 printf("\n\n        Passwords are not matching. Do you want to re-enter the new Password? ---- Press 'Y' -> Yes (or) 'N' -> No\n");	
			 get_response();
		      }
		    }while((strcmp(new_pass,conf_pass)==1));
		    if((strcmp(new_pass,conf_pass)==0))
		    {
		       fpp=fopen("pass.txt","w");
		       fputs(conf_pass,fpp);
		    }
		       fclose(fpp);
		       printf("\n\n       'Password changed successfully'");
		       printf("\n\n\n*******************************************************************************************************************************************************\n\n");
		       printf("        Press 'B' to go BACK : ");
		       getchar();
		       scanf("%c", &back);
		  }
	       }
	       else if(menu_option==4)
	       {
		   printf("\n	    Are you sure you want to exit? ---- Press 'Y'-> Yes    'N'-> No\n");
		   exit_menu_res=get_response();
		   if(exit_menu_res=='y'||exit_menu_res=='Y')
		   {
		     thank_you();
		     exit(1);
		   }
		   if(exit_menu_res=='n'||exit_menu_res=='N')
		   {
		     back='b';
		   }	
	       }
	       else
	       {
		  printf("\n\n		Invalid option! Do you want to select the option again? ---- 'Y' -> Yes   'N' -> No");
		  invalid_menu_res=get_response();
		  if(invalid_menu_res=='y'||invalid_menu_res=='Y')
		  {
	             invalid_option_flag=1;
		  }
	          else
		  {
		     thank_you();
		     exit(1);		
		  }
	        }
	     }while(back=='b'||back=='B'||res_no_flag==1||invalid_option_flag==1);
}

header()
{
	system("clear");
	printf("\n                                                                                                                                      'C' Evaluator");
	printf("\n**********************************************************************************************************************************************************\n\n");
}

// header for error /////////////////////////////////////////////////////////////////
header_error()
{
	system("clear");
	printf("\n                                                                                                                                      'C' Evaluator");
	printf("\n**********************************************************************************************************************************************************\n\n");
	printf("\nSHOWING ERROR FILE\n--------------------------------------\n\n");
}

// Validating user response in terms of 'yes' or 'no'../////////////////////////////

char get_response()
{
	int valid_char=0, i=0;
	char answer;
	do
	{
		printf("\n								     Enter your option: ");
		getchar();
		scanf("%c", &answer);
		if((answer=='y' || answer=='Y') || (answer=='n' || answer=='N'))
		{
			valid_char=2;
		}
		else
		{
			valid_char=3;
			printf("\n       -Invalid Input. ---- Press 'Y' -Yes (or) 'N' -No  \n");
			
		}
	}while(valid_char==3);
	
	return answer;
}

//Float validation.. ///////////////////////////////////////////////////////////////

int float_valid(char str[len])
{
	int i=0, ln, flag=1, convert, count=0;
	
	ln=strlen(str);
	while(i<ln)
	{
		if(i==0)
		{
			if( (str[0]=='+') || (str[0]>='0' && str[0]<='9') )
			{
				flag=0;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(i!=0)
		{
			if( (str[i]>='0' && str[i]<='9') || (str[i]=='.') )
			{
				flag=0;
				if(str[i]=='.')
				{
					count++;
					if(count>=2)
					{
						flag=1;
						break;
					}
				}
				
			}
			else
			{
				flag=1;
				break;
			}
		}
		i++;
	}
	return(flag);
}	

// printing invalid msg.////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

invalid_msg()
{
	printf("\n    'Invalid' Number. Do you want to re-enter the number? ---- 'Y' -> Yes   'N' -> No\n");
}

// validating source_file while accepting. //////////////////////////////////////////////////////////////////////////////////////////////////
int checkc(char str[])
{
	int flag,size=0;

	size = strlen(str);
	if(str[size-2]=='.' && str[size-1]=='c')
	{
		flag = 1;
	}
	else
	{
		flag =0;
	}

	return(flag);


}

// Documentation module ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int doc_check(char str[])
{
	FILE *f5;
	int flag=0, count=0;
	char ch,ch2,ch2_n;
	int author_flag=0, purpose_flag=0;
	if((f5 = fopen(str,"r")) == NULL)
	{
		printf("Cannot open file");
		exit(1);
	}

	while((ch =fgetc(f5)) != EOF)
	{
		if(ch == '/')
		{
			if((ch = fgetc(f5)) == '*')
			{
			
				while((ch2=fgetc(f5))!='#')
				{
				
					if(ch2=='A')
					{
						if((ch2=fgetc(f5))=='u')
						{
							if((ch2=fgetc(f5))=='t')
							{
						              	if((ch2=fgetc(f5))=='h')
						              	{
									if((ch2=fgetc(f5))=='o')
									{
										if((ch2=fgetc(f5))=='r')
										{
											//printf("\n Author is there\n");
											author_flag=1;
										}
									}					
								}
							}
						}
					}
				}
			}
		}
		
		
	}
	fclose(f5);
	
	if((f5 = fopen(str,"r")) == NULL)
	{
		printf("Cannot open file");
		exit(1);
	}
	
	while((ch =fgetc(f5)) != EOF)
	{
		if(ch == '/')
		{
			if((ch = fgetc(f5)) == '*')
			{
			
				while((ch2=fgetc(f5))!='#')
				{
				
					if(ch2=='P')
					{
						if((ch2=fgetc(f5))=='u')
						{
							if((ch2=fgetc(f5))=='r')
							{
						              	if((ch2=fgetc(f5))=='p')
						              	{
									if((ch2=fgetc(f5))=='o')
									{
										if((ch2=fgetc(f5))=='s')
										{
											if((ch2=fgetc(f5))=='e')
											{
												//printf("\n Purpose is there\n");
												purpose_flag=1;
											}
										}
									}					
								}
							}
						}
					}
				}
			}
		}
	}
	fclose(f5);
	
	if(author_flag==1 && purpose_flag==1)
	{
		flag=1;
	}
	if(author_flag==1 && purpose_flag!=1)
	{
		flag=2;
	}
	if(author_flag!=1 && purpose_flag==1)
	{
		flag=3;
	}
	if(author_flag!=1 && purpose_flag!=1)
	{
		flag=0;
	}
	
	
	return(flag);
	
}

// comment module  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int comment_check(char str[])
{
	FILE *f1;
	int flag=0,count=0;
	long int currentpos;
	char ch,check,ch2,ch_n;

	if((f1 = fopen(str,"r")) == NULL)
	{
		printf("cannot open %s", str);
		//exit(1);
	}

	
	while((ch = fgetc(f1)) != EOF)
	{


		if(ch == '/')
		{
			currentpos = ftell(f1);
			
			ch2 = fgetc(f1);
		
			if(ch2 == '/')
			{
				count=0;
			        while((ch_n=fgetc(f1))!='\n')
			        {
			        	count++;
			        	
				}
				if(count>10)
			        {
					flag++;		        	
			        }
				//flag++;
				
			}
		}
	}

	return(flag);

	//flushall();
	fclose(f1);

}

// indentation module   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int indentation(char str[], int *t_braces)
{

	int flag_indent;	
	
	char ch,check_char,string_store[len];
	int i=0,m=0,o_ch_position,string_ln;
	
	char c_check_char,c_string_store[len];
	int j=0,n=0,c_ch_position,close_braces=0,open_braces=0,c_string_ln;
	
	char length_string1[len], length_string2[len];
	int count_indent=0;
	open_braces=0;
	
	FILE *f1,*f2;

	if((f1 = fopen(str,"r")) == NULL)
	{
		printf("cannot open %s", str);
	}
	
	while((ch = fgetc(f1)) != EOF)
	{
		if(ch == '{')
		{
			open_braces++;
			o_ch_position = ftell(f1);
			check_char = ch;
			
			while(check_char!='\n'||check_char==' '||check_char=='\t')
			{
				i++;
			
				fseek(f1,o_ch_position-(i+1),0);
				string_store[i-1]=fgetc(f1);
			
				if(string_store[i-1]=='\n')
				{
					string_store[i-1]='\0';
					break;	
				}
				check_char=string_store[i-1];
				fseek(f1,o_ch_position,0);
			
			}
			string_ln=strlen(string_store);
			
			length_string1[m]=string_ln+48;
			
			m++;
			
			
			i=0;
			fseek(f1,o_ch_position+1,0);
			
		}
		
		if(ch == '}')
		{
			close_braces++;
			c_ch_position = ftell(f1);
			c_check_char = ch;
			while(c_check_char!='\n'||c_check_char==' '||c_check_char=='\t')
			{
				j++;
			
				fseek(f1,c_ch_position-(j+1),0);
				c_string_store[j-1]=fgetc(f1);
			
				if(c_string_store[j-1]=='\n')
				{
					c_string_store[j-1]='\0';
					break;	
				}
				c_check_char=c_string_store[j-1];
				fseek(f1,c_ch_position,0);
			
			}
			c_string_ln=strlen(c_string_store);
			
			
			length_string2[n]=c_string_ln+48;
			
			n++;

			j=0;
			fseek(f1,c_ch_position+1,0);
						
		}
		
        length_string1[m+1]='\0';
	length_string2[n+1]='\0';
		
	}
	*t_braces=open_braces;	
	int p=0,q=0;
	while(length_string1[p]!='\0')
	{
		q=0;
		while(length_string2[q]!='\0')
		{
			if(length_string1[p]==length_string2[q])
			{
				count_indent=count_indent+1;
				length_string2[q]='c';
				break;
			}
			q++;
		}
		p++;
	}
	
	fclose(f1);
	// checking for tab
	char ch2, check_char2, string_store2[len];
	int count_2=0, ch2_position, k=0, string_ln2;	
	
	int  l=0, ch2_next_position, string_ln2_next, count_2_next;
	char string_store2_next[len], ch2_next, check_char2_next; 
	f2=fopen(str,"r");
	while((ch2=fgetc(f2))!=EOF)
	{
		
		if(ch2=='{')
		{
			ch2_position = ftell(f2);
			check_char2=ch2;
			while(check_char2!='\n'||check_char2==' '||check_char2=='\t')
			{
				k++;
			
				fseek(f2,ch2_position-(k+1),0);
				string_store2[k-1]=fgetc(f2);
				if(string_store2[k-1]=='\n')
				{
					string_store2[k-1]='\0';
					break;	
				}
				check_char2=string_store2[k-1];
				fseek(f2,ch2_position,0);
			
			}
			string_ln2=strlen(string_store2);
			
			k=0;
			fseek(f2,ch2_position+1,0);
			while((ch2_next=fgetc(f2))!='}')
			{
				if(ch2_next=='{')
				{
					ch2_next_position=ftell(f2);
					check_char2_next=ch2_next;
					while(check_char2_next!='\n' || check_char2_next==' ' || check_char2_next=='\t')
					{
						l++;
						
						fseek(f2,ch2_next_position-(l+1),0);
						string_store2_next[l-1]=fgetc(f2);
						if(string_store2_next[l-1]=='\n')
						{
							string_store2_next[l-1]='\0';
							break;	
						}
						check_char2_next=string_store2_next[l-1];
						fseek(f2,ch2_next_position,0);
						
					}
					string_ln2_next=strlen(string_store2_next);
					
					if(string_ln2!=(string_ln2_next-1))
					{
						count_2++;
					}
					
					
					l=0;
					fseek(f2,ch2_next_position+1,0);
			
				}
				
			}
			
			
		}	
	}
	flag_indent=count_indent-count_2;
	return(flag_indent);
	fclose(f2);	
}	

// modularity module ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int modula(char str[])
{
	FILE *f3;
	int count=0,flag1=0;
	

	int l=0;
	int flag=0,current_pos,i=0,j,k,arraysize;

	char funcstore[len],ch,c,alpha_track;

	char lib_functions[][20] = {"scanf","printf","if","while","for","main"};

	if((f3 = fopen(str,"r")) == NULL)
	{
		printf("Cannot open file");
		exit(1);
	}
	while((ch=fgetc(f3)) != EOF)
	{
		if(ch == '(')
		{

			current_pos = ftell(f3);

			alpha_track = ch;
			while(alpha_track != '=' || alpha_track != ' ' || alpha_track != '\n' || alpha_track != '\t')
			{
				i++;
				fseek(f3,current_pos-(i+1),0);

				funcstore[i-1] = fgetc(f3);
				if(funcstore[i-1]=='='||funcstore[i-1]==' '||funcstore[i-1]=='\n' || funcstore[i-1]=='\t')
				{
					funcstore[i-1]='\0';
					break;
				}
				alpha_track = funcstore[i-1];

				fseek(f3,current_pos,0);
			}
			i=0;
			fseek(f3,current_pos+1,0);
				arraysize = strlen(funcstore);
				char new_func[arraysize];

					j=0;
					for(k=arraysize-1;k>=0;k--)
					{
						new_func[j] = funcstore[k];
						j++;
					}
				new_func[arraysize]='\0';;
				count++;
					
				int n;
				for(n=0;n<=6;n++)
				{			
				
					if((strcmp(new_func,lib_functions[n])==0))
					{
						flag++;
					}
				}
			/*	for(i=0;i<arraysize;i++)
				{
					if(new_func[i]!=lib_functions[0][i])
					{
						//printf("\nnew func %c",new_func[i]);
						//printf("\nlib_func %c",lib_functions[0][i]);

						l=-1;
						break;
					}
				}
				if(l==-1)
					flag++;
					l=0;
		        */
		}
		
		
	
	}

	
	fclose(f3);
	flag1=count-flag;	
	return(flag1);
}		

//execution module   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int executer(char str[],float *user_exe,float *exe2)
{
	int flag,cursor_pos,i=0,errorzero=0, user_ans_flag=0;
	float num=0,num_con=0;
	int e_answer,continue1_option;
	char ch,alpha_track,error_store[6];
	char choice,exechoice,exe,see_errors_res;
	char file_string[] = {"gcc -c "};
		strcat(file_string,str);
	char indirect_str[] = {" 2> output.txt"};
	strcat(file_string,indirect_str);
	FILE *f2;

	system("touch output.txt");
	system("touch errorcount.txt");
	system(file_string);
	system("grep error output.txt | wc -l | cat>errorcount.txt");

	printf("   >> The no of errors in the program code are: ");
	if((f2 = fopen("errorcount.txt","r")) == NULL)
	{
		printf("Cannot open file");
		exit(1);
	}

	while((ch = fgetc(f2)) != EOF)
	{
		if(ch=='0')
		{
			errorzero=1;
			hold_exe_check=errorzero;
		}
		printf("%c",ch);

	}
	if(errorzero==1)
	{
		printf("\n   >> There were no errors do you want to execute the file? ---- 'Y' -> Yes    'N' -> No : ");
		getchar();
		scanf("%c",&exechoice);
		if(exechoice=='y' || exechoice=='Y')
		{
			char exe[] = {"gcc -c "};
			strcat(exe,str);
			system(exe);

			int aa = strlen(str);
			char c_copy[aa];

			strcpy(c_copy,str);
			c_copy[aa-1] = 'o';

			char gcc[] = {"gcc "};
			strcat(gcc,c_copy);
			char o_exe[] = {" -o dg.exe"};
			strcat(gcc,o_exe);
			
			system(gcc);
			system("./dg.exe");
		}
		
		printf("\n  -Was the program working well?\n\n  -Do you want Evaluator give marks for the execution part.\n  -Or you want to give marks for the execution as per your evalution.");
		
		printf("\n\n  -Press '1'- To give marks for Execution.  '2'- Let Evaluator give the marks. ");				
		printf("\n  -Enter your option here: ");
		
		scanf("%d", &e_answer);
		if(e_answer==1)
		{

			user_ans_flag=1;
			do
			{
				num=0;
				printf("\n  -How much marks do you want give out of %2.f: ",*exe2);
				scanf("%f",&num);
				*user_exe = num;
				//num_con = *exe2;
				if(*user_exe > *exe2)
				{
					printf("\n  -Marks given are exeeding.\n  -Please give marks out of the inputed marks for execution category.\n");
					
				}

			}while(*user_exe > *exe2);
			printf("\n  -Execution marks are accepted.\n");
		}
		/*else
		{
			printf("\n  -Ok, Execution marks will be given by the Evaluator.\n");
		}*/
	}
	else
	{
		printf("\n   >> Do you want to check the error file? ---- Press 'Y' -> Yes    'N' -> No  \n");
		see_errors_res=get_response();
		
		if(see_errors_res=='y' || see_errors_res=='Y')
		{
			header_error();
			system("cat output.txt");
			printf("\n\n   Press '1' to continue: ");
			scanf("%d", &continue1_option);
			
		}

	}

		fclose(f2);

		//return(user_ans_flag);
		return(errorzero);

}

// counting no of lines in a program  //////////////////////////////////////////////////////////////////////////////////////////////////////

int line_count(char str[])
{
	FILE *f4;
	char ch,ch2;
	int index=0;
	if((f4 = fopen(str,"r")) == NULL)
	{
		printf("Cannot open file");
		exit(1);
	}
	while((ch = fgetc(f4)) != EOF)
	{
		if(ch=='\n')
		{
			if((ch2=fgetc(f4))!='\n')
			{
				index++;
			}
		}	
	}
	fclose(f4);
	return(index);	
}

// intr module  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

intro()
{
	
	printf("    -This program is Designed/Developed to Evaluate 'C' Programs of students.\n\n");
	printf("    -Programs are evaluated based on following categories:\n\n      - Documentation\n      - Comments\n      - Indentation\n      - Modularity\n      - Logic\n      - Executuion\n\n");
	printf("    -It takes student_rollno, grades and student source_code file as a input from the teacher required for evaluation process.\n\n");
	printf("    -Evaluator checks for each criteria from  the source_code file and starts evaluation as per his evalution.\n\n");
	printf("    -After evaluating, marks are assigned to each categories, later this marks are saved and are applicable whenever required.\n\n");
	printf("    -One of the beautiful feature of the evaluator is that it gives 'comment' on the evaluated program.\n\n");
	printf("    -The evaluator allows to run the program of another students after evaluating program of one.\n\n");
	printf("    -Record of a particular student or combined records of all students are showned to the user whenever required.\n\n");
	line_print();
	printf("      Choose your option (to go in detail)\n");
	printf("     ----------------------\n\n");
	printf("          1 -> Working of the program \n");
	printf("          2 -> Evaluation process for each categories\n");
	printf("          B -> to go Back to Menu\n\n");
	printf("          Enter option: ");
}

// Displaying/showing the workings of each categories.
categories_details()
{
	printf("    -Documentation checking:\n        Evaluator checks program code of the students file and sees whether the The student has written his name and\n        purpose of the program is specified or not.\n        If both are missing 0 marks is given to the Documantation,\n        If one is present and other is absent half marks is given to the documentaion,\n        Else Full marks are given to the dodumentaion.\n\n");
	printf("    -Comment checking:\n        Evaluator Checks whether student has commented his program code or not.\n\n");
	printf("    -Indentation checking:\n        Evaluator checks for the Proper indentations in the program.\n        He first checks the no of open braces are equal to the no of closed braces\n        and checks each open and close brace are in line, that they are properly indented or not.\n        then Evaluator checks for the no of proper indentations done and compares them with total no of proper indentations required.\n\n");
	printf("    -Modularity:\n        Evaluator checks for modularity by checking no of user made functions in the program.\n        modular program makes Evaluator to give more marks for the modularity.\n\n");
	printf("    -Logic:\n        To give marks for logic, Evaluator displays the full source code to the teacher and asks whether the code has proper logic or not?\n        If user feels that he wants to give marks for logic then that is allowed, else logic marks are given by the Evaluator.\n\n");
	printf("    -Execution:\n        The evaluator also does the compilation work and checks for errors.\n        If he founds any errors, all errors occured wile compilation are showned to the user, else no errors message is printed.\n        If user personally wants to execute and see execution of the program,that option is provided by the Evaluator\n        It allows user to know the working of the program from which user give marks for the execution.\n        If evaluator founds any errors 0 marks are assigned to the Execution.\n\n\n");
	line_print();
}
// To show the actual working of the program.
working_of_program()
{
	printf("      > At first a menu will be displayed containing 4 options Login, User manual, Change password, Exit.\n        Exit option allows to exit from the program, Change password option allows to change the current password to new password, User manual option will\n        guide the user of the program regarding the working of the program and will provide necessary information required. And login option will do the\n        user authentication and will start the evaluation process.\n\n");
	printf("      > Evaluator then asks to input total marks to be assigned to the program to be evaluated, also takes marks for each categories.\n\n");
	printf("      > After taking marks input evaluator asks to input student's roll_no and source_code file.\n\n");
	printf("      > After taking inputs evalution starts. The evaluator compiles and executes the program, 	If any errors are found evaluator asks user whether he wants\n        to see the error file which contains errors generated during compilation or not.\n\n      > If the code executed without any errors a question is asked to the user if he want to see the execution of the program or not, after showing\n        the execution of the program to the user a question is asked as -Is the student's program working correctly? If user feels he wants to give marks for\n        execution then that option is given to the user and execution marks are accepted from user, else evaluator gives full marks for execution knowing\n        there were no errors found.\n\n      > After finishing execution part, 3 options will be displayed to the user containing 1st option is to show the source_code of the student to the user\n        Although code was executed or not executed but, if user feels that logic of the code was not good or was very good, then user can give marks for the\n        logic as per his/her evaluation, Else option three can be choose to let evaluator give the marks. Note- Logic marks are given by the evaluator\n        thinking that logic is correct. Appropriate message is displayed before doing so.\n\n      > After that documentatin is checked and message will be displayed if documentation is there or not.\n\n      > Then commenting is checked if the student has commented the program well or not, No of comments used in the program are displayed to the user.\n\n      > Modularity of the program is then checked by the evaluator and no of user made functions are displayed to the user.\n\n      > Then proper indentation and required indentation is checked in the code and no of proper indentation are displayed out of required indentations.\n\n      > After checking for all categories and doing evaluation process, marks for each categories with total are displayed to the user.\n\n");
	printf("      > After that options are provided, - to see comment generated by the evaluator on student's code,\n        -to evaluate the program of another student, -to display resulted records of a particular student or records of all students, -to terminate the\n        program with thank you note.\n\n");
	
}

// thank you display  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
thank_you()
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    T H A N K   Y O U\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
line_print()
{
	printf("***********************************************************************************************************************************************************\n\n");
}
/*void check_names(char *name_string, int *roll)
{
	int see;
	*roll=see;
	printf("\n********%d*********\n",see);
	
	if(*roll==1001)
	{
		name_string="AnandKumar Singh";
		
	}
	else if(*roll==1002)
	{
		name_string="Bosco DCruz";
	}
	else if(*roll==1003)
	{
		name_string="Lubna Khan";
	}
	else if(*roll==1004)
	{
		name_string="Shilpa Shetye";
	}
	else if(*roll==1005)
	{
		name_string="Sheldon Rodrigues";
	}
	else if(*roll==1006)
	{
		name_string="Adrich DMello";
	}
	else if(*roll==1007)
	{
		name_string="Prashant Joshi";
	}
	else if(*roll==1008)
	{
		name_string="Seeya Kudtarker";
	}
	else if(*roll==1009)
	{
		name_string="Pascoala DSouza";
	}
	else if(*roll==1010)
	{
		name_string="Andrea Fernandes";
	}
	else if(*roll==1011)
	{
		name_string="Shambhavi Deshpande";
	}
	else if(*roll==1012)
	{
		name_string="Goverdhan M.";
	}
	else if(*roll==1013)
	{
		name_string="Ritesh Naik";
	}
	else if(*roll==1014)
	{
		name_string="Subhod Kumar";
	}
	else if(*roll==1015)
	{
		name_string="Shakeel Anvekar";
	}
	else if(*roll==1016)
	{
		name_string="Diker Pagui";
	}
	else if(*roll==1017)
	{
		name_string="Beryl Gonsalves";
	}
	else if(*roll==1018)
	{
		name_string="Azim Shaik";
	}
	else if(*roll==1019)
	{
		name_string="Leanne Fernandes";
	}
	else if(*roll==1020)
	{
		name_string="Tina Das";
	}
	else if(*roll==1021)
	{
		name_string="Heena Khan";
	}
	else if(*roll==1022)
	{
		name_string="Stalin Desa";
	}
	else if(*roll==1023)
	{
		name_string="David Vaz";
	}
	else if(*roll==1024)
	{
		name_string="Glenford Fernandes";
	}
	else if(*roll==1025)
	{
		name_string="Francesca Rodricks";
	}
	else if(*roll==1026)
	{
		name_string="Tarun Singh";
	}
	else if(*roll==1027)
	{
		name_string="Sunil Chawan";
	}
	else if(*roll==1028)
	{
		name_string="Abhijeet Kumar";
	}
	else if(*roll==1029)
	{
		name_string="Rajan Walecha";
	}
	else if(*roll==1030)
	{
		name_string="Atul Yadav";
	}
	else if(*roll==1031)
	{
		name_string="Mukesh Seemawat";
	}
	else if(*roll==1032)
	{
		name_string="Ryan Dias";
	}
	else
	{
		name_string="Unknown Roll_no";
	}
 // return name_string;	
}*/
