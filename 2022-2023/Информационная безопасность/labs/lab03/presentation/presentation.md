---
## Front matter
lang: ru-RU
title: Презентация по лабораторной работе №3
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

# Цель работы

Получение практических навыков работы в консоли с атрибутами файлов для групп пользователей.

# Выполнение лабораторной работы

## Создание пользователя guest2

![Создание пользователя guest2](../img/Image%20001.png){ #fig:001 width=70% }

## Добавление пользователя в группу guest

![Добавление пользователя в группу guest](../img/Image%20002.png){ #fig:002 width=70% }

## Проверка групп

![Вход и проверка групп с guest](../img/Image%20003.png){ #fig:003 width=70% }

## Регистрация в группе

![Регистрация пользователя guest2](../img/Image%20006.png){ #fig:006 width=70% }

## Изменение прав доступа

![Изменение прав доступа](../img/Image%20008.png){ #fig:008 width=70% }

## Проверка доступа

![Проверка доступа](../img/Image%20009.png){ #fig:009 width=70% }

## Фрагмент таблицы с правами

| Права директории | Права файла | Создание файла | Удаление файла | Запись в файл | Чтение файла | Смена директории | Просмотр файлов в директории | Переименование файла | Смена атрибутов файла |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 000 | 000 | - | - | - | - | - | - | - | - |
| 010 | 000 | - | - | - | - | + | - | - | - |
| 020 | 000 | - | - | - | - | - | - | - | - |
| 030 | 000 | + | + | - | - | + | - | + | - |

## Таблица минимально необходимых прав

| Операция | Минимальные права на директорию | Минимальные права на файл |
| --- | --- | --- |
| Создание файла | 030 | 000 |
| Удаление файла | 030 | 000 |
| Чтение файла | 010 | 040 |
| Запись в файл | 010 | 020 |
| Переименование файла | 030 | 000 |
| Создание поддиректории | 030 | 000 |
| Удаление поддиректории | 030 | 000 |

# Итог

Я получил практические навыки работы в консоли с атрибутами файлов для групп пользователей.
