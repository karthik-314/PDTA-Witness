// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   ppyylex


<<<<<<< HEAD
#line 39 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
=======
>>>>>>> 78b1f60 (First commit.)

#include "program.tab.hh"


<<<<<<< HEAD
#line 53 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:412
=======
>>>>>>> 78b1f60 (First commit.)
// Unqualified %code blocks.
#line 45 "program.yy"

  // Declare the lexer for the parser's sake.
  tchecker::parsing::program::parser_t::symbol_type ppyylex
  (std::string const & program_context,
  tchecker::log_t & log,
  tchecker::expression_t * & expr,
  tchecker::statement_t * & stmt);
  
  
  // Global variables
  static unsigned int error_count;
  
  
  // Fake expression used is case of syntax error to allow parsing of the
  // entire expression
  class fake_expression_t final : public tchecker::lvalue_expression_t {
    public:
    virtual ~fake_expression_t() = default;
    private:
    virtual std::ostream & do_output(std::ostream & os) const
    {
      return os;
    }
    
    virtual tchecker::expression_t * do_clone() const
    {
      return new fake_expression_t();
    }
    
    virtual void do_visit(tchecker::expression_visitor_t & v) const
    {}
  };
  
  
  // Fake variable expression used is case of syntax error to allow parsing of
  // the entire expression
  class fake_var_expression_t final : public tchecker::var_expression_t {
    public:
    fake_var_expression_t() : tchecker::var_expression_t("fake") {}
    
    virtual ~fake_var_expression_t() = default;
    private:
    virtual std::ostream & do_output(std::ostream & os) const
    {
      return os;
    }
    
    virtual tchecker::expression_t * do_clone() const
    {
      return new fake_var_expression_t();
    }
    
    virtual void do_visit(tchecker::expression_visitor_t & v) const
    {}
  };
  
  
  
  // Fake statement used in case of syntax error to allow parsing of the
  // entire statement
  class fake_statement_t final : public tchecker::statement_t {
    public:
    virtual ~fake_statement_t() = default;
    private:
    virtual std::ostream & do_output(std::ostream & os) const
    {
      return os;
    }
    
    virtual tchecker::statement_t * do_clone() const
    {
      return new fake_statement_t();
    }
    
    virtual void do_visit(tchecker::statement_visitor_t & v) const
    {}
  };

<<<<<<< HEAD
#line 134 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:413
=======
#line 127 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
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
    while (false)
# endif


// Enable debugging if requested.
#if PPYYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !PPYYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !PPYYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 13 "program.yy"
namespace tchecker { namespace parsing { namespace program {
<<<<<<< HEAD
#line 220 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser_t::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

=======
#line 220 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)

  /// Build a parser object.
  parser_t::parser_t (std::string const & program_context_yyarg, tchecker::log_t & log_yyarg, tchecker::expression_t * & expr_yyarg, tchecker::statement_t * & stmt_yyarg)
#if PPYYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      program_context (program_context_yyarg),
      log (log_yyarg),
      expr (expr_yyarg),
      stmt (stmt_yyarg)
  {}

  parser_t::~parser_t ()
  {}

  parser_t::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser_t::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser_t::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser_t::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser_t::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser_t::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser_t::symbol_kind_type
  parser_t::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser_t::stack_symbol_type::stack_symbol_type ()
  {}

  parser_t::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.YY_MOVE_OR_COPY< enum tchecker::binary_operator_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_term: // term
        value.YY_MOVE_OR_COPY< tchecker::expression_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.YY_MOVE_OR_COPY< tchecker::integer_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.YY_MOVE_OR_COPY< tchecker::lvalue_expression_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< tchecker::statement_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.YY_MOVE_OR_COPY< tchecker::var_expression_t * > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser_t::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.move< enum tchecker::binary_operator_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_term: // term
        value.move< tchecker::expression_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.move< tchecker::integer_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.move< tchecker::lvalue_expression_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.move< tchecker::statement_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.move< tchecker::var_expression_t * > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser_t::stack_symbol_type&
  parser_t::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.copy< enum tchecker::binary_operator_t > (that.value);
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_term: // term
        value.copy< tchecker::expression_t * > (that.value);
        break;

