import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("resonanca.dat")
OM=data[:,0]
amp=data[:,1]
'''print data
print OM'''
plt.plot(OM,amp)
plt.scatter(OM,amp)
plt.xlabel('frekvenca vzbujanja')
plt.ylabel('amplituda nihanja')
plt.savefig("resonanca_num.jpg",dpi=200,bbox_inches='tight')
plt.show()
plt.close()