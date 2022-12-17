%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    int yylex();
    int yyerror(char* s);

    #define YYDEBUG 1
    #define UNIQUE 1
    #define DUPLICATE -1
    #define NUMBER  1
    #define DECIMAL 2

    const int MAXN_VAR_ALLOWED = 20;
    const int MAXN_FUNC_ALLOWED = 20;
    int VAR_CNT = 0;
    int FUNC_CNT = 0;
    int condition_matched = 0;
    int current_function = 0;
    int current_parameter = 0;
    int function_rejected = 0;

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

    typedef struct {
        char *fname;
        info *fptr;
        int var_cnt;
    } stack;
    stack *funcptr;

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
    void read_value(char *name, int p) {
        printf("Enter Input for %s: ", name);
        int index = get_var_index(name);
        printf("index: %d\n", index);
        if (index == -1) {
            var_does_not_exist(name);
        } else {
            if(p >= varptr[index].length) {
                printf("Maximum Number of Variables Used.\n");
            } else {
                if (varptr[index].type == DECIMAL) {
                    scanf("%lf", &varptr[index].dval[p]);
                } else if (varptr[index].type == NUMBER) {
                    scanf("%d", &varptr[index].ival[p]);
                    printf("%d\n", varptr[index].ival[p]);
                }
            }
        }
    }
    void print_value(char *name) {
        int index = get_var_index(name);
        if(index == -1) {
            var_does_not_exist(name);
        } else {
            if(varptr[index].is_array) {

            } else {
                printf("Value of %s is: ", name);
                if(varptr[index].type == NUMBER) {
                    printf("%d\n", varptr[index].ival[0]);
                } else if(varptr[index].type == DECIMAL) {
                    printf("%lf\n", varptr[index].dval[0]);
                }
            }
        }
    }
    int get_var_index(char *name) {
        for(int i = 0; i < VAR_CNT; ++i) {
            if(strcmp(varptr[i].name, name) == 0) {
                return i;
            }
        }
        return -1;
    }
    int get_function_index(char *name){
        for(int i = 0; i < FUNC_CNT; ++i) {
            if(strcmp(funcptr[i].fname, name) == 0) {
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
%token VARIABLE ARROW INPUT PRINT
%token NUMBER_TYPE DECIMAL_TYPE
%token NUMBER_VALUE DECIMAL_VALUE
%token AND OR XOR NOT
%token INC DEC
%token LT GT EQL NEQL LEQL GEQL
%token IF ELIF ELSE
%token FOR IN WHILE
%token DEF CALL

%type <integer> NUMBER_VALUE
%type <real> DECIMAL_VALUE statements statement assignment expr while_conditions
%type <string> VARIABLE NUMBER_TYPE DECIMAL_TYPE

%nonassoc ELIF 
%nonassoc ELSE

%left INC DEC
%left AND OR XOR NOT
%left LT GT EQL NEQL LEQL GEQL
%left '+' '-'
%left '*' '/' '%'

%%

program:
    statements {
        printf("Header Found!\n");
    }
;

statements:
    {}
    |statements statement
;

statement: 
    EOL
    |SCOMMENT
    |MCOMMENT
    |input EOL
    |print EOL
    |declarations EOL
    |assignments EOL
    |if_blocks {
        condition_matched = 0;
    }
    |for_loop
    |while_loop
    |function_declare
    |function_call EOL
;

print:
    PRINT '(' output_variable ')' {

    }
;
output_variable:
    output_variable ',' VARIABLE {
        print_value($3);
    }
    |VARIABLE {
        print_value($1);

    }
;

input:
    INPUT '(' input_variable ')' {
    }
;

input_variable:
    input_variable ',' VARIABLE {
        read_value($3, 0);
    }
    |VARIABLE {
        read_value($1, 0);
    }

function_declare:
    DEF function_name '(' function_variable ')' ARROW return_types '{' statement '}' {
        printf("FUNCTION DECLARATION\n");
    }
;
return_types:
    NUMBER_TYPE
    |DECIMAL_TYPE
;

function_name:
    VARIABLE {
        int index = get_function_index($1);
        if(index != -1) {
            printf("Function Already Declared.\n");
        } else {
            printf("Declaring Function\n");
            funcptr[FUNC_CNT].fname = malloc((strlen($1) + 10) * sizeof(char));
            strcpy(funcptr[FUNC_CNT].fname, $1);
            funcptr[FUNC_CNT].var_cnt = 0;
            funcptr[FUNC_CNT].fptr = malloc(4 * sizeof(stack));
        }
    }
function_variable:
    |function_variable ',' single_variable
    | single_variable
;

single_variable:
    NUMBER_TYPE VARIABLE {
        int index = funcptr[FUNC_CNT].var_cnt;
        int value = 0;
        store_value($2, NUMBER, 1, VAR_CNT, &value, 0);
        funcptr[FUNC_CNT].fptr[index] = varptr[VAR_CNT];
        VAR_CNT++;
        funcptr[FUNC_CNT].var_cnt++;
        FUNC_CNT++;
    }
    |DECIMAL_TYPE VARIABLE {
        int index = funcptr[FUNC_CNT].var_cnt;
        double value = 0;
        store_value($2, DECIMAL, 1, VAR_CNT, &value, 0);
        funcptr[FUNC_CNT].fptr[index] = varptr[VAR_CNT];
        VAR_CNT++;
        funcptr[FUNC_CNT].var_cnt++;
        FUNC_CNT++;
    }
;

function_call:
    CALL user_function_name '(' parameters ')' EOL {
        if(function_rejected) {
            printf("Function Not Declared.\n");
        } else {
            printf("Function Successfully Called.\n");
        }
    }
;

user_function_name:
    VARIABLE {
        int index = get_function_index($1);
        if(index == -1) {
            printf("Function Doesn't Exist.\n");
        } else {
            current_function = index;
            current_parameter = 0;
            function_rejected = 0;
        }
    }
;

parameters:
    parameters ',' single_parameter
    |single_parameter
;

single_parameter: 
    VARIABLE {
        int index = get_var_index($1);
        if(current_parameter > funcptr[current_function].var_cnt) {
            printf("Way too many arguments.\n");
            function_rejected = 1;
        } else if(funcptr[current_function].fptr[current_parameter].type != varptr[index].type) {
            printf("Data Types Don't Match.\n");
            function_rejected = 1;
        } else {
            current_parameter++;
        }
    }
;

for_loop:
    FOR '(' VARIABLE IN '[' expr ',' expr ',' expr ']' ')' '{' statement '}' {
        printf("For Loop Block\n");
        int from = $6;
        int end = $8;
        int by = $10;
        int dif = end - from;
        if(dif * by < 0) {
            printf("Infinite FOR Loop\n");
        } else {
            int c = 1;
            for(int i = from; i <= end; i += by) {
                printf("For Loop Iteration: %d\n", c);
                c++;
            }
        }
    }
while_loop:
    WHILE '(' while_conditions ')' '{' statement '}' {
        printf("WHILE BLOCK\n");
        for(int i = 0; i < $3; ++i) {
            printf("WHILE Loop Iteration: %d\n", i + 1);
        }
    }
while_conditions:
    VARIABLE INC LT expr {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value > $4) {
                $$ = -1;
            } else {
                $$ = (int) $4 - value;
            }
        }
    }
    |VARIABLE INC LEQL expr {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value > $4) {
                $$ = -1;
            } else {
                $$ = (int) $4 - value + 1;
            }
        }
    }
    |VARIABLE INC NEQL expr {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value > $4) {
                $$ = -1;
            } else {
                $$ = (int) $4 - value;
            }
        }
    }
    |VARIABLE DEC GT expr {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value < $4) {
                $$ = -1;
            } else {
                $$ = value - (int) $4;
            }
        }
    }
    |VARIABLE DEC GEQL expr {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value < $4) {
                $$ = -1;
            } else {
                $$ = value - (int) $4 + 1;
            }
        }
    }
    |VARIABLE DEC NEQL expr {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value < $4) {
                $$ = -1;
            } else {
                $$ = value - (int) $4;
            }
        }
    }
