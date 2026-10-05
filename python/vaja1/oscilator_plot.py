import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]  # see below
data=np.loadtxt(ROOT / "output/vaja1/vzbujanonih.dat")
#data=np.loadtxt("dusnih.dat")
#data=np.loadtxt("vzbujanonih.dat")

time=data[:,0]  # cas so vsi podatki v prvem stolpcu
fi=data[:,1]
om=data[:,2]

maxfi=np.max(fi)  # poisce max vrednost odmika
minfi=np.min(fi)
maxom=np.max(om)
minom=np.min(om)
#Tmax=np.max(time)
Tmax=30

vis_faktor=0.1   # faktor za vizualizacijo

plt.plot(time,fi)
plt.plot(time,om)
plt.xlabel('cas')
plt.ylabel('fi, om')
plt.xlim(0,Tmax)
plt.ylim(minom*(1+vis_faktor),maxom*(1+vis_faktor))
plt.show()
plt.close()

# izris faznega portreta
plt.plot(fi,om)
plt.xlabel('fi')
plt.ylabel('om')
plt.show()
plt.close()