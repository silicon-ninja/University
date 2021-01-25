%{
void yyerror (char *s);
#include <stdio.h>     
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max_lexemes 100

extern FILE *yyin;
extern int yyparse();
extern int yylex();
extern int yylineno;
int count=0;

struct symbol{
    char type[10];
    char value[30];
    char name[10];
}symbol_table[max_lexemes];



int lookup(char *name)
{
	int i,j;
	for(i=0;i<=count;i++)
	{
		j=1;
		if(strcmp(symbol_table[i].name,name)==0) {
 			j=0;
 			break;
 		}
	}
 	if(j==1)
	{
		printf("Undeclared variable %s in line %d\n",name,yylineno);
		exit(0);
	}
	return i;
} 

void addvar(char* type, char* name){
	++count;
	strcpy(symbol_table[count].type,type);
	strcpy(symbol_table[count].name,name);
}

void setValue(char* value,int type,int index){
	char* expected_type=symbol_table[index].type; 
	//variable type from symbol table
	if(type==1){   
		if(strcmp(expected_type,"int")==0    
		    || strcmp(expected_type,"float")==0){  // floating values can have integer values also
			strcpy(symbol_table[index].value,value);
			return ;
		}
		else{
			printf("Type mismatch at %d",yylineno);
			exit(0);
		}
	}
	if(type==2){
		if(strcmp(expected_type,"float")==0){
			strcpy(symbol_table[index].value,value);
			return;
		}
		else{
			printf("type mismatch at %d",yylineno);
			exit(0);
		}
	}
	if(type==3){
		if(strcmp(expected_type,"char")==0){
			strcpy(symbol_table[index].value,value);
			return;
		}
		else{
			printf("type mismatch at %d",yylineno);
			exit(0);
		}
	}
		printf("Undefined type encountered at line %d\n",yylineno);
		exit(0);
}

char* getValue(char* name){
	return symbol_table[lookup(name)].value;
}

char* getTypeString(char* name){
	return symbol_table[lookup(name)].type;
}

int getTypeInt(char* name){
	if(strcmp(symbol_table[lookup(name)].type,"int")==0)
		return 1;
	else if(strcmp(symbol_table[lookup(name)].type,"float")==0)
		return 2;
	else if(strcmp(symbol_table[lookup(name)].type,"char")==0)
		return 3;
	return 0;
}



void display()
{
	int i;
	printf("SYMBOL TABLE\n");
	printf("%20s\t%20s\t%20s\n","Variable Name","Type","value");
	for(i=0;i<=count;i++)
		printf("\n%20s\t%20s\t%20s\n",symbol_table[i].name,symbol_table[i].type,symbol_table[i].value);
}


int notReservedKeyword(char* word){
	if(strcmp("int",word)==0 || strcmp("float",word)==0 || strcmp("char",word)==0 ||
	 strcmp("while",word)==0 || strcmp("do",word)==0 || strcmp("for",word)==0||
    strcmp("if",word)==0 || strcmp("else",word)==0){
    printf("Reserved keyword %s used at line %d \n",word,yylineno);
    exit(0);
  }
  return 1;
}

%}


%start START

%left ','
%right '='
%left OR
%left AND
%left EQUAL NOT_EQUAL 
%left GT LT LT_EQ GT_EQ
%left PLUS MINUS
%left MULT DIV MOD
%right NOT POW
%nonassoc IF_LESS_THAN_ELSE
%nonassoc ELSE

%union 
{
    int int_val;
    char *string;
	float float_val;
}

%token SCANF PRINTF STRING_FORMAT FLOAT_FORMAT INT_FORMAT CHAR_FORMAT
%token UNDERSCORE NOT IF FOR ELSE INCREMENT DECREMENT WHILE 
%token MAIN PREPROCESSING RETURN BREAK
%token  VOID
%token <string> VAR FLOAT INT CHAR
%token <int_val> INT_VALUE
%token <float_val> FLOAT_VALUE
%token <string> CHAR_LITERAL STRING_LITERAL

%type <string> TYPE UNARY_EXP
%type <int_val> A_INTEXP CONDITION TERM
%type <float_val> A_FLOATEXP

