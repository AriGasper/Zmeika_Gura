#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

const int width = 20;
const int height = 20;

int x, y, MoneyX, MoneyY, score, bombX, bombY;
int tailX[100], tailY[100];
int SpeedIndex = 100;
int nTail;
bool gameOver;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
int level;

void Start() //функция для начального меню
{
    //вывод надписи "ЗМЕЙКА"
    for (int p = -1; p < 8; p++) {
        for (int h = -1; h < 35; h++) {
            if (p == 0)
                if (h == 17) cout << "\033[1;32m#\033[0m";
                else cout << ' ';
            if (p == 1)
                if ((h == 0) || (h == 1) || (h == 2) || (h == 5) || (h == 9) || (h == 11) || (h == 12) || (h == 13) || (h == 14) || (h == 16) || (h == 19) || (h == 21) || (h == 25) || (h == 30))
                    cout << "\033[1;32m#\033[0m";
                else cout << ' ';

            if (p == 2)
                if (h == 3 || h == 5 || h == 6 || h == 8 || h == 9 || h == 11 || h == 16 || h == 19 || h == 21 || h == 24 || h == 29 || h == 31)
                    cout << "\033[1;32m#\033[0m";
                else cout << ' ';
            if (p == 3)
                if (h == 2 || h == 5 || h == 7 || h == 9 || h == 11 || h == 16 || h == 19 || h == 21 || h == 23 || h == 29 || h == 31)
                    cout << "\033[1;32m#\033[0m";
                else cout << ' ';
            if (p == 4)
                if (h == 0 || h == 1 || h == 5 || h == 9 || h == 11 || h == 12 || h == 13 || h == 16 || h == 19 || h == 21 || h == 22 || h == 28 || h == 32)
                    cout << "\033[1;32m#\033[0m";
                else cout << ' ';
            if (p == 5)
                if (h == 2 || h == 5 || h == 9 || h == 11 || h == 16 || h == 18 || h == 19 || h == 21 || h == 23 || h == 28 || h == 29 || h == 30 || h == 31 || h == 32)
                    cout << "\033[1;32m#\033[0m";
                else cout << ' ';
            if (p == 6)
                if (h == 3 || h == 5 || h == 9 || h == 11 || h == 16 || h == 17 || h == 19 || h == 21 || h == 24 || h == 27 || h == 33)
                    cout << "\033[1;32m#\033[0m";
                else cout << ' ';
            if (p == 7)
                if (h == 0 || h == 1 || h == 2 || h == 5 || h == 9 || h == 11 || h == 12 || h == 13 || h == 14 || h == 16 || h == 19 || h == 21 || h == 25 || h == 27 || h == 33)
                    cout << "\033[1;32m#\033[0m";
                else cout << ' ';
            if (h == 34)
                cout << endl;
        }
    }
    for (int endline = 0; endline < 5; endline++) cout << endl;
    cout << "\033[1;34mЦель игры:\033[0m собрать как можно больше монет, не врезаться в стены," << endl << "препятствия и не попасться на бомбу." << endl << endl << "\033[1;34mУправление змейкой:\033[0m" << endl << endl << "\033[1;34mw\033[0m - вверх" << endl << "\033[1;34ma\033[0m - влево" << endl << "\033[1;34ms\033[0m - вниз" << endl << "\033[1;34md\033[0m - вправо" << endl << "\033[1;34mx\033[0m - завершить игру" << endl<< "\033[1;34me\033[0m - ускорить змейку" <<endl << endl << "Выбери сложность игры: \033[1;32m1\033[0m - легко, \033[1;31m2\033[0m - сложно: ";


    std::cin >> level;
}

void Setup() // инициализация переменных
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    MoneyX = rand() % width;
    MoneyY = rand() % height;

    bombX = rand() % width;
    bombY = rand() % height;
    score = 0;
}

void Draw_1_Level() // функция отрисовки поля, змейки, денег, бомб и вывода мотивационных фраз для легкого режима игры
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "\033[1;34m#\033[0m";
    cout << endl;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "\033[1;34m#\033[0m";
            if (i == y && j == x)
                cout << "\033[1;32m0\033[0m";
            else if (i == MoneyY && j == MoneyX)
                cout << "\033[1;33m$\033[0m";
            else if (i == bombY && j == bombX && (score == 20 || score == 40 || score == 60 || score == 80))
                cout << "\033[1;31m@\033[0m";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "\033[1;32mo\033[0m";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "\033[1;34m#\033[0m";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "\033[1;34m#\033[0m";
    cout << endl;
    if (score < 21)
        cout << "\033[1;31mСчёт:\033[0m " << score << endl << "Я знаю, сложно, но ты сильнее всего этого!" << endl;
    if (score > 20 && score < 61)
        cout << "\033[1;33mСчёт:\033[0m" << score << endl << "Ты крутой! Не останавливайся." << endl;
    if (score > 60)
        cout << "\033[1;32mСчёт:\033[0m" << score << endl << "Вау! Восхитительно!!!" << endl;


}


