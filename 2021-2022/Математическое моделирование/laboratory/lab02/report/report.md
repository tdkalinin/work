---
# Front matter
title: "Отчёт по лабораторной работе №1"
subtitle: "Работа с git"
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

Смоделировать задачу о погоне в OpenModelica.

# Задание

Вариант 31

На море в тумане катер береговой охраны преследует лодку браконьеров. Через определенный промежуток времени туман рассеивается, и лодка обнаруживается на расстоянии 10,5 км от катера. Затем лодка снова скрывается в тумане и уходит прямолинейно в неизвестном направлении. Известно, что скорость катера в 4,3 раза больше скорости браконьерской лодки.

1. Запишите уравнение, описывающее движение катера, с начальными условиями для двух случаев (в зависимости от расположения катера относительно лодки в начальный момент времени).
2. Постройте траекторию движения катера и лодки для двух случаев.
3. Найдите точку пересечения траектории катера и лодки.

# Теоретическое введение

1. Принимаем за t~0~=0, x~л0~=0 - место нахождения лодки браконьеров в момент обнаружения, x~к0~=k - место нахождения катера береговой охраны относительно лодки браконьеров в момент обнаружения лодки.
2. Введем полярные координаты. Считаем, что полюс - это точка обнаружения лодки браконьеров x~л0~ ($\theta$), а полярная ось $r$ проходит через точку нахождения катера береговой охраны.
3. Траектория катера должна быть такой, чтобы и катер, и лодка все время были на одном расстоянии от полюса  $\theta$, только в этом случае траектория катера пересечется с траекторией лодки. Поэтому для начала катер береговой охраны должен двигаться некоторое
время прямолинейно, пока не окажется на том же расстоянии от полюса, что и лодка браконьеров. После этого катер береговой охраны должен двигаться вокруг полюса удаляясь от него с той же скоростью, что и лодка браконьеров.
4. Чтобы найти расстояние $x$ (расстояние после которого катер начнет двигаться вокруг полюса), необходимо составить простое уравнение. Пусть через время $t$ катер и лодка окажутся на одном расстоянии x от полюса. За
это время лодка пройдет $x$, а катер $k+x$ (или $k-x$, в зависимости от начального положения катера относительно полюса). Время, за которое они пройдут это расстояние, вычисляется как $\frac{x}{v}$ или $\frac{k+x}{4.3v}$ (во втором
случае $\frac{k-x}{4.3v}$). Так как время одно и то же, то эти величины одинаковы.
Тогда неизвестное расстояние $x$ можно найти из следующего уравнения:
$$
\frac{x}{v}=\frac{k+x}{4.3v}
$$ в первом случае
$$
\frac{x}{v}=\frac{k-x}{4.3v}
$$ во втором
Отсюда найдем x~1~=k/3.3=210/67 и x~2~=k/5.3=105/53.

5. После того, как катер береговой охраны окажется на одном расстоянии от полюса, что и лодка, он должен сменить прямолинейную траекторию и начать двигаться вокруг полюса удаляясь от него со скоростью лодки $v$.
Для этого скорость катера раскладываем на две составляющие: $v_{r}$ - радиальная скорость и $v_{\tau}$ - тангенциальная скорость. Радиальная скорость - это скорость, с которой катер удаляется от полюса, $v_{r}~=dr/dt$ Нам нужно, чтобы эта скорость была равна скорости лодки, поэтому полагаем $dr/dt=v$.
Тангенциальная скорость – это линейная скорость вращения катера относительно полюса. Она равна произведению угловой скорости $d\theta/dt$ на радиус $r$, $v~\tau~=rd\theta/dt$.
$v_{\tau}=\sqrt{18.49v^2-v^2}=\sqrt{17.49}v$
То есть $r\frac{d\theta}{dt}=\sqrt{17.49}v$

6. Решение исходной задачи сводится к решению системы из двух дифференциальных уравнений.
$$
dr/dt=v
$$
$$
v_{\tau}=\sqrt{17.49}v
$$
c начальными условиями
$$
\theta_{0}=0
$$
$$
r_{0}=x_{1}
$$ или
$$
\theta_{0}=-\pi
$$
$$
r_{0}=x_{2}
$$
Решив это уравнение, вы получите траекторию движения катера в полярных координатах.


# Выполнение лабораторной работы

1. Напишем программу для симуляции данной задачи в OpenModelica ([Рис. @fig:001]). В этой программе помимо выше приведеных формул используются формулы перевода координат из полярной в декартову для построения траекторий движения катера и лодки. Также стоит отметить, что все величины переведены в СИ. В качестве параметров задаем угол $\phi$, на который будет двигаться лодка, изначальное расстояние k, точки в которых катер начинает описывать спиралевидную траекторию x~1, x~2.

![Исходный код в программе](img/Image%201354.png){ #fig:001 width=70%}

2. Проверим на ошибки ([Рис. @fig:002]).

![Проверка на ошибки](img/Image%201355.png){#fig:002 width=70%}

3. Зададим параметры симуляции ([Рис. @fig:003]).

![Параметры симуляции](img/Image%201356.png){#fig:003 width=70%}

4. Запустим симуляцию ([Рис. @fig:004]) и посмотрим изменение угла $\theta$ c течением времени.
   
![Изменение угла](img/Image%201357.png){#fig:004 width=70%}

5. Перейдем в режим зависимости параметров. Посмотрим траектории катера и лодки ([Рис. @fig:005]). Мы видим точку пересечения траекторий ([Рис. @fig:006]).

![Траектория катера (красный) и лодки (синий)](img/Image%201358.png){#fig:005 width=70%}

![Точка пересечения](img/Image%201364.png){#fig:006 width=70%}

6. Теперь проверим второй случай ([Рис. @fig:007]). Мы также видим точку пересечения траекторий ([Рис. @fig:008]).

![Траектория катера и лодки](img/Image%201365.png){#fig:007 width=70%}

![Точка пересечения](img/Image%201366.png){#fig:008 width=70%}

# Выводы

В результате выполнения лабораторной работы мы смоделировали задачу о погоне в OpenModelica.
