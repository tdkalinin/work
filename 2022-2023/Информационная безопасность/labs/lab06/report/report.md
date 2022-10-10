---
# Front matter
title: "Отчёт по лабораторной работе №6"
subtitle: "Мандатное разграничение прав в Linux"
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

Развить навыки администрирования ОС Linux. Получить первое практическое знакомство с технологией SELinux1.
Проверить работу SELinx на практике совместно с веб-сервером Apache.

# Выполнение лабораторной работы

1. Войдите в систему с полученными учётными данными и убедитесь, что SELinux работает в режиме enforcing политики targeted с помощью команд getenforce и sestatus ([Рис. @fig:001])
   
![Статус selinux](../img/Image%20008.png){ #fig:001 width=70% } 

2. Обратитесь с помощью браузера к веб-серверу, запущенному на вашем компьютере, и убедитесь, что последний работает ([Рис. @fig:002]). Если не работает, запустите его так же, но с параметром start ([Рис. @fig:003])

![Статус веб-сервера](../img/Image%20009.png){ #fig:002 width=70% }

![Запуск веб-сервера](../img/Image%20010.png){ #fig:003 width=70% }
   
3. Найдите веб-сервер Apache в списке процессов, определите его контекст безопасности и занесите эту информацию в отчёт ([Рис. @fig:004]).

![Контекст службы Apache](../img/Image%20011.png){ #fig:004 width=70% } 

4. Посмотрите текущее состояние переключателей SELinux для Apache. Обратите внимание, что многие из них находятся в положении «off» ([Рис. @fig:005]).

![Состояние переключателей SELinux для Apache](../img/Image%20012.png){ #fig:005 width=70% } 
   
5. Посмотрите статистику по политике с помощью команды seinfo, также определите множество пользователей, ролей, типов ([Рис. @fig:006]).

![Статистика по политике](../img/Image%20013.png){ #fig:006 width=70% }

6. Определите тип файлов и поддиректорий, находящихся в директории /var/www ([Рис. @fig:007]):

![Тип файлов и директорий в /var/www](../img/Image%20014.png){ #fig:007 width=70% }

7. Определите тип файлов, находящихся в директории /var/www/html ([Рис. @fig:008]):

![Тип файлов в /var/www/html](../img/Image%20015.png){ #fig:008 width=70% }

8. Определите круг пользователей, которым разрешено создание файлов в директории /var/www/html. Как видим, создание файлов разрешено только владельцу каталога.

9.  Создайте от имени суперпользователя (так как в дистрибутиве после установки только ему разрешена запись в директорию) html-файл /var/www/html/test.html следующего содержания ([Рис. @fig:009]):

![Содержание test.html](../img/Image%20016.png){ #fig:009 width=70% }

10.  Проверьте контекст созданного вами файла. Занесите в отчёт контекст,
присваиваемый по умолчанию вновь созданным файлам в директории /var/www/html ([Рис. @fig:010]).

![Контекст test.html](../img/Image%20017.png){ #fig:010 width=70% }

11. Обратитесь к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1/test.html. Убедитесь, что файл был успешно отображён ([Рис. @fig:011]).

![Обращение к файлу через веб-сервер](../img/Image%20018.png){ #fig:011 width=70% }
    
12. Изучите справку man httpd_selinux и выясните, какие контексты файлов определены для httpd ([Рис. @fig:012]). Сопоставьте их с типом файла test.html. Проверить контекст файла можно командой ls -Z ([Рис. @fig:013]).

![Обращение к файлу через веб-сервер](../img/Image%20019.png){ #fig:012 width=70% }

![Контекст файла](../img/Image%20040.png){ #fig:013 width=70% }

13. Измените контекст файла /var/www/html/test.html с httpd_sys_content_t на любой другой, к которому процесс httpd не должен иметь доступа, например, на samba_share_t. После этого проверьте, что контекст поменялся ([Рис. @fig:014]).

![Изменение контекста](../img/Image%20020.png){ #fig:014 width=70% }

14. Попробуйте ещё раз получить доступ к файлу через веб-сервер, введя в
браузере адрес http://127.0.0.1/test.html . Вы должны получить
сообщение об ошибке ([Рис. @fig:015]):

![Проверка доступа через веб-сервер](../img/Image%20021.png){ #fig:015 width=70% }

15.  Проанализируйте ситуацию. Почему файл не был отображён, если права доступа позволяют читать этот файл любому пользователю? Потому что у процесса, который пытается запросить доступ к файлу, нет к нему доступа из-за метки.

Просмотрите log-файлы веб-сервера Apache. Также просмотрите системный лог-файл ([Рис. @fig:016]):

![Системный лог-файл](../img/Image%20022.png){ #fig:016 width=70% }

Если в системе окажутся запущенными процессы setroubleshootd и audtd, то вы также сможете увидеть ошибки, аналогичные указанным выше, в файле /var/log/audit/audit.log. Проверьте это утверждение самостоятельно ([Рис. @fig:017]).

![Файл /var/log/audit/audit.log](../img/Image%20023.png){ #fig:017 width=70% }

16.   Попробуйте запустить веб-сервер Apache на прослушивание ТСР-порта 100 (а не 80, как рекомендует IANA и прописано в /etc/services). Для этого в файле /etc/httpd/httpd.conf найдите строчку Listen 80 и замените её на Listen 100 ([Рис. @fig:018]).

![Прослушивание 100 порта](../img/Image%20024.png){ #fig:018 width=70% }

17.  Выполните перезапуск веб-сервера Apache. Произошёл сбой? Поясните
почему? Сбой произошел из-за того, что у процесса нет доступа к 100 порту протокола TCP, так как он ограничивается selinux ([Рис. @fig:019]).

![Сбой перезапуска](../img/Image%20025.png){ #fig:019 width=70% }

18. Проанализируйте лог-файлы ([Рис. @fig:020]):

![Содержимое системного лог-файла](../img/Image%20026.png){ #fig:020 width=70% }

Просмотрите файлы /var/log/http/error_log ([Рис. @fig:021]), /var/log/http/access_log ([Рис. @fig:022]) и /var/log/audit/audit.log ([Рис. @fig:023]) и выясните, в каких файлах появились записи.

![Содержимое /var/log/http/error_log](../img/Image%20027.png){ #fig:021 width=70% }

![Содержимое /var/log/http/access_log](../img/Image%20028.png){ #fig:022 width=70% }

![Содержимое /var/log/audit/audit.log](../img/Image%20029.png){ #fig:023 width=70% }

19.  Выполните команду `semanage port -a -t http_port_t -р tcp 81`
После этого проверьте список портов ([Рис. @fig:024])

![Добавление порта 100 для httpd](../img/Image%20030.png){ #fig:024 width=70% }

Убедитесь, что порт 100 появился в списке.

20.  Попробуйте запустить веб-сервер Apache ещё раз ([Рис. @fig:025]). Поняли ли вы, почему он сейчас запустился, а в предыдущем случае не смог? Потому что в этот раз у процесса веб-сервера был доступ к порту 100.

![Перезапуск Apache](../img/Image%20031.png){ #fig:025 width=70% }

21. Верните контекст httpd_sys_cоntent__t к файлу /var/www/html/ test.html ([Рис. @fig:026]):

![Возвращение контекста](../img/Image%20032.png){ #fig:026 width=70% }

После этого попробуйте получить доступ к файлу через веб-сервер, введя в браузере адрес http://127.0.0.1:81/test.html. Вы должны увидеть содержимое файла — слово «test» ([Рис. @fig:027]).

![Доступ через браузер](../img/Image%20033.png){ #fig:027 width=70% }

22. Исправьте обратно конфигурационный файл apache, вернув Listen 80 ([Рис. @fig:028]).

![Исправление конфигурационного файла](../img/Image%20034.png){ #fig:028 width=70% }

23. Удалите привязку http_port_t к 100 порту и проверьте, что порт 100 удалён ([Рис. @fig:029]).

![Удаление 100 порта](../img/Image%20035.png){ #fig:029 width=70% }

24. Удалите файл /var/www/html/test.html ([Рис. @fig:030]):

![Удаление test.html](../img/Image%20036.png){ #fig:030 width=70% }

# Выводы

Мы развили навыки администрирования ОС Linux и получили первое практическое знакомство с технологией SELinux.
Проверили работу SELinx на практике совместно с веб-сервером Apache.

# Библиография

1. Лабораторная работа №6. - 5 с. URL: [https://esystem.rudn.ru/pluginfile.php/1651891/mod_resource/content/2/006-lab_selinux.pdf](https://esystem.rudn.ru/pluginfile.php/1651891/mod_resource/content/2/006-lab_selinux.pdf)