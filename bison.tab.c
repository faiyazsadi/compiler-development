
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "bison.y"

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
    #define STRING 3

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

    void var_does_not_exist(char *name) {
        printf("Variable named \"%s\" doesn't exist.\n", name);
    }
    int get_var_index(char *name) {
        for(int i = 0; i < VAR_CNT; ++i) {
            if(strcmp(varptr[i].name, name) == 0) {
                return i;
            }
        }
        return -1;
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
            printf("Variable name is: %s\n", varptr[p].name);
            printf("Variable value is: %d\n", *varptr[p].ival);
        } else if(t == DECIMAL) {
            double *value = (double *) v;
            varptr[p].dval = malloc(l * sizeof(double));
            for(int i = 0; i < l; ++i) {
                varptr[p].dval[i] = value[i];
            }
            printf("Variable name is: %s\n", varptr[p].name);
            printf("Variable value is: %lf\n", *varptr[p].dval);
        } else if(t == STRING) {
            char **s = ((char**) v);
            varptr[p].sval = malloc(l * sizeof(char**));
            for(int i = 0; i < l; ++i) {
                varptr[p].sval[i] = s[i];
            }
            printf("Variable name is: %s\n", varptr[p].name);
            printf("Variable value is: %s\n", *varptr[p].sval);
        }
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
                } else if(varptr[index].type == STRING) {
                    char str [1000];
                    scanf("%s", str);
                    varptr[index].sval[p] = str;
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
                } else if(varptr[index].type == STRING) {
                    printf("%s\n", varptr[index].sval[0]);
                }
            }
        }
    }
    
    int get_function_index(char *name){
        for(int i = 0; i < FUNC_CNT; ++i) {
            if(strcmp(funcptr[i].fname, name) == 0) {
                return i;
            }
        }
        return -1;
    }
    
    


/* Line 189 of yacc.c  */
#line 227 "bison.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HEADER = 258,
     SCOMMENT = 259,
     MCOMMENT = 260,
     EOL = 261,
     VARIABLE = 262,
     ARROW = 263,
     INPUT = 264,
     PRINT = 265,
     NUMBER_TYPE = 266,
     DECIMAL_TYPE = 267,
     STRING_TYPE = 268,
     NUMBER_VALUE = 269,
     DECIMAL_VALUE = 270,
     STRING_VALUE = 271,
     POW = 272,
     SIN = 273,
     COS = 274,
     TAN = 275,
     LOG10 = 276,
     LOG2 = 277,
     LN = 278,
     SQRT = 279,
     AND = 280,
     OR = 281,
     XOR = 282,
     NOT = 283,
     INC = 284,
     DEC = 285,
     LT = 286,
     GT = 287,
     EQL = 288,
     NEQL = 289,
     LEQL = 290,
     GEQL = 291,
     IF = 292,
     ELIF = 293,
     ELSE = 294,
     FOR = 295,
     IN = 296,
     WHILE = 297,
     DEF = 298,
     CALL = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 156 "bison.y"

	int integer;
	double real;
	char *string;



