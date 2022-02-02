
from django.contrib import admin
from django.urls import path
import cimsWeb.views
import main.views
import coronicStatus.views
import socialDistance.views
import account.views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', main.views.home, name='Home'), 

    path('currentStage/', socialDistance.views.region),
    path('stageInfo/level1', socialDistance.views.level1),
    path('stageInfo/level2', socialDistance.views.level2),
    path('stageInfo/level3', socialDistance.views.level3),
    path('stageInfo/level4', socialDistance.views.level4),
    
    path('startpage/', coronicStatus.views.startpage, name='startpage'),
    path('stageInfo/', cimsWeb.views.stageInfo, name='stageInfo'),

    path('localCoronic/', coronicStatus.views.localCoronic, name='localCoronic'),
   
    path('mypage/', account.views.mypage, name='mypage'),
    path('change_pw/', account.views.change_pw, name='change_pw'),
    path('userDelete/', account.views.userDelete, name='userDelete'),
    
    path('login/', main.views.login, name='login'),
    path('signup/', main.views.signup, name='signup'),
    path('adminlogin/', main.views.adminlogin, name='adminlogin'),
]
