#pragma once
#include <type_traits>

namespace Sudoku
{
   class Coord;
   class Puzzle;
   class Solver;

   class AlgorithmInterface;
   class IterativeBacktrack;

   static const int PUZZLE_MAX_INDEX = 80;
   static const int PUZZLE_MAX_ELEMENTS = (PUZZLE_MAX_INDEX + 1);

   // Sudoku Primitive Types
   enum RowType : unsigned char
   {
      ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
   };

   enum ColType : unsigned char
   {
      COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
   };

   enum ValType : unsigned char
   {
      VAL_UNMARKED, VAL_1, VAL_2, VAL_3, VAL_4, VAL_5, VAL_6, VAL_7, VAL_8, VAL_9
   };

   template< typename T >
   constexpr bool is_SudokuPrimitive_v = (std::is_same<T, ValType>::value || std::is_same<T, RowType>::value || std::is_same<T, ColType>::value);

   template< typename T >
   using enable_if_SudokuPrim_t = typename std::enable_if<is_SudokuPrimitive_v<T>>::type;

   template< typename T1, typename T2 >
   using enable_if_SudokuPrim_t2 = typename std::enable_if<is_SudokuPrimitive_v<T1> || is_SudokuPrimitive_v<T2>>::type;

   template < class T1, class T2, class = enable_if_SudokuPrim_t2<T1, T2> >
   inline bool operator==(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) == static_cast<unsigned char>(rhs);
   }

   template < class T1, class T2, class = enable_if_SudokuPrim_t2<T1, T2> >
   inline bool operator!=(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) != static_cast<unsigned char>(rhs);
   }

   template < class T1, class T2, class = enable_if_SudokuPrim_t2<T1, T2> >
   inline bool operator>(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) > static_cast<unsigned char>(rhs);
   }

   template < class T1, class T2, class = enable_if_SudokuPrim_t2<T1, T2> >
   inline bool operator>=(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) >= static_cast<unsigned char>(rhs);
   }

   template < class T1, class T2, class = enable_if_SudokuPrim_t2<T1, T2> >
   inline bool operator<(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) < static_cast<unsigned char>(rhs);
   }

   template < class T1, class T2, class = enable_if_SudokuPrim_t2<T1, T2> >
   inline bool operator<=(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) <= static_cast<unsigned char>(rhs);
   }

   inline ValType operator+(const ValType& lhs, int rhs)
   {
      unsigned char sum =
         (static_cast<unsigned char>(lhs) + static_cast<unsigned char>(rhs)) % (static_cast<unsigned char>(VAL_9) + 1);
      return static_cast<ValType>(sum);
   }

   inline ValType operator++(ValType& val)
   {
      val = static_cast<ValType>((static_cast<int>(val) + 1) % (static_cast<unsigned char>(VAL_9) + 1));
      return val;
   }

   inline ValType operator++(ValType& val, int)
   {
      ValType temp = val;
      val = static_cast<ValType>((static_cast<int>(val) + 1) % (static_cast<unsigned char>(VAL_9) + 1));
      return temp;
   }

   inline ValType operator--(ValType& val)
   {
      val = val==0 ? VAL_9 : static_cast<ValType>((static_cast<int>(val) - 1));
      return val;
   }

   inline ValType operator--(ValType& val, int)
   {
      ValType temp = val;
      val==0 ? val = ValType::VAL_9 : val = static_cast<ValType>((static_cast<int>(val) - 1));
      return temp;
   }

   typedef ValType* PuzzlePtrType;
   typedef int Index;
}