      case symbol_kind::S_integer: // integer
        value.copy< tchecker::integer_t > (that.value);
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.copy< tchecker::lvalue_expression_t * > (that.value);
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.copy< tchecker::statement_t * > (that.value);
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.copy< tchecker::var_expression_t * > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser_t::stack_symbol_type&
  parser_t::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.move< enum tchecker::binary_operator_t > (that.value);
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_term: // term
        value.move< tchecker::expression_t * > (that.value);
        break;

      case symbol_kind::S_integer: // integer
        value.move< tchecker::integer_t > (that.value);
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.move< tchecker::lvalue_expression_t * > (that.value);
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.move< tchecker::statement_t * > (that.value);
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.move< tchecker::var_expression_t * > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser_t::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if PPYYDEBUG
  template <typename Base>
  void
  parser_t::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
<<<<<<< HEAD
            case 30: // "identifier"

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 468 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 31: // "integer"

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 475 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 36: // sequence_statement

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::statement_t * > (); }
#line 482 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 37: // statement

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::statement_t * > (); }
#line 489 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 38: // if_statement

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< tchecker::statement_t * > (); }
#line 496 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 39: // loop_statement

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< tchecker::statement_t * > (); }
#line 503 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 40: // local_statement

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< tchecker::statement_t * > (); }
#line 510 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 41: // simple_statement

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< tchecker::statement_t * > (); }
#line 517 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 42: // assignment

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::statement_t * > (); }
#line 524 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 43: // conjunctive_formula

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::expression_t * > (); }
#line 531 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 44: // non_atomic_conjunctive_formula

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::expression_t * > (); }
#line 538 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 45: // atomic_formula

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::expression_t * > (); }
#line 545 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 46: // predicate_formula

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::expression_t * > (); }
#line 552 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 47: // predicate_operator

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< enum tchecker::binary_operator_t > (); }
#line 559 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 48: // term

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::expression_t * > (); }
#line 566 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 49: // lvalue_term

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::lvalue_expression_t * > (); }
#line 573 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 50: // variable_term

#line 193 "program.yy" // lalr1.cc:636
        { yyoutput << * yysym.value.template as< tchecker::var_expression_t * > (); }
#line 580 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
        break;

      case 51: // integer

#line 192 "program.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< tchecker::integer_t > (); }
#line 587 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:636
=======
      case symbol_kind::S_TOK_ID: // "identifier"
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 530 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_TOK_INTEGER: // "integer"
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 536 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::statement_t * > (); }
#line 542 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::statement_t * > (); }
#line 548 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_if_statement: // if_statement
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < tchecker::statement_t * > (); }
#line 554 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_loop_statement: // loop_statement
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < tchecker::statement_t * > (); }
#line 560 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_local_statement: // local_statement
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < tchecker::statement_t * > (); }
#line 566 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_simple_statement: // simple_statement
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < tchecker::statement_t * > (); }
#line 572 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_assignment: // assignment
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::statement_t * > (); }
#line 578 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::expression_t * > (); }
#line 584 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::expression_t * > (); }
#line 590 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_atomic_formula: // atomic_formula
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::expression_t * > (); }
#line 596 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_predicate_formula: // predicate_formula
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::expression_t * > (); }
#line 602 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_predicate_operator: // predicate_operator
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < enum tchecker::binary_operator_t > (); }
#line 608 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_term: // term
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::expression_t * > (); }
#line 614 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::lvalue_expression_t * > (); }
#line 620 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_variable_term: // variable_term
#line 193 "program.yy"
                 { yyoutput << * yysym.value.template as < tchecker::var_expression_t * > (); }
#line 626 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_integer: // integer
#line 192 "program.yy"
                 { yyoutput << yysym.value.template as < tchecker::integer_t > (); }
