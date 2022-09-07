---
# Front matter
title: "Отчёт по лабораторной работе №1"
subtitle: "Установка и конфигурация операционной системы на виртуальную машину"
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
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Целью данной работы является приобретение практических навыков установки операционной системы на виртуальную машину, настройки минимально необходимых для дальнейшей работы сервисов.

# Задание

Лабораторная работа подразумевает установку на виртуальную машину
VirtualBox (https://www.virtualbox.org/) операционной системы Linux
(дистрибутив Rocky (https://rockylinux.org/)).

# Выполнение лабораторной работы

Создадим в VirtualBox новую виртуальную машину ([Рис. @fig:001]).

![Создание виртуальной машины](../img/Image%20001.png){ #fig:001 width=70% }

Укажем объем памяти ([Рис. @fig:002]).

![Выбор объема памяти](../img/Image%20002.png){ #fig:002 width=70% }

Создадим новый виртуальный жесткий диск ([Рис. @fig:003]).

![Создание нового виртуального жесткого диска](../img/Image%20003.png){ #fig:003 width=70% }

Укажем его тип ([Рис. @fig:004]).

![Выбор типа диска](../img/Image%20004.png){ #fig:004 width=70% }

Укажем его размер ([Рис. @fig:005]).

![Размер диска](../img/Image%20005.png){ #fig:005 width=70% }

Добавим дистрибутив как оптический диск, с которого будет устанавливаться ОС ([Рис. @fig:006]).

![Добавление оптического диска](../img/Image%20006.png){ #fig:006 width=70% }

Запустим установку ([Рис. @fig:007]).

![Запуск установки](../img/Image%20007.png){ #fig:007 width=70% }

Выберем язык ([Рис. @fig:008]).

![Выбор языка](../img/Image%20008.png){ #fig:008 width=70% }

Добавим дополнительное ПО ([Рис. @fig:009]).

![Добавление доп. ПО](../img/Image%20009.png){ #fig:009 width=70% }

Отключим KDUMP ([Рис. @fig:010]).

![Отключение KDUMP](../img/Image%20010.png){ #fig:010 width=70% }

Зададим имя сетевого узла ([Рис. @fig:011]).

![Имя узла](../img/Image%20011.png){ #fig:011 width=70% }

Зададим также пароль для root-пользователя и начнем установку ([Рис. @fig:012]).

![Процесс установки](../img/Image%20012.png){ #fig:012 width=70% }

Перезапустим машину после установки и создадим пользователя ([Рис. @fig:013]).

![Создание пользователя](../img/Image%20013.png){ #fig:013 width=70% }

Зададим для него пароль ([Рис. @fig:014]).

![Задание пароля](../img/Image%20014.png){ #fig:014 width=70% }

Скачаем дополнения для гостевой ОС ([Рис. @fig:015]).

![Дополнения гостевой ОС](../img/Image%20015.png){ #fig:015 width=70% }

Используем команду dmesg в терминале для получения следующей информации: 

1. Версия ядра Linux ([Рис. @fig:016]).

![Версия ядра Linux](../img/Image%20017.png){ #fig:016 width=70% }
   
2. Частота процессора ([Рис. @fig:017]).

![Частота процессора](../img/Image%20018.png){ #fig:017 width=70% }
   
3. Модель процессора ([Рис. @fig:018]).

![Модель процессора](../img/Image%20019.png){ #fig:018 width=70% }
   
4. Объем доступной оперативной памяти ([Рис. @fig:019]).

![Объем доступной оперативной памяти](../img/Image%20020.png){ #fig:019 width=70% }
   
5. Тип обнаруженного гипервизора ([Рис. @fig:020]).

![Тип обнаруженного гипервизора](../img/Image%20021.png){ #fig:020 width=70% }
   
6. Тип файловой системы корневого раздела ([Рис. @fig:021]).

![Тип файловой системы корневого раздела](../img/Image%20022.png){ #fig:021 width=70% }

7. Последовательность монтирования файловых систем ([Рис. @fig:022]).

![Последовательность монтирования файловых систем](../img/Image%20023.png){ #fig:022 width=70% }

# Выводы

В результате лабораторной работы мы успешно установили операционную систему Rocky Linux на виртуальную машину.

# Ответы на контрольные вопросы

1. Какую информацию содержит учётная запись пользователя?

Информацию, необходимую для его идентификации, то есть логин и пароль.

2. Укажите команды терминала и приведите примеры:
   
– для получения справки по команде;

man имя_команды (man ls)

– для перемещения по файловой системе;

cd путь_к_каталогу (cd ~/my_dir)

– для просмотра содержимого каталога;

ls путь_к_каталогу (ls ~/my_dir)

– для определения объёма каталога;

du путь_к_каталогу (du ~/my_dir)

– для создания / удаления каталогов / файлов;

touch имя_файла (touch ~/new_file.txt)

mkdir имя_каталога (mkdir ~/new_dir)

– для задания определённых прав на файл / каталог;

chmod права имя_файла (chmod +x ~/my_file.txt)

– для просмотра истории команд.

history

3. Что такое файловая система? Приведите примеры с краткой характери-
стикой.

Файловая система - это способ организации, хранения и именования данных на носителях информации в компьютерах. Файловая система определяет формат содержимого и способ физического хранения информации, которую принято группировать в виде файлов.

FAT32 - файловая система, созданная компанией Microsoft. Использует 32-разрядную адресацию кластеров.

ext2 - файловая система, используемая в ядре Linux. Является нежурналируемой файловой системы.

4. Как посмотреть, какие файловые системы подмонтированы в ОС?

Через команду mount

5. Как удалить зависший процесс?

С помощью команды kill id_процесса

# Библиография

1. Лабораторная работа №1. - 14 с. URL: [https://esystem.rudn.ru/pluginfile.php/1651880/mod_folder/content/0/001-lab_virtualbox.pdf?forcedownload=1](https://esystem.rudn.ru/pluginfile.php/1651880/mod_folder/content/0/001-lab_virtualbox.pdf?forcedownload=1)