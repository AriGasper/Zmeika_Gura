# Реализация консольной игры «Змейка» на языке C++
### Цель игры: 
Cобрать как можно больше денег, передвигаясь по игровому полю.
### Правила игры:
- В начальном меню нужно выбрать сложность предстоящей игры: `1` - легко,  `2` - сложно;
- Иногда на поле появляются бомбы, они не навсегда, но их нужно остерегаться. Если столкнуться с бомбой, игра закончится;
- Еще игра закончится, если врезаться в стенку или "съесть свой хвост";
- В сложном режиме игры кроме стен есть препятствия-ограждения, в которые также нельзя врезаться;
- Собрать деньги можно, дотронувшись до них головой змеи;
- Одна собранная монета равняется 10 баллам счёта.
### Как управлять змейкой?
- Чтобы змейка начала движение, нажмите на одну из клавиш: `w` (вверх) `a` (влево) `s` (вниз) `d` (вправо);
- Управляйте змейкой с помощью тех же клавиш: `w` (вверх) `a` (влево) `s` (вниз) `d` (вправо);
- При нажатии на клавишу `x` игра закончится;
- Чтобы ускорить змейку, можно нажать клавишу `e`.

### Обозначения в игре: 
стенка или преграда| голова змеи| туловище змеи| деньги| бомбы
:-----|:----------:|:------------:|:-----:|:-----:
#|0|o|$|@

## Как выглядит игра?
### Начальное меню
![1st window](https://github.com/AriGasper/Zmeika_Gura/blob/master/Снимок%20экрана%202023-05-30%20225358.png)
### Легкий уровень
![1st level](https://github.com/AriGasper/Zmeika_Gura/blob/master/Снимок%20экрана%202023-05-30%20232650.png)
### Сложный уровень
![2nd level](https://github.com/AriGasper/Zmeika_Gura/blob/master/Снимок%20экрана%202023-05-30%20232747.png)

