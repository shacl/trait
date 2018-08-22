template<typename Left, typename Right = Left, typename = void>
struct GreaterThanEqualDefined : std::false_type {};

template<typename Left, typename Right>
struct GreaterThanEqualDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() >= std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool GreaterThanEqualDefined_v =
 GreaterThanEqualDefined<Left, Right>::value;
