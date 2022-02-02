from django.shortcuts import render
from .models import CoronicStatusOfRegion, CoronicStatusOfKorea

# Create your views here.
def startpage(request):
    total = CoronicStatusOfKorea.objects.all()
    context = {'total': total}
    return render(request, 'startpage.html', context)

def localCoronic(request):
    coronic = CoronicStatusOfRegion.objects.all()
    context = {'coronic':coronic}
    return render(request, 'localCoronic.html', context)