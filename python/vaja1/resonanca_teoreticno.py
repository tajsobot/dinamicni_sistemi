import numpy as np
import matplotlib.pyplot as plt

# Constants
#m = 1.0  # Mass
l = 1.0  # Length of the pendulum
F0 = 0.1  # Amplitude of the periodic forcing
g = 9.81

om0=np.sqrt(g/l)

Omega = np.linspace(2, 5, 200)

beta_values = [0.08, 0.12, 0.16, 0.32, 0.64]

z0 = np.zeros((len(beta_values), len(Omega)))

for i, beta in enumerate(beta_values):
    z0[i] = F0 / np.sqrt( (om0*om0-Omega*Omega)**2 + 4*(beta*Omega)**2 )

# Plot amplitude as a function of forcing frequency for each beta
plt.figure(figsize=(6, 6))
for i, beta in enumerate(beta_values):
    plt.plot(Omega, z0[i], label=f'Beta = {beta}')
plt.xlabel('Forcing Frequency (Omega)')
plt.ylabel('Amplitude (z0)')
#plt.title('Amplitude of Forced Pendulum vs Forcing Frequency for Different Beta Values')
#plt.grid(True)
plt.legend()
plt.show()
plt.close()