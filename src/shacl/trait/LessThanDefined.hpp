template<typename Left, typename Right = Left, typename = void>
struct LessThanDefined : std::false_type {};

template<typename Left, typename Right>
struct LessThanDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() < std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool LessThanDefined_v =
 LessThanDefined<Left, Right>::value;
