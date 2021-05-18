/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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


/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 4 "grammar.y"

#include <stdio.h>
#include "SymbolNodes.h"
#include "Grammar.tab.h"
#include "SymbolTable.h"
#include "ReservationTable.h"

extern FILE *lol;
extern ofstream* asl;
extern int yylex(yy::parser::semantic_type *yylvall);

/* Line 279 of lalr1.cc  */
#line 50 "grammar.tab.cpp"


#include "grammar.tab.h"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 58 "grammar.tab.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
/* Line 353 of lalr1.cc  */
#line 153 "grammar.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 43 "grammar.y"
    { g_root = (yyval.node) = new CCompileUnit(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 46 "grammar.y"
    { (yyval.node) = new CStatements(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 47 "grammar.y"
    { (yyval.node) = new CStatements(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node));}
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 50 "grammar.y"
    { (yyval.node) = new CStatement(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node));}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 51 "grammar.y"
    { (yyval.node) = new CStatement();}
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 62 "grammar.y"
    {(yyval.node) = new CCompound();}
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 63 "grammar.y"
    {(yyval.node) = new CCompound(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (2)].node));}
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 67 "grammar.y"
    { (yyval.node)= new CInsideList(); (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 68 "grammar.y"
    { (yyval.node)= new CInsideList(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node));  (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node));}
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 71 "grammar.y"
    {(yyval.node) = new CWhile(); (yyval.node)->AddChild((yysemantic_stack_[(5) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node));}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 74 "grammar.y"
    { (yyval.node) = new CFor(); (yyval.node)->AddChild((yysemantic_stack_[(9) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (5)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (7)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (9)].node));}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 77 "grammar.y"
    { (yyval.node) = new CDo_While(); (yyval.node)->AddChild((yysemantic_stack_[(7) - (2)].node)); (yyval.node)->AddChild((yysemantic_stack_[(7) - (5)].node));}
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 80 "grammar.y"
    { (yyval.node)= new CIf_telesths(); (yyval.node)->AddChild((yysemantic_stack_[(7) - (2)].node)); (yyval.node)->AddChild((yysemantic_stack_[(7) - (5)].node)); (yyval.node)->AddChild((yysemantic_stack_[(7) - (7)].node));}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 81 "grammar.y"
    { (yyval.node)= new CIf_telesths(); (yyval.node)->AddChild((yysemantic_stack_[(9) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (4)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (7)].node)); (yyval.node)->AddChild((yysemantic_stack_[(9) - (9)].node));}
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 84 "grammar.y"
    { (yyval.node) = new CIf_statement(); (yyval.node)->AddChild((yysemantic_stack_[(7) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(7) - (5)].node)); (yyval.node)->AddChild((yysemantic_stack_[(7) - (7)].node));}
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 85 "grammar.y"
    { (yyval.node) = new CIf_statement(); (yyval.node)->AddChild((yysemantic_stack_[(5) - (3)].node)); (yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node));}
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 88 "grammar.y"
    { (yyval.node) = new CPrintf('y');}
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 94 "grammar.y"
    {(yyval.node) = new CAssignment(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 95 "grammar.y"
    {(yyval.node) = new CAddition(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 96 "grammar.y"
    {(yyval.node) = new CSubtraction(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 97 "grammar.y"
    {(yyval.node) = new CMultiplication(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 98 "grammar.y"
    {(yyval.node) = new CDivision(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 99 "grammar.y"
    {(yyval.node) = new CModulo(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 100 "grammar.y"
    {(yyval.node) = new CBigger(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 101 "grammar.y"
    {(yyval.node) = new CSmaller(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 102 "grammar.y"
    {(yyval.node) = new CBit_And(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 103 "grammar.y"
    {(yyval.node) = new CBit_Xor(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 104 "grammar.y"
    {(yyval.node) = new CBit_Or(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 105 "grammar.y"
    {(yyval.node) = new CBigger_Eq(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 106 "grammar.y"
    {(yyval.node) = new CSmaller_Eq(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 107 "grammar.y"
    {(yyval.node) = new CEq(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 108 "grammar.y"
    {(yyval.node) = new CNot_Eq(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 109 "grammar.y"
    {(yyval.node) = new CLogical_And(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 110 "grammar.y"
    {(yyval.node) = new CLogical_Or(); (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node)); (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node));}
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 111 "grammar.y"
    {(yyval.node) = new CNot(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node));}
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 112 "grammar.y"
    {(yyval.node) = new CBit_Not(); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node));}
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 113 "grammar.y"
    {(yyval.node) = new CInc(0); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node));}
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 114 "grammar.y"
    {(yyval.node) = new CInc(1); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node));}
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 115 "grammar.y"
    {(yyval.node) = new CDcr(0); (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node));}
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 116 "grammar.y"
    {(yyval.node) = new CDcr(1); (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node));}
    break;


/* Line 670 of lalr1.cc  */
#line 664 "grammar.tab.cpp"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char parser::yypact_ninf_ = -35;
  const short int
  parser::yypact_[] =
  {
       118,   -35,    54,   -34,   -31,   -28,   118,     6,    -1,    -1,
      60,    79,    -1,   -35,    30,    58,   118,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   143,   -35,   -35,   102,    -1,
      -1,    -1,    81,    80,    63,   -35,   -35,   -35,   -35,   215,
     -35,   -35,   108,   -35,   -35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   -35,    -1,   387,   238,   261,   167,    62,    57,    -1,
      87,   -35,   -35,   402,    -5,    53,   414,   425,   434,   434,
     148,   148,   148,   148,   170,   170,   -35,   -35,   -35,   284,
     118,   118,    -1,    -1,    64,    -1,    95,   103,   -35,   191,
     307,   -35,   354,    -1,   118,    -1,    77,    -1,   371,   -35,
     330,   -35,   387,    -1,   118,   387,   -35
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     2,     3,     7,     8,
       9,    10,    11,    12,    13,     0,    49,    47,     0,     0,
       0,     0,     0,     0,    27,    45,    46,    50,    48,     0,
      14,    16,     0,     1,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,    28,     0,     0,     0,     0,     0,     0,
       0,    15,    17,    44,    43,    38,    37,    36,    42,    41,
      35,    34,    40,    39,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    18,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    23,
       0,    20,    21,     0,     0,    22,    19
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -35,   -35,   -35,    -6,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,    -3
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    15,    16,    17,    18,    42,    19,    20,    21,    22,
      23,    24,    25
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned char
  parser::yytable_[] =
  {
        32,    29,     1,    34,    30,    35,    36,    31,    41,    39,
      44,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    63,    64,    65,    66,     8,
       9,    10,    11,     1,     2,     3,    72,     4,     5,     6,
       7,    33,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    43,    89,
       8,     9,    10,    11,    37,    12,    63,    13,    14,    40,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    38,    97,    98,    26,    27,    67,    99,
     100,    68,   102,    94,    28,    26,    27,    93,   109,    95,
     108,   101,   110,    69,   112,     1,    34,   103,   116,   104,
     115,     1,     2,     3,   111,     4,     5,     6,     7,     0,
       0,     1,     2,     3,     0,     4,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,     0,    62,     8,     9,
      10,    11,     0,    12,     0,    13,    14,    71,     8,     9,
      10,    11,     0,    12,     0,    13,    14,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    56,    57,    58,    59,    60,     0,     0,
      61,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    58,    59,    60,
       0,     0,     0,     0,    92,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,   105,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,    70,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,    90,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,    91,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
      96,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,   106,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,   114,   107,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   113,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    52,    53,    54,    55,    56,
      57,    58,    59,    60
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
         6,    35,     3,     4,    35,     8,     9,    35,    14,    12,
      16,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    28,    29,    30,    31,    30,
      31,    32,    33,     3,     4,     5,    42,     7,     8,     9,
      10,    35,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,    62,
      30,    31,    32,    33,     4,    35,    69,    37,    38,    39,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     4,    90,    91,    32,    33,     7,    92,
      93,    11,    95,    36,    40,    32,    33,    35,   104,    12,
     103,    37,   105,    40,   107,     3,     4,    12,   114,     6,
     113,     3,     4,     5,    37,     7,     8,     9,    10,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    30,    31,
      32,    33,    -1,    35,    -1,    37,    38,    39,    30,    31,
      32,    33,    -1,    35,    -1,    37,    38,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    25,    26,    27,    28,    29,    -1,    -1,
      37,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    27,    28,    29,
      -1,    -1,    -1,    -1,    37,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    21,    22,    23,    24,    25,
      26,    27,    28,    29
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     3,     4,     5,     7,     8,     9,    10,    30,    31,
      32,    33,    35,    37,    38,    42,    43,    44,    45,    47,
      48,    49,    50,    51,    52,    53,    32,    33,    40,    35,
      35,    35,    44,    35,     4,    53,    53,     4,     4,    53,
      39,    44,    46,     0,    44,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    37,    35,    53,    53,    53,    53,     7,    11,    40,
      36,    39,    44,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      36,    36,    37,    35,    36,    12,    36,    44,    44,    53,
      53,    37,    53,    12,     6,    37,    36,    13,    53,    44,
      53,    37,    53,    13,    36,    53,    44
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,    63,    58,   267,   268,   124,    94,    38,   269,
     270,    60,    62,   271,   272,    43,    45,    42,    47,    37,
      33,   126,   273,   274,    34,    40,    41,    59,   123,   125,
      61
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    45,    45,    46,    46,    47,    48,
      49,    50,    50,    51,    51,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     2,     5,     9,
       7,     7,     9,     7,     5,     5,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "IF", "ELSE",
  "WHILE", "FOR", "DO", "PRINTF", "STRING", "'?'", "':'", "LOG_OR",
  "LOG_AND", "'|'", "'^'", "'&'", "NOT_EQ", "EQ", "'<'", "'>'",
  "SMALLER_EQUAL", "BIGGER_EQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "'~'", "DCR", "INC", "'\"'", "'('", "')'", "';'", "'{'", "'}'",
  "'='", "$accept", "compileUnit", "statements", "statement",
  "compound_exp", "inside_list", "while_expression", "for_expression",
  "do_while_expression", "kind_of_if", "if_statement", "printf_statement",
  "expression", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        42,     0,    -1,    43,    -1,    44,    -1,    43,    44,    -1,
      53,    37,    -1,    37,    -1,    45,    -1,    47,    -1,    48,
      -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,    38,
      39,    -1,    38,    46,    39,    -1,    44,    -1,    46,    44,
      -1,     7,    35,    53,    36,    44,    -1,     8,    35,    53,
      37,    53,    37,    53,    36,    44,    -1,     9,    44,     7,
      35,    53,    36,    37,    -1,    35,    53,    36,    12,    53,
      13,    53,    -1,     4,    40,    35,    53,    36,    12,    53,
      13,    53,    -1,     5,    35,    53,    36,    44,     6,    44,
      -1,     5,    35,    53,    36,    44,    -1,    10,    35,    11,
      36,    37,    -1,     3,    -1,     4,    -1,     4,    40,    53,
      -1,    53,    25,    53,    -1,    53,    26,    53,    -1,    53,
      27,    53,    -1,    53,    28,    53,    -1,    53,    29,    53,
      -1,    53,    22,    53,    -1,    53,    21,    53,    -1,    53,
      18,    53,    -1,    53,    17,    53,    -1,    53,    16,    53,
      -1,    53,    24,    53,    -1,    53,    23,    53,    -1,    53,
      20,    53,    -1,    53,    19,    53,    -1,    53,    15,    53,
      -1,    53,    14,    53,    -1,    30,    53,    -1,    31,    53,
      -1,     4,    33,    -1,    33,     4,    -1,     4,    32,    -1,
      32,     4,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    32,    36,    38,    41,    47,
      57,    65,    73,    83,    91,    97,   103,   105,   107,   111,
     115,   119,   123,   127,   131,   135,   139,   143,   147,   151,
     155,   159,   163,   167,   171,   175,   178,   181,   184,   187,
     190
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  parser::yyrline_[] =
  {
         0,    43,    43,    46,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    62,    63,    67,    68,    71,    74,
      77,    80,    81,    84,    85,    88,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,    34,     2,     2,    29,    18,     2,
      35,    36,    27,    25,     2,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    13,    37,
      21,    40,    22,    12,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    17,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    16,    39,    31,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    14,    15,    19,
      20,    23,    24,    32,    33
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 463;
  const int parser::yynnts_ = 13;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 43;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 41;

  const unsigned int parser::yyuser_token_number_max_ = 274;
  const parser::token_number_type parser::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 1252 "grammar.tab.cpp"
/* Line 1142 of lalr1.cc  */
#line 122 "grammar.y"
 
namespace yy{
	void parser::error (const location_type& loc, const std::string& msg){
		std::cerr << "error at " <<loc << ":" << msg << std::endl;
	}
}
void yyerror(const char *message)
{

	printf("%s", message);



}

