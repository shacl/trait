template<typename Left, typename Right = Left>
struct Comparable :
  std::integral_constant
  <bool,
   LessThanDefined_v<Left, Right>
   and LessThanEqualDefined_v<Left, Right>
   and GreaterThanDefined_v<Left, Right>
   and GreaterThanEqualDefined_v<Left, Right>
   and EqualityDefined_v<Left, Right>
   and InequalityDefined_v<Left, Right>>{};

template<typename Left, typename Right = Left>
static constexpr bool Comparable_v = Comparable<Left, Right>::value;
