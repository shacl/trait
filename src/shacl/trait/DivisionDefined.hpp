template<typename Left, typename Right = Left, typename = void>
struct DivisionDefined : std::false_type {};

template<typename Left, typename Right>
struct DivisionDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() / std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool DivisionDefined_v =
 DivisionDefined<Left, Right>::value;
