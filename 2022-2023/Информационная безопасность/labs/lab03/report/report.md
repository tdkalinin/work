---
# Front matter
title: "Отчёт по лабораторной работе №3"
subtitle: "Дискреционное разграничение прав в Linux. Два пользователя"
author: "Тимур Дмитриевич Калинин"

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography
csl: pandoc/csl/gost-r-7-0-5-2008-numeric.csl

# References settings
linkReferences: true
nameInLink: true

# Pdf output format
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
lot: true # List of tables
fontsize: 12pt
linestretch: 1.5
papersize: a4
documentclass: scrreprt
## I18n
polyglossia-lang:
  name: russian
  options:
	- spelling=modern
	- babelshorthands=true
polyglossia-otherlangs:
  name: english
### Fonts
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase,Scale=0.9
# Biblatex
biblatex: true
biblio-style: "gost-numeric"
biblatexoptions:
  - parentracker=true
  - backend=biber
  - hyperref=auto
  - language=auto
  - autolang=other*
  - citestyle=gost-numeric
## Misc options
indent: true
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=070 # the penalty for breaking a line at a binary operator
  - \relpenalty=050 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=010 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=01000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 02000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Получение практических навыков работы в консоли с атрибутами файлов для групп пользователей.

# Выполнение лабораторной работы

1. В установленной операционной системе создайте учётную запись пользователя guest (используя учётную запись администратора)
   
2. Задайте пароль для пользователя guest (используя учётную запись администратора). Эти пункты можем пропустить, так как пользователя guest мы создавали в предыдущей лабораторной работе.

3. Аналогично создайте второго пользователя guest2 ([Рис. @fig:001]).

