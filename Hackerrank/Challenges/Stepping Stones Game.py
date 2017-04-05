import math

tt=int(raw_input(""))
while(tt>0):
	k=long(raw_input(""))
	kk=8*k+1
	kk=math.sqrt(kk)
	kk=long(kk)
	k2=kk*kk
	#print kk
	if(k2==(8*k+1)):
		print "Go On Bob",(1+kk)/2-1
	else:
		print "Better Luck Next Time"
	tt-=1

