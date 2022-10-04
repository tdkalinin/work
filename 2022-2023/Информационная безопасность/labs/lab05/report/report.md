---
# Front matter
title: "Отчёт по лабораторной работе №5"
subtitle: "Дискреционное разграничение прав в Linux. Исследование влияния дополнительных атрибутов"
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

Изучение механизмов изменения идентификаторов, применения SetUID- и Sticky-битов. Получение практических навыков работы в консоли с дополнительными атрибутами. Рассмотрение работы механизма смены идентификатора процессов пользователей, а также влияние бита Sticky на запись и удаление файлов.

# Выполнение лабораторной работы

## Создание программы

1. Войдите в систему от имени пользователя guest 

2. Создайте программу simpleid.c ([Рис. @fig:001]).

![Код simpleid.c](../img/Image%20006.png){ #fig:001 width=70% }

3. Скомплилируйте программу и убедитесь, что файл программы создан ([Рис. @fig:002])

4. Выполните программу simpleid ([Рис. @fig:002]).

![Компиляция и выполнение](../img/Image%20007.png){ #fig:002 width=70% }
 
5. Выполните системную программу id и сравните полученный вами результат с данными предыдущего пункта задания ([Рис. @fig:003]).

![Выполнение id](../img/Image%20008.png){ #fig:003 width=70% }

6. Усложните программу, добавив вывод действительных идентификаторов ([Рис. @fig:004]).

![Код simpleid2.c](../img/Image%20009.png){ #fig:004 width=70% }

7. Скомпилируйте и запустите simpleid2.c ([Рис. @fig:005]).

![Компиляция и выполнение simpleid2.c](../img/Image%20010.png){ #fig:005 width=70% }

8. От имени суперпользователя выполните команды ([Рис. @fig:006]).

![Установка прав](../img/Image%20011.png){ #fig:006 width=70% }

9. Используйте sudo или повысьте временно свои права с помощью su.

10. Выполните проверку правильности установки новых атрибутов и смены владельца файла simpleid2 ([Рис. @fig:007]).

![Проверка](../img/Image%20012.png){ #fig:007 width=70% }

11. Запустите simpleid2 ([Рис. @fig:008]).

![Запуск simpleid2](../img/Image%20013.png){ #fig:008 width=70% }

12. Проделайте тоже самое относительно SetGID-бита ([Рис. @fig:009]).

![Установка setGID-бита](../img/Image%20014.png){ #fig:009 width=70% }

13. Создайте программу readfile.c ([Рис. @fig:010]).

![Код readfile.c](../img/Image%20015.png){ #fig:010 width=70% }

14. Откомпилируйте её ([Рис. @fig:011]).

![Комплиляция readfile.c](../img/Image%20016.png){ #fig:011 width=70% }

15. Смените владельца у файла readfile.c (или любого другого текстового файла в системе) и измените права так, чтобы только суперпользователь (root) мог прочитать его, a guest не мог ([Рис. @fig:012]).

![Изменяем владельца](../img/Image%20017.png){ #fig:012 width=70% }
    
16.  Проверьте, что пользователь guest не может прочитать файл readfile.c ([Рис. @fig:013]).

![Проверка чтения](../img/Image%20018.png){ #fig:013 width=70% }
    
17. Смените у программы readfile владельца и установите SetU’D-бит ([Рис. @fig:014], [Рис. @fig:015]).

![Смена владельца](../img/Image%20019.png){ #fig:014 width=70% }

![Установка setUID-бита](../img/Image%20020.png){ #fig:015 width=70% }
    
18. Проверьте, может ли программа readfile прочитать файл readfile.c? ([Рис. @fig:016]). Да, может

![Проверка чтения readfile.c](../img/Image%20021.png){ #fig:016 width=70% }
    
19. Проверьте, может ли программа readfile прочитать файл /etc/shadow?
Отразите полученный результат и ваши объяснения в отчёте ([Рис. @fig:017]). Да, может, так как мы запускаем программу на исполнение от имени владельца, то есть пользователя root.

![Проверка чтения /etc/shadow](../img/Image%20022.png){ #fig:017 width=70% }

## Исследование Sticky-бита

1. Выясните, установлен ли атрибут Sticky на директории /tmp, для чего выполните команду ([Рис. @fig:018]). Да установлен (буква t)

![Атрибуты](../img/Image%20023.png){ #fig:018 width=70% }

2. От имени пользователя guest создайте файл file01.txt в директории /tmp со словом test ([Рис. @fig:019]).

![Создание нового файла](../img/Image%20024.png){ #fig:019 width=70% }

3. Просмотрите атрибуты у только что созданного файла и разрешите чтение и запись для категории пользователей «все остальные» ([Рис. @fig:020], [Рис. @fig:021]).

![Просмотр атрибутов](../img/Image%20025.png){ #fig:020 width=70% }

![Установка прав доступа](../img/Image%20040.png){ #fig:021 width=70% }

4. От пользователя guest2 (не являющегося владельцем) попробуйте прочитать файл /tmp/file01.txt ([Рис. @fig:022]).

![Чтение файла](../img/Image%20026.png){ #fig:022 width=70% }

5. От пользователя guest2 попробуйте дозаписать в файл /tmp/file01.txt слово test2 ([Рис. @fig:023]).

![Дозапись в файл](../img/Image%20027.png){ #fig:023 width=70% }

6. От пользователя guest2 попробуйте записать в файл /tmp/file01.txt слово test3, стерев при этом всю имеющуюся в файле информацию командой ([Рис. @fig:024]).

![Перезапись файла](../img/Image%20028.png){ #fig:024 width=70% }

7. Проверьте содержимое файла командой ([Рис. @fig:025]).

![Проверка содержимого](../img/Image%20029.png){ #fig:025 width=70% }

8.  От пользователя guest2 попробуйте удалить файл /tmp/file01.txt командой ([Рис. @fig:026]).

![Попытка удаления](../img/Image%20030.png){ #fig:026 width=70% }

9.  Повысьте свои права до суперпользователя следующей командой и выполните после этого команду, снимающую атрибут t (Sticky-бит) с директории /tmp ([Рис. @fig:027]).

![Снятие атрибута t](../img/Image%20031.png){ #fig:027 width=70% }

10.  Покиньте режим суперпользователя

11.  От пользователя guest2 проверьте, что атрибута t у директории /tmp нет ([Рис. @fig:028]).

![Проверка атрибутов](../img/Image%20032.png){ #fig:028 width=70% }

12.  Повторите предыдущие шаги. Какие наблюдаются изменения? ([Рис. @fig:029]). В этот раз удалось удалить файл.

![Повтор действий](../img/Image%20033.png){ #fig:029 width=70% }
    
13.  Удалось ли вам удалить файл от имени пользователя, не являющегося
его владельцем? Да, теперь удалось.
   

# Выводы

Мы изучили механизмы изменения идентификаторов, применения SetUID- и Sticky-битов. Получили практические навыки работы в консоли с дополнительными атрибутами. Рассмотрели работу механизма смены идентификатора процессов пользователей, а также влияние бита Sticky на запись и удаление файлов.

# Библиография

1. Лабораторная работа №5. - 2 с. URL: [https://esystem.rudn.ru/pluginfile.php/1651889/mod_resource/content/2/005-lab_discret_sticky.pdf](https://esystem.rudn.ru/pluginfile.php/1651889/mod_resource/content/2/005-lab_discret_sticky.pdf)