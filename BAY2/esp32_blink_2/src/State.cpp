#include "State.h"

String bayStatus = "FREE";

float voltage = 0.0;
float current = 0.0;
float power = 0.0;
float energyWh = 0.0;
float temperature = 0.0;

unsigned long sessionStartMs = 0;

// Edge AI variables
float predictedArrivalProb = 0.0;

int predictedDurationMin = 0;

int lastHourOfDay = 12;

float predictionThreshold = 0.5;

// Optimization variables
String loadDecision = "ALLOW";

int throttleLevel = 50;

int peakTariffStartHr = 18;
int peakTariffEndHr = 21;

bool overloadActive = false;

int overloadCurrentA = 16;

int maxStationLoadW = 3000;
bool manualOverrideActive = true;