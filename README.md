# 📚 LearningCPP

![tony](https://github.com/user-attachments/assets/7c95bca2-6cb4-42f2-a1a7-8f7c2f4f7086)

## 🎓 Учебный проект по C++

> Репозиторий для совместного обучения и обмена подходами к решению практических и домашних заданий.

## ⚖️ Дисклеймер

- Формулировки заданий и сами задания принадлежат их **правообладателю** (образовательной организации/авторам методических материалов).
- Этот репозиторий **не является** «сливом экзамена» или закрытых материалов: используется только общедоступная учебная информация, которая, насколько известно, годами ходит в похожем виде и обычно лишь перемешивается от года к году.
- Здесь не присваивается чужая работа и не предпринимаются попытки «украсть» задания или выдать их за свои; цели репозитория — обучение, сравнение подходов и практика командной работы с Git/GitHub.

---

## 📖 Оглавление

- [Дисклеймер](#️-дисклеймер)
- [О проекте](#-о-проекте)
- [Кросс-платформенность и CMake](#-кросс-платформенность-и-cmake)
- [Наша команда](#-наша-команда)
- [Структура репозитория](#-структура-репозитория)
- [Система защиты кода](#-система-защиты-кода-codeowners)
- [Как запустить проект](#-как-запустить-проект)
- [Видеоинструкция](#-видеоинструкция)
- [Технические детали](#️-технические-детали)

---

## ✨ О проекте

Этот репозиторий создан для совместной работы над практическими и домашними заданиями по C++. Здесь удобно сравнивать разные подходы к решению одной задачи, делать ревью и прокачивать навыки командной разработки.

**Что делает проект полезным:**

- Совместное обучение: у каждого своя директория, но решения видны всем.
- Code review: изменения вносятся через Pull Request.
- Кросс-платформенность: сборка единообразна для разных ОС.
- Защита кода: CODEOWNERS не даст «случайно поправить» чужие файлы.

---

## 🌍 Кросс-платформенность и CMake

### 🔧 Почему нужен CMake

Команда работает на разных ОС, и CMake даёт единый способ собрать проект без ручной настройки под каждую систему.

- Генерирует файлы сборки под вашу платформу (Makefile/Ninja/Visual Studio/Xcode).
- Автоматически подхватывает исходники и создаёт отдельные таргеты.
- Копирует входные данные из `files/` в директорию сборки.

### ⚠️ Про кодировки в Windows

Если задачи предполагают ввод/вывод кириллицы, Windows часто требует дополнительной настройки кодировок консоли, в отличие от Linux/macOS, где UTF‑8 обычно «по умолчанию».

---

## 👥 Наша команда

> Иконки платформ сделаны через бейджи, чтобы macOS было видно и в тёмной теме GitHub.

<table>
<thead>
<tr>
<th align="center">👤 Участник</th>
<th align="center">💻 Платформа</th>
<th align="center">🔗 GitHub</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center"><strong>Vennilay</strong></td>
<td align="center"><img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white" /> → <img alt="GNU/Linux" src="https://img.shields.io/badge/GNU%2FLinux-000000?logo=linux&logoColor=white" /></td>
<td align="center"><a href="https://github.com/Vennilay">@Vennilay</a></td>
</tr>
<tr>
<td align="center"><strong>BAALOC</strong></td>
<td align="center"><img alt="macOS" src="https://img.shields.io/badge/macOS-000000?logo=apple&logoColor=white" /></td>
<td align="center"><a href="https://github.com/BAALOC">@BAALOC</a></td>
</tr>
<tr>
<td align="center"><strong>Fq1jjeR</strong></td>
<td align="center"><img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white" /></td>
<td align="center"><a href="https://github.com/Fq1jjeR">@Fq1jjeR</a></td>
</tr>
<tr>
<td align="center"><strong>EgorDevRus</strong></td>
<td align="center"><img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white" /> → <img alt="GNU/Linux" src="https://img.shields.io/badge/GNU%2FLinux-000000?logo=linux&logoColor=white" /></td>
<td align="center"><a href="https://github.com/EgorDevRus">@EgorDevRus</a></td>
</tr>
<tr>
<td align="center"><strong>Thesavewill</strong></td>
<td align="center"><img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white" /></td>
<td align="center"><a href="https://github.com/Thesavewill">@Thesavewill</a></td>
</tr>
<tr>
<td align="center"><strong>Vondre1</strong></td>
<td align="center"><img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white" /> → <img alt="GNU/Linux" src="https://img.shields.io/badge/GNU%2FLinux-000000?logo=linux&logoColor=white" /></td>
<td align="center"><a href="https://github.com/Vondre1">@Vondre1</a></td>
</tr>
<tr>
<td align="center"><strong>lkzz13</strong></td>
<td align="center"><img alt="macOS" src="https://img.shields.io/badge/macOS-000000?logo=apple&logoColor=white" /></td>
<td align="center"><a href="https://github.com/lkzz13">@lkzz13</a></td>
</tr>
<tr>
<td align="center"><strong>MXLNIK</strong></td>
<td align="center"><img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white" /></td>
<td align="center"><a href="https://github.com/MXLNIK">@MXLNIK</a></td>
</tr>
<tr>
<td align="center"><strong>lii636</strong></td>
<td align="center"><img alt="GNU/Linux" src="https://img.shields.io/badge/GNU%2FLinux-000000?logo=linux&logoColor=white" /></td>
<td align="center"><a href="https://github.com/lii636">@lii636</a></td>
</tr>
</tbody>
</table>

---

## 📁 Структура репозитория

```
LearningCPP/
│
├── .github/
│   └── CODEOWNERS              # Права доступа к директориям
│
├── files/                      # Входные данные для программ
│   └── <author>/
│
├── homework/                   # Решения
│   └── <author>/
│       └── HW_<N>/
│           ├── Task1.cpp
│           ├── Task2.cpp
│           └── ...
│
├── tasks/                      # Условия (PDF)
│
├── CMakeLists.txt
└── README.md
```

---

## 🔒 Система защиты кода (CODEOWNERS)

Используется `.github/CODEOWNERS`, чтобы изменения в чужих директориях проходили через ревью владельца.

---

## 🚀 Как запустить проект

### 📋 Требования

- CMake 3.20+
- Компилятор C++ с поддержкой C++17 (GCC/Clang/MSVC)
- Git

### ⌨️ Сборка через командную строку

**GNU/Linux / macOS:**

```bash
cd LearningCPP
mkdir -p build && cd build
cmake ..
cmake --build .
```

**Windows:**

```bat
cd LearningCPP
mkdir build
cd build
cmake ..
cmake --build .
```

---

## 🎥 Видеоинструкция

https://github.com/user-attachments/assets/d0fc5383-34d3-4ed0-95dc-8fe59b489f3d

---

## ⚙️ Технические детали

| Параметр | Значение |
|----------|----------|
| Язык | C++ |
| Стандарт | C++17 |
| Система сборки | CMake 3.20+ |
| Автообнаружение | Все `.cpp` файлы в `homework/` |
| Копирование данных | Автоматическое из `files/` в `build/` |
| Платформы | <img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white" /> / <img alt="macOS" src="https://img.shields.io/badge/macOS-000000?logo=apple&logoColor=white" /> / <img alt="GNU%2FLinux" src="https://img.shields.io/badge/GNU%2FLinux-000000?logo=linux&logoColor=white" /> |
| Контроль версий | Git + GitHub |
| Защита | CODEOWNERS + PR review |
