%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int yylex();
    int yyerror(char* s);

    #define YYDEBUG 1
    #define UNIQUE 1
    #define DUPLICATE -1
    #define NUMBER  1
    #define DECIMAL 2

    const int MAXN_VAR_ALLOWED = 20;
    int VAR_CNT = 0;
    typedef struct {
        char *name;
        int type;
        int length;
        int *ival;
        double *dval;
        char **sval;
        int is_array;
    } info;
    info *varptr;

    int check_unique(char *name) {
        for(int i = 0; i < VAR_CNT; ++i) {
            if(strcmp(varptr[i].name, name) == 0) {
                return DUPLICATE;
            }
        }
        return UNIQUE;
    } 

    void not_unique(char *name) {
        printf("Variable named \"%s\" already exists.\n", name);
    }

    void store_value(char *n, int t, int l, int p, void *v, int is_Array) {
        varptr[p].name = n;
        varptr[p].type = t;
        varptr[p].length = l;
        varptr[p].is_array = is_Array;
        if(t == NUMBER) {
            int *value = (int *) v;
            varptr[p].ival = malloc(l * sizeof(int));
            for(int i = 0; i < l; ++i) {
                varptr[p].ival[i] = value[i];
            }
        }
        printf("Variable name is: %s\n", varptr[p].name);
        printf("Variable value is: %d\n", *varptr[p].ival);
    }

    int get_var_index(char *name) {
        for(int i = 0; i < VAR_CNT; ++i) {
            if(strcmp(varptr[i].name, name) == 0) {
                return i;
            }
        }
        return -1;
    }

    void var_does_not_exist(char *name) {
        printf("Variable named \"%s\" doesn't exist.\n", name);
    }
    
%}

%error-verbose
%debug
%union {
	int integer;
	double real;
	char *string;
}

%token HEADER SCOMMENT MCOMMENT EOL
%token VARIABLE
%token NUMBER_TYPE DECIMAL_TYPE
%token NUMBER_VALUE DECIMAL_VALUE

%type <integer> NUMBER_VALUE
%type <real> DECIMAL_VALUE statements statement assignment expr
%type <string> VARIABLE NUMBER_TYPE DECIMAL_TYPE


%%

program:
    HEADER statements {
    printf("Header Found!\n");
}
;


statements:
    {}
    | statements statement
;

statement: 
    EOL
    |SCOMMENT
    |MCOMMENT
    |declarations EOL
    |assignments EOL
;

declarations:
    NUMBER_TYPE num_vars
;

num_vars: 
    num_vars ',' num_var
    |num_var
;

num_var: 
    VARIABLE '=' expr {
        if(check_unique($1) == UNIQUE) {
            int value = $3;
            store_value($1, NUMBER, 1, VAR_CNT, &value, 0);
            VAR_CNT++;
        } else {
            not_unique($1);
        }
    }
    |VARIABLE {
        int value = 0;
        store_value($1, NUMBER, 1, VAR_CNT, &value, 0);
        VAR_CNT++;
    }
;

assignments:
    assignments ',' assignment
    |assignment
;

assignment:
    VARIABLE '=' expr {
        int i = get_var_index($1);
        if(i == -1) {
            var_does_not_exist($1);
            $$ = 0;
        } else if(varptr[i].type == NUMBER) {
            $$ = varptr[i].ival[0];
        } else if(varptr[i].type == DECIMAL) {
            $$ = varptr[i].dval[0];
        }
    }
;
expr:
    NUMBER_VALUE {
        $$ = $1;
    }
    |DECIMAL_VALUE {
        $$ = $1;
    }
    |VARIABLE {
        int i = get_var_index($1);
        if(i == -1) {
            var_does_not_exist($1);
            $$ = 0;
        } else if(varptr[i].type == NUMBER) {
            $$ = varptr[i].ival[0];
        } else if(varptr[i].type == DECIMAL) {
            $$ = varptr[i].dval[0];
        }
    }

%%
int main() {
    varptr = malloc(MAXN_VAR_ALLOWED * sizeof(info));
    FILE *yyin = freopen("input.txt", "r", stdin);
    yyparse();
    fclose(yyin);
    return 0;
}