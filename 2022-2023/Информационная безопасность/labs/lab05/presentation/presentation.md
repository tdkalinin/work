---
## Front matter
lang: ru-RU
title: Презентация по лабораторной работе №5
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

Изучение механизмов изменения идентификаторов, применения SetUID- и Sticky-битов. Получение практических навыков работы в консоли с дополнительными атрибутами. Рассмотрение работы механизма смены идентификатора процессов пользователей, а также влияние бита Sticky на запись и удаление файлов.

# Выполнение лабораторной работы

## Создание программы

![Код simpleid2.c](../img/Image%20009.png){ #fig:004 width=70% }

---

![Компиляция и выполнение simpleid2.c](../img/Image%20010.png){ #fig:005 width=70% }

---

![Установка прав](../img/Image%20011.png){ #fig:006 width=70% }

---

![Запуск simpleid2](../img/Image%20013.png){ #fig:008 width=70% }

---

![Установка setGID-бита](../img/Image%20014.png){ #fig:009 width=70% }

---

![Код readfile.c](../img/Image%20015.png){ #fig:010 width=70% }

---

![Изменяем владельца](../img/Image%20017.png){ #fig:012 width=70% }

---

![Проверка чтения](../img/Image%20018.png){ #fig:013 width=70% }

---

![Смена владельца](../img/Image%20019.png){ #fig:014 width=70% }

---

![Установка setUID-бита](../img/Image%20020.png){ #fig:015 width=70% }

---

![Проверка чтения readfile.c](../img/Image%20021.png){ #fig:016 width=70% }

---

![Проверка чтения /etc/shadow](../img/Image%20022.png){ #fig:017 width=70% }

---

## Исследование Sticky-бита

![Атрибуты](../img/Image%20023.png){ #fig:018 width=70% }

---

![Создание нового файла](../img/Image%20024.png){ #fig:019 width=70% }

---

![Просмотр атрибутов](../img/Image%20025.png){ #fig:020 width=70% }

---

![Установка прав доступа](../img/Image%20040.png){ #fig:021 width=70% }

---

![Чтение файла](../img/Image%20026.png){ #fig:022 width=70% }

---

![Дозапись в файл](../img/Image%20027.png){ #fig:023 width=70% }

---

![Перезапись файла](../img/Image%20028.png){ #fig:024 width=70% }

---

![Проверка содержимого](../img/Image%20029.png){ #fig:025 width=70% }

---

![Попытка удаления](../img/Image%20030.png){ #fig:026 width=70% }

---

![Снятие атрибута t](../img/Image%20031.png){ #fig:027 width=70% }

---

![Повтор действий](../img/Image%20033.png){ #fig:029 width=70% }

# Итог

Мы изучили механизмы изменения идентификаторов, применения SetUID- и Sticky-битов. Получили практические навыки работы в консоли с дополнительными атрибутами. Рассмотрели работу механизма смены идентификатора процессов пользователей, а также влияние бита Sticky на запись и удаление файлов.
