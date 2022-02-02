from django.shortcuts import render, redirect
from django.contrib.auth.models import User
from django.contrib import auth, messages
from django.views import View
from django.http import JsonResponse
from django.core.exceptions import ValidationError
from django.http import HttpResponse
from django.core.paginator import Paginator
from django.contrib.auth.forms import PasswordChangeForm
from django.contrib.auth.hashers import check_password

# Create your views here.
def mypage(request):
    return render(request, 'mypage.html')

def change_pw(request):
    context = {}
    if request.method == 'POST':
        current_password = request.POST.get("password-cur")
        user = request.user
        if check_password(current_password, user.password):
            new_password = request.POST.get("password")
            password_confirm = request.POST.get("password-re")
            if new_password == password_confirm:
                user.set_password(new_password)
                user.save()
                auth.login(request,user)
                return redirect("/")
            else:
                context.update({'error':"새로운 비밀번호를 다시 확인해주세요."})
    else:
        context.update({'error':"현재 비밀번호가 일치하지 않습니다."})

    return render(request, "home.html",context)  

def logout(request):
    if request.method == 'POST':
        auth.logout(request)
        return redirect('/')
    else:
        return render(request, 'home.html')   

def userDelete(request):
    user = request.user
    user.delete()
    logout(request)
    context = {}
    return render(request, 'home.html', context)