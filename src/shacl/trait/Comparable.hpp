template<typename Left, typename Right = Left>
constexpr const bool Comparable_v =
  LessThanDefined_v<Left, Right>
  and LessThanEqualDefined_v<Left, Right>
  and GreaterThanDefined_v<Left, Right>
  and GreaterThanEqualDefined_v<Left, Right>
  and EqualityDefined_v<Left, Right>
  and InequalityDefined_v<Left, Right>;

template<typename Left, typename Right = Left>
using Comparable = bool_t<Comparable_v<Left, Right>>;
