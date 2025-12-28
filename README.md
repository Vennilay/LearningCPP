# LearningCPP

Учебный репозиторий с решениями практических и домашних заданий по C++.

## Дисклеймер

- Формулировки заданий и сами задания принадлежат их правообладателю (образовательной организации/авторам методических материалов).
- Репозиторий не является «сливом экзаменов» или закрытых материалов: здесь используется то, что находится в открытом доступе и в похожем виде встречается из года в год.
- Цель — обмен подходами и обучение. Ничьи работы не выдаются за свои и чужие материалы не «присваиваются».

## Навигация

### Выбор домашки (без 404)

Проще всего искать по папкам `HW_<N>` через встроенный поиск GitHub по репозиторию (страница *Find*): выбираете домашку — получаете список всех совпадений в `homework/`.

- HW_1: https://github.com/Vennilay/LearningCPP/find/Vennilay?path=homework&q=HW_1
- HW_2: https://github.com/Vennilay/LearningCPP/find/Vennilay?path=homework&q=HW_2
- HW_3: https://github.com/Vennilay/LearningCPP/find/Vennilay?path=homework&q=HW_3
- HW_4: https://github.com/Vennilay/LearningCPP/find/Vennilay?path=homework&q=HW_4
- HW_5: https://github.com/Vennilay/LearningCPP/find/Vennilay?path=homework&q=HW_5
- HW_6: https://github.com/Vennilay/LearningCPP/find/Vennilay?path=homework&q=HW_6

Если у автора нет нужной домашки, в выдаче просто не будет его папки (никаких битых ссылок).

### Выбор автора

- Решения: [`homework/`](./homework/) → `<author>/` → `HW_<N>/`.
- Входные файлы (если используются): [`files/`](./files/) → `<author>/`.
- Условия: [`tasks/`](./tasks/) (PDF).

## Структура

```
LearningCPP/
├── .github/
│   └── CODEOWNERS
├── files/
│   └── <author>/
├── homework/
│   └── <author>/
│       └── HW_<N>/
│           ├── *.cpp
│           └── ...
├── tasks/
├── CMakeLists.txt
└── README.md
```

## Сборка

Требования: CMake 3.20+, компилятор с C++17, Git.

GNU/Linux / macOS:

```bash
cd LearningCPP
mkdir -p build && cd build
cmake ..
cmake --build .
```

Windows:

```bat
cd LearningCPP
mkdir build
cd build
cmake ..
cmake --build .
```

## Видео

https://github.com/user-attachments/assets/d0fc5383-34d3-4ed0-95dc-8fe59b489f3d
