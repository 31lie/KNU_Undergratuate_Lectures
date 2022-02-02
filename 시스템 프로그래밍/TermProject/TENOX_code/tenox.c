#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

#define listSize 9 * 10
#define ESCAPE 27
#define ENTER 10

int numList[listSize] = {0, };
char *menu_item[] = {"", "   SELECT Game Mode", "   RECORD" , "   How to Play", "   Quit"};
char *game_menu[] = {"", " makeZERO", " timeKILL", " BACK"};
int timeCount = 0;

/* function Declaration */
void init_scr();
void printLogo();
void printList(WINDOW *scr);
void makeRandomList();
void calculate(int *, int *);
WINDOW ** menu_list();
int scroll_menu(WINDOW **, int , int , int , int);
WINDOW **game_list();
void check_quit();
int totalSum();
int score();
void *time_check(void *);
void *time_count(void *);
void gameStart_makeZero(WINDOW*);
void gameStart_timeKill(WINDOW* , WINDOW* );
void make_record(int , int);
void game_finish(int);
void print_record();
void print_howto();
void wait();

/* initiation screen */
void init_scr() {
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_WHITE, COLOR_GREEN);
    curs_set(0);
    keypad(stdscr, TRUE);
}

/* Printing Logo */
void printLogo() {   
    FILE *fp = fopen("./Data/tenox_logo.txt", "r");
    char buf[1000] = {0, };
    fread(buf, 1, 1000, fp);
    printw("%s", buf);
    fclose(fp);
}

/* Print List */
void printList(WINDOW *scr) {

    for (int i=0 ; i<11; i++) {

        if (i==0) 
            wprintw(scr, "   ");
        else
            wprintw(scr,"%4d", i-1);
    }
    wprintw(scr, "\n   ------------------------------------------\n");

    for (int i=0 ; i<listSize ; i++) {

        if ((i+1)%10==1) {
            wprintw(scr, "%d |", i / 10);
        }

        wprintw(scr,"%4d", numList[i]);

        if ((i+1)%10==0) {
            
            wprintw(scr, "  | %d", i/10);
            
            if (i==listSize-1) {
                wprintw(scr, "\n   ------------------------------------------\n");
                for (int i=0 ; i<11; i++) {

                    if (i==0) 
                        wprintw(scr, "   ");
                    else
                        wprintw(scr,"%4d", i-1);
                }
            }
            else {
                wprintw(scr, "\n  | \n");
            }
        }
    }
    wrefresh(scr);
}

