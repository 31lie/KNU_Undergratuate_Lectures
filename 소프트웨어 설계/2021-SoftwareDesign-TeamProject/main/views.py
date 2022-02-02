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
def home(request):
    return render(request, 'home.html')

def login(request):
    if request.method == "POST":
        username = request.POST['username']
        password = request.POST['password']
        user = auth.authenticate(request, username=username, password=password)

        if user is not None:
            auth.login(request, user)
            return redirect('/startpage')
        else:
            return render(request, 'home.html', {'error0704':'error'})
    else:
        return render(request, 'home.html')   

def adminlogin(request):
    if request.method == "POST":
        username = request.POST['username']
        password = request.POST['password']
        user = auth.authenticate(request, username=username, password=password)

        if user is not None:
            if user.username == "admin":
                auth.login(request, user)
                return redirect('/admin')
            else:
                return render(request, 'home.html', {'error1300':'error'})
        else:
            return render(request, 'home.html', {'error0704':'error'})
    else:
        return render(request, 'home.html')  


def signup(request):
    if request.method == 'POST':
        if request.POST['password'] == request.POST['password-re']:
            try:
                user = User.objects.get(username = request.POST['username'])
                return render(request, 'home.html', {'error1736':'error'})
            except User.DoesNotExist:
                user = User.objects.create_user(
                username = request.POST['username'],
                password = request.POST['password'])
            return render(request, 'home.html', {'error1200':'error'})
            #return redirect('/') # 바로 로그인되면, home 화면으로 바로 redirect
        else:
            return render(request, 'home.html', {'error1219':'error'})
    return render(request, 'home.html') 