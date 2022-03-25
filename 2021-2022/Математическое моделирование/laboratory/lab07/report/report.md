---
# Front matter
title: "Отчёт по лабораторной работе №7"
subtitle: "Модель эффективности рекламы"
author: "Тимур Дмитриевич Калинин"

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography

# References settings
linkReferences: true
nameInLink: true

# Pdf output format
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
lot: false # List of tables
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

Построить модель рекламы в OpenModelica.

# Задание

Вариант 31

Постройте график распространения рекламы, математическая модель которой описывается
следующим уравнением:

1. $\frac{dn}{dt}=(0.14+0.00004n(t))(N-n(t))$
   
2. $\frac{dn}{dt}=(0.000015+0.29n(t))(N-n(t))$
   
3. $\frac{dn}{dt}=(0.5sin(0.5t)+0.07cos(0.7t)n(t))(N-n(t))$

При этом объем аудитории $N=805$, в начальный момент о товаре знает 3 человек. Для случая 2 определите в какой момент времени скорость распространения рекламы будет
иметь максимальное значение.

# Теоретическое введение

Организуется рекламная кампания нового товара или услуги. Необходимо, чтобы прибыль будущих продаж с избытком покрывала издержки на рекламу. Вначале расходы могут превышать прибыль, поскольку лишь малая часть
потенциальных покупателей будет информирована о новинке. Затем, при увеличении числа продаж, возрастает и прибыль, и, наконец, наступит момент, когда рынок насытиться, и рекламировать товар станет бесполезным.

Предположим, что торговыми учреждениями реализуется некоторая продукция, о которой в момент времени t из числа потенциальных покупателей $N$ знает лишь $n$ покупателей. Для ускорения сбыта продукции запускается реклама по радио, телевидению и других средств массовой информации. После запуска рекламной кампании информация о продукции начнет распространяться среди потенциальных покупателей путем общения друг с другом. Таким образом, после запуска рекламных объявлений скорость изменения числа знающих о продукции людей пропорциональна как числу знающих о товаре покупателей, так и числу покупателей о нем не знающих.

Модель рекламной кампании описывается следующими величинами.
Считаем, что - $\frac{dn}{dt}$ скорость изменения со временем числа потребителей, узнавших о товаре и готовых его купить, $t$ - время, прошедшее с начала рекламной кампании, $n(t)$ - число уже информированных клиентов. Эта величина пропорциональна числу покупателей, еще не знающих о нем, это описывается следующим образом: ${\alpha}_1(t)(N-n(t))$, где $N$ - общее число потенциальных платежеспособных покупателей, ${\alpha}_1(t)$ - характеризует интенсивность рекламной кампании (зависит от затрат на рекламу в данный момент времени). Помимо этого, узнавшие о товаре потребители также распространяют полученную информацию среди потенциальных покупателей, не знающих о нем (в этом случае работает т.н. сарафанное радио). Этот вклад в рекламу описывается величиной ${\alpha}_2(t)n(t)(N-n(t))$, эта величина увеличивается с увеличением потребителей, узнавших о товаре. Математическая модель распространения рекламы описывается уравнением:

$$
\frac{dn}{dt}=({\alpha}_1(t)+{\alpha}_2(t)n(t))(N-n(t))
$$

При ${\alpha}_1(t){\ge}{\alpha}_2(t)$ получается модель типа модели Мальтуса.

В обратном случае, при ${\alpha}_1(t){\le}{\alpha}_2(t)$ получаем уравнение логистической кривой.

# Выполнение лабораторной работы

1. Напишем код программы ([Рис. @fig:001]). Программа моделирует все три случая. За первый случай отвечает переменная n1, за второй - n2, за третий - n3. Зададим параметры симуляции ([Рис. @fig:002]).

![Код программы](../img/img_1.png){#fig:001}

![Параметры симуляции](../img/img_2.png){#fig:002}

2. Запустим программу на исполнение. Посмотрим на графики числа всех трех величин ([Рис. @fig:003]). Как видим, быстрее всего растет третьего случая, далее идет график второго случая и затем - первого. Так как для первого случая число график сильно отличается, запустим программу с другими параметрами симуляции. ([Рис. @fig:004]). Посмотрим на график первого случая ([Рис. @fig:005]). Он растет по модели Мальтуса.
   
![Графики для всех случаев](../img/img_3.png){#fig:003}

![Другие параметры симуляции](../img/img_4.png){#fig:004}

![График для первого случая](../img/img_5.png){#fig:005}

3. Определим, в какой момент времени скорость распространения рекламы будет иметь максимальное значение. Для этого посмотрим на график производной и определим ее максимум. ([Рис. @fig:006]). Он находится в точке 0.024.

![Максимальное значение скорости распространения рекламы](../img/img_6.png){#fig:006}

# Выводы

В результате выполнения лабораторной работы мы познакомились с моделью рекламы и написали ее реализацию в OpenModelica.

# Библиография

1. OpenModelica User's Guide. URL: [https://www.openmodelica.org/doc/OpenModelicaUsersGuide/latest/](https://www.openmodelica.org/doc/OpenModelicaUsersGuide/latest/)
2. Лабораторная работа №6. - 4 с. URL: [https://esystem.rudn.ru/mod/resource/view.php?id=831127](https://esystem.rudn.ru/mod/resource/view.php?id=831127)
