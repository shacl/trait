template<typename T, typename = void>
struct IsRange : std::false_type {};

template<typename T>
struct IsRange
<T, void_t<decltype(std::begin(std::declval<T>())),
           decltype(std::end(std::declval<T>()))>> :
  std::true_type {};

template<typename T>
static constexpr bool IsRange_v = IsRange<T>::value;
