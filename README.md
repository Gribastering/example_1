# example_1

Язык программирования: C++
Среда выполнения: Microsoft Visual Studio
Время выполнения: 4 часа 
Задача:
Необходимо разработать консольное приложение, которое рассчитывает и выводит время,
которое пройдет от старта двигателя внутреннего сгорания до момента его перегрева, в
зависимости от заданной температуры окружающей среды. Приложение должно принимать с
консоли пользовательский ввод температуры окружающей среды в градусах Цельсия, и выводить
на консоль время до перегрева в секундах. Рассчитывать время точно, аналитическим путем не
нужно, интересует получение этого времени методом симуляции (разумеется, таким образом
время будет вычислено с определенной погрешностью).
Приложение должно состоять из трех логических блоков:
1. Симуляция двигателя внутреннего сгорания
Требуется упрощенно симулировать изменение скорости вращения коленвала и температуры
охлаждающей жидкости двигателя, работающего без нагрузки, с течением времени. Входные
параметры:
• Момент инерции двигателя I (кг∙м
2
)

• Кусочно-линейная зависимость крутящего момента M, вырабатываемого двигателем, от
скорости вращения коленвала V (крутящий момент в Н∙м, скорость вращения в
радиан/сек):

• Температура перегрева Tперегрева (C
0
)

• Коэффициент зависимости скорости нагрева от крутящего момента HM (
C
0
H∙m∙сек)
• Коэффициент зависимости скорости нагрева от скорости вращения коленвала HV (
C
0
∙сек
рад2
)
• Коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей
среды C (
1
сек)

Так как двигатель работает без нагрузки, то весь вырабатываемый момент идет на раскрутку
коленвала, и его ускорение вычисляется просто: a =
M
I

Специальной логики старта двигателя не требуется. Считаем, что при старте он просто начинает
вырабатывать крутящий момент по заданному графику начиная с нулевой скорости вращения.

Скорость нагрева двигателя рассчитывать как VH = M × HM + V
2 × HV (С
0
/сек)
Скорость охлаждения двигателя рассчитывать как VC = C × (Tсреды - Тдвигателя) (С
0
/сек)

Температура двигателя до момента старта должна равняться температуре окружающей среды.
Нагрев и охлаждение, рассчитанные по формулам выше, действуют на двигатель постоянно,
одновременно и независимо друг от друга.
2. Логика тестирования двигателя на перегрев
Требуется реализовать «тестовый стенд», исследующий поданный на вход двигатель. Тестовый
стенд должен включать двигатель, следить за его температурой, и в момент перегрева
прекращать тест и возвращать время, прошедшее с момента старта до перегрева.
Расчет симуляции двигателя не должен производиться в реальном времени. Необходимо
использовать модельное время, чтобы ожидание результатов работы программы не было
продолжительным.
3. Консольный ввод-вывод, задание исходных данных и запуск теста
Эта часть приложения содержит точку входа, и должна обеспечивать весь ввод/вывод на консоль,
а так же задание всех исходных данных и запуск теста двигателя. Все исходные данные, кроме
температуры окружающей среды, нужно задать в коде или в конфигурационном файле:
I = 10
M = { 20, 75, 100, 105, 75, 0 } при V = { 0, 75, 150, 200, 250, 300 } соответственно
Tперегрева = 110
HM = 0.01
HV = 0.0001
C = 0.1
Температура окружающей среды вводится пользователем с клавиатуры, после запуска
приложения.
