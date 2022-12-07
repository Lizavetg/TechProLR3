# Отчет по лабораторной работе №3  
### ЛР выполнили: Прокопенко Дарья, Герасимова Елизавета; гр.М30-406с-19.  
#### Цель работы:  
Разработайте программу, в которой будет реализован следующий
функционал:
1. Создайте класс profiler, в конструкторе которого должно засекаться
время при помощи `steady_clock::time_point start_time_ = steady_clock::now();`, а в деструкторе выводится в консоль длительность существования
класса.
2. Соберите программу через консоль PowerShell, используя компилятор, установленный через MinGW. При компиляции обязательно использовать флаги -Wall и -Werror.
3. Напишите Makefile для сборки проекта.
4. Проведите профилировку методов класса навигационной комплексной системы. 

#### Выполнение работы:
1. Разработка программы: 
   В часть программы, представленной в методичке, были добавленны конструктор и деструктор. В конструкторе происходит засекание времени, в то время, как в деструкторе высчитывается конечное время, а после выводится в консоль время существования класса. Вычисление длительности существования класса осуществляется следующим образом: `duration_cast<milliseconds>(end_time_ - start_t_).count()`
 
2. После разработки программы, она была собрана через консоль PowerShell, используя компилятор MinGW c добавлением флагов -Wall и -Werror. Для этого требовалось:  
    - В консоли PowerShell указать расположение файлов, для этого использовалась команда cd D:\TechProLR3;  
    - После чего скомпилировать файл cpp командой g++ -Wall -Werror LR3.cpp -o name, где name-это название exe файла;  
    - Запустить exe файл командой .\name.exe.  
3. После сборки программы был создан Makefile.   
    Makefile — это файл с инструкциями для утилиты make, которая нужна для автоматической сборки проекта.  
    Пример содержания Makefile:  
      `all:`  
	      `g++ -Wall -Werror techprol.cpp -o techprol  `,
    где all-это цель,после которой указаны нужные команды, с использование табуляции.  
    Для того, чтобы запустить Makefile была использована команда make -f nameMakefile,  
    где nameMakefile-имя файла.  

    
    
