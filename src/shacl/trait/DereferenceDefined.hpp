template<typename T, typename = void>
struct DereferenceDefined : std::false_type {};

template<typename T>
struct DereferenceDefined< T, void_t<decltype(*std::declval<T>())> > 
  : std::true_type {};

template<typename T>
static constexpr bool DereferenceDefined_v = 
  DereferenceDefined< T >::value;