%%
START: PROGRAM  {printf("This Program has no Syntax Error \nEverything Was Accepted !\n");display();}

PROGRAM: RETURN_TYPE MAIN '(' ')' COMPOUND_STATEMENT  {printf("Function completed\n");}
|DECL ';' PROGRAM									{printf("Global declaration section\n");}
|PREPROCESSING PROGRAM							{printf("PREPROCESSING started\n");}
;

RETURN_TYPE:
INT				
|FLOAT
|CHAR
|VOID
;

COMPOUND_STATEMENT: '{' STATEMENTS_LIST '}' 
;

STATEMENTS_LIST: STATEMENT STATEMENTS_LIST 
		|STATEMENT 
;

STATEMENT:  DECL ';'
		   	|ASSIGN_EXP ';'
			|PRINTF_STMT ';'
			|SCANF_STMT	';'
			|UNARY_EXP ';'
			|IF_STMT        
			|IF_ELSE_STMT   
			|WHILE_STMT     
			|FOR_STMT	
			|RETURN VAR_OR_VALUE ';'	
			|BREAK ';'
			|
;

VAR_OR_VALUE: VAR|INT_VALUE|FLOAT_VALUE|CHAR_LITERAL|STRING_LITERAL
;
			
COMPOUND_OR_STMT: COMPOUND_STATEMENT|STATEMENT
;

IF_STMT:
IF '(' CONDITION ')' COMPOUND_OR_STMT {
	if($3)
		printf("line %d: IF control encountered, condition evaluated to true\n",yylineno);
	else
		printf("line %d: IF control encountered, condition evaluated to false"
				" shifting control to next statement\n",yylineno);
		}
;

IF_ELSE_STMT:
IF '(' CONDITION ')' COMPOUND_OR_STMT ELSE COMPOUND_OR_STMT{
	if($3)
		printf("line %d: IF ELSE control encountered, condition evaluated to true\n",yylineno);
	else
		printf("line %d: IF ELSE control encountered, condition evaluated to false"
				", running else part\n",yylineno);
		}
;


WHILE_STMT:
WHILE '(' CONDITION ')' COMPOUND_OR_STMT {
	if($3)
		printf("line %d: WHILE loop encountered, condition evaluated to true\n",yylineno);
	else
		printf("line %d: WHILE loop encountered, condition evaluated to false"
				", shifting to next statement after WHILE loop\n",yylineno);
		}
;

FOR_STMT:
FOR '(' DECL_OR_ASSIGN ';' CONDITION ';' UNARY_OR_ASSIGN ')' COMPOUND_OR_STMT {
	if($5)
		printf("line %d: FOR loop encountered, condition evaluated to true\n",yylineno);
	else
		printf("line %d: FOR loop encountered, condition evaluated to false"
				", shifting to next statement after FOR loop\n",yylineno);
		}
| FOR '(' ';' ';' ')'{printf("line %d: INFINITE FOR loop encountered\n",yylineno);}
;

DECL_OR_ASSIGN: DECL|ASSIGN_EXP
;


UNARY_OR_ASSIGN: UNARY_EXP|ASSIGN_EXP
;

ASSIGN_EXP:
VAR '=' A_INTEXP  {
				printf("line %d:Expression evaluated to %d and assigned to variable %s\n",yylineno,$3,$1);
			   if(getTypeInt($1)){
				   printf("%s = %d\n",$1,$3);
					char intstring[10];
					sprintf(intstring,"%10d",$3);
				   setValue(intstring,getTypeInt($1),lookup($1));}
			   }
|VAR '=' A_FLOATEXP {
				printf("line %d:Expression evaluated to %f and assigned to variable %s\n",yylineno,$3,$1);
			   if(getTypeInt($1)){
				   printf("%s = %f\n",$1,$3);
					char floatstring[10];
					sprintf(floatstring,"%7.3f",$3);
			   	   setValue(floatstring,getTypeInt($1),lookup($1));}
				}
;

DECL: TYPE VARLIST 
;

TYPE:
INT		{strcpy($$,$1);}
|FLOAT  {strcpy($$,$1);}
|CHAR   {strcpy($$,$1);}
;

