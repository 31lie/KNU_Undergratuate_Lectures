#2020114658 이윤서
#8주차 과제_MyCircle 클래스 구현


import math

class MyCircle :
    def __init__(self,x,y,radius):
        self.__x=x
        self.__y=y
        self.__radius=radius

    def area(self):
        area=self.__radius*self.__radius*3.14
        return area

    def distance(self,circle):
        distance=math.sqrt((circle.__x-self.__x)**2+(circle.__y-self.__y)**2)
        return distance

    def overlaps(self,circle):
        if (self.__radius+circle.__radius)>self.distance(circle) :
            result = True
        else :
            result = False
        return result

    def contains(self,circle):
        if (self.__radius - circle.__radius) > self.distance(circle):
            result = True
        else:
            result = False
        return result

    def get_x(self):
        return self.__x
    def set_x(self,x):
        self.__x=x

    def get_y(self):
        return self.__y
    def set_y(self,y):
        self.__y=y

    def get_radius(self):
        return self.__radius
    def set_radius(self,value):
        self.__radius=value

    def __str__(self):
        return 'Circle : (x=%d, y=%d, r=%d), 면적: %.1f'%(self.__x,self.__y,self.__radius,self.area())


c1 = MyCircle(0, 0, 100)
c2 = MyCircle(0, -10, 10)
c3 = MyCircle(-100, 0, 120)
print('c1 =', c1)
print('c2 =', c2)
print('c3 =', c3)
print('c1 contains c2 :', c1.contains(c2))
print('c1 contains c3 :', c1.contains(c3))
print('c1 overlaps c2 :', c1.overlaps(c2))
print('c1 overlaps c3 :', c1.overlaps(c3))
print('c3 contains c1 :', c3.contains(c1))