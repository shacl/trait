template<typename Left, typename Right = Left, typename = void>
struct EqualityDefined : std::false_type {};

template<typename Left, typename Right>
struct EqualityDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() == std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool EqualityDefined_v =
 EqualityDefined<Left, Right>::value;
