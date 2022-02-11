---
# Front matter
title: "Отчёт по лабораторной работе №1"
subtitle: "Работа с git"
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

Познакомиться с системой контроля версий git. Научиться создавать отчеты при помощи языка Markdown.

# Задание

Требуется познакомиться с системой контроля версий git. Опробовать механизмы создания коммитов, тегов. Изучить ветки, слияния, перебазирования. Научиться работать с удаленными репозиториями.

# Теоретическое введение


# Выполнение лабораторной работы

## Создание проекта

Начните работу в пустом рабочем каталоге с создания пустого каталога с именем hello, затем войдите в него и создайте там файл с именем hello.html ([Рис. @fig:001]).

![Создание каталога](img/Image%201317.png){ #fig:001 width=70% }

### Создание репозитория

Чтобы создать git репозиторий из этого каталога, выполните команду git init ([Рис. @fig:002]).

![Инициализация репозитория](img/Image%201318.png){ #fig:002 width=70% }

### Добавление файла в репозиторий

Добавим файл в репозиторий ([Рис. @fig:003]).

![Добавление файла в репозиторий](img/Image%201319.png){ #fig:003 width=70% }

### Проверка состояния репозитория

Проверим текущее состояние репозитория ([Рис. @fig:004]).

![Проверка состояния репозитория](img/Image%201320.png){ #fig:004 width=70% }

Команда проверки состояния сообщает, что коммитить нечего. 

## Внесение изменений

### Измените страницу «Hello, World»

Добавим кое-какие HTML-теги к нашему приветствию ([Рис. @fig:005]).

![Добавление тегов](img/Image%201321.png){ #fig:005 width=70% }

Проверьте состояние рабочего каталога ([Рис. @fig:006]).

![Проверка состояния](img/Image%201322.png){ #fig:006 width=70% }

## Индексация изменений

Теперь выполните команду git, чтобы проиндексировать изменения. Проверьте
состояние ([Рис. @fig:007]).

![Индексация](img/Image%201323.png){ #fig:007 width=70% }

### Коммит изменений

Сделайте коммит и проверьте состояние ([Рис. @fig:008]).

![Коммит](img/Image%201324.png){ #fig:008 width=70% }

### Добавьте стандартные теги страницы

Измените страницу «Hello, World», чтобы она содержала стандартные теги ([Рис. @fig:009]).

![Модификация файла](img/Image%201326.png){ #fig:009 width=70% }

Теперь добавьте это изменение в индекс git ([Рис. @fig:010]).

![Индексация](img/Image%201327.png){ #fig:010 width=70% }

Теперь добавьте заголовки HTML (секцию head) к странице «Hello, World» ([Рис. @fig:011]).

![Изменение файла](img/Image%201328.png){ #fig:011 width=70% }

Проверьте текущий статус ([Рис. @fig:012]):

![Статус](img/Image%201329.png){ #fig:012 width=70% }

Произведите коммит проиндексированного изменения (значение по умолчанию), а затем еще раз проверьте состояние ([Рис. @fig:013]).

![Коммит](img/Image%201330.png){ #fig:013 width=70% }

Теперь добавьте второе изменение в индекс, а затем проверьте состояние с
помощью команды git status ([Рис. @fig:014]).

![Индексация второго изменения](img/Image%201331.png){ #fig:014 width=70% }

Сделайте коммит второго изменения ([Рис. @fig:015]).

![Коммит второго изменения](img/Image%201332.png){ #fig:015 width=70% }

### История

Получим список произведенных изменений ([Рис. @fig:016]):

![История изменений](img/Image%201333.png){ #fig:016 width=70% }

Однострочный формат истории ([Рис. @fig:017]):

![Однострочный формат истории](img/Image%201334.png){ #fig:017 width=70% }

### Получение старых версий

Получите хэши предыдущих версий. Перейдем к первому коммиту по его хэшу ([Рис. @fig:018] , [Рис. @fig:019]).

![Хэши](img/Image%201335.png){ #fig:018 width=70% }

![Просмотр hello.html](img/Image%201336.png){ #fig:019 width=70% }

Вернитесь к последней версии в ветке master ([Рис. @fig:020])

![Ветка master](img/Image%201337.png){ #fig:020 width=70% }


### Создание тегов версий

Создайте тег первой версии([Рис. @fig:021])

![Создание тегов](img/Image%201338.png){ #fig:021 width=70% }

Вернемся к предыдущей тегу версии([Рис. @fig:022], [Рис. @fig:023])

![Возвращение к тегу предыдущей версии](img/Image%201339.png){ #fig:022 width=70% }

![Просмотр файла hello.html](img/Image%201340.png){ #fig:023 width=70% }

Дадим ей тег([Рис. @fig:024])

![Добавление тега](img/Image%201341.png){ #fig:024 width=70% }


### Переключение по имени тега

Теперь попробуйте попереключаться между двумя отмеченными версиями ([Рис. @fig:025]).

![Переключение между тегами](img/Image%201342.png){ #fig:025 width=70% }

### Просмотр тегов с помощью команды tag

Посмотрим теги ([Рис. @fig:026])

![Просмотр тегов](img/Image%201343.png){#fig:026 width=70% }

## Отмена локальных изменений (до индексации)

### Переключитесь на ветку master

Переключимся на ветку master([Рис. @fig:027])

![Переключение на master](img/Image%201344.png){ #fig:027 width=70% }

### Измените hello.html

Изменим hello.html([Рис. @fig:029])

![Изменение файла hello.html](img/Image%201425.png){ #fig:029 width=70% }

### Отмена изменений в рабочем каталоге

Используйте команду git checkout для переключения версии файла hello.html в репозитории ([Рис. @fig:030]).

![Использование git checkout](img/Image%201346.png){ #fig:030 width=70% }

## Отмена проиндексированных изменений (перед коммитом)

### Измените файл и проиндексируйте изменения

Внесите изменение в файл hello.html в виде нежелательного комментария ([Рис. @fig:031])

![Нежелательный комментарий](img/Image%201427.png){ #fig:031 width=70% }


Проиндексируйте это изменение. Проверьте состояние нежелательного изменения ([Рис. @fig:032]).

![Индексация](img/Image%201426.png){ #fig:032 width=70% }

### Выполните сброс буферной зоны

Команда git reset сбрасывает буферную зону к HEAD. Это очищает буферную
зону от изменений, которые мы только что проиндексировали ([Рис. @fig:033]).

![Сброс](img/Image%201345.png){ #fig:033 width=70% }

### Переключитесь на версию коммита

Переключимся ([Рис. @fig:034])

![Переключение](img/Image%201347.png){ #fig:034 width=70% }

## Отмена коммитов

### Измените файл и сделайте коммит

Измените файл hello.html на следующий ([Рис. @fig:035]).

![Изменение файла](img/Image%201348.png){ #fig:035 width=70% }

Выполните ([Рис. @fig:036]):

![Коммит](img/Image%201349.png){ #fig:036 width=70% }

### Сделайте коммит с новыми изменениями, отменяющими предыдущие

Чтобы отменить коммит, нам необходимо сделать коммит, который удаляет изменения, сохраненные нежелательным коммитом ([Рис. @fig:037]).

![Отменяющий коммит](img/Image%201350.png){ #fig:037 width=70% }

### Проверьте лог

Проверка лога показывает нежелательные и отмененные коммиты в наш репозиторий ([Рис. @fig:038]).

![Проверка лога](img/Image%201428.png){ #fig:038 width=70% }

## Удаление коммиттов из ветки

### Для начала отметьте эту ветку

Отметим последний коммит тегом ([Рис. @fig:039])

![Тегирование последнего коммита](img/Image%201351.png){ #fig:039 width=70% }

### Сброс коммитов к предшествующим коммиту Oops

Сбросим ветку до точки v1 ([Рис. @fig:040], [Рис. @fig:041]). Мы все еще видим ошибочные коммиты

![Сброс ветки](img/Image%201352.png){ #fig:040 width=70% }

![Проверка лога](img/Image%201353.png){ #fig:041 width=70% }

## Удаление тега oops

Удалим тег oops([Рис. @fig:042], [Рис. @fig:043])

![Удаление тега](img/Image%201354.png){ #fig:042 width=70% }

![Просмотр лога](img/Image%201355.png){ #fig:043 width=70% }

## Внесение изменений в коммиты

Добавим на страницу комментарий ([Рис. @fig:044])

![Добавление комментария](img/Image%201356.png){ #fig:044 width=70% }

Сделаем коммит ([Рис. @fig:045])

![Коммит](img/Image%201357.png){ #fig:045 width=70% }

Добавим email на страницу ([Рис. @fig:046])

![Добавление email](img/Image%201358.png){ #fig:046 width=70% }

Изменим предыдущий коммит ([Рис. @fig:047])

![Изменение предыдущего коммита](img/Image%201359.png){ #fig:047 width=70% }

Посмотрим историю([Рис. @fig:048])

![Просмотр истории](img/Image%201360.png){ #fig:048 width=70% }

## Перемещение файлов

Перемесим hello.html в каталог lib ([Рис. @fig:049])

![Перемещение файлов](img/Image%201361.png){ #fig:049 width=70% }

Сделаем новый коммит ([Рис. @fig:050])

![Создание нового коммита](img/Image%201362.png){ #fig:050 width=70% }

## Подробнее о структуре

Создадим файл index.html ([Рис. @fig:051], [Рис. @fig:050])

![Создание файла index.html](img/Image%201363.png){ #fig:051 width=70% }

![index.html](img/Image%201364.png){ #fig:052 width=70% }

Добавим файл и сделаем коммит ([Рис. @fig:053])

![index.html](img/Image%201365.png){ #fig:053 width=70% }

## Git внутри: Каталог .git

Посмотрим каталог .git ([Рис. @fig:054])

![index.html](img/Image%201366.png){ #fig:054 width=70% }

Откроем .git/objects ([Рис. @fig:055])

![.git/objects](img/Image%201367.png){ #fig:055 width=70% }

Откроем один из внутренних каталогов ([Рис. @fig:056])

![Внутренний каталог](img/Image%201368.png){ #fig:056 width=70% }

Откроем .git/config ([Рис. @fig:057])

![.git/config](img/Image%201369.png){ #fig:057 width=70% }

Посмотрим каталоги с тегами, ветками и т.д. ([Рис. @fig:058])

![Каталоги с тегами, ветками и т.д.](img/Image%201370.png){ #fig:058 width=70% }

Посмотрим каталог с ссылкой на текущую ветку ([Рис. @fig:059])

![Каталог с ссылкой на текущую ветку](img/Image%201371.png){ #fig:059 width=70% }

## Работа непосредственно с объектами git

Найдем последний коммит ([Рис. @fig:060]):

![Последний коммит](img/Image%201373.png){ #fig:060 width=70% }

Выполните ([Рис. @fig:061]): 

![cat-file](img/Image%201374.png){ #fig:061 width=70% }

Выполните ([Рис. @fig:062]):

![cat-file](img/Image%201376.png){ #fig:062 width=70% }

Смотрите, удастся ли вам
найти оригинальный файл hello.html с самого первого коммита вручную по ссылкам SHA1 хэша в последнем коммите ([Рис. @fig:063]).

![Оригинальный hello.html](img/Image%201375.png){ #fig:063 width=70% }

## Создание ветки

Создадим ветку и css файл ([Рис. @fig:064], [Рис. @fig:065]).

![Ветка](img/Image%201377.png){ #fig:064 width=70% }

![css файл](img/Image%201378.png){ #fig:065 width=70% }

Выполним ([Рис. @fig:066]):

![Коммит](img/Image%201379.png){ #fig:066 width=70% }

Обновите файл hello.html ([Рис. @fig:067])

![Обновление hello.html](img/Image%201380.png){ #fig:067 width=70% }

Выполните ([Рис. @fig:068]):

![Коммит](img/Image%201381.png){ #fig:068 width=70% }

Обновите файл index.html ([Рис. @fig:069])

![Обновление index.html](img/Image%201429.png){ #fig:069 width=70% }

Выполните ([Рис. @fig:070]):

![Коммит](img/Image%201382.png){ #fig:070 width=70% }

Используйте команду git checkout для переключения между ветками ([Рис. @fig:071]):

![Переключение](img/Image%201383.png){ #fig:071 width=70% }

Вернемся к ветке style. Выполните ([Рис. @fig:072]):

![Ветка style](img/Image%201384.png){ #fig:072 width=70% }

## Изменения в ветке master

Создайте файл README в ветке master. Выполните ([Рис. @fig:073]):

![README](img/Image%201385.png){ #fig:073 width=70% }

Сделайте коммит изменений README.md в ветку master ([Рис. @fig:074]).

![Коммит](img/Image%201386.png){ #fig:074 width=70% }

Просмотрим ветки ([Рис. @fig:075])

![Ветки](img/Image%201387.png){ #fig:075 width=70% }

## Слияние

Сольем ветки master и style ([Рис. @fig:076], [Рис. @fig:077]).

![Слияние](img/Image%201388.png){ #fig:076 width=70% }

![Графический лог](img/Image%201389.png){ #fig:077 width=70% }

## Создание конфликта

Вернемся в ветку master и внесем следующие изменения ([Рис. @fig:078]):

![Внесение конфликта](img/Image%201390.png){ #fig:078 width=70% }

Закоммитим ([Рис. @fig:079])

![Коммит](img/Image%201391.png){ #fig:079 width=70% }

Просмотрим ветки ([Рис. @fig:080])

![Просмотр веток](img/Image%201392.png){ #fig:080 width=70% }

Теперь вернемся к ветке style и попытаемся объединить ее с новой веткой
master ([Рис. @fig:081], [Рис. @fig:082]).

![Ветка style](img/Image%201394.png){ #fig:081 width=70% }

![Конфликт](img/Image%201393.png){ #fig:082 width=70% }

Необходимо разрешить конфликт ([Рис. @fig:083])

![Конфликт](img/Image%201395.png){ #fig:083 width=70% }

Сделаем коммит ([Рис. @fig:084], [Рис. @fig:085])

![Коммит](img/Image%201396.png){ #fig:084 width=70% }

![Лог](img/Image%201397.png){ #fig:085 width=70% }

Теперь попробуем сделатть перебазирование. Для начала сбросим ветку style ([Рис. @fig:086]).

![Сброс ветки style](img/Image%201398.png){ #fig:086 width=70% }

Теперь сбросим ветку master ([Рис. @fig:087])

![Сброс ветки master](img/Image%201399.png){ #fig:087 width=70% }

Выполним перебазирование ([Рис. @fig:088]).

![Перебазирование](img/Image%201402.png){ #fig:088 width=70% }

Теперь сольем style в master ([Рис. @fig:089])

![Слияние](img/Image%201403.png){ #fig:089 width=70% }

## Клонирование репозиториев

Перейдем в рабочий каталог. Создадим клон репозитория ([Рис. @fig:090]).

![Клонирование](img/Image%201405.png){ #fig:090 width=70% }

Посмотрим коммиты ([Рис. @fig:091]).

![Просмотр коммитов](img/Image%201406.png){ #fig:091 width=70% }

Мы видим, что клонированный репозиторий знает об имени по умолчанию удаленного репозитория ([Рис. @fig:092]).

![Удаленный репозиторий](img/Image%201409.png){ #fig:092 width=70% }

Посмотрим на список веток ([Рис. @fig:093]).

![Список веток](img/Image%201410.png){ #fig:093 width=70% }

Изменим оригинальный репозиторий ([Рис. @fig:094]).

![Изменение оригинального репозитория](img/Image%201411.png){ #fig:094 width=70% }

Сделаем коммит ([Рис. @fig:095]).

![Коммит](img/Image%201412.png){ #fig:095 width=70% }

Извлечем изменения из удаленного репозитория ([Рис. @fig:096]).

![Извлечение изменений](img/Image%201429.png){ #fig:096 width=70% }

Теперь сольем извлеченные изменения ([Рис. @fig:097])

![Слияние изменений](img/Image%201416.png){ #fig:097 width=70% }

Добавим ветку наблюдения ([Рис. @fig:098])

![Ветка наблюдения](img/Image%201417.png){ #fig:098 width=70% }

Создадим чистый репозиторий ([Рис. @fig:099])

![Чистый репозиторий](img/Image%201419.png){ #fig:099 width=70% }

Добавим удаленный репозиторий ([Рис. @fig:100])

![Добавление удаленного репозитория](img/Image%201420.png){ #fig:100 width=70% }

Изменим файл readme([Рис. @fig:101]). Закоммитим и отправим изменения в общий репозиторий ([Рис. @fig:102])

![Изменение README](img/Image%201421.png){ #fig:101 width=70% }

![Отправка изменений](img/Image%201422.png){ #fig:102 width=70% }

Вернемся в клонированный репозиторий и извлечем изменения ([Рис. @fig:103]).

![Извлечение новых изменений](img/Image%201423.png){ #fig:103 width=70% }


# Выводы

В результате лабораторной работы мы познакомились с системой контроля версий git
