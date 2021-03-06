---
## Front matter
lang: ru-RU
title: Презентация по лабораторной работе №4
author: Калинин Тимур Дмитриевич
institute: РУДН
date: 

## Formatting
toc: false
slide_level: 2
theme: metropolis
header-includes: 
 - \metroset{progressbar=frametitle,sectionpage=progressbar,numbering=fraction}
 - '\makeatletter'
 - '\beamer@ignorenonframefalse'
 - '\makeatother'
aspectratio: 43
section-titles: true
---

# Цель выполнения лабораторной работы

Построить модель гармонического осциллятора в OpenModelica.

# Задачи выполнения лабораторной работы

## Условия и задача

Вариант 31

Постройте фазовый портрет гармонического осциллятора и решение уравнения гармонического осциллятора для следующих случаев:

1. Колебания гармонического осциллятора без затуханий и без действий внешней силы $\ddot{x}+17x=0$.
   
2. Колебания гармонического осциллятора c затуханием и без действий внешней силы $\ddot{x}+1.7\dot{x}+6x=0$.
   
3. Колебания гармонического осциллятора c затуханием и под действием внешней силы $\ddot{x}+3.6\dot{x}+8x=0.6\cos{3t}$.

На интервале $t \in [0; 66]$ (шаг 0.05) с начальными условиями $x_0=0.3, y_0=0.7$

# Результаты выполнения лабораторной

## Код программы

![Исходный код программы](img/Image%201385.png){ #fig:001 width=70%}

## График для первого случая

![График для первого случая](img/Image%201387.png){ #fig:002 width=70%}

## График для второго случая

![График для второго случая](img/Image%201388.png){ #fig:003 width=70%}

## График для третьего случая

![График для третьего случая](img/Image%201389.png){ #fig:004 width=70%}

# Итог

В результате выполнения лабораторной работы я построил модель гармонических колебаний в OpenModelica.
