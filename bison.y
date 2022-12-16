%{
    #include <stdio.h>
    int yylex();
    int yyerror(char* s);
%}

%token IMPORT EOL

%%

program: IMPORT statements EOL {
    printf("Header Found!\n");
}
;


statements:
;

%%
int main() {
    FILE *yyin = freopen("input.txt", "r", stdin);
    yyparse();
    fclose(yyin);
    return 0;
}