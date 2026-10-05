import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]  # see below
data=np.loadtxt(ROOT /"output/vaja1/dusnih.dat")
OM=data[:,0]
amp=data[:,1]
'''print data
print OM'''
plt.plot(OM,amp)
plt.scatter(OM,amp)
plt.xlabel('frekvenca vzbujanja')
plt.ylabel('amplituda nihanja')
plt.show()
plt.close()