template<typename Left, typename Right = Left>
struct Scalable :
  std::integral_constant
  <bool,
   MultiplicationDefined_v<Left, Right>
   and DivisionDefined_v<Left, Right>>{};

template<typename Left, typename Right = Left>
static constexpr bool Scalable_v = Scalable<Left, Right>::value;