VARLIST:
VAR  { printf("line %d:variable %s declared\n",yylineno,$1);
	if(notReservedKeyword($1))
			addvar($<string>0,$1);} EQUAL_PART    
|VARLIST ',' VAR { 
	if(notReservedKeyword($<string>1))
				addvar($<string>0,$<string>3);}  EQUAL_PART 
|VAR '[' INT_VALUE ']' {printf("line %d: %s type 1D array named %s declared with size %d \n ",
							 yylineno,$<string>0,$<string>1,$<int_val>3);}
|VAR '[' INT_VALUE ']' '[' INT_VALUE ']' {
							 printf("line %d: %s type 2D array named %s declared with order %d X %d \n ",
							 yylineno,$<string>0,$<string>1,$<int_val>3,$<int_val>6);}
;

EQUAL_PART:
'=' INT_VALUE {
	printf("line %d:Integer value %d assigned to variable\n",yylineno,$2);
	char value[15];
	sprintf(value,"%d",$2);
	setValue(value,1,count);}
|'=' FLOAT_VALUE {
	printf("line %d:Float value %f assigned to variable\n",yylineno,$2);
	char value[15];
	sprintf(value,"%f",$2);
	setValue(value,2,count);}
|'=' CHAR_LITERAL {
	printf("line %d:character %s assigned to variable\n",yylineno,$2);
	setValue($2,3,count);}
|'=' VAR { 
	printf("line %d:variable %s assigned to variable\n",yylineno,$2);
	setValue(getValue($2),getTypeInt($2),count);}
|'=' A_INTEXP {
	printf("line %d:Expression evaluated to %d and assigned to variable\n",yylineno,$2);
	char intstring[10];
	sprintf(intstring,"%10d",$2);
	setValue(intstring, 1 ,count);}
|'=' A_FLOATEXP {
	printf("line %d:Expression evaluated to %f and assigned to variable\n",yylineno,$2);
	char floatstring[10];
	sprintf(floatstring,"%7.3f",$2);
	setValue(floatstring, 2 ,count);}
|
;

PRINTF_STMT:
	PRINTF '(' INT_FORMAT ',' VAR ')' 		{ printf("line %d: %d\n",yylineno,atoi(getValue($5)));}
	|PRINTF '(' FLOAT_FORMAT ',' VAR ')' 	{ printf("line %d: %f\n",yylineno,atof(getValue($5)));}
	|PRINTF '(' STRING_FORMAT ',' VAR ')' 	{ printf("line %d: %s\n",yylineno,getValue($5));}
	|PRINTF '(' STRING_LITERAL ')' 			{ printf("line %d: %s \n",yylineno ,$3);}
	|PRINTF '(' INT_FORMAT ',' A_INTEXP ')' {printf("line %d: %d\n",yylineno,$5);}
	|PRINTF '(' FLOAT_FORMAT ',' A_FLOATEXP ')' {printf("line %d: %f\n",yylineno,$5);}
	|PRINTF '(' INT_FORMAT ',' CONDITION ')' {printf("line %d: %d\n",yylineno,$5);}
;

SCANF_STMT:
	SCANF '(' INT_FORMAT ',' '&' VAR ')' {	int num;
											printf("input:");
											scanf("%d",&num);
											printf("line %d: %d scanned\n",yylineno-1,num);
											}
	|SCANF '(' FLOAT_FORMAT ',' '&' VAR ')' {	float num;
											printf("input:");
											scanf("%f",&num);
											printf("line %d: %7.3f scanned\n",yylineno,num);
											}
	|SCANF '(' STRING_FORMAT ',' '&' VAR ')' {	
											char character;
											printf("input:");
											scanf("%s",&character);
											printf("line %d: %s scanned\n",yylineno,&character);
											}
