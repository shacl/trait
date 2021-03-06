template<typename Left, typename Right = Left>
constexpr const bool Arithmetic_v =
  AdditionDefined_v<Left, Right>
  and SubtractionDefined_v<Left, Right>
  and Scalable_v<Left, Right>
  and Comparable_v<Left, Right>;

template<typename... Args>
using Arithmetic = bool_t<Arithmetic_v<Args...>>;
