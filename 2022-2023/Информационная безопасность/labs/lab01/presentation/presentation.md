---
## Front matter
lang: ru-RU
title: Презентация по лабораторной работе №1
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

## Fonts
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase,Scale=0.9
---

# Цель выполнения лабораторной работы

Целью данной работы является приобретение практических навыков установки операционной системы на виртуальную машину, настройки минимально необходимых для дальнейшей работы сервисов.

# Задачи выполнения лабораторной работы

Лабораторная работа подразумевает установку на виртуальную машину
VirtualBox (https://www.virtualbox.org/) операционной системы Linux
(дистрибутив Rocky (https://rockylinux.org/)).

# Результаты выполнения лабораторной

## Создание виртуальной машины

![Создание виртуальной машины](../img/Image%20001.png){ #fig:001 width=70% }

## Настройки виртуальной машины

![Создание нового виртуального жесткого диска](../img/Image%20003.png){ #fig:002 width=70% }

## Запуск установки.

![Запуск установки](../img/Image%20007.png){ #fig:003 width=70% }

## Настройки установки ОС

![Добавление доп. ПО](../img/Image%20009.png){ #fig:004 width=70% }

## Процесс установки ОС

![Процесс установки](../img/Image%20012.png){ #fig:005 width=70% }

## Добавления дополнений для гостевой ОС

![Дополнения гостевой ОС](../img/Image%20015.png){ #fig:006 width=70% }

## Просмотр информации о системе с помощью dmesg

![Модель процессора](../img/Image%20019.png){ #fig:007 width=70% }

## Просмотр информации о системе с помощью dmesg

![Объем доступной оперативной памяти](../img/Image%20020.png){ #fig:008 width=70% }

# Итог

В результате лабораторной работы мы успешно установили операционную систему Rocky Linux на виртуальную машину.
