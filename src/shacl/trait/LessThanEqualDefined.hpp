template<typename Left, typename Right = Left, typename = void>
struct LessThanEqualDefined : std::false_type {};

template<typename Left, typename Right>
struct LessThanEqualDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() <= std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool LessThanEqualDefined_v =
 LessThanEqualDefined<Left, Right>::value;
