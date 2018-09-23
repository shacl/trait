template<typename T, typename = void>
struct HasType : std::false_type {};

template<typename T>
struct HasType<T, void_t<typename T::type>> : std::true_type{};

template<typename T>
static constexpr bool HasType_v = HasType<T>::value;
