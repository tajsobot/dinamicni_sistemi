#include "Vaja1.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define PI 3.1415926

double fi, om, g, l, om0, t, dt, fi_new, om_new, beta;
double F0, OM, maxamp;
int i, mod;

std::pmr::vector<double> fi_t;

FILE *out;  // za izpis v datoteko

Vaja1::Vaja1() {
  g = 9.81;
  l = 1.0;
  fi = 0.4;
  om = 0.0;
  t = 0.0;
  dt = 0.00005;
  i = 0;
  beta = 0.05;
  F0 = 0.2;
  OM = 2.0;
  mod = 100;
}


// todo ne dela vredu!
void Vaja1::resonanca() {
  out = fopen(PROJECT_ROOT "/output/vaja1/resonanca.dat", "w");
  fi = 0.2;  // zacetni pogoj
  om = 0.0;
  t = 0.0;
  i = 0;
  maxamp = 0.0;

  double OM_ranges[] = {1.0, 2.0, 3.0};

  for (auto om_range : OM_ranges) {
    while (t < 300) {
      fi_new = fi + dt * om;
      om_new = om + dt * ((-g / l) * fi - 2 * beta * om + F0 * cos(OM * t));
      fi = fi_new;
      om = om_new;
      t = t + dt;
      i++;
      if (t > 200) {
        if (fi > maxamp) maxamp = fi;  // poisce max amplitudo

      }
    }
    fprintf(out, "%.4f %.4f %.4f\n",om_range, maxamp);
  }
  fclose(out);
}

void Vaja1::dusnih() {
  t = 0.0;
  i = 0;
  fi_t.clear();
  out = fopen(PROJECT_ROOT "/output/vaja1/dusnih.dat", "w");

  while (t < 100) {
    om += dt * ((-g / l) * fi - 2 * beta * om);  // semi-implicit Euler: om first,
    fi += dt * om;                               // then fi with the new om
    t += dt;

    if (i % mod == 0) {
      fprintf(out, "%.4f %.4f %.4f\n", t, fi, om);
      fi_t.push_back(fi);
    }
    i++;
  }
  fclose(out);

  int no = 0;
  for (size_t k = 1; k + 1 < fi_t.size(); k++) {
    if (fi_t[k] > fi_t[k - 1] && fi_t[k] > fi_t[k + 1]) no++;
  }

  double freq = no / (fi_t.size() * dt * mod);
  printf("Frekvenca: %d %.6lf\n", no, freq);
}

void Vaja1::vzbujanonih() {
  out = fopen(PROJECT_ROOT "/output/vaja1/vzbujanonih.dat", "w");
  fi = 0.2;  // zacetni pogoj
  om = 0.0;
  t = 0.0;
  i = 0;
  maxamp = 0.0;

  while (t < 300) {
    fi_new = fi + dt * om;
    om_new = om + dt * ((-g / l) * fi - 2 * beta * om + F0 * cos(OM * t));
    fi = fi_new;
    om = om_new;
    t = t + dt;
    if (i % mod == 0) {
      fprintf(out, "%.4f %.4f %.4f\n", t, fi, om);
    }
    i++;
    if (t > 200) {
      if (fi > maxamp) maxamp = fi;  // poisce max amplitudo
    }
  }
  fclose(out);
}