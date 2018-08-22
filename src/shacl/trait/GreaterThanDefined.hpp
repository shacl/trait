template<typename Left, typename Right = Left, typename = void>
struct GreaterThanDefined : std::false_type {};

template<typename Left, typename Right>
struct GreaterThanDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() > std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool GreaterThanDefined_v =
 GreaterThanDefined<Left, Right>::value;
