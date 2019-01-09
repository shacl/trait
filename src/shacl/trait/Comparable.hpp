template<typename Left, typename Right = Left,
         bool =
         LessThanDefined_v<Left, Right>
         and LessThanDefined_v<Right, Left>
         and LessThanEqualDefined_v<Left, Right>
         and LessThanEqualDefined_v<Right, Left>
         and GreaterThanDefined_v<Left, Right>
         and GreaterThanDefined_v<Right, Left>
         and GreaterThanEqualDefined_v<Left, Right>
         and GreaterThanEqualDefined_v<Right, Left>
         and EqualityComparable_v<Left, Right>>
constexpr const bool Comparable_v =
  std::is_convertible<LessThanResult_t<Left, Right>, bool>::value
  and std::is_convertible<LessThanResult_t<Right, Left>, bool>::value
  and std::is_convertible<LessThanEqualResult_t<Left, Right>, bool>::value
  and std::is_convertible<LessThanEqualResult_t<Right, Left>, bool>::value
  and std::is_convertible<GreaterThanResult_t<Left, Right>, bool>::value
  and std::is_convertible<GreaterThanResult_t<Right, Left>, bool>::value
  and std::is_convertible<GreaterThanEqualResult_t<Left, Right>, bool>::value
  and std::is_convertible<GreaterThanEqualResult_t<Right, Left>, bool>::value;

template<typename Left, typename Right>
constexpr const bool Comparable_v<Left, Right, false> = false;

template<typename... Args>
using Comparable = bool_t<Comparable_v<Args...>>;
