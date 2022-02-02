from django.shortcuts import render
from .models import SocialDistanceLevelOfRegion
from .models import MetroCity
from .models import Do
from .models import SelfGoverningDo
from .models import SelfGoverningSi
from .models import Si
from .models import Gun
from .models import SocialDistanceLevel

# Create your views here.
def region(req):
    rg = SocialDistanceLevelOfRegion.objects
    return render(req, 'currentStage.html', {'rg': rg})


def metroCity(req):
    mc = MetroCity.objects
    return render(req, 'currentStage.html', {'mc': mc})


def do(req):
    do = Do.objects
    return render(req, 'currentStage.html', {'do': do})


def selfGoverningDo(req):
    sgd = SelfGoverningDo.objects
    return render(req, 'currentStage.html', {'sgd': sgd})


def selfGoverningSi(req):
    sgs = SelfGoverningSi.objects
    return render(req, 'currentStage.html', {'sgs': sgs})


def si(req):
    si = Si.objects
    return render(req, 'currentStage.html', {'si': si})


def gun(req):
    gun = Gun.objects
    return render(req, 'currentStage.html', {'gun': gun})


def socialDistanceLevel(req):
    return render(req, "socialDistanceLevel.html")


def level1(req):
    level1 = SocialDistanceLevel.objects
    return render(req, "level1.html", {'level1': level1})


def level2(req):
    level2 = SocialDistanceLevel.objects
    return render(req, "level2.html", {'level2': level2})


def level3(req):
    level3 = SocialDistanceLevel.objects
    return render(req, "level3.html", {'level3': level3})


def level4(req):
    level4 = SocialDistanceLevel.objects
    return render(req, "level4.html", {'level4': level4})


def currentStage(request):
    return render(request, 'currentStage.html')