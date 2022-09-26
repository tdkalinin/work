---
# Front matter
title: "Отчёт по лабораторной работе №4"
subtitle: "Дискреционное разграничение прав в Linux. Расширенные атрибуты"
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

Получение практических навыков работы в консоли с расширенными атрибутами файлов.

# Выполнение лабораторной работы

1. От имени пользователя guest определите расширенные атрибуты файла `/home/guest/dir1/file1` командой `lsattr /home/guest/dir1/file1` ([Рис. @fig:001])

![Расширенные атрибуты файла](../img/Image%20001.png){ #fig:001 width=70% }

2. Установите командой `chmod 600 file1` на файл file1 права, разрешающие чтение и запись для владельца файла ([Рис. @fig:002]).

![Установка прав](../img/Image%20002.png){ #fig:002 width=70% }

3. Попробуйте установить на файл /home/guest/dir1/file1 расширенный атрибут a от имени пользователя guest ([Рис. @fig:003]):

![Установка расширенного атрибута](../img/Image%20003.png){ #fig:003 width=70% }

В ответ получаем отказ от выполнения операции.

4. Зайдите на третью консоль с правами администратора. Попробуйте установить расширенный атрибут a на файл `/home/guest/dir1/file1` от имени суперпользователя ([Рис. @fig:004])

![Установка расширенного атрибута от имени суперпользователя](../img/Image%20004.png){ #fig:004 width=70% }

5. От пользователя guest проверьте правильность установления атрибута ([Рис. @fig:005]):

![Проверка](../img/Image%20005.png){ #fig:005 width=70% }

6. Выполните дозапись в файл file1 слова «test» командой `echo "test" /home/guest/dir1/file1`. После этого выполните чтение файла file1 командой `cat /home/guest/dir1/file1`. Убедитесь, что слово test было успешно записано в `file1` ([Рис. @fig:006]).

![Дозапись и чтение файла](../img/Image%20006.png){ #fig:006 width=70% }

7. Попробуйте удалить файл file1 либо стереть имеющуюся в нём информацию командой `echo "abcd" > /home/guest/dirl/file1` ([Рис. @fig:007]). Попробуйте переименовать файл ([Рис. @fig:008]).

![Перезапись файла](../img/Image%20007.png){ #fig:007 width=70% }

![Переименование файла](../img/Image%20008.png){ #fig:008 width=70% }

8. Попробуйте с помощью команды `chmod 000 file1` установить на файл `file1` права, например, запрещающие чтение и запись для владельца файла ([Рис. @fig:009]). Удалось ли вам успешно выполнить указанные команды?

![Установка прав](../img/Image%20009.png){ #fig:009 width=70% }
   
9.  Снимите расширенный атрибут a с файла `/home/guest/dirl/file1` от имени суперпользователя командой 
`chattr -a /home/guest/dir1/file1` ([Рис. @fig:010]).

![Удаление атрибута](../img/Image%20010.png){ #fig:010 width=70% }

Повторите операции, которые вам ранее не удавалось выполнить. Ваши
наблюдения занесите в отчёт ([Рис. @fig:011]).

![Повтор операций](../img/Image%20011.png){ #fig:011 width=70% }

Теперь удается выполнить те операции, которые раннее не удавалось выполнить.

10.  Повторите ваши действия по шагам, заменив атрибут «a» атрибутом «i» ([Рис. @fig:012], [Рис. @fig:013]).
Удалось ли вам дозаписать информацию в файл? Ваши наблюдения занесите в отчёт.

![Установка атрибута i](../img/Image%20012.png){ #fig:012 width=70% }

![Повтор операций c атрибутом i](../img/Image%20013.png){ #fig:013 width=70% }

# Выводы

В результате выполнения работы мы повысили свои навыки использования интерфейса командой строки (CLI), познакомились на примерах с тем, как используются основные и расширенные атрибуты при разграничении доступа. Имели возможность связать теорию дискреционного разделения доступа (дискреционная политика безопасности) с её реализацией на практике в ОС Linux. Составили наглядные таблицы, поясняющие какие операции возможны при тех или иных установленных правах. Опробовали действие на практике расширенных атрибутов «а» и «i».

# Библиография

1. Лабораторная работа №4. - 2 с. URL: [https://esystem.rudn.ru/pluginfile.php/1651887/mod_resource/content/3/004-lab_discret_extattr.pdf](https://esystem.rudn.ru/pluginfile.php/1651887/mod_resource/content/3/004-lab_discret_extattr.pdf)