/* Line 214 of yacc.c  */
#line 315 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 327 "bison.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   565

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    49,     2,     2,
      50,    51,    47,    45,    52,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,     9,    12,    14,    18,    20,
      22,    25,    28,    31,    34,    36,    38,    40,    42,    45,
      50,    54,    56,    61,    65,    67,    78,    80,    82,    84,
      85,    89,    91,    94,    97,   103,   105,   109,   111,   113,
     129,   137,   142,   147,   152,   157,   162,   167,   171,   178,
     179,   181,   184,   186,   189,   191,   199,   204,   207,   210,
     213,   217,   219,   223,   225,   229,   231,   235,   237,   241,
     243,   247,   249,   253,   255,   259,   261,   263,   265,   268,
     271,   274,   277,   281,   285,   289,   293,   297,   301,   305,
     309,   313,   317,   321,   325,   329,   333,   337,   340,   343,
     346,   350,   355,   360,   365,   370,   375,   380
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,     3,    60,    -1,    60,    -1,    -1,    60,
      61,    -1,     6,    -1,    61,     6,    61,    -1,     4,    -1,
       5,    -1,    64,     6,    -1,    62,     6,    -1,    84,     6,
      -1,    91,     6,    -1,    78,    -1,    75,    -1,    76,    -1,
      66,    -1,    71,     6,    -1,    10,    50,    63,    51,    -1,
      63,    52,     7,    -1,     7,    -1,     9,    50,    65,    51,
      -1,    65,    52,     7,    -1,     7,    -1,    43,    68,    50,
      69,    51,     8,    67,    53,    61,    54,    -1,    11,    -1,
      12,    -1,     7,    -1,    -1,    69,    52,    70,    -1,    70,
      -1,    11,     7,    -1,    12,     7,    -1,    44,    72,    50,
      73,    51,    -1,     7,    -1,    73,    52,    74,    -1,    74,
      -1,     7,    -1,    40,    50,     7,    41,    55,    93,    52,
      93,    52,    93,    56,    51,    53,    61,    54,    -1,    42,
      50,    77,    51,    53,    61,    54,    -1,     7,    29,    31,
      93,    -1,     7,    29,    35,    93,    -1,     7,    29,    34,
      93,    -1,     7,    30,    32,    93,    -1,     7,    30,    36,
      93,    -1,     7,    30,    34,    93,    -1,    37,    79,    80,
      -1,    50,    93,    51,    53,    61,    54,    -1,    -1,    81,
      -1,    81,    83,    -1,    83,    -1,    81,    82,    -1,    82,
      -1,    38,    50,    93,    51,    53,    61,    54,    -1,    39,
      53,    61,    54,    -1,    11,    89,    -1,    12,    87,    -1,
      13,    85,    -1,    85,    52,    86,    -1,    86,    -1,     7,
      57,    16,    -1,     7,    -1,    87,    52,    88,    -1,    88,
      -1,     7,    57,    93,    -1,     7,    -1,    89,    52,    90,
      -1,    90,    -1,     7,    57,    93,    -1,     7,    -1,    91,
      52,    92,    -1,    92,    -1,     7,    57,    93,    -1,    14,
      -1,    15,    -1,     7,    -1,    45,    93,    -1,    46,    93,
      -1,    29,    93,    -1,    30,    93,    -1,    93,    45,    93,
      -1,    93,    46,    93,    -1,    93,    47,    93,    -1,    93,
      48,    93,    -1,    93,    49,    93,    -1,    93,    17,    93,
      -1,    93,    33,    93,    -1,    93,    34,    93,    -1,    93,
      31,    93,    -1,    93,    32,    93,    -1,    93,    35,    93,
      -1,    93,    36,    93,    -1,    93,    25,    93,    -1,    93,
      26,    93,    -1,    93,    27,    93,    -1,    28,    93,    -1,
       7,    29,    -1,     7,    30,    -1,    50,    93,    51,    -1,
      18,    50,    93,    51,    -1,    19,    50,    93,    51,    -1,
      20,    50,    93,    51,    -1,    21,    50,    93,    51,    -1,
      22,    50,    93,    51,    -1,    23,    50,    93,    51,    -1,
      24,    50,    93,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   193,   199,   200,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   215,   216,   217,   218,   222,
     227,   230,   237,   242,   245,   250,   254,   255,   259,   271,
     272,   273,   277,   286,   298,   308,   321,   322,   326,   341,
     358,   365,   380,   395,   410,   425,   440,   458,   463,   473,
     474,   475,   476,   480,   481,   484,   499,   509,   510,   511,
     515,   516,   519,   529,   535,   536,   539,   548,   555,   556,
     560,   569,   577,   578,   582,   595,   598,   601,   612,   615,
     618,   621,   624,   627,   630,   633,   636,   640,   644,   648,
     652,   655,   658,   661,   665,   669,   673,   677,   681,   694,
     707,   710,   713,   716,   719,   722,   725,   728
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HEADER", "SCOMMENT", "MCOMMENT", "EOL",
  "VARIABLE", "ARROW", "INPUT", "PRINT", "NUMBER_TYPE", "DECIMAL_TYPE",
  "STRING_TYPE", "NUMBER_VALUE", "DECIMAL_VALUE", "STRING_VALUE", "POW",
  "SIN", "COS", "TAN", "LOG10", "LOG2", "LN", "SQRT", "AND", "OR", "XOR",
  "NOT", "INC", "DEC", "LT", "GT", "EQL", "NEQL", "LEQL", "GEQL", "IF",
  "ELIF", "ELSE", "FOR", "IN", "WHILE", "DEF", "CALL", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'('", "')'", "','", "'{'", "'}'", "'['", "']'", "'='",
  "$accept", "program", "statements", "statement", "print",
  "output_variable", "input", "input_variable", "function_declare",
  "return_types", "function_name", "function_variable", "single_variable",
  "function_call", "user_function_name", "parameters", "single_parameter",
  "for_loop", "while_loop", "while_conditions", "if_blocks", "if_block",
  "else_block", "elif_block", "single_elif_block", "single_else_block",
  "declarations", "str_vars", "str_var", "dec_vars", "dec_var", "num_vars",
  "num_var", "assignments", "assignment", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    43,    45,    42,    47,    37,
      40,    41,    44,   123,   125,    91,    93,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      63,    63,    64,    65,    65,    66,    67,    67,    68,    69,
      69,    69,    70,    70,    71,    72,    73,    73,    74,    75,
      76,    77,    77,    77,    77,    77,    77,    78,    79,    80,
      80,    80,    80,    81,    81,    82,    83,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     3,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     4,
       3,     1,     4,     3,     1,    10,     1,     1,     1,     0,
       3,     1,     2,     2,     5,     1,     3,     1,     1,    15,
       7,     4,     4,     4,     4,     4,     4,     3,     6,     0,
       1,     2,     1,     2,     1,     7,     4,     2,     2,     2,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     4,     0,     3,     2,     1,     8,     9,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,    17,     0,    15,    16,    14,     0,     0,
      73,     0,     0,     0,    71,    57,    69,    67,    58,    65,
      63,    59,    61,     0,    49,     0,     0,    28,     0,    35,
       0,     0,    11,    10,    18,    12,    13,     0,    77,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    24,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    50,
      54,    52,     0,     0,     0,    29,     0,     7,    72,    98,
      99,     0,     0,     0,     0,     0,     0,     0,    97,    80,
      81,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    19,     0,    70,    68,    66,    64,    62,    60,     0,
       0,     0,    53,    51,     0,     0,     0,     0,     0,     0,
       0,    31,    38,     0,    37,     0,     0,     0,     0,     0,
       0,     0,   100,    87,    94,    95,    96,    90,    91,    88,
      89,    92,    93,    82,    83,    84,    85,    86,    23,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,     0,   101,   102,   103,
     104,   105,   106,   107,     0,     0,    56,     0,    41,    43,
      42,    44,    46,    45,     0,     0,    30,    36,    48,     0,
       0,    40,    26,    27,     0,     0,     0,     0,    55,     0,
       0,     0,    25,     0,     0,     0,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    20,    21,    78,    22,    76,    23,   224,
      48,   150,   151,    24,    50,   153,   154,    25,    26,    94,
      27,    44,    88,    89,    90,    91,    28,    41,    42,    38,
      39,    35,    36,    29,    30,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yytype_int16 yypact[] =
{
       9,   -44,    15,    83,    83,   -44,   -44,   -44,   -44,   -40,
     -13,    20,    41,    79,    93,    51,    60,    61,   108,   109,
     111,   112,   113,   -44,   115,   -44,   -44,   -44,   116,     3,
     -44,    84,   117,   121,    74,    80,   -44,    76,    85,   -44,
      78,    86,   -44,    84,   -31,   129,   132,   -44,    97,   -44,
      99,    83,   -44,   -44,   -44,   -44,   -44,   143,    -8,   -44,
     -44,   102,   103,   104,   105,   106,   107,   114,    84,    84,
      84,    84,    84,    84,   510,   -44,   -28,   -44,   -20,    84,
      41,    84,    79,   146,    93,   240,   122,   110,   -44,   -31,
     -44,   -44,   130,     4,   123,    33,   166,   111,   -44,   -44,
     -44,    84,    84,    84,    84,    84,    84,    84,   516,   510,
     510,    18,    18,   267,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,   -44,
     168,   -44,   169,   510,   -44,   510,   -44,   -44,   -44,   125,
      84,    83,   -44,   -44,   133,   -21,   -16,   131,   178,   182,
       5,   -44,   -44,    17,   -44,   294,   321,   348,   375,   402,
     429,   456,   -44,   510,   516,   516,   516,    -6,    -6,    -6,
      -6,    -6,    -6,    18,    18,   175,   175,   175,   -44,   -44,
      83,   483,    -5,    84,    84,    84,    84,    84,    84,    84,
      83,   -44,   -44,   185,    33,   -44,   166,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    -4,   141,   -44,   174,   510,   510,
     510,   510,   510,   510,    -3,    35,   -44,   -44,   -44,    83,
      84,   -44,   -44,   -44,   144,    -2,   207,    83,   -44,    84,
      -1,   134,   -44,   145,   149,    83,     0,   -44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   197,   -32,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,    10,   -44,   -44,   -44,    16,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   124,   126,   -44,   -44,   127,   -44,
     135,   -44,   136,   -44,   157,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      85,    51,    51,    51,    51,    51,    51,    86,    87,    56,
     184,   114,     1,   185,   186,     5,   187,    31,   188,    97,
     189,    99,   100,   129,   130,   108,   109,   110,   111,   112,
     113,   131,   132,   145,   146,   114,   133,    32,   135,   124,
     125,   126,   127,   128,   148,   149,   222,   223,    34,   206,
     218,   221,   228,   232,   237,    57,   193,   194,   155,   156,
     157,   158,   159,   160,   161,   126,   127,   128,   195,   196,
      33,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    37,     6,     7,     8,
       9,    58,    10,    11,    12,    13,    14,   181,    59,    60,
      40,    43,    61,    62,    63,    64,    65,    66,    67,   182,
      45,    46,    68,    69,    70,    47,    49,    51,    52,    53,
      15,    54,    55,    16,    75,    17,    18,    19,    77,    71,
      72,    79,    80,    81,    73,    83,    92,    82,    84,    93,
     207,   208,   209,   210,   211,   212,   213,    95,   204,    96,
       9,   114,   101,   102,   103,   104,   105,   106,   214,   115,
     116,   117,   137,   141,   107,   118,   119,   120,   121,   122,
     123,   144,   140,   152,   147,   178,   179,   226,   180,   124,
     125,   126,   127,   128,   190,   191,   231,   225,   183,   192,
     233,   114,   114,   215,   219,   230,   234,   227,     4,   115,
     116,   117,   235,   236,   216,   118,   119,   120,   121,   122,
     123,   138,   217,   142,    98,   143,   134,   136,     0,   124,
     125,   126,   127,   128,   114,     0,   220,     0,     0,     0,
       0,     0,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   114,     0,   229,
       0,     0,     0,     0,     0,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,   114,   124,   125,   126,   127,   128,
       0,   139,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,   114,   124,   125,   126,   127,   128,     0,   162,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,   114,   124,
     125,   126,   127,   128,     0,   197,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,   114,   124,   125,   126,   127,
     128,     0,   198,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,   114,   124,   125,   126,   127,   128,     0,   199,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,   114,
     124,   125,   126,   127,   128,     0,   200,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,   114,   124,   125,   126,
     127,   128,     0,   201,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,   114,   124,   125,   126,   127,   128,     0,
     202,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
     114,   124,   125,   126,   127,   128,     0,   203,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,   114,   124,   125,
     126,   127,   128,   114,   205,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   118,   119,   120,
     121,   122,   123,     0,     0,   124,   125,   126,   127,   128,
       0,   124,   125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
      43,     6,     6,     6,     6,     6,     6,    38,    39,     6,
      31,    17,     3,    34,    35,     0,    32,    57,    34,    51,
      36,    29,    30,    51,    52,    68,    69,    70,    71,    72,
      73,    51,    52,    29,    30,    17,    79,    50,    81,    45,
      46,    47,    48,    49,    11,    12,    11,    12,     7,    54,
      54,    54,    54,    54,    54,    52,    51,    52,   101,   102,
     103,   104,   105,   106,   107,    47,    48,    49,    51,    52,
      50,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     7,     4,     5,     6,
       7,     7,     9,    10,    11,    12,    13,   140,    14,    15,
       7,    50,    18,    19,    20,    21,    22,    23,    24,   141,
      50,    50,    28,    29,    30,     7,     7,     6,     6,     6,
      37,     6,     6,    40,     7,    42,    43,    44,     7,    45,
      46,    57,    52,    57,    50,    57,     7,    52,    52,     7,
     183,   184,   185,   186,   187,   188,   189,    50,   180,    50,
       7,    17,    50,    50,    50,    50,    50,    50,   190,    25,
      26,    27,    16,    53,    50,    31,    32,    33,    34,    35,
      36,    41,    50,     7,    51,     7,     7,   220,    53,    45,
      46,    47,    48,    49,    53,     7,   229,   219,    55,     7,
      56,    17,    17,     8,    53,   227,    51,    53,     1,    25,
      26,    27,    53,   235,   194,    31,    32,    33,    34,    35,
      36,    84,   196,    89,    57,    89,    80,    82,    -1,    45,
      46,    47,    48,    49,    17,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    17,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    45,    46,    47,    48,    49,
      -1,    51,    25,    26,    27,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    45,    46,    47,    48,    49,    -1,    51,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    45,
      46,    47,    48,    49,    -1,    51,    25,    26,    27,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    45,    46,    47,    48,
      49,    -1,    51,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    45,    46,    47,    48,    49,    -1,    51,
      25,    26,    27,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      45,    46,    47,    48,    49,    -1,    51,    25,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    45,    46,    47,
      48,    49,    -1,    51,    25,    26,    27,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    45,    46,    47,    48,    49,    -1,
      51,    25,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    45,    46,    47,    48,    49,    -1,    51,    25,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    45,    46,
      47,    48,    49,    17,    51,    25,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    31,    32,    33,
      34,    35,    36,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    45,    46,    47,    48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    59,    60,    60,     0,     4,     5,     6,     7,
       9,    10,    11,    12,    13,    37,    40,    42,    43,    44,
      61,    62,    64,    66,    71,    75,    76,    78,    84,    91,
      92,    57,    50,    50,     7,    89,    90,     7,    87,    88,
       7,    85,    86,    50,    79,    50,    50,     7,    68,     7,
      72,     6,     6,     6,     6,     6,     6,    52,     7,    14,
      15,    18,    19,    20,    21,    22,    23,    24,    28,    29,
      30,    45,    46,    50,    93,     7,    65,     7,    63,    57,
      52,    57,    52,    57,    52,    93,    38,    39,    80,    81,
      82,    83,     7,     7,    77,    50,    50,    61,    92,    29,
      30,    50,    50,    50,    50,    50,    50,    50,    93,    93,
      93,    93,    93,    93,    17,    25,    26,    27,    31,    32,
      33,    34,    35,    36,    45,    46,    47,    48,    49,    51,
      52,    51,    52,    93,    90,    93,    88,    16,    86,    51,
      50,    53,    82,    83,    41,    29,    30,    51,    11,    12,
      69,    70,     7,    73,    74,    93,    93,    93,    93,    93,
      93,    93,    51,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,     7,     7,
      53,    93,    61,    55,    31,    34,    35,    32,    34,    36,
      53,     7,     7,    51,    52,    51,    52,    51,    51,    51,
      51,    51,    51,    51,    61,    51,    54,    93,    93,    93,
      93,    93,    93,    93,    61,     8,    70,    74,    54,    53,
      52,    54,    11,    12,    67,    61,    93,    53,    54,    52,
      61,    93,    54,    56,    51,    53,    61,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 190 "bison.y"
    {
        printf("COMPILATION SUCCESSFUL!\n");
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 193 "bison.y"
    {
        printf("COMPILATION SUCCESSFUL!\n");
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 199 "bison.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 212 "bison.y"
    {
        condition_matched = 0;
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 222 "bison.y"
    {

    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 227 "bison.y"
    {
        print_value((yyvsp[(3) - (3)].string));
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 230 "bison.y"
    {
        print_value((yyvsp[(1) - (1)].string));

    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 237 "bison.y"
    {
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 242 "bison.y"
    {
        read_value((yyvsp[(3) - (3)].string), 0);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 245 "bison.y"
    {
        read_value((yyvsp[(1) - (1)].string), 0);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 250 "bison.y"
    {
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 259 "bison.y"
    {
        int index = get_function_index((yyvsp[(1) - (1)].string));
        if(index != -1) {
            printf("Function Already Declared.\n");
        } else {
            printf("Declaring Function\n");
            funcptr[FUNC_CNT].fname = malloc((strlen((yyvsp[(1) - (1)].string)) + 10) * sizeof(char));
            strcpy(funcptr[FUNC_CNT].fname, (yyvsp[(1) - (1)].string));
            funcptr[FUNC_CNT].var_cnt = 0;
            funcptr[FUNC_CNT].fptr = malloc(4 * sizeof(stack));
        }
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 277 "bison.y"
    {
        int index = funcptr[FUNC_CNT].var_cnt;
        int value = 0;
        store_value((yyvsp[(2) - (2)].string), NUMBER, 1, VAR_CNT, &value, 0);
        funcptr[FUNC_CNT].fptr[index] = varptr[VAR_CNT];
        VAR_CNT++;
        funcptr[FUNC_CNT].var_cnt++;
        FUNC_CNT++;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 286 "bison.y"
    {
        int index = funcptr[FUNC_CNT].var_cnt;
        double value = 0;
        store_value((yyvsp[(2) - (2)].string), DECIMAL, 1, VAR_CNT, &value, 0);
        funcptr[FUNC_CNT].fptr[index] = varptr[VAR_CNT];
        VAR_CNT++;
        funcptr[FUNC_CNT].var_cnt++;
        FUNC_CNT++;
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 298 "bison.y"
    {
        if(function_rejected) {
            printf("Function Not Declared.\n");
        } else {
            printf("Function Successfully Called.\n");
        }
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 308 "bison.y"
    {
        int index = get_function_index((yyvsp[(1) - (1)].string));
        if(index == -1) {
            printf("Function Doesn't Exist.\n");
        } else {
            current_function = index;
            current_parameter = 0;
            function_rejected = 0;
        }
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 326 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (1)].string));
        if(current_parameter >= funcptr[current_function].var_cnt) {
            printf("Way too many arguments.\n");
            function_rejected = 1;
        } else if(funcptr[current_function].fptr[current_parameter].type != varptr[index].type) {
            printf("Data Types Don't Match.\n");
            function_rejected = 1;
        } else {
            current_parameter++;
        }
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 341 "bison.y"
    {
        printf("For Loop Block\n");
        int from = (yyvsp[(6) - (15)].real);
        int end = (yyvsp[(8) - (15)].real);
        int by = (yyvsp[(10) - (15)].real);
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
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 358 "bison.y"
    {
        printf("WHILE BLOCK\n");
        for(int i = 0; i < (yyvsp[(3) - (7)].real); ++i) {
            printf("WHILE Loop Iteration: %d\n", i + 1);
        }
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 365 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (4)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (4)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value > (yyvsp[(4) - (4)].real)) {
                (yyval.real) = -1;
            } else {
                (yyval.real) = (int) (yyvsp[(4) - (4)].real) - value;
            }
        }
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 380 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (4)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (4)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value > (yyvsp[(4) - (4)].real)) {
                (yyval.real) = -1;
            } else {
                (yyval.real) = (int) (yyvsp[(4) - (4)].real) - value + 1;
            }
        }
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 395 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (4)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (4)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value > (yyvsp[(4) - (4)].real)) {
                (yyval.real) = -1;
            } else {
                (yyval.real) = (int) (yyvsp[(4) - (4)].real) - value;
            }
        }
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 410 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (4)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (4)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value < (yyvsp[(4) - (4)].real)) {
                (yyval.real) = -1;
            } else {
                (yyval.real) = value - (int) (yyvsp[(4) - (4)].real);
            }
        }
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 425 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (4)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (4)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value < (yyvsp[(4) - (4)].real)) {
                (yyval.real) = -1;
            } else {
                (yyval.real) = value - (int) (yyvsp[(4) - (4)].real) + 1;
            }
        }
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 440 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (4)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (4)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Variable should be NUMBER Type.\n");
        } else {
            int value = varptr[index].ival[0];
            if(value < (yyvsp[(4) - (4)].real)) {
                (yyval.real) = -1;
            } else {
                (yyval.real) = value - (int) (yyvsp[(4) - (4)].real);
            }
        }
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 458 "bison.y"
    {

    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 463 "bison.y"
    {
        printf("IF BLOCK\n");
        int condition = (fabs((yyvsp[(2) - (6)].real)) > 1e-9);
        if(condition) {
            condition_matched = 1;
            printf("Condition Matched in IF Block.\n");
        } else {
            printf("Condition Didn't match in IF Block.\n");
        }
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 484 "bison.y"
    {
        if(condition_matched == 1) {
            printf("Condition Already Matched in IF Block.\n");
        } else {
            int condition = (fabs((yyvsp[(3) - (7)].real)) > 1e-9);
            if(condition) {
                printf("Condition Matched in ELIF Block.\n");
                condition_matched = 1;
            } else {
                printf("Condition Didn't Match in ELIF Block.\n");
            }
        }
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 499 "bison.y"
    {
        if(condition_matched == 1) {
            printf("Condition Already Matched.\n");
        } else {
            printf("Condition Matched in ELSE Block.\n");
        }
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 519 "bison.y"
    {
        int exists = check_unique((yyvsp[(1) - (3)].string));
        if(exists == DUPLICATE) {
            not_unique((yyvsp[(1) - (3)].string));
        } else {
            char *value = (yyvsp[(3) - (3)].string);
            store_value((yyvsp[(1) - (3)].string), STRING, 1, VAR_CNT, &value, 0);
            VAR_CNT++;
        }
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 529 "bison.y"
    {
        char *value = "";
        store_value((yyvsp[(1) - (1)].string), STRING, 1, VAR_CNT, &value, 0);
        VAR_CNT++;
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 539 "bison.y"
    {
        if(check_unique((yyvsp[(1) - (3)].string)) == DUPLICATE) {
            not_unique((yyvsp[(1) - (3)].string));
        } else {
            double value = (yyvsp[(3) - (3)].real);
            store_value((yyvsp[(1) - (3)].string), DECIMAL, 1, VAR_CNT, &value, 0);
            VAR_CNT++;
        }
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 548 "bison.y"
    {
        double value = 0.0;
        store_value((yyvsp[(1) - (1)].string), DECIMAL, 1, VAR_CNT, &value, 0);
        VAR_CNT++;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 560 "bison.y"
    {
        if(check_unique((yyvsp[(1) - (3)].string)) == UNIQUE) {
            int value = (yyvsp[(3) - (3)].real);
            store_value((yyvsp[(1) - (3)].string), NUMBER, 1, VAR_CNT, &value, 0);
            VAR_CNT++;
        } else {
            not_unique((yyvsp[(1) - (3)].string));
        }
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 569 "bison.y"
    {
        int value = 0;
        store_value((yyvsp[(1) - (1)].string), NUMBER, 1, VAR_CNT, &value, 0);
        VAR_CNT++;
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 582 "bison.y"
    {
        int i = get_var_index((yyvsp[(1) - (3)].string));
        if(i == -1) {
            var_does_not_exist((yyvsp[(1) - (3)].string));
            (yyval.real) = 0;
        } else if(varptr[i].type == NUMBER) {
            (yyval.real) = varptr[i].ival[0];
        } else if(varptr[i].type == DECIMAL) {
            (yyval.real) = varptr[i].dval[0];
        }
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 595 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (1)].integer);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 598 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (1)].real);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 601 "bison.y"
    {
        int i = get_var_index((yyvsp[(1) - (1)].string));
        if(i == -1) {
            var_does_not_exist((yyvsp[(1) - (1)].string));
            (yyval.real) = 0;
        } else if(varptr[i].type == NUMBER) {
            (yyval.real) = varptr[i].ival[0];
        } else if(varptr[i].type == DECIMAL) {
            (yyval.real) = varptr[i].dval[0];
        }
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 612 "bison.y"
    {
        (yyval.real) = (yyvsp[(2) - (2)].real);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 615 "bison.y"
    {
        (yyval.real) = -(yyvsp[(2) - (2)].real);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 618 "bison.y"
    {
        (yyval.real) = (yyvsp[(2) - (2)].real);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 621 "bison.y"
    {
        (yyval.real) = (yyvsp[(2) - (2)].real);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 624 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) + (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 627 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 630 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) * (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 633 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 636 "bison.y"
    {

        (yyval.real) = (int)(yyvsp[(1) - (3)].real) % (int)(yyvsp[(3) - (3)].real);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 640 "bison.y"
    {

        (yyval.real) = pow((yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 645 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) == (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 649 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) != (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 652 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) < (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 655 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) > (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 658 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) <= (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 662 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) >= (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 666 "bison.y"
    {
        (yyval.real) = ( (yyvsp[(1) - (3)].real) && (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 670 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) || (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 674 "bison.y"
    {
        (yyval.real) = ((int)(yyvsp[(1) - (3)].real) ^ (int)(yyvsp[(3) - (3)].real));
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 678 "bison.y"
    {
        (yyval.real) = !(yyvsp[(2) - (2)].real);
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 682 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (2)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (2)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Can't Increment Incompatible Types.\n");
        } else {
            varptr[index].ival[0]++;
            (yyval.real) = varptr[index].ival[0];

        }
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 695 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (2)].string));
        if(index == -1) {
            var_does_not_exist((yyvsp[(1) - (2)].string));
        } else if(varptr[index].type != NUMBER) {
            printf("Can't Increment Incompatible Types.\n");
        } else {
            varptr[index].ival[0]--;
            (yyval.real) = varptr[index].ival[0];

        }
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 707 "bison.y"
    {
        (yyval.real) = (yyvsp[(2) - (3)].real);
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 710 "bison.y"
    {
        (yyval.real) = sin((yyvsp[(3) - (4)].real));
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 713 "bison.y"
    {
        (yyval.real) = cos((yyvsp[(3) - (4)].real));
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 716 "bison.y"
    {
        (yyval.real) = tan((yyvsp[(3) - (4)].real));
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 719 "bison.y"
    {
        (yyval.real) = log10((yyvsp[(3) - (4)].real));
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 722 "bison.y"
    {
        (yyval.real) = log2((yyvsp[(3) - (4)].real));
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 725 "bison.y"
    {
        (yyval.real) = log((yyvsp[(3) - (4)].real));
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 728 "bison.y"
    {
        (yyval.real) = sqrt((yyvsp[(3) - (4)].real));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2620 "bison.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 734 "bison.y"

int main() {
    varptr = malloc(MAXN_VAR_ALLOWED * sizeof(info));
    funcptr = malloc(MAXN_FUNC_ALLOWED * sizeof(stack));
    FILE *yyin = freopen("input.txt", "r", stdin);
    FILE *yyout = freopen("output.txt", "w", stdout);
    yyparse();
    fclose(yyin);
    fclose(yyout);
    free(varptr);
    free(funcptr);
    return 0;
}
