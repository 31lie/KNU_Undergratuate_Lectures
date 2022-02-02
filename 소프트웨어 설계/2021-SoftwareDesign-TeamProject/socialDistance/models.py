from django.db import models

# Create your models here.
class SocialDistanceLevelOfRegion(models.Model):
    region = models.CharField(max_length=100)
    level = models.IntegerField()
    term = models.CharField(max_length=100)
    
    def __str__(self):
        #    """String for representing the Model object."""
        return f'{self.region}({self.level}단계)'


class MetroCity(SocialDistanceLevelOfRegion):
    pass


class Do(SocialDistanceLevelOfRegion):
    pass


class SelfGoverningDo(SocialDistanceLevelOfRegion):
    pass


class SelfGoverningSi(SocialDistanceLevelOfRegion):
    pass


class Si(SocialDistanceLevelOfRegion):
    pass


class Gun(SocialDistanceLevelOfRegion):
    pass


class SocialDistanceLevel(models.Model):
    level = models.CharField(max_length=1000)
    criterion = models.CharField(max_length=1000)
    privateMeetingRule = models.CharField(max_length=1000)
    festivalRule = models.CharField(max_length=1000)
    rallyRule = models.CharField(max_length=1000)
    
    def __str__(self):
        #    """String for representing the Model object."""
        return f'{self.level} 단계'