from django.db import models

# Create your models here.
class CoronicStatusOfRegion(models.Model):
    #"""Model representing a Coronic Status of Region."""
    region = models.CharField(max_length=100)
    year = models.IntegerField()
    month = models.IntegerField()
    day = models.IntegerField()
    coronicCount = models.IntegerField()
    coronicGap = models.IntegerField()

    def __str__(self):
        #    """String for representing the Model object."""
        return f'{self.region} : {self.coronicCount}({self.coronicGap})'

class CoronicStatusOfKorea(models.Model):
    year = models.IntegerField()
    month = models.IntegerField()
    day = models.IntegerField()
    coronicCount = models.IntegerField()
    coronicGap = models.IntegerField()
    
    def __str__(self):
        #    """String for representing the Model object."""
        return f'{self.coronicCount}({self.coronicGap})'
