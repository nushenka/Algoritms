Известная утилита word2vec, основанная на нейронной сети, умеет приписывать каждому слову из словаря некоторый числовой вектор размерности N. При этом оказывается, что семантически «близким» словам соответствуют «близкие» векторы. Эта утилита находит широкое применение в задачах обработки естественного языка и машинного обучения.
В качестве меры «близости» между словами обычно выбирают угол между их векторами, косинус которого вычисляют по известной формуле

Однако часто векторы слов нормируют (чтобы их длина стала равна константе), и тогда в качестве меры близости рассматривают просто скалярное произведение

Чем это скалярное произведение больше, тем семантически «ближе» слова друг к другу.
Вам дан словарь из M слов, каждому из которых сопоставлен N-мерный вектор. Гарантируется, что все слова различны. Требуется найти в этом списке ближайшие слова к первому слову (кроме самого этого первого слова), используя в качестве метрики близости просто скалярное произведение.