#line 632 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser_t::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser_t::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser_t::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if PPYYDEBUG
  std::ostream&
  parser_t::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser_t::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser_t::debug_level_type
  parser_t::debug_level () const
  {
    return yydebug_;
  }

  void
  parser_t::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // PPYYDEBUG

  parser_t::state_type
  parser_t::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser_t::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser_t::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser_t::operator() ()
  {
    return parse ();
  }

  int
  parser_t::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 125 "program.yy"
{
  error_count = 0;
}

<<<<<<< HEAD
#line 705 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:741
=======
#line 756 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"

>>>>>>> 78b1f60 (First commit.)

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (program_context, log, expr, stmt));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        yylhs.value.emplace< enum tchecker::binary_operator_t > ();
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_term: // term
        yylhs.value.emplace< tchecker::expression_t * > ();
        break;

      case symbol_kind::S_integer: // integer
        yylhs.value.emplace< tchecker::integer_t > ();
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        yylhs.value.emplace< tchecker::lvalue_expression_t * > ();
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< tchecker::statement_t * > ();
        break;

      case symbol_kind::S_variable_term: // variable_term
        yylhs.value.emplace< tchecker::var_expression_t * > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: sequence_statement
#line 212 "program.yy"
{ expr = nullptr;
  if (error_count > 0) {
    stmt = nullptr;
    delete yystack_[0].value.as < tchecker::statement_t * > ();
  }
  else
    stmt = yystack_[0].value.as < tchecker::statement_t * > ();
}
<<<<<<< HEAD
#line 861 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 940 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 3: // program: conjunctive_formula
#line 221 "program.yy"
{
  if (error_count > 0) {
    expr = nullptr;
    delete yystack_[0].value.as < tchecker::expression_t * > ();
  }
  else
    expr = yystack_[0].value.as < tchecker::expression_t * > ();
  stmt = nullptr;
}
<<<<<<< HEAD
#line 875 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 239 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = yystack_[1].value.as< tchecker::statement_t * > (); }
#line 881 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 954 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 6: // sequence_statement: statement opt_semicolon
#line 239 "program.yy"
{ yylhs.value.as < tchecker::statement_t * > () = yystack_[1].value.as < tchecker::statement_t * > (); }
#line 960 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 7: // sequence_statement: statement ";" sequence_statement
#line 241 "program.yy"
{
  try {
    yylhs.value.as < tchecker::statement_t * > () = new tchecker::sequence_statement_t(yystack_[2].value.as < tchecker::statement_t * > (), yystack_[0].value.as < tchecker::statement_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::statement_t * > () = new fake_statement_t();
  }
}
<<<<<<< HEAD
#line 895 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 254 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = yystack_[0].value.as< tchecker::statement_t * > (); }
#line 901 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 256 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = yystack_[0].value.as< tchecker::statement_t * > (); }
#line 907 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 258 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = yystack_[0].value.as< tchecker::statement_t * > (); }
#line 913 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 263 "program.yy" // lalr1.cc:859
    {  yylhs.value.as< tchecker::statement_t * > () = new tchecker::if_statement_t(yystack_[3].value.as< tchecker::expression_t * > (), yystack_[1].value.as< tchecker::statement_t * > (), new tchecker::nop_statement_t()); }
#line 919 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 265 "program.yy" // lalr1.cc:859
    {  yylhs.value.as< tchecker::statement_t * > () = new tchecker::if_statement_t(yystack_[5].value.as< tchecker::expression_t * > (), yystack_[3].value.as< tchecker::statement_t * > (), yystack_[1].value.as< tchecker::statement_t * > ()); }
#line 925 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 270 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = new tchecker::while_statement_t(yystack_[3].value.as< tchecker::expression_t * > (), yystack_[1].value.as< tchecker::statement_t * > ()); }
#line 931 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 275 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = new tchecker::local_var_statement_t(yystack_[0].value.as< tchecker::var_expression_t * > ()); }
#line 937 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 277 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = new tchecker::local_var_statement_t(yystack_[2].value.as< tchecker::var_expression_t * > (), yystack_[0].value.as< tchecker::expression_t * > ()); }
#line 943 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 279 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = new tchecker::local_array_statement_t(yystack_[3].value.as< tchecker::var_expression_t * > (), yystack_[1].value.as< tchecker::expression_t * > ()); }
#line 949 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 284 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = yystack_[0].value.as< tchecker::statement_t * > (); }
#line 955 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 286 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = new tchecker::nop_statement_t(); }
#line 961 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 288 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::statement_t * > () = yystack_[0].value.as< tchecker::statement_t * > (); }
#line 967 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 974 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 8: // statement: simple_statement
#line 254 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = yystack_[0].value.as < tchecker::statement_t * > (); }
#line 980 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 9: // statement: if_statement
#line 256 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = yystack_[0].value.as < tchecker::statement_t * > (); }
#line 986 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 10: // statement: loop_statement
#line 258 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = yystack_[0].value.as < tchecker::statement_t * > (); }
#line 992 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 11: // if_statement: "if" conjunctive_formula "then" sequence_statement "end"
#line 263 "program.yy"
    {  yylhs.value.as < tchecker::statement_t * > () = new tchecker::if_statement_t(yystack_[3].value.as < tchecker::expression_t * > (), yystack_[1].value.as < tchecker::statement_t * > (), new tchecker::nop_statement_t()); }
#line 998 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 12: // if_statement: "if" conjunctive_formula "then" sequence_statement "else" sequence_statement "end"
#line 265 "program.yy"
    {  yylhs.value.as < tchecker::statement_t * > () = new tchecker::if_statement_t(yystack_[5].value.as < tchecker::expression_t * > (), yystack_[3].value.as < tchecker::statement_t * > (), yystack_[1].value.as < tchecker::statement_t * > ()); }
#line 1004 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 13: // loop_statement: "while" conjunctive_formula "do" sequence_statement "end"
#line 270 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = new tchecker::while_statement_t(yystack_[3].value.as < tchecker::expression_t * > (), yystack_[1].value.as < tchecker::statement_t * > ()); }
#line 1010 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 14: // local_statement: "local" variable_term
#line 275 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = new tchecker::local_var_statement_t(yystack_[0].value.as < tchecker::var_expression_t * > ()); }
#line 1016 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 15: // local_statement: "local" variable_term "=" term
#line 277 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = new tchecker::local_var_statement_t(yystack_[2].value.as < tchecker::var_expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ()); }
#line 1022 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 16: // local_statement: "local" variable_term "[" term "]"
#line 279 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = new tchecker::local_array_statement_t(yystack_[3].value.as < tchecker::var_expression_t * > (), yystack_[1].value.as < tchecker::expression_t * > ()); }
#line 1028 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 17: // simple_statement: assignment
#line 284 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = yystack_[0].value.as < tchecker::statement_t * > (); }
#line 1034 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 18: // simple_statement: "nop"
#line 286 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = new tchecker::nop_statement_t(); }
#line 1040 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 19: // simple_statement: local_statement
#line 288 "program.yy"
    { yylhs.value.as < tchecker::statement_t * > () = yystack_[0].value.as < tchecker::statement_t * > (); }
#line 1046 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 20: // assignment: lvalue_term "=" term
#line 294 "program.yy"
{
  try {
    yylhs.value.as < tchecker::statement_t * > () = new tchecker::assign_statement_t(yystack_[2].value.as < tchecker::lvalue_expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::statement_t * > () = new fake_statement_t();
  }
}
<<<<<<< HEAD
#line 981 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 308 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::expression_t * > () = yystack_[0].value.as< tchecker::expression_t * > (); }
#line 987 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 310 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::expression_t * > () =yystack_[0].value.as< tchecker::expression_t * > (); }
#line 993 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1060 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 21: // conjunctive_formula: atomic_formula
#line 308 "program.yy"
{ yylhs.value.as < tchecker::expression_t * > () = yystack_[0].value.as < tchecker::expression_t * > (); }
#line 1066 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 22: // conjunctive_formula: non_atomic_conjunctive_formula
#line 310 "program.yy"
{ yylhs.value.as < tchecker::expression_t * > () =yystack_[0].value.as < tchecker::expression_t * > (); }
#line 1072 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 23: // non_atomic_conjunctive_formula: "(" non_atomic_conjunctive_formula ")"
#line 316 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::par_expression_t(yystack_[1].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1007 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1086 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 24: // non_atomic_conjunctive_formula: atomic_formula "&&" conjunctive_formula
#line 326 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::binary_expression_t(tchecker::EXPR_OP_LAND, yystack_[2].value.as < tchecker::expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1021 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 340 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::expression_t * > () = yystack_[0].value.as< tchecker::expression_t * > (); }
#line 1027 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 342 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::expression_t * > () = yystack_[0].value.as< tchecker::expression_t * > (); }
#line 1033 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1100 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 25: // atomic_formula: term
#line 340 "program.yy"
{ yylhs.value.as < tchecker::expression_t * > () = yystack_[0].value.as < tchecker::expression_t * > (); }
#line 1106 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 26: // atomic_formula: predicate_formula
#line 342 "program.yy"
{ yylhs.value.as < tchecker::expression_t * > () = yystack_[0].value.as < tchecker::expression_t * > (); }
#line 1112 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 27: // atomic_formula: "!" atomic_formula
#line 344 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::unary_expression_t(tchecker::EXPR_OP_LNOT, yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1047 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1126 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 28: // predicate_formula: "(" predicate_formula ")"
#line 358 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::par_expression_t(yystack_[1].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1061 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1140 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 29: // predicate_formula: term predicate_operator term
#line 368 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::binary_expression_t(yystack_[1].value.as < enum tchecker::binary_operator_t > (), yystack_[2].value.as < tchecker::expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1075 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 381 "program.yy" // lalr1.cc:859
    { yylhs.value.as< enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_EQ; }
#line 1081 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 382 "program.yy" // lalr1.cc:859
    { yylhs.value.as< enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_NEQ; }
#line 1087 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 383 "program.yy" // lalr1.cc:859
    { yylhs.value.as< enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_LT; }
#line 1093 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 384 "program.yy" // lalr1.cc:859
    { yylhs.value.as< enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_LE; }
#line 1099 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 385 "program.yy" // lalr1.cc:859
    { yylhs.value.as< enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_GE; }
#line 1105 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 386 "program.yy" // lalr1.cc:859
    { yylhs.value.as< enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_GT; }
#line 1111 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1154 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 30: // predicate_operator: "=="
#line 381 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_EQ; }
#line 1160 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 31: // predicate_operator: "!="
#line 382 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_NEQ; }
#line 1166 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 32: // predicate_operator: "<"
#line 383 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_LT; }
#line 1172 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 33: // predicate_operator: "<="
#line 384 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_LE; }
#line 1178 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 34: // predicate_operator: ">="
#line 385 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_GE; }
#line 1184 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 35: // predicate_operator: ">"
#line 386 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_GT; }
#line 1190 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 36: // term: integer
#line 392 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::int_expression_t(yystack_[0].value.as < tchecker::integer_t > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1125 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 402 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::expression_t * > () = yystack_[0].value.as< tchecker::lvalue_expression_t * > (); }
#line 1131 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1204 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 37: // term: lvalue_term
#line 402 "program.yy"
{ yylhs.value.as < tchecker::expression_t * > () = yystack_[0].value.as < tchecker::lvalue_expression_t * > (); }
#line 1210 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 38: // term: "(" term ")"
#line 404 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::par_expression_t(yystack_[1].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1145 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1224 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 39: // term: "-" term
#line 414 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::unary_expression_t(tchecker::EXPR_OP_NEG, yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1159 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1238 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 40: // term: term "+" term
#line 424 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::binary_expression_t(tchecker::EXPR_OP_PLUS, yystack_[2].value.as < tchecker::expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1173 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1252 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 41: // term: term "-" term
#line 434 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::binary_expression_t(tchecker::EXPR_OP_MINUS, yystack_[2].value.as < tchecker::expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1187 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1266 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 42: // term: term "*" term
#line 444 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::binary_expression_t(tchecker::EXPR_OP_TIMES, yystack_[2].value.as < tchecker::expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1201 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1280 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 43: // term: term "/" term
#line 454 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::binary_expression_t(tchecker::EXPR_OP_DIV, yystack_[2].value.as < tchecker::expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1215 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1294 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 44: // term: term "%" term
#line 464 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::binary_expression_t(tchecker::EXPR_OP_MOD, yystack_[2].value.as < tchecker::expression_t * > (), yystack_[0].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1229 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1308 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 45: // term: "(" "if" conjunctive_formula "then" term "else" term ")"
#line 474 "program.yy"
{
  try {
    yylhs.value.as < tchecker::expression_t * > () = new tchecker::ite_expression_t(yystack_[5].value.as < tchecker::expression_t * > (), yystack_[3].value.as < tchecker::expression_t * > (), yystack_[1].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1243 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 488 "program.yy" // lalr1.cc:859
    { yylhs.value.as< tchecker::lvalue_expression_t * > () = yystack_[0].value.as< tchecker::var_expression_t * > (); }
#line 1249 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1322 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;

  case 46: // lvalue_term: variable_term
#line 488 "program.yy"
{ yylhs.value.as < tchecker::lvalue_expression_t * > () = yystack_[0].value.as < tchecker::var_expression_t * > (); }
#line 1328 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 47: // lvalue_term: variable_term "[" term "]"
#line 490 "program.yy"
{
  try {
    yylhs.value.as < tchecker::lvalue_expression_t * > () = new tchecker::array_expression_t(yystack_[3].value.as < tchecker::var_expression_t * > (), yystack_[1].value.as < tchecker::expression_t * > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::lvalue_expression_t * > () = new fake_expression_t();
  }
}
<<<<<<< HEAD
#line 1263 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1342 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 48: // variable_term: "identifier"
#line 504 "program.yy"
{
  try {
    yylhs.value.as < tchecker::var_expression_t * > () = new tchecker::var_expression_t(yystack_[0].value.as < std::string > ());
  }
  catch (std::exception const & e) {
    error(yylhs.location, e.what());
    yylhs.value.as < tchecker::var_expression_t * > () = new fake_var_expression_t();
  }
}
<<<<<<< HEAD
#line 1277 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1356 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
>>>>>>> 78b1f60 (First commit.)
    break;

  case 49: // integer: "integer"
#line 518 "program.yy"
{
  try {
    long long l = std::stoll(yystack_[0].value.as < std::string > (), nullptr, 10);
    if ( (l < std::numeric_limits<integer_t>::min()) || (l > std::numeric_limits<integer_t>::max()) )
    throw std::out_of_range("");
    yylhs.value.as < tchecker::integer_t > () = static_cast<tchecker::integer_t>(l);
  }
  catch (std::exception const & e) {
    error(yystack_[0].location, "value " + yystack_[0].value.as < std::string > () + " out of range " + std::to_string(std::numeric_limits<integer_t>::min()) + "," +
    std::to_string(std::numeric_limits<integer_t>::max()) );
    yylhs.value.as < tchecker::integer_t > () = 0;
  }
}
<<<<<<< HEAD
#line 1295 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
    break;


#line 1299 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:859
=======
#line 1374 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"
    break;


#line 1378 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"

>>>>>>> 78b1f60 (First commit.)
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser_t::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser_t::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser_t::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser_t::context.
  parser_t::context::context (const parser_t& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser_t::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser_t::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser_t::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser_t::yypact_ninf_ = -39;

  const signed char parser_t::yytable_ninf_ = -1;

  const short
  parser_t::yypact_[] =
  {
      53,     8,    83,     4,    46,    46,   -39,    -5,   -39,   -39,
      28,   -39,    21,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
      23,   -39,   133,    37,    35,   -39,    46,    47,    23,    54,
     110,   -39,    70,   -39,    81,   -39,    27,    40,    18,   -39,
     -13,   -39,    46,    83,    83,    83,    83,    83,   -39,   -39,
     -39,   -39,   -39,   -39,    83,    83,    83,    38,   -39,   -39,
     -39,    97,    54,   110,   -13,   -13,    83,    83,   -39,    37,
     -39,    -7,    -7,   -39,   -39,   -39,    86,    86,   157,    83,
      -3,    41,    86,   164,   -39,   123,   -39,   -13,   -39,   -39,
      83,    50,   150,   -39,   -39
  };

  const signed char
  parser_t::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,    18,     0,    48,    49,
       0,     2,     5,     9,    10,    19,     8,    17,     3,    22,
      21,    26,    25,    37,    46,    36,     0,     0,     0,    26,
      25,    37,     0,    39,     0,    27,     0,     0,    14,     1,
       4,     6,     0,     0,     0,     0,     0,     0,    30,    31,
      33,    34,    32,    35,     0,     0,     0,     0,    23,    28,
      38,     0,     0,     0,     0,     0,     0,     0,     7,     0,
      24,    40,    41,    42,    43,    44,    29,    20,     0,     0,
       0,     0,    15,     0,    47,     0,    11,     0,    13,    16,
       0,     0,     0,    12,    45
  };

  const signed char
  parser_t::yypgoto_[] =
  {
     -39,   -39,   -39,   -38,   -39,   -39,   -39,   -39,   -39,   -39,
       6,    68,    57,     2,   -39,    -1,     7,    63,   -39
  };

  const signed char
  parser_t::yydefgoto_[] =
  {
       0,    10,    41,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    54,    22,    31,    24,    25
  };

  const signed char
  parser_t::yytable_[] =
  {
      30,    33,    68,    29,    45,    46,    47,    23,    34,     4,
      36,    37,     1,     5,     2,     6,     7,     8,     2,     3,
      86,    66,    87,     3,    67,     8,    80,    81,    39,    40,
      26,    61,    57,    63,     8,     9,    62,    42,     8,     9,
      55,    56,    71,    72,    73,    74,    75,    69,    70,    91,
       1,    64,    58,    76,    77,    78,     2,     1,    28,    59,
      35,     3,    79,     2,    88,    82,    83,    65,     3,    27,
      38,    69,    69,    93,    32,     4,     8,     9,    85,     5,
       2,     6,     7,     8,     9,    34,     0,    32,     0,    92,
       0,     2,    26,     2,    69,    43,    44,    45,    46,    47,
       8,     9,    60,    26,     0,     0,    43,    44,    45,    46,
      47,     8,     9,     8,     9,    60,     0,     0,     0,    43,
      44,    45,    46,    47,     0,     0,    48,    49,    50,    51,
      52,    53,    43,    44,    45,    46,    47,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,     0,    90,    48,
      49,    50,    51,    52,    53,    94,     0,     0,     0,    43,
      44,    45,    46,    47,    84,     0,    43,    44,    45,    46,
      47,    89,     0,    43,    44,    45,    46,    47
  };

  const signed char
  parser_t::yycheck_[] =
  {
       1,     2,    40,     1,    11,    12,    13,     0,     4,    22,
       4,     5,     4,    26,    10,    28,    29,    30,    10,    15,
      23,     3,    25,    15,     6,    30,    64,    65,     0,     8,
      22,    32,    26,    34,    30,    31,    34,    14,    30,    31,
       3,     6,    43,    44,    45,    46,    47,    40,    42,    87,
       4,    24,     5,    54,    55,    56,    10,     4,     1,     5,
       3,    15,    24,    10,    23,    66,    67,    27,    15,     1,
       7,    64,    65,    23,     4,    22,    30,    31,    79,    26,
      10,    28,    29,    30,    31,     4,    -1,     4,    -1,    90,
      -1,    10,    22,    10,    87,     9,    10,    11,    12,    13,
      30,    31,     5,    22,    -1,    -1,     9,    10,    11,    12,
      13,    30,    31,    30,    31,     5,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    -1,    -1,    16,    17,    18,    19,
      20,    21,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    -1,    25,    16,
      17,    18,    19,    20,    21,     5,    -1,    -1,    -1,     9,
      10,    11,    12,    13,     7,    -1,     9,    10,    11,    12,
      13,     7,    -1,     9,    10,    11,    12,    13
  };

  const signed char
  parser_t::yystos_[] =
  {
       0,     4,    10,    15,    22,    26,    28,    29,    30,    31,
      34,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    48,    49,    50,    51,    22,    44,    45,    46,
      48,    49,     4,    48,     4,    45,    43,    43,    50,     0,
       8,    35,    14,     9,    10,    11,    12,    13,    16,    17,
      18,    19,    20,    21,    47,     3,     6,    43,     5,     5,
       5,    48,    46,    48,    24,    27,     3,     6,    36,    49,
      43,    48,    48,    48,    48,    48,    48,    48,    48,    24,
      36,    36,    48,    48,     7,    48,    23,    25,    23,     7,
      25,    36,    48,    23,     5
  };

  const signed char
  parser_t::yyr1_[] =
  {
       0,    33,    34,    34,    35,    35,    36,    36,    37,    37,
      37,    38,    38,    39,    40,    40,    40,    41,    41,    41,
      42,    43,    43,    44,    44,    45,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    50,    51
  };

  const signed char
  parser_t::yyr2_[] =
  {
       0,     2,     1,     1,     1,     0,     2,     3,     1,     1,
       1,     5,     7,     5,     2,     4,     5,     1,     1,     1,
       3,     1,     1,     3,     3,     1,     1,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     3,     3,     3,     8,     1,     4,     1,     1
  };


#if PPYYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser_t::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"=\"", "\"(\"",
  "\")\"", "\"[\"", "\"]\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"%\"", "\"&&\"", "\"!\"", "\"==\"", "\"!=\"", "\"<=\"", "\">=\"",
  "\"<\"", "\">\"", "\"if\"", "\"end\"", "\"then\"", "\"else\"",
  "\"while\"", "\"do\"", "\"nop\"", "\"local\"", "\"identifier\"",
  "\"integer\"", "UMINUS", "$accept", "program", "opt_semicolon",
  "sequence_statement", "statement", "if_statement", "loop_statement",
  "local_statement", "simple_statement", "assignment",
  "conjunctive_formula", "non_atomic_conjunctive_formula",
  "atomic_formula", "predicate_formula", "predicate_operator", "term",
  "lvalue_term", "variable_term", "integer", YY_NULLPTR
  };
#endif


#if PPYYDEBUG
  const short
  parser_t::yyrline_[] =
  {
       0,   211,   211,   220,   233,   234,   238,   240,   253,   255,
     257,   262,   264,   269,   274,   276,   278,   283,   285,   287,
     293,   307,   309,   315,   325,   339,   341,   343,   357,   367,
     381,   382,   383,   384,   385,   386,   391,   401,   403,   413,
     423,   433,   443,   453,   463,   473,   487,   489,   503,   517
  };

  void
  parser_t::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser_t::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // PPYYDEBUG


#line 13 "program.yy"
} } } // tchecker::parsing::program
<<<<<<< HEAD
#line 1745 "/home/karthik/IITB/MTP/tchecker/src/parsing/program_parser/program.tab.cc" // lalr1.cc:1167
#line 534 "program.yy" // lalr1.cc:1168
=======
#line 1922 "/home/karthik/Computers/tchecker/src/parsing/program_parser/program.tab.cc"

#line 534 "program.yy"
>>>>>>> 78b1f60 (First commit.)



void tchecker::parsing::program::parser_t::error(location_type const & l, std::string const & msg)
{
  if (program_context.empty()) {
    log.error(l, msg);
  }
  else {
    std::stringstream strl;
    strl << l;
    log.error(program_context, msg + " (at " + strl.str() + ")");
  }
  ++ error_count;
}
