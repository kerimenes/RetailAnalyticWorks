#ifndef HELPER_H
#define HELPER_H

#include <QList>
#include <vector>

namespace helper {
template <class T> QList<T> VectorToQList(const std::vector<T> &a_input) {
  QList<T> res;
  for (auto &x : a_input) {
    res.append(x);
  }
  return res;
}
} // namespace helper

#endif // HELPER_H
