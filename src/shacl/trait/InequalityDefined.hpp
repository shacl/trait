template<typename Left, typename Right = Left, typename = void>
struct InequalityDefined : std::false_type {};

template<typename Left, typename Right>
struct InequalityDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() != std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool InequalityDefined_v =
  InequalityDefined<Left, Right>::value;
