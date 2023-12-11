#include <stdio.h>
#include <limits.h>

#define V 6

void dijkstra(int graphe[V][V], int depart) {
  // Initialisation
  int distance[V];
  int visite[V];
  for (int i = 0; i < V; i++) {
    distance[i] = INT_MAX;
    visite[i] = 0;
  }
  // La distance de la source à elle-même est toujours 0
  distance[depart] = 0;
  // Trouver le chemin le plus court pour tous les sommets
  for (int i = 0; i < V - 1; i++) {
    // Choisir le sommet avec la distance minimale non visitée
    int sommet_actuel = -1;
    for (int j = 0; j < V; j++) {
      if (!visite[j] && (sommet_actuel == -1 || distance[j] < distance[sommet_actuel])) {
        sommet_actuel = j;
      }
    }
    // Marquer le sommet comme visité
    visite[sommet_actuel] = 1;
    // Mettre à jour la distance des sommets adjacents
    for (int j = 0; j < V; j++) {
      if (!visite[j] && graphe[sommet_actuel][j] && distance[sommet_actuel] != INT_MAX && distance[sommet_actuel] + graphe[sommet_actuel][j] < distance[j]) {
        distance[j] = distance[sommet_actuel] + graphe[sommet_actuel][j];
      }
    }
  }

  // Afficher les distances les plus courtes depuis la source
  printf("Sommet | Distance depuis le sommet de départ\n");
  for (int i = 0; i < V; i++) {
    printf("%d | %d\n", i, distance[i]);
  }
}

int main() {
  int graphe[V][V] = {
    {0, 2, 4, 0, 0, 0},
    {0, 0, 1, 7, 0, 0},
    {0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 2, 0, 5},
    {0, 0, 0, 0, 0, 0}
  };

  int depart = 0;
  dijkstra(graphe, depart);
  return 0;