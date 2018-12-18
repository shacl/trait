template<typename Left, typename Right = Left>
static constexpr bool Scalable_v =
  MultiplicationDefined_v<Left, Right> and DivisionDefined_v<Left, Right>;

template<typename Left, typename Right = Left>
using Scalable = bool_t<Scalable_v<Left, Right>>;