![Создание пользователя guest2](../img/Image%20001.png){ #fig:001 width=70% }

4. Добавьте пользователя guest2 в группу guest ([Рис. @fig:002]):

![Добавление пользователя в группу guest](../img/Image%20002.png){ #fig:002 width=70% }

5. Осуществите вход в систему от двух пользователей на двух разных консолях: guest на первой консоли и guest2 на второй консоли. Для обоих пользователей командой pwd определите директорию, в которой вы находитесь. Сравните её с приглашениями командной строки. Уточните имя вашего пользователя, его группу, кто входит в неё и к каким группам принадлежит он сам. Определите командами groups guest и groups guest2, в какие группы входят пользователи guest и guest2. Сравните вывод команды groups с выводом команд id -Gn и id -G ([Рис. @fig:003], [Рис. @fig:004]).

![Вход и проверка групп с guest](../img/Image%20003.png){ #fig:003 width=70% }

![Вход и проверка групп с guest2](../img/Image%20004.png){ #fig:004 width=70% }
   
6. Сравните полученную информацию с содержимым файла `/etc/group`.
Просмотрите файл командой cat `/etc/group`

![Проверка файла /etc/group](../img/Image%20005.png){ #fig:005 width=70% }

7. От имени пользователя guest2 выполните регистрацию пользователя
guest2 в группе guest командой `newgrp guest`

![Регистрация пользователя guest2](../img/Image%20006.png){ #fig:006 width=70% }

8.  От имени пользователя guest измените права директории `/home/guest`, разрешив все действия для пользователей группы:

[Изменение прав доступа](../img/Image%20007.png){ #fig:007 width=70% }

9.  От имени пользователя guest снимите: с директории `/home/guest/dir1`
все атрибуты командой `chmod 000 dirl` и проверьте правильность снятия атрибутов.

[Изменение прав доступа](../img/Image%20008.png){ #fig:008 width=70% }

[Проверка доступа](../img/Image%20009.png){ #fig:009 width=70% }

Меняя атрибуты у директории dir1 и файла file1 от имени пользова-
теля guest и делая проверку от пользователя guest2, заполните таблицу,
определив опытным путём, какие операции разрешены, а какие нет. Ес-
ли операция разрешена, занесите в таблицу знак «+», если не разрешена,
знак «-».

10.   Заполните таблицу «Установленные права и разрешённые действия», выполняя действия от имени владельца директории (файлов), определив опытным путём, какие операции разрешены, а какие нет.Если операция разрешена, занесите в таблицу знак «+», если не разрешена, знак «-».

| Права директории | Права файла | Создание файла | Удаление файла | Запись в файл | Чтение файла | Смена директории | Просмотр файлов в директории | Переименование файла | Смена атрибутов файла |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 000 | 000 | - | - | - | - | - | - | - | - |
| 010 | 000 | - | - | - | - | + | - | - | - |
| 020 | 000 | - | - | - | - | - | - | - | - |
| 030 | 000 | + | + | - | - | + | - | + | - |
| 040 | 000 | - | - | - | - | - | + | - | - |
| 050 | 000 | - | - | - | - | + | + | - | - |
| 060 | 000 | - | - | - | - | - | + | - | - |
| 070 | 000 | + | + | - | - | + | + | + | - |
| 000 | 010 | - | - | - | - | - | - | - | - |
| 010 | 010 | - | - | - | - | + | - | - | - |
| 020 | 010 | - | - | - | - | - | - | - | - |
| 030 | 010 | + | + | - | - | + | - | + | - |
| 040 | 010 | - | - | - | - | - | + | - | - |
| 050 | 010 | - | - | - | - | + | + | - | - |
| 060 | 010 | - | - | - | - | - | + | - | - |
| 070 | 010 | + | + | - | - | + | + | + | - |
| 000 | 020 | - | - | - | - | - | - | - | - |
| 010 | 020 | - | - | + | - | + | - | - | - |
| 020 | 020 | - | - | - | - | - | - | - | - |
| 030 | 020 | + | + | + | - | + | - | + | - |
| 040 | 020 | - | - | - | - | - | + | - | - |
| 050 | 020 | - | - | + | - | + | + | - | - |
| 060 | 020 | - | - | - | - | - | + | - | - |
| 070 | 020 | + | + | + | - | + | + | + | - |
| 000 | 030 | - | - | - | - | - | - | - | - |
| 010 | 030 | - | - | + | - | + | - | - | - |
| 020 | 030 | - | - | - | - | - | - | - | - |
| 030 | 030 | + | + | + | - | + | - | + | - |
| 040 | 030 | - | - | - | - | - | + | - | - |
| 050 | 030 | - | - | + | - | + | + | - | - |
| 060 | 030 | - | - | - | - | - | + | - | - |
| 070 | 030 | + | + | + | - | + | + | + | - |
| 000 | 040 | - | - | - | - | - | - | - | - |
| 010 | 040 | - | - | - | + | + | - | - | - |
| 020 | 040 | - | - | - | - | - | - | - | - |
| 030 | 040 | + | + | - | + | + | - | + | - |
| 040 | 040 | - | - | - | - | - | + | - | - |
| 050 | 040 | - | - | - | + | + | + | - | - |
| 060 | 040 | - | - | - | - | - | + | - | - |
| 070 | 040 | + | + | - | + | + | + | + | - |
| 000 | 050 | - | - | - | - | - | - | - | - |
| 010 | 050 | - | - | - | + | + | - | - | - |
| 020 | 050 | - | - | - | - | - | - | - | - |
| 030 | 050 | + | + | - | + | + | - | + | - |
| 040 | 050 | - | - | - | - | - | + | - | - |
| 050 | 050 | - | - | - | + | + | + | - | - |
| 060 | 050 | - | - | - | - | - | + | - | - |
| 070 | 050 | + | + | - | + | + | + | + | - |
| 010 | 060 | - | - | - | - | - | - | - | - |
| 020 | 060 | - | - | + | + | + | - | - | - |
| 030 | 060 | - | - | - | - | - | - | - | - |
| 030 | 060 | + | + | + | + | + | - | + | - |
| 040 | 060 | - | - | - | - | - | + | - | - |
| 050 | 060 | - | - | + | + | + | + | - | - |
| 060 | 060 | - | - | - | - | - | + | - | - |
| 070 | 060 | + | + | + | + | + | + | + | - |
| 010 | 070 | - | - | - | - | - | - | - | - |
| 020 | 070 | - | - | + | + | + | - | - | - |
| 030 | 070 | - | - | - | - | - | - | - | - |
| 030 | 070 | + | + | + | + | + | - | + | - |
| 040 | 070 | - | - | - | - | - | + | - | - |
| 050 | 070 | - | - | + | + | + | + | - | - |
| 060 | 070 | - | - | - | - | - | + | - | - |
| 070 | 070 | + | + | + | + | + | + | + | - |

Сравните таблицу из лабораторной работы и получившуюся таблицу. Как видим, эти таблицы идентичны, за исключением того, что мы не можем изменить атрибуты файла от имени другого пользователя

11.  На основании заполненной таблицы определите те или иные минимально необходимые права для выполнения пользователем guest2 операций внутри директории dir1 и заполните таблицу

| Операция | Минимальные права на директорию | Минимальные права на файл |
| --- | --- | --- |
| Создание файла | 030 | 000 |
| Удаление файла | 030 | 000 |
| Чтение файла | 010 | 040 |
| Запись в файл | 010 | 020 |
| Переименование файла | 030 | 000 |
| Создание поддиректории | 030 | 000 |
| Удаление поддиректории | 030 | 000 |

# Выводы

Я получил практические навыки работы в консоли с атрибутами файлов для групп пользователей.

# Библиография

1. Лабораторная работа №3. - 4 с. URL: [https://esystem.rudn.ru/mod/resource/view.php?id=892078](https://esystem.rudn.ru/mod/resource/view.php?id=892078)