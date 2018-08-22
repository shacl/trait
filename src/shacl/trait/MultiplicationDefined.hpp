template<typename Left, typename Right = Left, typename = void>
struct MultiplicationDefined : std::false_type {};

template<typename Left, typename Right>
struct MultiplicationDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() * std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool MultiplicationDefined_v =
 MultiplicationDefined<Left, Right>::value;
