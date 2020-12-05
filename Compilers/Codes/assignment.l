%{
    int yylex();
    void yyerror(char *s);
    int line=0;
    int spaces=0;
%}
alphabet [a-zA-Z]
number [0-9]
newline \n
whitespace [ \t] 
special_character [\!\?\.\[\]\(\)\,]
%x newline_state
%x spaces_state
%x special_state
%%
<<EOF>> {printf("\nThe Number of Spaces are %d.\n",spaces);printf("The Number of lines are %d.\n",line);exit(0);}
{alphabet}|{number} {printf("%s",yytext);}
{newline} {BEGIN newline_state;} 
{whitespace} {BEGIN spaces_state;} 
{special_character} {BEGIN special_state;printf("%s",yytext);}

<newline_state>{alphabet}|{number} {BEGIN INITIAL;line++;printf("\n%s",yytext);} 
<newline_state>{newline} {BEGIN newline_state;}
<newline_state>{special_character} {BEGIN special_state;printf("\n%s",yytext);}
<newline_state>{whitespace} ; 

<spaces_state>{alphabet}|{number} {BEGIN INITIAL;spaces++;printf(" %s",yytext);} 
<spaces_state>{newline} {BEGIN newline_state;}
<spaces_state>{special_character} {BEGIN special_state;printf("%s",yytext);}
<spaces_state>{whitespace} {BEGIN spaces_state;}
 
<special_state>{alphabet}|{number} {BEGIN INITIAL;printf("%s",yytext);} 
<special_state>{newline} {BEGIN newline_state;} 
<special_state>{special_character} {BEGIN special_state;printf("%s",yytext);}
<special_state>{whitespace} {BEGIN special_state;} 
%%
int yywrap(){ return 1;} 
void yyerror (char *s) {fprintf (stderr, "%s at line %d\n", s, yylineno);} 
int main() 
{ 
 yyin = fopen("Input.txt", "r"); 
 if(yyin==NULL) printf("\nError\n"); 
 else{  
 printf("\Started Lexing\n"); printf("17ETCS002124 K Srikanth\n");yylex();} 
fclose(yyin); 
return 0; 
}
