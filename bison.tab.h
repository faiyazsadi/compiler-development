
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 156 "bison.y"

	int integer;
	double real;
	char *string;



/* Line 1676 of yacc.c  */
#line 104 "bison.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


