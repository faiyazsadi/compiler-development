
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
    


/* Line 189 of yacc.c  */
#line 202 "bison.tab.c"

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
     NUMBER_VALUE = 268,
     DECIMAL_VALUE = 269,
     AND = 270,
     OR = 271,
     XOR = 272,
     NOT = 273,
     INC = 274,
     DEC = 275,
     LT = 276,
     GT = 277,
     EQL = 278,
     NEQL = 279,
     LEQL = 280,
     GEQL = 281,
     IF = 282,
     ELIF = 283,
     ELSE = 284,
     FOR = 285,
     IN = 286,
     WHILE = 287,
     DEF = 288,
     CALL = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 131 "bison.y"

	int integer;
	double real;
	char *string;



/* Line 214 of yacc.c  */
#line 280 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 292 "bison.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      40,    41,    37,    35,    42,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    18,
      21,    24,    27,    29,    31,    33,    35,    38,    43,    47,
      49,    54,    58,    60,    71,    73,    75,    77,    78,    82,
      84,    87,    90,    97,    99,   103,   105,   107,   123,   131,
     136,   141,   146,   151,   156,   161,   165,   172,   173,   175,
     178,   180,   183,   185,   193,   198,   201,   205,   207,   211,
     213,   217,   219,   223,   225,   227,   229,   232,   235,   238,
     241,   245,   249,   253,   257,   261,   265,   269,   273,   277,
     281,   285,   289,   293,   297,   300,   303
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    -1,    50,    51,    -1,     6,
      -1,     4,    -1,     5,    -1,    54,     6,    -1,    52,     6,
      -1,    74,     6,    -1,    77,     6,    -1,    68,    -1,    65,
      -1,    66,    -1,    56,    -1,    61,     6,    -1,    10,    40,
      53,    41,    -1,    53,    42,     7,    -1,     7,    -1,     9,
      40,    55,    41,    -1,    55,    42,     7,    -1,     7,    -1,
      33,    58,    40,    59,    41,     8,    57,    43,    51,    44,
      -1,    11,    -1,    12,    -1,     7,    -1,    -1,    59,    42,
      60,    -1,    60,    -1,    11,     7,    -1,    12,     7,    -1,
      34,    62,    40,    63,    41,     6,    -1,     7,    -1,    63,
      42,    64,    -1,    64,    -1,     7,    -1,    30,    40,     7,
      31,    45,    79,    42,    79,    42,    79,    46,    41,    43,
      51,    44,    -1,    32,    40,    67,    41,    43,    51,    44,
      -1,     7,    19,    21,    79,    -1,     7,    19,    25,    79,
      -1,     7,    19,    24,    79,    -1,     7,    20,    22,    79,
      -1,     7,    20,    26,    79,    -1,     7,    20,    24,    79,
      -1,    27,    69,    70,    -1,    40,    79,    41,    43,    51,
      44,    -1,    -1,    71,    -1,    71,    73,    -1,    73,    -1,
      71,    72,    -1,    72,    -1,    28,    40,    79,    41,    43,
      51,    44,    -1,    29,    43,    51,    44,    -1,    11,    75,
      -1,    75,    42,    76,    -1,    76,    -1,     7,    47,    79,
      -1,     7,    -1,    77,    42,    78,    -1,    78,    -1,     7,
      47,    79,    -1,    13,    -1,    14,    -1,     7,    -1,    35,
      79,    -1,    36,    79,    -1,    19,    79,    -1,    20,    79,
      -1,    79,    35,    79,    -1,    79,    36,    79,    -1,    79,
      37,    79,    -1,    79,    38,    79,    -1,    79,    39,    79,
      -1,    79,    23,    79,    -1,    79,    24,    79,    -1,    79,
      21,    79,    -1,    79,    22,    79,    -1,    79,    25,    79,
      -1,    79,    26,    79,    -1,    79,    15,    79,    -1,    79,
      16,    79,    -1,    79,    17,    79,    -1,    18,    79,    -1,
       7,    19,    -1,     7,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   170,   171,   175,   176,   177,   178,   179,
     180,   181,   182,   185,   186,   187,   188,   192,   197,   200,
     207,   212,   215,   220,   225,   226,   230,   242,   243,   244,
     248,   257,   269,   279,   292,   293,   297,   312,   329,   336,
     351,   366,   381,   396,   411,   429,   434,   444,   445,   446,
     447,   451,   452,   455,   470,   480,   484,   485,   489,   498,
     506,   507,   511,   524,   527,   530,   541,   544,   547,   550,
     553,   556,   559,   562,   565,   569,   573,   577,   580,   583,
     586,   590,   594,   598,   602,   606,   619
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HEADER", "SCOMMENT", "MCOMMENT", "EOL",
  "VARIABLE", "ARROW", "INPUT", "PRINT", "NUMBER_TYPE", "DECIMAL_TYPE",
  "NUMBER_VALUE", "DECIMAL_VALUE", "AND", "OR", "XOR", "NOT", "INC", "DEC",
  "LT", "GT", "EQL", "NEQL", "LEQL", "GEQL", "IF", "ELIF", "ELSE", "FOR",
  "IN", "WHILE", "DEF", "CALL", "'+'", "'-'", "'*'", "'/'", "'%'", "'('",
  "')'", "','", "'{'", "'}'", "'['", "']'", "'='", "$accept", "program",
  "statements", "statement", "print", "output_variable", "input",
  "input_variable", "function_declare", "return_types", "function_name",
  "function_variable", "single_variable", "function_call",
  "user_function_name", "parameters", "single_parameter", "for_loop",
  "while_loop", "while_conditions", "if_blocks", "if_block", "else_block",
  "elif_block", "single_elif_block", "single_else_block", "declarations",
  "num_vars", "num_var", "assignments", "assignment", "expr", 0
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
     285,   286,   287,   288,   289,    43,    45,    42,    47,    37,
      40,    41,    44,   123,   125,    91,    93,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    53,    53,
      54,    55,    55,    56,    57,    57,    58,    59,    59,    59,
      60,    60,    61,    62,    63,    63,    64,    65,    66,    67,
      67,    67,    67,    67,    67,    68,    69,    70,    70,    70,
      70,    71,    71,    72,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     4,     3,     1,
       4,     3,     1,    10,     1,     1,     1,     0,     3,     1,
       2,     2,     6,     1,     3,     1,     1,    15,     7,     4,
       4,     4,     4,     4,     4,     3,     6,     0,     1,     2,
       1,     2,     1,     7,     4,     2,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     6,     7,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,    15,
       0,    13,    14,    12,     0,     0,    61,     0,     0,     0,
      59,    55,    57,     0,    47,     0,     0,    26,     0,    33,
       0,     9,     8,    16,    10,    11,     0,    65,    63,    64,
       0,     0,     0,     0,     0,    62,    22,     0,    19,     0,
       0,     0,     0,     0,     0,    45,    48,    52,    50,     0,
       0,     0,    27,     0,    60,    85,    86,    84,    68,    69,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    17,     0,
      58,    56,     0,     0,     0,    51,    49,     0,     0,     0,
       0,     0,     0,     0,    29,    36,     0,    35,    81,    82,
      83,    77,    78,    75,    76,    79,    80,    70,    71,    72,
      73,    74,    21,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    31,     0,     0,     0,
       0,     0,     0,    54,     0,    39,    41,    40,    42,    44,
      43,     0,     0,    28,    32,    34,    46,     0,     0,    38,
      24,    25,     0,     0,     0,     0,    53,     0,     0,     0,
      23,     0,     0,     0,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    17,    59,    18,    57,    19,   172,
      38,   113,   114,    20,    40,   116,   117,    21,    22,    71,
      23,    34,    65,    66,    67,    68,    24,    31,    32,    25,
      26,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int16 yypact[] =
{
    -104,    10,     2,  -104,  -104,  -104,  -104,   -31,   -12,   -10,
      26,    -3,     0,     5,    56,    64,  -104,    41,    73,  -104,
      95,  -104,  -104,  -104,    96,    -4,  -104,   104,   105,   106,
      67,    61,  -104,   104,   -14,   108,   109,  -104,    79,  -104,
      80,  -104,  -104,  -104,  -104,  -104,   114,    46,  -104,  -104,
     104,   104,   104,   104,   104,   236,  -104,    40,  -104,    42,
     104,    26,   182,    85,    83,  -104,   -14,  -104,  -104,    97,
      66,    86,    81,   122,  -104,  -104,  -104,   242,   236,   236,
     -34,   -34,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,  -104,   123,  -104,   124,
     236,  -104,    89,   104,     2,  -104,  -104,    91,    18,    22,
      90,   127,   130,    53,  -104,  -104,    55,  -104,   242,   242,
     242,   -13,   -13,   -13,   -13,   -13,   -13,   -34,   -34,  -104,
    -104,  -104,  -104,  -104,     2,   209,    94,   104,   104,   104,
     104,   104,   104,   104,     2,  -104,  -104,   137,    81,   140,
     122,   110,   112,  -104,   126,   236,   236,   236,   236,   236,
     236,   113,    88,  -104,  -104,  -104,  -104,     2,   104,  -104,
    -104,  -104,   115,   116,   154,     2,  -104,   104,   128,    52,
    -104,   118,   131,     2,   129,  -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,  -103,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,     8,  -104,  -104,  -104,     3,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,   100,   101,  -104,  -104,   120,  -104,
     136,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      62,   136,    45,    93,    94,    95,     4,     5,     6,     7,
       3,     8,     9,    10,    63,    64,    27,    77,    78,    79,
      80,    81,    91,    92,    93,    94,    95,   100,    28,    11,
      29,   151,    12,    30,    13,    14,    15,    33,    46,   138,
      35,   161,   139,   140,   141,    36,   142,    41,   143,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    37,   173,    75,    76,    82,    83,    84,
     135,    39,   178,    85,    86,    87,    88,    89,    90,    42,
     184,    96,    97,    98,    99,   108,   109,    91,    92,    93,
      94,    95,   111,   112,   147,   148,   149,   150,   181,   170,
     171,    43,    44,    61,   154,   155,   156,   157,   158,   159,
     160,    47,    56,    58,    60,    69,    70,    48,    49,    72,
      73,     7,    50,    51,    52,   103,   104,   110,   107,   115,
     132,   133,   134,   144,   145,   174,   137,   146,   153,    53,
      54,    82,    83,    84,   179,   162,   164,    85,    86,    87,
      88,    89,    90,   165,   166,   167,   163,   169,   175,   182,
     176,    91,    92,    93,    94,    95,   105,   106,   168,    82,
      83,    84,   180,   185,   183,    85,    86,    87,    88,    89,
      90,   101,    74,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,   177,    82,    83,    84,
       0,     0,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,     0,   102,    82,    83,    84,     0,     0,     0,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,     0,
     152,    82,    83,    84,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    85,    86,    87,    88,    89,    90,     0,
       0,    91,    92,    93,    94,    95,     0,    91,    92,    93,
      94,    95
};

