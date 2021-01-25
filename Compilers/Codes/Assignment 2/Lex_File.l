%{
#include "Yacc_File.tab.h"
int yylineno=1;
extern void yyerror (char *s);

%}
// K Srikanth 17ETCS002124
alphabet [a-zA-Z]
digit [0-9]
underscore _
whitespace [ \t\r\f\v]+
%x PREPROCESSING
%x MULTILINECOMMENT
%x SINGLELINECOMMENT

%%


<<EOF>>         {exit(0);}  
\"%d\"          {return INT_FORMAT;}
\"%f\"          {return FLOAT_FORMAT;}
\"%s\"          {return STRING_FORMAT;}
\".*\"          {yylval.string=strdup(yytext);return STRING_LITERAL;}
[ \t]+	              ;
\n                  { yylineno++;}
\+                  {return PLUS;}
\-                  {return MINUS;}
\*                  {return MULT;}
\/                  {return DIV;}
\^                  {return POW;}
\%                  {return MOD;}
"--"                                {return DECREMENT;}
"++"                                {return INCREMENT;}
">"                                 {return GT;}
"<"                                 {return LT;}
">="                                {return GT_EQ;}
"<="                                {return LT_EQ;}
"=="                                {return EQUAL;}
"||"                                {return OR;}
"&&"                                {return AND;}
"!"                                 {return NOT;}
"!="                                {return NOT_EQUAL;}
return                { return RETURN;}
break                 { return BREAK;}
main                  { return MAIN;}
if                    { yylval.string=strdup(yytext); return IF;}
else                  { yylval.string=strdup(yytext); return ELSE;}
while                 { yylval.string=strdup(yytext); return WHILE;}
for                   { yylval.string=strdup(yytext); return FOR;}
int	                  { yylval.string=strdup(yytext); return INT;}
float                 { yylval.string=strdup(yytext); return FLOAT;}
char                  { yylval.string=strdup(yytext); return CHAR;}
void    			        { yylval.string=strdup(yytext); return VOID;}
printf                { return PRINTF;}
scanf                 { return SCANF;}

^"#include"                                  {BEGIN PREPROCESSING;}
<PREPROCESSING>{whitespace}                   ;
<PREPROCESSING>"<"[^<>\n]*">"                {BEGIN INITIAL;}
<PREPROCESSING>\"[^<>\n]*\"                  {BEGIN INITIAL;}
<PREPROCESSING>"\n"                          {yylineno++; BEGIN INITIAL;}
<PREPROCESSING>.                             {yyerror("Mistake in Header");}

"/*"                                         {BEGIN MULTILINECOMMENT;}
<MULTILINECOMMENT>.|{whitespace}             ;
<MULTILINECOMMENT>\n                         {yylineno++;}
<MULTILINECOMMENT>"*/"                       {BEGIN INITIAL;}
<MULTILINECOMMENT>"/*"                       {yyerror("Comment format invalid");}
"//"                                         {BEGIN SINGLELINECOMMENT;}
<SINGLELINECOMMENT>\n                       {yylineno++; BEGIN INITIAL;}
<SINGLELINECOMMENT>.                        ;

({underscore}|{alphabet})({underscore}|{alphabet}|{digit})*  {
  yylval.string=strdup(yytext);
  return VAR;
  }

{digit}+        		{ 
  yylval.int_val=atoi(yytext);
  return INT_VALUE;
  }

{digit}+[\.]{digit}+            {
  yylval.float_val=atof(yytext); 
  return FLOAT_VALUE;
 }

(\"{alphabet}\"|'{alphabet}')     { 
  yylval.string=strdup(yytext);   
  return CHAR_LITERAL;
  }

.				{ return yytext[0];}  

%%

