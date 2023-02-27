// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
<<<<<<< HEAD
 ** \file /home/karthik/IITB/MTP/tchecker/src/parsing/system_parser/system.tab.hh
=======
 ** \file /home/karthik/Computers/tchecker/src/parsing/system_parser/system.tab.hh
>>>>>>> 78b1f60 (First commit.)
 ** Define the tchecker::parsing::system::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

<<<<<<< HEAD
#ifndef YY_SPYY_HOME_KARTHIK_IITB_MTP_TCHECKER_SRC_PARSING_SYSTEM_PARSER_SYSTEM_TAB_HH_INCLUDED
# define YY_SPYY_HOME_KARTHIK_IITB_MTP_TCHECKER_SRC_PARSING_SYSTEM_PARSER_SYSTEM_TAB_HH_INCLUDED
// //                    "%code requires" blocks.
#line 22 "system.yy" // lalr1.cc:377
=======
// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_SPYY_HOME_KARTHIK_COMPUTERS_TCHECKER_SRC_PARSING_SYSTEM_PARSER_SYSTEM_TAB_HH_INCLUDED
# define YY_SPYY_HOME_KARTHIK_COMPUTERS_TCHECKER_SRC_PARSING_SYSTEM_PARSER_SYSTEM_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 22 "system.yy"
>>>>>>> 78b1f60 (First commit.)

  #include <cstdlib>
  #include <limits>
  #include <sstream>
  #include <string>
  #include <vector>
  
  #include <boost/algorithm/string.hpp>
  
  #include "tchecker/basictypes.hh"
  #include "tchecker/parsing/declaration.hh"
  #include "tchecker/utils/log.hh"

<<<<<<< HEAD
#line 58 "/home/karthik/IITB/MTP/tchecker/src/parsing/system_parser/system.tab.hh" // lalr1.cc:377
=======
#line 63 "/home/karthik/Computers/tchecker/src/parsing/system_parser/system.tab.hh"
>>>>>>> 78b1f60 (First commit.)

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef SPYY_ASSERT
# include <cassert>
# define SPYY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef SPYYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define SPYYDEBUG 1
#  else
#   define SPYYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define SPYYDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined SPYYDEBUG */

#line 13 "system.yy"
namespace tchecker { namespace parsing { namespace system {
<<<<<<< HEAD
#line 143 "/home/karthik/IITB/MTP/tchecker/src/parsing/system_parser/system.tab.hh" // lalr1.cc:377
=======
#line 212 "/home/karthik/Computers/tchecker/src/parsing/system_parser/system.tab.hh"
>>>>>>> 78b1f60 (First commit.)




  /// A Bison parser.
  class parser_t
  {
  public:
#ifdef SPYYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define SPYYSTYPE in C++, use %define api.value.type"
# endif
    typedef SPYYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      SPYY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      SPYY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      SPYY_ASSERT (!yytypeid_);
      SPYY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      SPYY_ASSERT (!yytypeid_);
      SPYY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      SPYY_ASSERT (!yytypeid_);
      SPYY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      SPYY_ASSERT (yytypeid_);
      SPYY_ASSERT (*yytypeid_ == typeid (T));
      SPYY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      SPYY_ASSERT (yytypeid_);
      SPYY_ASSERT (*yytypeid_ == typeid (T));
      SPYY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      SPYY_ASSERT (yytypeid_);
      SPYY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // sync_strength
      char dummy1[sizeof (enum tchecker::sync_strength_t)];

      // "identifier"
      // "integer value"
      // "text value"
      // text_or_empty
      char dummy2[sizeof (std::string)];

      // sync_constraint_list
      char dummy3[sizeof (std::vector<tchecker::parsing::sync_constraint_t const *>)];

      // integer
      char dummy4[sizeof (tchecker::integer_t)];

      // attr
      char dummy5[sizeof (tchecker::parsing::attr_t *)];

      // attr_list
      // non_empty_attr_list
      char dummy6[sizeof (tchecker::parsing::attributes_t)];

      // sop
      char dummy7[sizeof (tchecker::parsing::stack_op *)];

      // sync_constraint
      char dummy8[sizeof (tchecker::parsing::sync_constraint_t *)];

