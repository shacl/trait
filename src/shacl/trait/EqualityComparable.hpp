template<typename Left, typename Right = Left>
struct EqualityComparable :
  std::integral_constant
  <bool, EqualityDefined_v<Left, Right>
         and InequalityDefined_v<Left, Right>>{};

template<typename... Args>
static constexpr bool EqualityComparable_v =
  EqualityComparable<Args...>::value;
