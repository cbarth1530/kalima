/*
  pour introger l'etat de tous les pins (A & D) pour stockage db
  et changer egalement par TTY avec confirmation d'execution
  commandes possibles
  r g b 0 Leds Rouges Vertes Bleues Oranges suivies de valeurs 0->255
  c Co2
  t time
  h hours
  m minutes
  p ph
  f fan suivi de 1 - 2 entree sortie
  d dht digital humidite temperature
  
*/
#include <Wire.h>
#define DS3231_I2C_ADDRESS 0x68
