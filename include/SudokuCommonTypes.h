#pragma once
namespace Sudoku
{
   class Coord;
   class Puzzle;
   class Solver;

   class AlgorithmInterface;
   class RecursiveBacktrack;

   static const int PUZZLE_MAX_INDEX = 80;
   static const int PUZZLE_MAX_ELEMENTS = (PUZZLE_MAX_INDEX + 1);

   enum class RowType : unsigned char
   {
      ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
   };

   enum class ColType : unsigned char
   {
      COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
   };

   enum class ValType : unsigned char
   {
      VAL_UNMARKED, VAL_1, VAL_2, VAL_3, VAL_4, VAL_5, VAL_6, VAL_7, VAL_8, VAL_9
   };

   template <class T1, class T2>
   inline bool operator==(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) == static_cast<unsigned char>(rhs);
   }

   template <class T1, class T2>
   inline bool operator!=(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) != static_cast<unsigned char>(rhs);
   }

   template <class T1, class T2>
   inline bool operator>(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) > static_cast<unsigned char>(rhs);
   }

   template <class T1, class T2>
   inline bool operator>=(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) >= static_cast<unsigned char>(rhs);
   }

   template <class T1, class T2>
   inline bool operator<(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) < static_cast<unsigned char>(rhs);
   }

   template <class T1, class T2>
   inline bool operator<=(const T1& lhs, const T2& rhs)
   {
      return static_cast<unsigned char>(lhs) <= static_cast<unsigned char>(rhs);
   }

   template <class T1, class T2>
   inline ValType operator+(const T1& lhs, const T2& rhs)
   {
      unsigned char sum = static_cast<unsigned char>(lhs) + static_cast<unsigned char>(rhs);
      return static_cast<ValType>(static_cast<unsigned char>(lhs) + static_cast<unsigned char>(rhs));
   }


   // ValType Specific overload operators
   inline ValType operator++(ValType& val)
   {
      val = static_cast<ValType>((static_cast<int>(val) + 1) % (11));
      return val;
   }

   inline ValType operator++(ValType& val, int)
   {
      ValType temp = val;
      val = static_cast<ValType>((static_cast<int>(val) + 1) % (11));
      return temp;
   }

   inline ValType operator--(ValType& val)
   {
      val = val==0 ? ValType::VAL_9 : static_cast<ValType>((static_cast<int>(val) - 1));
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