      // uinteger
      char dummy9[sizeof (unsigned int)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        SPYYEMPTY = -2,
    TOK_EOF = 0,                   // "end of file"
    SPYYerror = 256,               // error
    SPYYUNDEF = 257,               // "invalid token"
    TOK_CLOCK = 258,               // "clock"
    TOK_COLON = 259,               // ":"
    TOK_AT = 260,                  // "@"
    TOK_QMARK = 261,               // "?"
    TOK_LBRACE = 262,              // "{"
    TOK_RBRACE = 263,              // "}"
    TOK_LSQBRACE = 264,            // "["
    TOK_RSQBRACE = 265,            // "]"
    TOK_LT = 266,                  // "<"
    TOK_GT = 267,                  // ">"
    TOK_LEQ = 268,                 // "<="
    TOK_GEQ = 269,                 // ">="
    TOK_PUSH = 270,                // "push"
    TOK_POP = 271,                 // "pop"
    TOK_EDGE = 272,                // "edge"
    TOK_EOL = 273,                 // "\n"
    TOK_EVENT = 274,               // "event"
    TOK_ID = 275,                  // "identifier"
    TOK_INT = 276,                 // "int"
    TOK_INTEGER = 277,             // "integer value"
    TOK_LOCATION = 278,            // "location"
    TOK_PROCESS = 279,             // "process"
    TOK_SYNC = 280,                // "sync"
    TOK_SYSTEM = 281,              // "system"
    TOK_TEXT = 282                 // "text value"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 28, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_TOK_CLOCK = 3,                         // "clock"
        S_TOK_COLON = 4,                         // ":"
        S_TOK_AT = 5,                            // "@"
        S_TOK_QMARK = 6,                         // "?"
        S_TOK_LBRACE = 7,                        // "{"
        S_TOK_RBRACE = 8,                        // "}"
        S_TOK_LSQBRACE = 9,                      // "["
        S_TOK_RSQBRACE = 10,                     // "]"
        S_TOK_LT = 11,                           // "<"
        S_TOK_GT = 12,                           // ">"
        S_TOK_LEQ = 13,                          // "<="
        S_TOK_GEQ = 14,                          // ">="
        S_TOK_PUSH = 15,                         // "push"
        S_TOK_POP = 16,                          // "pop"
        S_TOK_EDGE = 17,                         // "edge"
        S_TOK_EOL = 18,                          // "\n"
        S_TOK_EVENT = 19,                        // "event"
        S_TOK_ID = 20,                           // "identifier"
        S_TOK_INT = 21,                          // "int"
        S_TOK_INTEGER = 22,                      // "integer value"
        S_TOK_LOCATION = 23,                     // "location"
        S_TOK_PROCESS = 24,                      // "process"
        S_TOK_SYNC = 25,                         // "sync"
        S_TOK_SYSTEM = 26,                       // "system"
        S_TOK_TEXT = 27,                         // "text value"
        S_YYACCEPT = 28,                         // $accept
        S_system = 29,                           // system
        S_30_1 = 30,                             // $@1
        S_declaration_list = 31,                 // declaration_list
        S_non_empty_declaration_list = 32,       // non_empty_declaration_list
        S_declaration = 33,                      // declaration
        S_attr_list = 34,                        // attr_list
        S_non_empty_attr_list = 35,              // non_empty_attr_list
        S_sop = 36,                              // sop
        S_attr = 37,                             // attr
        S_text_or_empty = 38,                    // text_or_empty
        S_sync_constraint_list = 39,             // sync_constraint_list
        S_sync_constraint = 40,                  // sync_constraint
        S_sync_strength = 41,                    // sync_strength
        S_eol_sequence = 42,                     // eol_sequence
        S_integer = 43,                          // integer
        S_uinteger = 44                          // uinteger
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_sync_strength: // sync_strength
        value.move< enum tchecker::sync_strength_t > (std::move (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer value"
      case symbol_kind::S_TOK_TEXT: // "text value"
      case symbol_kind::S_text_or_empty: // text_or_empty
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_sync_constraint_list: // sync_constraint_list
        value.move< std::vector<tchecker::parsing::sync_constraint_t const *> > (std::move (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.move< tchecker::integer_t > (std::move (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.move< tchecker::parsing::attr_t * > (std::move (that.value));
        break;

      case symbol_kind::S_attr_list: // attr_list
      case symbol_kind::S_non_empty_attr_list: // non_empty_attr_list
        value.move< tchecker::parsing::attributes_t > (std::move (that.value));
        break;

      case symbol_kind::S_sop: // sop
        value.move< tchecker::parsing::stack_op * > (std::move (that.value));
        break;

      case symbol_kind::S_sync_constraint: // sync_constraint
        value.move< tchecker::parsing::sync_constraint_t * > (std::move (that.value));
        break;

      case symbol_kind::S_uinteger: // uinteger
        value.move< unsigned int > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, enum tchecker::sync_strength_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const enum tchecker::sync_strength_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<tchecker::parsing::sync_constraint_t const *>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<tchecker::parsing::sync_constraint_t const *>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, tchecker::integer_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const tchecker::integer_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, tchecker::parsing::attr_t *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const tchecker::parsing::attr_t *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, tchecker::parsing::attributes_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const tchecker::parsing::attributes_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, tchecker::parsing::stack_op *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const tchecker::parsing::stack_op *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, tchecker::parsing::sync_constraint_t *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const tchecker::parsing::sync_constraint_t *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unsigned int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unsigned int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_sync_strength: // sync_strength
        value.template destroy< enum tchecker::sync_strength_t > ();
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer value"
      case symbol_kind::S_TOK_TEXT: // "text value"
      case symbol_kind::S_text_or_empty: // text_or_empty
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_sync_constraint_list: // sync_constraint_list
        value.template destroy< std::vector<tchecker::parsing::sync_constraint_t const *> > ();
        break;

      case symbol_kind::S_integer: // integer
        value.template destroy< tchecker::integer_t > ();
        break;

      case symbol_kind::S_attr: // attr
        value.template destroy< tchecker::parsing::attr_t * > ();
        break;

      case symbol_kind::S_attr_list: // attr_list
      case symbol_kind::S_non_empty_attr_list: // non_empty_attr_list
        value.template destroy< tchecker::parsing::attributes_t > ();
        break;

      case symbol_kind::S_sop: // sop
        value.template destroy< tchecker::parsing::stack_op * > ();
        break;

      case symbol_kind::S_sync_constraint: // sync_constraint
        value.template destroy< tchecker::parsing::sync_constraint_t * > ();
        break;

      case symbol_kind::S_uinteger: // uinteger
        value.template destroy< unsigned int > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser_t::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        SPYY_ASSERT (tok == token::TOK_EOF
                   || (token::SPYYerror <= tok && tok <= token::TOK_EVENT)
                   || tok == token::TOK_INT
                   || (token::TOK_LOCATION <= tok && tok <= token::TOK_SYSTEM));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        SPYY_ASSERT (tok == token::TOK_ID
                   || tok == token::TOK_INTEGER
                   || tok == token::TOK_TEXT);
#endif
      }
    };

    /// Build a parser object.
    parser_t (std::string const & filename_yyarg, tchecker::log_t & log_yyarg, tchecker::parsing::system_declaration_t * & system_declaration_yyarg);
    virtual ~parser_t ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser_t (const parser_t&) = delete;
    /// Non copyable.
    parser_t& operator= (const parser_t&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if SPYYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_EOF (location_type l)
      {
        return symbol_type (token::TOK_EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_EOF (const location_type& l)
      {
        return symbol_type (token::TOK_EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPYYerror (location_type l)
      {
        return symbol_type (token::SPYYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_SPYYerror (const location_type& l)
      {
        return symbol_type (token::SPYYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPYYUNDEF (location_type l)
      {
        return symbol_type (token::SPYYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_SPYYUNDEF (const location_type& l)
      {
        return symbol_type (token::SPYYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_CLOCK (location_type l)
      {
        return symbol_type (token::TOK_CLOCK, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_CLOCK (const location_type& l)
      {
        return symbol_type (token::TOK_CLOCK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_COLON (location_type l)
      {
        return symbol_type (token::TOK_COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_COLON (const location_type& l)
      {
        return symbol_type (token::TOK_COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_AT (location_type l)
      {
        return symbol_type (token::TOK_AT, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_AT (const location_type& l)
      {
        return symbol_type (token::TOK_AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_QMARK (location_type l)
      {
        return symbol_type (token::TOK_QMARK, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_QMARK (const location_type& l)
      {
        return symbol_type (token::TOK_QMARK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LBRACE (location_type l)
      {
        return symbol_type (token::TOK_LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_RBRACE (location_type l)
      {
        return symbol_type (token::TOK_RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_RBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LSQBRACE (location_type l)
      {
        return symbol_type (token::TOK_LSQBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LSQBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_LSQBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_RSQBRACE (location_type l)
      {
        return symbol_type (token::TOK_RSQBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_RSQBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_RSQBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LT (location_type l)
      {
        return symbol_type (token::TOK_LT, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LT (const location_type& l)
      {
        return symbol_type (token::TOK_LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_GT (location_type l)
      {
        return symbol_type (token::TOK_GT, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_GT (const location_type& l)
      {
        return symbol_type (token::TOK_GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LEQ (location_type l)
      {
        return symbol_type (token::TOK_LEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LEQ (const location_type& l)
      {
        return symbol_type (token::TOK_LEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_GEQ (location_type l)
      {
        return symbol_type (token::TOK_GEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_GEQ (const location_type& l)
      {
        return symbol_type (token::TOK_GEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_PUSH (location_type l)
      {
        return symbol_type (token::TOK_PUSH, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_PUSH (const location_type& l)
      {
        return symbol_type (token::TOK_PUSH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_POP (location_type l)
      {
        return symbol_type (token::TOK_POP, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_POP (const location_type& l)
      {
        return symbol_type (token::TOK_POP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_EDGE (location_type l)
      {
        return symbol_type (token::TOK_EDGE, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_EDGE (const location_type& l)
      {
        return symbol_type (token::TOK_EDGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_EOL (location_type l)
      {
        return symbol_type (token::TOK_EOL, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_EOL (const location_type& l)
      {
        return symbol_type (token::TOK_EOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_EVENT (location_type l)
      {
        return symbol_type (token::TOK_EVENT, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_EVENT (const location_type& l)
      {
        return symbol_type (token::TOK_EVENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_ID (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_INT (location_type l)
      {
        return symbol_type (token::TOK_INT, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_INT (const location_type& l)
      {
        return symbol_type (token::TOK_INT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_INTEGER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_INTEGER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LOCATION (location_type l)
      {
        return symbol_type (token::TOK_LOCATION, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LOCATION (const location_type& l)
      {
        return symbol_type (token::TOK_LOCATION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_PROCESS (location_type l)
      {
        return symbol_type (token::TOK_PROCESS, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_PROCESS (const location_type& l)
      {
        return symbol_type (token::TOK_PROCESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_SYNC (location_type l)
      {
        return symbol_type (token::TOK_SYNC, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_SYNC (const location_type& l)
      {
        return symbol_type (token::TOK_SYNC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_SYSTEM (location_type l)
      {
        return symbol_type (token::TOK_SYSTEM, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_SYSTEM (const location_type& l)
      {
        return symbol_type (token::TOK_SYSTEM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_TEXT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TEXT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_TEXT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TEXT, v, l);
      }
#endif


    class context
    {
    public:
      context (const parser_t& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser_t& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser_t (const parser_t&);
    /// Non copyable.
    parser_t& operator= (const parser_t&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if SPYYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 143,     ///< Last index in yytable_.
      yynnts_ = 17,  ///< Number of nonterminal symbols.
      yyfinal_ = 5 ///< Termination state number.
    };


    // User arguments.
    std::string const & filename;
    tchecker::log_t & log;
    tchecker::parsing::system_declaration_t * & system_declaration;

  };

  inline
  parser_t::symbol_kind_type
  parser_t::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
    };
    // Last valid token kind.
    const int code_max = 282;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser_t::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_sync_strength: // sync_strength
        value.copy< enum tchecker::sync_strength_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer value"
      case symbol_kind::S_TOK_TEXT: // "text value"
      case symbol_kind::S_text_or_empty: // text_or_empty
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sync_constraint_list: // sync_constraint_list
        value.copy< std::vector<tchecker::parsing::sync_constraint_t const *> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.copy< tchecker::integer_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.copy< tchecker::parsing::attr_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr_list: // attr_list
      case symbol_kind::S_non_empty_attr_list: // non_empty_attr_list
        value.copy< tchecker::parsing::attributes_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sop: // sop
        value.copy< tchecker::parsing::stack_op * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sync_constraint: // sync_constraint
        value.copy< tchecker::parsing::sync_constraint_t * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uinteger: // uinteger
        value.copy< unsigned int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser_t::symbol_kind_type
  parser_t::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser_t::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser_t::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_sync_strength: // sync_strength
        value.move< enum tchecker::sync_strength_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer value"
      case symbol_kind::S_TOK_TEXT: // "text value"
      case symbol_kind::S_text_or_empty: // text_or_empty
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_sync_constraint_list: // sync_constraint_list
        value.move< std::vector<tchecker::parsing::sync_constraint_t const *> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_integer: // integer
        value.move< tchecker::integer_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_attr: // attr
        value.move< tchecker::parsing::attr_t * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_attr_list: // attr_list
      case symbol_kind::S_non_empty_attr_list: // non_empty_attr_list
        value.move< tchecker::parsing::attributes_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_sop: // sop
        value.move< tchecker::parsing::stack_op * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_sync_constraint: // sync_constraint
        value.move< tchecker::parsing::sync_constraint_t * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_uinteger: // uinteger
        value.move< unsigned int > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser_t::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser_t::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser_t::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser_t::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser_t::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser_t::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser_t::symbol_kind_type
  parser_t::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser_t::symbol_kind_type
  parser_t::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 13 "system.yy"
} } } // tchecker::parsing::system
<<<<<<< HEAD
#line 1431 "/home/karthik/IITB/MTP/tchecker/src/parsing/system_parser/system.tab.hh" // lalr1.cc:377
=======
#line 2056 "/home/karthik/Computers/tchecker/src/parsing/system_parser/system.tab.hh"
>>>>>>> 78b1f60 (First commit.)




<<<<<<< HEAD
#endif // !YY_SPYY_HOME_KARTHIK_IITB_MTP_TCHECKER_SRC_PARSING_SYSTEM_PARSER_SYSTEM_TAB_HH_INCLUDED
=======
#endif // !YY_SPYY_HOME_KARTHIK_COMPUTERS_TCHECKER_SRC_PARSING_SYSTEM_PARSER_SYSTEM_TAB_HH_INCLUDED
>>>>>>> 78b1f60 (First commit.)
