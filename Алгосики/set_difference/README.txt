Вам необходимо реализовать шаблонный алгоритм transform_if с заголовком
template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter TransformIf(InIter first, InIter last, OutIter out, Predicate condition, Action f)
Этот алгоритм должен применить функцию f к тем элементам из полуинтервала [first, last), для которых предикат condition вернул true, и положить результат применения во второй полуинтервал (начинающийся с out) в том же порядке.
Результатом работы функции должен быть итератор, указывающий за последний сохраненный элемент (или равный out, если ни один элемент скопирован не был).
