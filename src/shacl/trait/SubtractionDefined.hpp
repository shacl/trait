template<typename Left, typename Right = Left, typename = void>
struct SubtractionDefined : std::false_type {};

template<typename Left, typename Right>
struct SubtractionDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() - std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool SubtractionDefined_v =
 SubtractionDefined<Left, Right>::value;