void Draw_2_Level() // функция отрисовки поля, преград, змейки, денег, бомб и вывода мотивационных фраз для сложного режима игры
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "\033[1;34m#\033[0m";
    cout << endl;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "\033[1;34m#\033[0m";
            if (i == y && j == x)
                cout << "\033[1;32m0\033[0m";
            else if ((i == MoneyY && j == MoneyX) && not(i == 3 && j > 5 && j < 10) && not(i == 8 && j > 15 && j < 20) && not(i == 12 && j > 2 && j < 7))
                cout << "\033[1;33m$\033[0m";
            else if (i == bombY && j == bombX && (score == 20 || score == 40 || score == 60 || score == 80) && not(i == 3 && j > 5 && j < 10) && not(i == 8 && j > 15 && j < 20) && not(i == 12 && j > 2 && j < 7))
                cout << "\033[1;31m@\033[0m";
            else if (i == 3 && j > 5 && j < 10)
                cout << "\033[1;34m#\033[0m";
            else if (i == 8 && j > 15 && j < 20)
                cout << "\033[1;34m#\033[0m";
            else if (i == 12 && j > 2 && j < 7)
                cout << "\033[1;34m#\033[0m";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "\033[1;32mo\033[0m";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "\033[1;34m#\033[0m";
        }
        cout << endl;
    }


    for (int i = 0; i < width + 2; i++)
        cout << "\033[1;34m#\033[0m";
    cout << endl;
    if (score < 21)
        cout << "\033[1;31mСчёт:\033[0m " << score << endl << "Я знаю, сложно, но ты сильнее всего этого!" << endl;
    if (score > 20 && score < 61)
        cout << "\033[1;33mСчёт:\033[0m" << score << endl << "Ты крутой! Не останавливайся." << endl;
    if (score > 60)
        cout << "\033[1;32mСчёт:\033[0m" << score << endl << "Вау! Восхитительно!!!" << endl;


}


void Input() // идентификация нажатия клавиш
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        case 'e': 
            SpeedIndex = 20;
            Sleep(SpeedIndex);
            break;
        }
    }
}


void Logic_1_Level() { // функция логики игры в легком режиме

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int l = 1; l < nTail; l++)
    {
        prev2X = tailX[l];
        prev2Y = tailY[l];
        tailX[l] = prevX;
        tailY[l] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width-1 || x < 0 || y > height-1 || y < 0)
    {
        gameOver = true;
        cout << "\033[1;31mУпс, ты врезался в стенку:( Попробуй еще раз!\033[0m" << endl;
    }
    for (int l = 0; l < nTail; l++)
    {
        if (tailX[l] == x && tailY[l] == y)
        {
            gameOver = true;
            cout << "\033[1;31mУпс, ты съел свой хвост:( Попробуй еще раз!\033[0m" << endl;
        }
    }
    if (x == bombX && y == bombY && (score == 20 || score == 40 || score == 60 || score == 80)) {
        gameOver = true;
        cout << "\033[1;31mУпс, ты попался на бомбу:( Попробуй еще раз!\033[0m" << endl;
    }
    if (x == MoneyX && y == MoneyY)
    {
        score += 10;
        MoneyX = rand() % width;
        MoneyY = rand() % height;
        nTail++;
    }
}

void Logic_2_Level() { // функция логики игры в сложном режиме
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int l = 1; l < nTail; l++)
    {
        prev2X = tailX[l];
        prev2Y = tailY[l];
        tailX[l] = prevX;
        tailY[l] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x > width-1 || x < 0 || y > height-1 || y < 0 || (y == 3 && x > 5 && x < 10) || (y == 8 && x > 15 && x < 20) || (y == 12 && x > 2 && x < 7))
    {
        gameOver = true;
        cout << "\033[1;31mУпс, ты врезался в стенку:( Попробуй еще раз!\033[0m" << endl;
    }

    for (int l = 0; l < nTail; l++)
    {
        if (tailX[l] == x && tailY[l] == y)
        {
            gameOver = true;
            cout << "\033[1;31mУпс, ты съел свой хвост:( Попробуй еще раз!\033[0m" << endl;
        }
    }
    if (x == bombX && y == bombY && (score == 20 || score == 40 || score == 60 || score == 80)) {
        gameOver = true;
        cout << "\033[1;31mУпс, ты попался на бомбу:( Попробуй еще раз!\033[0m" << endl;

    }
    if (x == MoneyX && y == MoneyY)
    {
        score += 10;
        MoneyX = rand() % width;
        MoneyY = rand() % height;
        nTail++;
    }
}

int main() // основная функция
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    Start();

    Setup();
    while (!gameOver)
    {
        if (level == 1) {
            Draw_1_Level();
            Logic_1_Level();
        }
        if (level == 2) {
            Draw_2_Level();
            Logic_2_Level();
        }
        Input();
        
        if (score < 21)
            Sleep(160);
        if (score > 20 && score < 61)
            Sleep(120);
        if (score > 60 && score < 101)
            Sleep(80);
        if (score > 100)
            Sleep(40);
    }
    return 0;
}
