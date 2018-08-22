template<typename Left, typename Right = Left>
struct Arithmetic :
  std::integral_constant
  <bool,
   AdditionDefined_v<Left, Right>
   and SubtractionDefined_v<Left, Right>
   and Scalable_v<Left, Right>>{};

template<typename Left, typename Right = Left>
static constexpr bool Arithmetic_v = Arithmetic<Left, Right>::value;