/* Make Random List */
void makeRandomList() {
    
    int countNum[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int temp, success=0;
    srand(time(NULL));
    // make Random number (1~9)
    while (success != listSize) {

        temp = rand() % 9 + 1;
        if (countNum[temp-1] != 10) {
            countNum[temp-1]++;
            numList[success] = temp;
            success++;
        }
    }
}

void calculate(int* startPosition, int* boxSize) {

    int start = startPosition[0] * 10 + startPosition[1];
    int sum = 0;

    for (int i = 0; i < boxSize[0]; i++) {
        for (int j = 0; j < boxSize[1]; j++){
            sum += numList[start + i + j*10];
        }
    }

    if (sum == 10) {
        for (int i = 0; i < boxSize[0]; i++) {
            for (int j = 0; j < boxSize[1]; j++){
                numList[start + i + j*10] = 0;
            }
        }
    }
}


/* Make menu list window */
WINDOW ** menu_list() {

    WINDOW **items;
    items = (WINDOW **)malloc(5 * sizeof(WINDOW *));

    items[0] = newwin(6, 32, 18, 25);
    wbkgd(items[0], COLOR_PAIR(2));
    box(items[0], ACS_VLINE, ACS_HLINE);

    items[1] = subwin(items[0], 1, 30, 19, 26);
    items[2] = subwin(items[0], 1, 30, 20, 26);
    items[3] = subwin(items[0], 1, 30, 21, 26);
    items[4] = subwin(items[0], 1, 30, 22, 26);

    for (int i=1 ; i < 5 ; i++) 
        wprintw(items[i], "%s", menu_item[i]);
    wbkgd(items[1], COLOR_PAIR(1));
    wrefresh(items[0]);
    return items;
}

/* Scrolling items */
int scroll_menu(WINDOW **items, int count, int menu_start_col, int index_num, int select_pair) {

    int key;
    int selected = 0;

    while (1) {
        key = getch();
        if (key == KEY_DOWN || key == KEY_UP) {
            wbkgd(items[selected + 1], COLOR_PAIR(select_pair));
            wnoutrefresh(items[selected+1]);
            
            if (key == KEY_DOWN)
                selected = (selected+1) % count;
            else
                selected = (selected + count - 1) % count;
            
            wbkgd(items[selected+1], COLOR_PAIR(1));
            wnoutrefresh(items[selected+1]);
            doupdate();
        }

        else if (key == ESCAPE)
            return -1;
        else if (key == ENTER)
            return selected;
    }
}

/* Make game mode list Window */
WINDOW **game_list() {

    WINDOW **items;
    items = (WINDOW **)malloc(4 * sizeof(WINDOW *));

    items[0] = newwin(5, 20, 18, 60);
    wbkgd(items[0], COLOR_PAIR(4));

    items[1] = subwin(items[0], 1, 20, 19, 60);
    items[2] = subwin(items[0], 1, 20, 20, 60);
    items[3] = subwin(items[0], 1, 20, 21, 60);

    for (int i = 1; i < 4; i++)
        wprintw(items[i], "%s", game_menu[i]);
    wbkgd(items[1], COLOR_PAIR(1));
    wrefresh(items[0]);
    return items;
}

/* Make quit check window */
void check_quit() {

    WINDOW *check;
    int key;

    check = newwin(6, 35, 10, 23);
    wmove(check, 2,2);
    wprintw(check, "  Do you want to quit TENOX ?");
    wmove(check, 3,2);
    wprintw(check, "    If you do, press 'y'");
    wbkgd(check, COLOR_PAIR(2));
    box(check, ACS_VLINE, ACS_HLINE);
    refresh();
    key = wgetch(check);
    delwin(check);
    if (key == 'y' || key == 'Y') {
        endwin();
        exit(0);
    }
}

/* Calculate Sum */
int totalSum(){
    int sum = 0;
    for (int i=0 ; i<listSize; i++) {
        sum += numList[i];
    }
    return sum;
}

/* calculate score */
int score() {

    int sum = totalSum();
    int score = (450 - sum) * 100 / 450 ;

    return score;
}

void *time_check(void *time) {

    WINDOW* timeWin = (WINDOW*) time;
    signal(SIGALRM, game_finish);

    for (timeCount = 30; timeCount > 0; timeCount--) {    
        if (timeCount == 30)
            alarm(31);
        werase(timeWin);
        sleep(1);
        wprintw(timeWin, "Time left : %ds", timeCount);  
        wrefresh(timeWin);     
    }
    
}

void *time_count(void *time) {

    WINDOW* timeWin = (WINDOW*) time;
    for (timeCount = 0; ; timeCount++) {
        
        werase(timeWin);
        wprintw(timeWin, "Time Count : %ds", timeCount);
        wrefresh(timeWin);
        sleep(1);

        if (totalSum() == 0) {
            make_record(timeCount, 1);
            game_finish(1);
        }
    } 
}

/* makeZero mode game start */
void gameStart_makeZero(WINDOW* gameWin) {

    /* User input */
    int startPoint[2], boxSize[2], myscore;

    /* Window setting */
    wbkgd(gameWin, COLOR_PAIR(1));
    wrefresh(gameWin);

    /* make Random list to play */
    makeRandomList();

    while(1) {
        printList(gameWin);

        wprintw(gameWin, "\n\n\n\nInput your Start Point (row col): ");
        wscanw(gameWin, "%d %d", &startPoint[0], &startPoint[1]);
        wrefresh(gameWin);
    
        wmove(gameWin, 44, 0);

        wprintw(gameWin, "Input your box Size (width height): ");
        wscanw(gameWin, "%d %d", &boxSize[0], &boxSize[1]);
        wrefresh(gameWin);

        calculate(startPoint, boxSize);

        werase(gameWin);
        touchwin(gameWin);
    }
}

void gameStart_timeKill(WINDOW* gameWin, WINDOW* scoreWin) {

    /* User input */
    int startPoint[2], boxSize[2], myscore;

    /* Window setting */
    wbkgd(gameWin, COLOR_PAIR(1));
    wrefresh(gameWin);

    /* make Random list to play */
    makeRandomList();


    while(1) {
        printList(gameWin);
        myscore = score();
        werase(scoreWin);
        wprintw(scoreWin, "Your score : %d", myscore);
        wrefresh(scoreWin);
        touchwin(scoreWin);

        wprintw(gameWin, "\n\n\n\nInput your Start Point (row col): ");
        wscanw(gameWin, "%d %d", &startPoint[0], &startPoint[1]);
        wrefresh(gameWin);
    
        wmove(gameWin, 44, 0);

        wprintw(gameWin, "Input your box Size (width height): ");
        wscanw(gameWin, "%d %d", &boxSize[0], &boxSize[1]);
        wrefresh(gameWin);

        calculate(startPoint, boxSize);
        
        werase(gameWin);
        touchwin(gameWin);
    }
}

void make_record(int score, int gametype) {

    int thepipe[2];
    char buf[BUFSIZ];
    char type[BUFSIZ];

    FILE *fp = fopen("./Record/gameRecord.txt", "a");

    if (pipe(thepipe) == -1) {
        perror("Could not make pipe");
        exit(1);
    }

    switch(fork()) {

        case -1:
            perror("fork error");
        
        /* Child Process */
        case 0:
            close(thepipe[1]);
            read(thepipe[0], buf, BUFSIZ);
            fprintf(fp, "%s", buf);
            break;

        /* Parent Process */
        default:

            close(thepipe[0]);

            char timebuf[BUFSIZ];
            time_t t = time(NULL);
            struct tm* tm_info = localtime(&t);
            strftime(timebuf, BUFSIZ, "%Y.%m.%d %H:%M", tm_info);

            if (gametype == 1){
                sprintf(type, "MakeZERO mode");
            }
            else {
                sprintf(type, "TimeKILL mode");
            }

            sprintf(buf, "%20s   %5d    %20s\n", type, score, timebuf);

            if(strlen(buf) != write(thepipe[1], buf, strlen(buf))) {
				perror("write");
				exit(3);
			}
            wait(NULL);
            break;         
    }
}

/* game finish window */
void game_finish(int type) {
    
    WINDOW *timeout;
    int key;
    int myscore = score();
    make_record(myscore, type);
    timeout = newwin(6, 40, 10, 23);
    wmove(timeout, 2, 2);
    wprintw(timeout, " Game finish! Your Score is %d", myscore);
    wmove(timeout, 3, 2);
    wprintw(timeout, "Your play is Successfully recorded!");
    wbkgd(timeout, COLOR_PAIR(2));
    box(timeout, ACS_VLINE, ACS_HLINE);
    refresh();
    key = wgetch(timeout);
    if (key){
        werase(timeout);
        touchwin(timeout);
        delwin(timeout);
        endwin();
        exit(0);
    }
}

void print_record() {

    werase(stdscr);
    move(1, 0);
    printLogo();
    FILE *fp = fopen("./Record/gameRecord.txt", "r");
    char buf[1000] = {0, };
    fread(buf, 1, 1000, fp);
    mvprintw(25, 0, "%20s   %5s    %20s", "Game mode", "Score / Time", "Play time");
    mvprintw(27, 0, "%s", buf);
    fclose(fp);
}

void print_howto() {

    werase(stdscr);
    move(1,0);
    printLogo();
    FILE *fp = fopen("./Data/how_to.txt", "r");
    char buf[1000] = {0, };
    fread(buf, 1, 1000, fp);
    mvprintw(27, 0, "%s", buf);
    fclose(fp);
}

void main() {

    /* Screen Setting */
    init_scr();
    bkgd(COLOR_PAIR(1));
    signal(SIGINT, check_quit);


    /* declare and Setting Windows */
    WINDOW *gameWin, *start, *score, *time;
    start = subwin(stdscr, 2, 30, 20, 25);
    gameWin = subwin(stdscr, 30, 100, 8, 15);
    time = subwin(stdscr, 1, 20, 3, 50);
    score = subwin(stdscr, 1, 30, 3, 13);

    /* Print TENOX logo to stdscr */
    move(1,0);
    printLogo();

    /* START window */
    wattron(start, A_BOLD);
    waddstr(start, "! Press ENTER to start game !");
    move(1, 0);
    wattron(start, A_DIM);
    waddstr(start, "   ESC or q to quit the game");
    wrefresh(start);

    int key, selected_menu, selected_game;
    WINDOW **menu, **gameList;

    key = getch();
    werase(start);
    wrefresh(start);

    /* Show Menu if enter key is pressed */
    if (key == ENTER) {
        
        while(1) {
            menu = menu_list();
            selected_menu = scroll_menu(menu, 4, 20, 0, 2);

            /* Select Game mode */
            if (selected_menu == 0) {

                gameList = game_list();
                selected_menu = scroll_menu(gameList, 3, 57, 0, 4);
                
                /* makeZero mode */
                if (selected_menu == 0) {
                    werase(stdscr);
                    selected_game = 1;
                    break;
                }

                /* timeKill mode */
                else if (selected_menu == 1) {
                    werase(stdscr);
                    selected_game = 2;
                    break;
                }
            }

            /* RECORD */
            else if (selected_menu == 1) {
                print_record();
            }

            /* How to play */
            else if (selected_menu == 2) {
                print_howto();
            }

            /* Quit */
            else if (selected_menu == 3) {
                check_quit();
                endwin();
            }
            touchwin(stdscr);
            refresh();
        }
    }

    refresh();

    /* Start game */
    if (selected_game == 1) {

        pthread_t t1;
        pthread_create(&t1, NULL, time_count, (void*)time);
        gameStart_makeZero(gameWin);
    }

    if (selected_game == 2) {

        pthread_t t2;
        pthread_create(&t2, NULL, time_check, (void *)time);
        gameStart_timeKill(gameWin, score);

    }

    endwin();
}