#2020114658 이윤서
#11주차 과제_미로찾기

class Mazeclear:

    def __init__(self, stack_size, entrance, exit):
        self.top = -1
        self.stack = [] * stack_size
        self.max_stack_size = stack_size
        self.pos = entrance
        self.exit = exit

    def is_empty(self):
        if self.top == -1:
            return True
        else :
            return False

    def direction(self):
        global way
        y,x = self.pos[0], self.pos[1]
        if maze[y][x+1] == 0:
            way = 'straight'
        elif maze[y+1][x] == 0:
            way = 'down'
        elif maze[y][x-1] == 0:
            way = 'back'
        elif maze[y-1][x] == 0:
            way = 'up'
        elif maze[y][x+1] == 1:
            way = 'restraight'
        elif maze[y+1][x] == 1:
            way = 'redown'
        elif maze[y][x-1] == 1:
            way = 'reback'
        elif maze[y-1][x] == 1:
            way = 'reup'
        else :
            return False
        return way

    def move(self):
        maze[self.pos[0]][self.pos[1]] = 1
        y,x=self.pos[0],self.pos[1]
        if way == 'straight' :
            Mazeclear.push(self)
            x=x+1
        elif way == 'down' :
            Mazeclear.push(self)
            y=y+1
        elif way == 'back' :
            Mazeclear.push(self)
            x= x-1
        elif way == 'up' :
            Mazeclear.push(self)
            y= y-1
        elif way == 'restraight' :
            maze[self.pos[0]][self.pos[1]] = 2
            Mazeclear.push(self)
            x=x+1
        elif way == 'redown' :
            maze[self.pos[0]][self.pos[1]] = 2
            Mazeclear.push(self)
            self.y= self.y+1
        elif way == 'reback' :
            maze[self.pos[0]][self.pos[1]] = 2
            Mazeclear.push(self)
            x= x-1
        elif way == 'reup' :
            maze[self.pos[0]][self.pos[1]] = 2
            Mazeclear.push(self)
            y= y-1
        self.pos=(y,x)
        return self.pos


    def push(self):
        self.stack.insert(0,(self.pos[0],self.pos[1]))
        self.top+=1

    def pop(self):
        self.stack.pop(0)
        self.top-=1

    def is_full(self):
        if self.top == self.max_stack_size :
            return True
        else :
            return False

    def print_all(self):
        for i in range(7):
            for j in range(7):
                print('%2d'%maze[i][j], end=' ')
            print()

    def finish_maze(self):
        print('이동 경로:')
        for i in reversed(self.stack) :
            if i!=self.stack[0] :
                print(i,end=' => ')
            else:
                print(i)
        print()
        print()
        print('Escaped Maze')
        Mazeclear.print_all(self)


def main():
    print('미로 모양:')
    mazeRobot.print_all()
    while not mazeRobot.pos == mazeRobot.exit :
        mazeRobot.direction()
        mazeRobot.move()
    mazeRobot.move()
    print()
    mazeRobot.finish_maze()





#미로모양, 출구, 입구 위치 설정
maze = [[-1,-1,-1,-1,-1,-1,-1],
        [ 0, 0, 0, 0, 0, 0,-1],
        [-1,-1, 0,-1,-1,-1,-1],
        [-1, 0, 0,-1, 0, 0,-1],
        [-1,-1, 0, 0, 0,-1,-1],
        [-1,-1, 0,-1, 0, 0, 0],
        [-1,-1,-1,-1,-1,-1,-1]]

#객체 생성 및 메인함수 호출
mazeRobot = Mazeclear(100, (1, 0), (5, 6))
main()

