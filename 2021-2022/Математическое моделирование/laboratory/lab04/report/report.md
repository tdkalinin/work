---
# Front matter
title: "Отчёт по лабораторной работе №4"
subtitle: "Модель гармонических колебаний"
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

Построить фазовый портрет модели гармонических колебаний в OpenModelica.

# Задание

Вариант 31

Постройте фазовый портрет гармонического осциллятора и решение уравнения
гармонического осциллятора для следующих случаев:

1. Колебания гармонического осциллятора без затуханий и без действий внешней силы $\ddot{x}+17x=0$.
   
2. Колебания гармонического осциллятора c затуханием и без действий внешней силы $\ddot{x}+1.7x+6x=0$.
   
3. Колебания гармонического осциллятора c затуханием и под действием внешней силы $\ddot{x}+3.6\dot{x}+8x=0.6\cos{3t}$.
   
На интервале $t \in [0; 66]$ (шаг 0.05) с начальными условиями $x_0=0.3, y_0=0.7$

# Теоретическое введение

Движение грузика на пружинке, маятника, заряда в электрическом контуре, а также эволюция во времени многих систем в физике, химии, биологии и других науках при определенных предположениях можно описать одним и тем же
дифференциальным уравнением, которое в теории колебаний выступает в качестве основной модели. Эта модель называется линейным гармоническим осциллятором.

Уравнение свободных колебаний гармонического осциллятора имеет следующий вид:

$$
\ddot{x}+2\gamma\dot{x}+{{\omega}_0}^2x=0
$$

где $x$ - переменная, описывающая состояние системы (смещение грузика, заряд конденсатора и т.д.), $\gamma$ – параметр, характеризующий потери энергии (трение в механической системе, сопротивление в контуре), ${\omega}_0$ собственная частота колебаний, $t$ – время.

При отсутствии потерь в системе ($\gamma=0$) получаем
уравнение консервативного осциллятора, энергия колебания которого сохраняется во времени.

$$
\ddot{x}+{{\omega}_0}^2x=0
$$

Для однозначной разрешимости уравнения второго порядка необходимо задать два начальных условия вида

$$
\begin{cases}
x(t_0)=x_0\\
\dot{x}(t_0)=y_0
\end{cases}
$$

Уравнение второго порядка можно представить в виде системы двух уравнений первого порядка:

$$
\begin{cases}
\dot{x}=y\\
\dot{y}=-{{\omega}_0}^2x
\end{cases}
$$

Начальные условия примут вид:

$$
\begin{cases}
x(t_0)=x_0\\
y(t_0)=y_0
\end{cases}
$$

Независимые переменные $x, y$ определяют пространство, в котором «движется» решение. Это фазовое пространство системы, поскольку оно двумерно будем называть его фазовой плоскостью.

Значение фазовых координат $x, y$ в любой момент времени полностью определяет состояние системы. Решению уравнения движения как функции времени отвечает гладкая кривая в фазовой плоскости. Она называется фазовой траекторией. Если множество различных решений (соответствующих различным
начальным условиям) изобразить на одной фазовой плоскости, возникает общая картина поведения системы. Такую картину, образованную набором фазовых траекторий, называют фазовым портретом.

# Выполнение лабораторной работы

1. Напишем код программы ([Рис. @fig:001]). Данная программа моделирует все три случая. Задаются параметры gamma и omega для соответствующих уравнений, переменные, начальные условия и сами уравнения. Зададим параметры симуляции ([Рис. @fig:002]).

![Код программы](img\Image%201385.png){#fig:001}

![Параметры симуляции](img\Image%201386.png){#fig:002}

2. Запустим программу на исполнение. Посмотрим фазовый портрет для уравнений ([Рис. @fig:003], [Рис. @fig:004], [Рис. @fig:005]).

![1-й случай](img\Image%201387.png){#fig:003}

![2-й случай](img\Image%201388.png){#fig:004}

![3-й случай](img\Image%201389.png){#fig:005}

# Ответы на вопросы
1. Запишите простейшую модель гармонических колебаний

$$
\ddot{x}+2\gamma\dot{x}+{{\omega}_0}^2x=0
$$

2. Дайте определение осциллятора

Осциллятор — система, совершающая колебания, то есть показатели которой периодически повторяются во времени.

3. Запишите модель математического маятника

$$
\ddot{x}+{{\omega}_0}^2x=0
$$ 

4. Запишите алгоритм перехода от дифференциального уравнения второго порядка к двум дифференциальным уравнениям первого порядка.

Нужно произвести замену производной второго порядка на переменную (первое уравнение) и выразить производную этой переменной из изначального уравнения (второе уравнение).

5. Что такое фазовый портрет и фазовая траектория?

Фазовый портрет - это геометрическое представление траекторий динамической системы на фазовой плоскости. Каждый набор начальных условий представлен отдельной кривой или точкой.

Фазовая траектория - гладкая кривая в фазовой плоскости, которая отвечают решению уравнения движения как функции времени.

# Выводы

В результате выполнения лабораторной работы мы написали модель гармонических колебаний в OpenModelica.

# Библиография

1. OpenModelica User's Guide. URL: [https://www.openmodelica.org/doc/OpenModelicaUsersGuide/latest/](https://www.openmodelica.org/doc/OpenModelicaUsersGuide/latest/)
2. Лабораторная работа №4. - 4 с. URL: [https://esystem.rudn.ru/mod/resource/view.php?id=831115](https://esystem.rudn.ru/mod/resource/view.php?id=831115)
