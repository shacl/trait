template<typename T, typename U=std::remove_cv_t<T>>
struct IsInteger : std::false_type {};

template<typename T>
struct IsInteger<T, short> : std::true_type {};

template<typename T>
struct IsInteger<T, unsigned short> : std::true_type {};

template<typename T>
struct IsInteger<T, int> : std::true_type {};

template<typename T>
struct IsInteger<T, unsigned int> : std::true_type {};

template<typename T>
struct IsInteger<T, long> : std::true_type {};

template<typename T>
struct IsInteger<T, unsigned long> : std::true_type {};

template<typename T>
struct IsInteger<T, long long> : std::true_type {};

template<typename T>
struct IsInteger<T, unsigned long long> : std::true_type {};

template<typename T>
static constexpr bool IsInteger_v = IsInteger< T >::value;
