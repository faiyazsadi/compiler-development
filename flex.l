%{
    #include "bison.tab.h"
%}

IDENTIFIER                  [a-zA-Z][_a-zA-Z0-9]*

%%
"import"[ ]+{IDENTIFIER}[.][h][ ]* {
    return IMPORT;
}

";" {
    return EOL;
}

%%
int yywrap() {
    return 1;
}

int yyerror(char *s){
	fprintf(stderr,"error: %s\n", s);
    return 1;
}