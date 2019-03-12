namespace detail {

template<class T, class Type, class T1, class... Args,
         class ResultT = decltype((std::declval<T1>().*std::declval<Type T::*>())(
                                    std::declval<Args>()...)),
         std::enable_if_t
         <std::is_member_function_pointer<Type T::*>::value
          and std::is_base_of<T, std::decay_t<T1>>::value, bool> = true>
ResultT INVOKE(Type T::* f, T1&& t1, Args&&... args)
  noexcept(noexcept((std::forward<T1>(t1).*f)(std::forward<Args>(args)...))) {
  return (std::forward<T1>(t1).*f)(std::forward<Args>(args)...);
}

template<class T, class Type, class T1, class... Args,
         class ResultT = decltype((std::declval<T1>().get().*std::declval<Type T::*>())(
                                    std::declval<Args>()...)),
         std::enable_if_t
         <std::is_member_function_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
ResultT INVOKE(Type T::* f, T1&& t1, Args&&... args)
  noexcept(noexcept((t1.get().*f)(std::forward<Args>(args)...))) {
  return (t1.get().*f)(std::forward<Args>(args)...);
}

template<class T, class Type, class T1, class... Args,
         class ResultT = decltype(((*std::declval<T1>()).*std::declval<Type T::*>())(
                                    std::declval<Args>()...)),
         std::enable_if_t
         <std::is_member_function_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and not IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
ResultT INVOKE(Type T::* f, T1&& t1, Args&&... args)
  noexcept(noexcept(((*std::forward<T1>(t1)).*f)(std::forward<Args>(args)...))) {
  return ((*std::forward<T1>(t1)).*f)(std::forward<Args>(args)...);
}

template<class T, class Type, class T1,
         class ResultT = decltype(std::declval<T1>().*std::declval<Type T::*>()),
         std::enable_if_t
         <std::is_member_object_pointer<Type T::*>::value
          and std::is_base_of<T, std::decay_t<T1>>::value, bool> = true>
ResultT INVOKE(Type T::* f, T1&& t1)
  noexcept(noexcept(std::forward<T1>(t1).*f)) {
  return std::forward<T1>(t1).*f;
}

template<class T, class Type, class T1,
         class ResultT = decltype(std::declval<T1>().get().*std::declval<Type T::*>()),
         std::enable_if_t
         <std::is_member_object_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
ResultT INVOKE(Type T::* f, T1&& t1)
  noexcept(noexcept(t1.get().*f)) {
  return t1.get().*f;
}

template<class T, class Type, class T1,
         class ResultT = decltype(*(std::declval<T1>()).*std::declval<Type T::*>()),
         std::enable_if_t
         <std::is_member_object_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and not IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
ResultT INVOKE(Type T::* f, T1&& t1)
  noexcept(noexcept((*std::forward<T1>(t1)).*f)) {
  return (*std::forward<T1>(t1)).*f;
}

template<class F, class... Args,
         class ResultT = decltype(std::declval<F>()(std::declval<Args>()...)),
         std::enable_if_t
         <not std::is_member_object_pointer<F>::value
          and not std::is_member_function_pointer<F>::value, bool> = true>
ResultT INVOKE(F&& f, Args&&... args)
  noexcept(noexcept(std::forward<F>(f)(std::forward<Args>(args)...))) {
  return std::forward<F>(f)(std::forward<Args>(args)...);
}

}