static const yytype_int16 yycheck[] =
{
      33,   104,     6,    37,    38,    39,     4,     5,     6,     7,
       0,     9,    10,    11,    28,    29,    47,    50,    51,    52,
      53,    54,    35,    36,    37,    38,    39,    60,    40,    27,
      40,   134,    30,     7,    32,    33,    34,    40,    42,    21,
      40,   144,    24,    25,    22,    40,    24,     6,    26,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     7,   167,    19,    20,    15,    16,    17,
     103,     7,   175,    21,    22,    23,    24,    25,    26,     6,
     183,    41,    42,    41,    42,    19,    20,    35,    36,    37,
      38,    39,    11,    12,    41,    42,    41,    42,    46,    11,
      12,     6,     6,    42,   137,   138,   139,   140,   141,   142,
     143,     7,     7,     7,    47,     7,     7,    13,    14,    40,
      40,     7,    18,    19,    20,    40,    43,    41,    31,     7,
       7,     7,    43,    43,     7,   168,    45,     7,    44,    35,
      36,    15,    16,    17,   177,     8,     6,    21,    22,    23,
      24,    25,    26,   150,    44,    43,   148,    44,    43,    41,
      44,    35,    36,    37,    38,    39,    66,    66,    42,    15,
      16,    17,    44,    44,    43,    21,    22,    23,    24,    25,
      26,    61,    46,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    -1,    -1,    42,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    -1,    41,    15,    16,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,
      41,    15,    16,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    21,    22,    23,    24,    25,    26,    -1,
      -1,    35,    36,    37,    38,    39,    -1,    35,    36,    37,
      38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     4,     5,     6,     7,     9,    10,
      11,    27,    30,    32,    33,    34,    51,    52,    54,    56,
      61,    65,    66,    68,    74,    77,    78,    47,    40,    40,
       7,    75,    76,    40,    69,    40,    40,     7,    58,     7,
      62,     6,     6,     6,     6,     6,    42,     7,    13,    14,
      18,    19,    20,    35,    36,    79,     7,    55,     7,    53,
      47,    42,    79,    28,    29,    70,    71,    72,    73,     7,
       7,    67,    40,    40,    78,    19,    20,    79,    79,    79,
      79,    79,    15,    16,    17,    21,    22,    23,    24,    25,
      26,    35,    36,    37,    38,    39,    41,    42,    41,    42,
      79,    76,    41,    40,    43,    72,    73,    31,    19,    20,
      41,    11,    12,    59,    60,     7,    63,    64,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,     7,     7,    43,    79,    51,    45,    21,    24,
      25,    22,    24,    26,    43,     7,     7,    41,    42,    41,
      42,    51,    41,    44,    79,    79,    79,    79,    79,    79,
      79,    51,     8,    60,     6,    64,    44,    43,    42,    44,
      11,    12,    57,    51,    79,    43,    44,    42,    51,    79,
      44,    46,    41,    43,    51,    44
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
#line 164 "bison.y"
    {
        printf("Header Found!\n");
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 170 "bison.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 182 "bison.y"
    {
        condition_matched = 0;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 192 "bison.y"
    {

    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 197 "bison.y"
    {
        print_value((yyvsp[(3) - (3)].string));
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 200 "bison.y"
    {
        print_value((yyvsp[(1) - (1)].string));

    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 207 "bison.y"
    {
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 212 "bison.y"
    {
        read_value((yyvsp[(3) - (3)].string), 0);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 215 "bison.y"
    {
        read_value((yyvsp[(1) - (1)].string), 0);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 220 "bison.y"
    {
        printf("FUNCTION DECLARATION\n");
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 230 "bison.y"
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

  case 30:

/* Line 1455 of yacc.c  */
#line 248 "bison.y"
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

  case 31:

/* Line 1455 of yacc.c  */
#line 257 "bison.y"
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

  case 32:

/* Line 1455 of yacc.c  */
#line 269 "bison.y"
    {
        if(function_rejected) {
            printf("Function Not Declared.\n");
        } else {
            printf("Function Successfully Called.\n");
        }
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 279 "bison.y"
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

  case 36:

/* Line 1455 of yacc.c  */
#line 297 "bison.y"
    {
        int index = get_var_index((yyvsp[(1) - (1)].string));
        if(current_parameter > funcptr[current_function].var_cnt) {
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

  case 37:

/* Line 1455 of yacc.c  */
#line 312 "bison.y"
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

  case 38:

/* Line 1455 of yacc.c  */
#line 329 "bison.y"
    {
        printf("WHILE BLOCK\n");
        for(int i = 0; i < (yyvsp[(3) - (7)].real); ++i) {
            printf("WHILE Loop Iteration: %d\n", i + 1);
        }
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 336 "bison.y"
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

  case 40:

/* Line 1455 of yacc.c  */
#line 351 "bison.y"
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

  case 41:

/* Line 1455 of yacc.c  */
#line 366 "bison.y"
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
#line 381 "bison.y"
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

  case 43:

/* Line 1455 of yacc.c  */
#line 396 "bison.y"
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

  case 44:

/* Line 1455 of yacc.c  */
#line 411 "bison.y"
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
#line 429 "bison.y"
    {

    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 434 "bison.y"
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

  case 53:

/* Line 1455 of yacc.c  */
#line 455 "bison.y"
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

  case 54:

/* Line 1455 of yacc.c  */
#line 470 "bison.y"
    {
        if(condition_matched == 1) {
            printf("Condition Already Matched.\n");
        } else {
            printf("Condition Matched in ELSE Block.\n");
        }
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 489 "bison.y"
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

  case 59:

/* Line 1455 of yacc.c  */
#line 498 "bison.y"
    {
        int value = 0;
        store_value((yyvsp[(1) - (1)].string), NUMBER, 1, VAR_CNT, &value, 0);
        VAR_CNT++;
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 511 "bison.y"
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

  case 63:

/* Line 1455 of yacc.c  */
#line 524 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (1)].integer);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 527 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (1)].real);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 530 "bison.y"
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

  case 66:

/* Line 1455 of yacc.c  */
#line 541 "bison.y"
    {
        (yyval.real) = (yyvsp[(2) - (2)].real);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 544 "bison.y"
    {
        (yyval.real) = -(yyvsp[(2) - (2)].real);
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 547 "bison.y"
    {
        (yyval.real) = (yyvsp[(2) - (2)].real);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 550 "bison.y"
    {
        (yyval.real) = (yyvsp[(2) - (2)].real);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 553 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) + (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 556 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 559 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) * (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 562 "bison.y"
    {
        (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].real);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 565 "bison.y"
    {

        (yyval.real) = (int)(yyvsp[(1) - (3)].real) % (int)(yyvsp[(3) - (3)].real);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 570 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) == (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 574 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) != (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 577 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) < (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 580 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) > (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 583 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) <= (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 587 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) >= (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 591 "bison.y"
    {
        (yyval.real) = ( (yyvsp[(1) - (3)].real) && (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 595 "bison.y"
    {
        (yyval.real) = ((yyvsp[(1) - (3)].real) || (yyvsp[(3) - (3)].real));
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 599 "bison.y"
    {
        (yyval.real) = ((int)(yyvsp[(1) - (3)].real) ^ (int)(yyvsp[(3) - (3)].real));
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 603 "bison.y"
    {
        (yyval.real) = !(yyvsp[(2) - (2)].real);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 607 "bison.y"
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

  case 86:

/* Line 1455 of yacc.c  */
#line 620 "bison.y"
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



/* Line 1455 of yacc.c  */
#line 2351 "bison.tab.c"
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
#line 635 "bison.y"

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
