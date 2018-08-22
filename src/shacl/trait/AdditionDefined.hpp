template<typename Left, typename Right = Left, typename = void>
struct AdditionDefined : std::false_type {};

template<typename Left, typename Right>
struct AdditionDefined
<Left, Right,
 void_t<decltype(std::declval<Left>() + std::declval<Right>())>>
  : std::true_type {};

template<typename Left, typename Right = Left>
static constexpr bool AdditionDefined_v =
 AdditionDefined<Left, Right>::value;