;

if_blocks:
    IF if_block else_block {

    }

if_block:
    '(' expr ')' '{' statement '}' {
        printf("IF BLOCK\n");
        int condition = (fabs($2) > 1e-9);
        if(condition) {
            condition_matched = 1;
            printf("Condition Matched in IF Block.\n");
        } else {
            printf("Condition Didn't match in IF Block.\n");
        }
    }
else_block:
    |elif_block
    |elif_block single_else_block
    |single_else_block
;

elif_block:
    elif_block single_elif_block
    | single_elif_block

single_elif_block:
    ELIF '(' expr ')' '{' statement '}' {
        if(condition_matched == 1) {
            printf("Condition Already Matched in IF Block.\n");
        } else {
            int condition = (fabs($3) > 1e-9);
            if(condition) {
                printf("Condition Matched in ELIF Block.\n");
                condition_matched = 1;
            } else {
                printf("Condition Didn't Match in ELIF Block.\n");
            }
        }
    }

single_else_block:
    ELSE '{' statement '}' {
        if(condition_matched == 1) {
            printf("Condition Already Matched.\n");
        } else {
            printf("Condition Matched in ELSE Block.\n");
        }
    }


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
    |'+' expr {
        $$ = $2;
    }
    |'-' expr {
        $$ = -$2;
    }
    |INC expr {
        $$ = $2;
    }
    |DEC expr {
        $$ = $2;
    }
    |expr '+' expr {
        $$ = $1 + $3;
    }
    |expr '-' expr {
        $$ = $1 - $3;
    }
    |expr '*' expr {
        $$ = $1 * $3;
    } 
    |expr '/' expr {
        $$ = $1 / $3;
    }
    |expr '%' expr {

        $$ = (int)$1 % (int)$3;
    }
    |expr EQL expr         
    {
        $$ = ($1 == $3);
    }
    |expr NEQL expr        
    {
        $$ = ($1 != $3);
    }
    |expr LT expr {
        $$ = ($1 < $3);
    }
    |expr GT expr {
        $$ = ($1 > $3);
    }
    |expr LEQL expr {
        $$ = ($1 <= $3);
    }
    |expr GEQL expr        
    {
        $$ = ($1 >= $3);
    }
    |expr AND expr         
    {
        $$ = ( $1 && $3);
    }
    |expr OR expr          
    {
        $$ = ($1 || $3);
    }
    |expr XOR expr         
    {
        $$ = ((int)$1 ^ (int)$3);
    }
    |NOT expr              
    {
        $$ = !$2;
    }
    |VARIABLE INC
    {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Can't Increment Incompatible Types.\n");
        } else {
            varptr[index].ival[0]++;
            $$ = varptr[index].ival[0];

        }
    }
    |VARIABLE DEC       
    {
        int index = get_var_index($1);
        if(index == -1) {
            var_does_not_exist($1);
        } else if(varptr[index].type != NUMBER) {
            printf("Can't Increment Incompatible Types.\n");
        } else {
            varptr[index].ival[0]--;
            $$ = varptr[index].ival[0];

        }
    }
; 
    

%%
int main() {
    varptr = malloc(MAXN_VAR_ALLOWED * sizeof(info));
    funcptr = malloc(MAXN_FUNC_ALLOWED * sizeof(stack));
    // FILE *yyin = freopen("input.txt", "r", stdin);
    yyparse();
    // fclose(yyin);
    free(varptr);
    free(funcptr);
    return 0;
}