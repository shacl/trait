template<typename Left, typename Right = Left,
         bool =
         EqualityDefined_v<Left, Right>
         and EqualityDefined_v<Right, Left>
         and InequalityDefined_v<Left, Right>
         and InequalityDefined_v<Right, Left>>
constexpr const bool EqualityComparable_v =
  std::is_convertible<EqualityResult_t<Left, Right>, bool>::value
  and std::is_convertible<EqualityResult_t<Right, Left>, bool>::value
  and std::is_convertible<InequalityResult_t<Left, Right>, bool>::value
  and std::is_convertible<InequalityResult_t<Right, Left>, bool>::value;

template<typename Left, typename Right>
constexpr const bool EqualityComparable_v<Left, Right, false> = false;

template<typename... Args>
using EqualityComparable = bool_t<EqualityComparable_v<Args...>>;