;
UNARY_EXP:
	VAR INCREMENT {char string_num[10];
					sprintf(string_num,"%d\n",atoi(getValue($1))+1);
					setValue(string_num,1,lookup($1));
					printf("line %d: %s incremented\n",yylineno,$1);
					}
	|VAR DECREMENT {char string_num[10];
					sprintf(string_num,"%d\n",atoi(getValue($1))-1);
					setValue(string_num,1,lookup($1));
					printf("line %d: %s decremented\n",yylineno,$1);
					}
	|INCREMENT VAR {char string_num[10];
					sprintf(string_num,"%d\n",atoi(getValue($2))+1);
					setValue(string_num,1,lookup($2));
					printf("line %d: %s incremented\n",yylineno,$2);
					}
	|DECREMENT VAR {char string_num[10];
					sprintf(string_num,"%d\n",atoi(getValue($2))-1);
					setValue(string_num,1,lookup($2));
					printf("line %d: %s decremented\n",yylineno,$2);
					}
;

A_INTEXP:
	'(' A_INTEXP ')' 			{$$=$2;}
	|A_INTEXP PLUS A_INTEXP 	{$$=$1+$3;}
	|A_INTEXP MINUS A_INTEXP 	{$$=$1-$3;}
	|A_INTEXP MULT A_INTEXP 	{$$=$1*$3;}
	|A_INTEXP MOD A_INTEXP 		{$$=$1%$3;}
	|A_INTEXP DIV A_INTEXP {if($3==0)yyerror("Division by zero");
								else $$=$1/$3;}
	|A_INTEXP POW A_INTEXP 	{$$=pow($1,$3);}
	|INT_VALUE 				{$$=$1;}
	|VAR 					{if(getTypeInt($1)==1) $$=atoi(getValue($1));
								else yyerror("Type mismatch");}
;
A_FLOATEXP:
	'(' A_FLOATEXP ')' {$$=$2;}
	|A_FLOATEXP PLUS A_FLOATEXP {$$=$1+$3;}
	|A_FLOATEXP MINUS A_FLOATEXP {$$=$1-$3;}
	|A_FLOATEXP MULT A_FLOATEXP {$$=$1*$3;}
	|A_FLOATEXP DIV A_FLOATEXP {
		if($3==0.0)yyerror("Division by zero");
		else $$=$1/$3;}
	|A_FLOATEXP POW A_FLOATEXP {$$=pow($1,$3);}
	|FLOAT_VALUE {$$=$1;}
	|INT_VALUE {$$=(float)$1;}
	|VAR {
		if(getTypeInt($1)==1 || getTypeInt($1)==2)$$=atof(getValue($1));
		else yyerror("Type mismatch");}
;
	
CONDITION:
CONDITION AND CONDITION 	{$$=$1 && $3;}
|CONDITION OR CONDITION 	{$$=$1 || $3;}
|NOT CONDITION 				{$$=!$2;}
|TERM NOT_EQUAL TERM 		{$$=$1 != $3;}
|TERM EQUAL TERM 			{$$=$1 == $3;}
|TERM GT TERM 				{$$=$1 > $3;}
|TERM GT_EQ TERM 			{$$=$1 >= $3;}
|TERM LT TERM 				{$$=$1 < $3;}
|TERM LT_EQ TERM 			{$$=$1 <= $3;}
;

TERM:
VAR {$$=atoi(getValue($1));}
|INT_VALUE {$$=$1;}
;

CONDITION:
FLOAT_VALUE NOT_EQUAL FLOAT_VALUE   {$$=$1 != $3;}
|FLOAT_VALUE  EQUAL FLOAT_VALUE     {$$=$1 == $3;}
|FLOAT_VALUE  GT FLOAT_VALUE        {$$=$1 > $3;}
|FLOAT_VALUE  GT_EQ FLOAT_VALUE     {$$=$1 >= $3;}
|FLOAT_VALUE  LT FLOAT_VALUE        {$$=$1 < $3;}
|FLOAT_VALUE  LT_EQ FLOAT_VALUE     {$$=$1 <= $3;}
;

%%

int main(){
	//#ifdef YYDEBUG
  	//yydebug = 1;
	//#endif
	yyin = fopen("InputFile.c", "r");
	if(yyin==NULL )
		printf("\nError\n");
	else{
		printf("\nStarted Parsing\n");
		printf("\nK Srikanth 17ETCS002124\n");
			yyparse();
	}
	fclose(yyin);
	
    return 0;
}

int yywrap(){
    return 1;
}

void yyerror (char *s) {fprintf (stderr, "%s at line %d\n", s, yylineno);} 