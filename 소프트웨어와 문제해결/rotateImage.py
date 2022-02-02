# 2020114658 이윤서
# 9주차 과제_이미지 회전

from PIL import Image

def rotate90(image) :
    width, height = image.size
    new_image = Image.new("RGB",(height,width), "white")
    for i in range(width):
        for j in range(height):
            pixel = image.getpixel((i, j))
            red = pixel[0]
            green = pixel[1]
            blue = pixel[2]
            new_image.putpixel((j,width-1-i),(int(red),int(green),int(blue)))
    return new_image


def mirror(image):
    width, height = image.size
    new_image = Image.new("RGB", (width, height), "white")
    for i in range(height):
        for j in range((width//2)):
            pixel1 = image.getpixel((j, i))
            red1=pixel1[0]
            green1=pixel1[1]
            blue1=pixel1[2]
            pixel2 = image.getpixel((width-(j+1),i))
            red2=pixel2[0]
            green2=pixel2[1]
            blue2=pixel2[2]
            new_image.putpixel((j,i),(int(red2),int(green2),int(blue2)))
            new_image.putpixel((width-(j+1),i),(int(red1),int(green1),int(blue1)))
    return new_image

original = Image.open('newyork.jpg')

rotate90_image = rotate90(original)
rotate90_image.show()
rotate90_image.save('newyork-ccw90.jpg')

mirror_image = mirror(original)
mirror_image.show()
mirror_image.save('newyork-mirror.jpg')
