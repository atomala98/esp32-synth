#include "SPI.h"
#include "TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();

uint16_t x, y;

const int attackPin = 34;
const int sustainPin = 35;
const int releasePin = 32;
const int frequencyPin = 26;
const int wavePin = 36;
const int modPin = 14;
const int betaPin = 13;
const int BPMPin = 39;
const int arpPin = 27;
const int modFreqPin = 33;
//pot pins

float sine[] = {0.0, 0.025, 0.049, 0.074, 0.098, 0.122, 0.147, 0.171, 0.195, 0.219, 0.243, 0.267, 0.29, 0.314, 0.337, 0.36, 0.383, 0.405, 0.428, 0.45, 0.471, 0.493, 0.514, 0.535, 0.556, 0.576, 0.596, 0.615, 0.634, 0.653, 0.672, 0.69, 0.707, 0.724, 0.741, 0.757, 0.773, 0.788, 0.803, 0.818, 0.831, 0.845, 0.858, 0.87, 0.882, 0.893, 0.904, 0.914, 0.924, 0.933, 0.942, 0.95, 0.957, 0.964, 0.97, 0.976, 0.981, 0.985, 0.989, 0.992, 0.995, 0.997, 0.999, 1.0, 1.0, 1.0, 0.999, 0.997, 0.995, 0.992, 0.989, 0.985, 0.981, 0.976, 0.97, 0.964, 0.957, 0.95, 0.942, 0.933, 0.924, 0.914, 0.904, 0.893, 0.882, 0.87, 0.858, 0.845, 0.831, 0.818, 0.803, 0.788, 0.773, 0.757, 0.741, 0.724, 0.707, 0.69, 0.672, 0.653, 0.634, 0.615, 0.596, 0.576, 0.556, 0.535, 0.514, 0.493, 0.471, 0.45, 0.428, 0.405, 0.383, 0.36, 0.337, 0.314, 0.29, 0.267, 0.243, 0.219, 0.195, 0.171, 0.147, 0.122, 0.098, 0.074, 0.049, 0.025, 0.0, -0.025, -0.049, -0.074, -0.098, -0.122, -0.147, -0.171, -0.195, -0.219, -0.243, -0.267, -0.29, -0.314, -0.337, -0.36, -0.383, -0.405, -0.428, -0.45, -0.471, -0.493, -0.514, -0.535, -0.556, -0.576, -0.596, -0.615, -0.634, -0.653, -0.672, -0.69, -0.707, -0.724, -0.741, -0.757, -0.773, -0.788, -0.803, -0.818, -0.831, -0.845, -0.858, -0.87, -0.882, -0.893, -0.904, -0.914, -0.924, -0.933, -0.942, -0.95, -0.957, -0.964, -0.97, -0.976, -0.981, -0.985, -0.989, -0.992, -0.995, -0.997, -0.999, -1.0, -1.0, -1.0, -0.999, -0.997, -0.995, -0.992, -0.989, -0.985, -0.981, -0.976, -0.97, -0.964, -0.957, -0.95, -0.942, -0.933, -0.924, -0.914, -0.904, -0.893, -0.882, -0.87, -0.858, -0.845, -0.831, -0.818, -0.803, -0.788, -0.773, -0.757, -0.741, -0.724, -0.707, -0.69, -0.672, -0.653, -0.634, -0.615, -0.596, -0.576, -0.556, -0.535, -0.514, -0.493, -0.471, -0.45, -0.428, -0.405, -0.383, -0.36, -0.337, -0.314, -0.29, -0.267, -0.243, -0.219, -0.195, -0.171, -0.147, -0.122, -0.098, -0.074, -0.049, -0.025};
float triangle[] = { -1.0, -0.984, -0.969, -0.953, -0.938, -0.922, -0.906, -0.891, -0.875, -0.859, -0.844, -0.828, -0.812, -0.797, -0.781, -0.766, -0.75, -0.734, -0.719, -0.703, -0.688, -0.672, -0.656, -0.641, -0.625, -0.609, -0.594, -0.578, -0.562, -0.547, -0.531, -0.516, -0.5, -0.484, -0.469, -0.453, -0.438, -0.422, -0.406, -0.391, -0.375, -0.359, -0.344, -0.328, -0.312, -0.297, -0.281, -0.266, -0.25, -0.234, -0.219, -0.203, -0.188, -0.172, -0.156, -0.141, -0.125, -0.109, -0.094, -0.078, -0.062, -0.047, -0.031, -0.016, 0.0, 0.016, 0.031, 0.047, 0.062, 0.078, 0.094, 0.109, 0.125, 0.141, 0.156, 0.172, 0.188, 0.203, 0.219, 0.234, 0.25, 0.266, 0.281, 0.297, 0.312, 0.328, 0.344, 0.359, 0.375, 0.391, 0.406, 0.422, 0.438, 0.453, 0.469, 0.484, 0.5, 0.516, 0.531, 0.547, 0.562, 0.578, 0.594, 0.609, 0.625, 0.641, 0.656, 0.672, 0.688, 0.703, 0.719, 0.734, 0.75, 0.766, 0.781, 0.797, 0.812, 0.828, 0.844, 0.859, 0.875, 0.891, 0.906, 0.922, 0.938, 0.953, 0.969, 0.984, 1.0, 0.984, 0.969, 0.953, 0.938, 0.922, 0.906, 0.891, 0.875, 0.859, 0.844, 0.828, 0.812, 0.797, 0.781, 0.766, 0.75, 0.734, 0.719, 0.703, 0.688, 0.672, 0.656, 0.641, 0.625, 0.609, 0.594, 0.578, 0.562, 0.547, 0.531, 0.516, 0.5, 0.484, 0.469, 0.453, 0.438, 0.422, 0.406, 0.391, 0.375, 0.359, 0.344, 0.328, 0.312, 0.297, 0.281, 0.266, 0.25, 0.234, 0.219, 0.203, 0.188, 0.172, 0.156, 0.141, 0.125, 0.109, 0.094, 0.078, 0.062, 0.047, 0.031, 0.016, 0.0, -0.016, -0.031, -0.047, -0.062, -0.078, -0.094, -0.109, -0.125, -0.141, -0.156, -0.172, -0.188, -0.203, -0.219, -0.234, -0.25, -0.266, -0.281, -0.297, -0.312, -0.328, -0.344, -0.359, -0.375, -0.391, -0.406, -0.422, -0.438, -0.453, -0.469, -0.484, -0.5, -0.516, -0.531, -0.547, -0.562, -0.578, -0.594, -0.609, -0.625, -0.641, -0.656, -0.672, -0.688, -0.703, -0.719, -0.734, -0.75, -0.766, -0.781, -0.797, -0.812, -0.828, -0.844, -0.859, -0.875, -0.891, -0.906, -0.922, -0.938, -0.953, -0.969, -0.984};
float square[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
float saw[] = {1.0, -0.992, -0.984, -0.977, -0.969, -0.961, -0.953, -0.945, -0.938, -0.93, -0.922, -0.914, -0.906, -0.898, -0.891, -0.883, -0.875, -0.867, -0.859, -0.852, -0.844, -0.836, -0.828, -0.82, -0.812, -0.805, -0.797, -0.789, -0.781, -0.773, -0.766, -0.758, -0.75, -0.742, -0.734, -0.727, -0.719, -0.711, -0.703, -0.695, -0.688, -0.68, -0.672, -0.664, -0.656, -0.648, -0.641, -0.633, -0.625, -0.617, -0.609, -0.602, -0.594, -0.586, -0.578, -0.57, -0.562, -0.555, -0.547, -0.539, -0.531, -0.523, -0.516, -0.508, -0.5, -0.492, -0.484, -0.477, -0.469, -0.461, -0.453, -0.445, -0.438, -0.43, -0.422, -0.414, -0.406, -0.398, -0.391, -0.383, -0.375, -0.367, -0.359, -0.352, -0.344, -0.336, -0.328, -0.32, -0.312, -0.305, -0.297, -0.289, -0.281, -0.273, -0.266, -0.258, -0.25, -0.242, -0.234, -0.227, -0.219, -0.211, -0.203, -0.195, -0.188, -0.18, -0.172, -0.164, -0.156, -0.148, -0.141, -0.133, -0.125, -0.117, -0.109, -0.102, -0.094, -0.086, -0.078, -0.07, -0.062, -0.055, -0.047, -0.039, -0.031, -0.023, -0.016, -0.008, 0.0, 0.008, 0.016, 0.023, 0.031, 0.039, 0.047, 0.055, 0.062, 0.07, 0.078, 0.086, 0.094, 0.102, 0.109, 0.117, 0.125, 0.133, 0.141, 0.148, 0.156, 0.164, 0.172, 0.18, 0.188, 0.195, 0.203, 0.211, 0.219, 0.227, 0.234, 0.242, 0.25, 0.258, 0.266, 0.273, 0.281, 0.289, 0.297, 0.305, 0.312, 0.32, 0.328, 0.336, 0.344, 0.352, 0.359, 0.367, 0.375, 0.383, 0.391, 0.398, 0.406, 0.414, 0.422, 0.43, 0.438, 0.445, 0.453, 0.461, 0.469, 0.477, 0.484, 0.492, 0.5, 0.508, 0.516, 0.523, 0.531, 0.539, 0.547, 0.555, 0.562, 0.57, 0.578, 0.586, 0.594, 0.602, 0.609, 0.617, 0.625, 0.633, 0.641, 0.648, 0.656, 0.664, 0.672, 0.68, 0.688, 0.695, 0.703, 0.711, 0.719, 0.727, 0.734, 0.742, 0.75, 0.758, 0.766, 0.773, 0.781, 0.789, 0.797, 0.805, 0.812, 0.82, 0.828, 0.836, 0.844, 0.852, 0.859, 0.867, 0.875, 0.883, 0.891, 0.898, 0.906, 0.914, 0.922, 0.93, 0.938, 0.945, 0.953, 0.961, 0.969, 0.977, 0.984, 0.992};
float noise[] = { -0.886, 0.336, -0.474, 0.369, -0.685, -0.764, -0.464, 0.241, 0.083, 0.168, -0.184, -0.648, 0.025, 0.267, 0.999, 0.554, -0.222, 0.01, 0.59, 0.273, 0.367, 0.424, -0.493, 0.963, 0.781, -0.538, 0.379, 0.054, -0.849, -0.734, -0.653, 0.292, -0.013, 0.014, -0.652, -0.11, -0.186, 0.707, -0.553, 0.133, -0.086, -0.376, -0.254, -0.09, -0.937, -0.946, -0.444, 0.24, 0.029, -0.253, 0.441, -0.039, 0.054, 0.039, 0.658, 0.85, 0.319, 0.014, -0.2, 0.673, -0.718, -0.309, -0.264, -0.334, -0.16, 0.579, 0.442, -0.308, 0.65, -0.613, -0.804, -0.047, 0.087, -0.956, 0.337, 0.438, 0.025, -0.035, 0.521, 0.582, -0.148, -0.989, 0.073, -0.692, -0.746, -0.832, 0.551, 0.184, -0.679, -0.509, -0.103, -0.341, 0.538, 0.754, 0.129, -0.37, -0.497, 0.694, -0.615, -0.568, -0.971, 0.609, 0.7, -0.713, 0.317, -0.48, 0.774, -0.363, -0.105, 0.49, -0.977, 0.411, 0.97, -0.037, 0.584, 0.141, 0.034, -0.88, -0.393, 0.53, -0.052, 0.832, 0.074, -0.392, -0.128, 0.447, -0.363, 0.832, -0.801, -0.623, -0.538, 0.524, 0.017, 0.112, -0.627, -0.126, -0.847, -0.891, 0.593, 0.317, -0.547, 0.236, -0.756, -0.823, -0.103, -0.353, 0.677, 0.947, -0.935, 0.525, -0.644, -0.378, -0.737, 0.985, -0.149, -0.065, 0.028, -0.758, -0.674, -0.768, -0.635, -0.95, 0.988, 0.048, -0.098, -0.739, 0.286, 0.248, 0.269, 0.738, -0.28, -0.005, 0.246, 0.809, -0.187, 0.659, 0.359, -0.156, -0.111, 0.85, -0.337, 0.263, 0.119, 0.613, 0.429, 0.841, -0.149, 0.102, -0.735, -0.473, 0.621, 0.625, 0.363, -0.403, -0.389, -0.736, -0.022, -0.627, -0.394, 0.707, 0.642, -0.746, -0.795, 0.949, 0.25, 0.081, -0.941, -0.811, -0.374, 0.724, 0.48, 0.48, 0.294, -0.533, 0.386, -0.288, -0.934, 0.263, -0.665, 0.33, -0.916, -0.163, 0.832, 0.578, 0.827, 0.712, -0.735, 0.942, -0.767, -0.368, 0.068, -0.815, -0.739, -0.524, 0.515, 0.933, -0.7, 0.607, -0.528, -0.661, 0.863, 0.453, 0.186, 0.363, 0.161, -0.128, 0.149, -0.312, -0.31, -0.563, 0.56, 0.938, -0.135, 0.386, -0.947, -0.651};
float wave[256];
//wave models

float arpeggio[4][8] = {{1, 1.19, 1.498, 1, 1.19, 1.498, 1, 1.19}, {1, 1.26, 1.498, 1, 1.26, 1.498, 1, 1.26}, {1, 1.19, 1.498, 1.781, 1, 1.19, 1.498, 1.781}, {1, 1.26, 1.498, 1.781, 1, 1.26, 1.498, 1.781}};
int arpType = 0;
int arpTimer = 0;
int BPM = 10;
int tempBPM = 0;

float baseFreq = 65.406;
float touchScreenMultiplier = 1;
float touchFreq = 0;
float freq = baseFreq;
float modFreq = 100;
int modType = analogRead(modPin);
int octave = 0;
float octaveFreq = 0;
int tempModFreq = 0;
//base freqency + modulation

unsigned int sampleRate = 40000;
//sample rate
float beta = 20;
// modulation index
unsigned int i = 0;
// iterator
unsigned int interruptCounter = 0;
unsigned int totalInterruptCounter = 0;
// interrupt definition
bool att = true;
bool sus = false;
bool rel = false;
float envelope = 0;
float susTimer = 0;
float attTime = analogRead(attackPin);
float susTime = analogRead(sustainPin);
float relTime = analogRead(releasePin);
//actual ASR (ADSR) state values

const int adcResolution = 4096;
const int wavesAmount = 5;
const int modAmount = 3;
const int arpAmount = 4;

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


void IRAM_ATTR onTimer() {
  // timer interrupt
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

void touchScreen() {
  uint16_t x, y;
  tft.getTouchRaw(&x, &y);
  //Serial.println(tft.getTouchRawZ());
  if (tft.getTouchRawZ() < 200)
    touchScreenMultiplier = 1;
  else if (y > 3600)
    touchScreenMultiplier = 1;
  else if (y > 3333)
    touchScreenMultiplier = 1.059;
  else if (y > 3068)
    touchScreenMultiplier = 1.122;
  else if (y > 2800)
    touchScreenMultiplier = 1.19;
  else if (y > 2533)
    touchScreenMultiplier = 1.26;
  else if (y > 2266)
    touchScreenMultiplier = 1.335;
  else if (y > 2000)
    touchScreenMultiplier = 1.414;
  else if (y > 1733)
    touchScreenMultiplier = 1.498;
  else if (y > 1467)
    touchScreenMultiplier = 1.587;
  else if (y > 1200)
    touchScreenMultiplier = 1.681;
  else if (y > 933)
    touchScreenMultiplier = 1.781;
  else if (y > 666)
    touchScreenMultiplier = 1.888;
  else if (y > 400)
    touchScreenMultiplier = 2;
}



void calcEnvelope() {
  // real-time creating envelope
  if (att) {
    if (envelope < 1) envelope += 1 / attTime;
    else {
      att = false;
      sus = true;
    }
  }
  else if (sus) {
    if (susTimer < 1) {
      envelope = envelope;
      susTimer += 1 / susTime;
    }
    else {
      sus = false;
      rel = true;
      susTimer = 0;
    }
  }
  else if (envelope > 0) envelope -= 1 / relTime;
  else {
    rel = false;
    att = true;
    i = 0;
  }
  if (envelope > 1)
    envelope = 1;
  if (envelope < 0)
    envelope = 0;
}


void selectWave(float *wave, int type) {
  // choosing waveform, an saving it to wave array
  if (type < adcResolution / wavesAmount)
    for (int i = 0; i < 256; i++)
      wave[i] = sine[i];
  else if (type < 2 * adcResolution / wavesAmount)
    for (int i = 0; i < 256; i++)
      wave[i] = triangle[i];
  else if (type < 3 * adcResolution / wavesAmount)
    for (int i = 0; i < 256; i++)
      wave[i] = square[i];
  else if (type < 4 * adcResolution / wavesAmount)
    for (int i = 0; i < 256; i++)
      wave[i] = saw[i];
  else
    for (int i = 0; i < 256; i++)
      wave[i] = noise[i];
}

void chooseArpeggio(int arpeggioType) {
  if (arpeggioType < adcResolution / arpAmount) arpType = 0;
  else if (arpeggioType < 2 * adcResolution / arpAmount) arpType = 1;
  else if (arpeggioType < 3 * adcResolution / arpAmount) arpType = 2;
  else arpType = 3;
}

void arpeggiator() {
  freq = touchFreq * arpeggio[arpType][arpTimer];
  arpTimer++;
  if (arpTimer == 8) arpTimer = 0;
  att = true;
  sus = false;
  rel = false;
  envelope = 0;
}



void play() {
  // calculating each sample real-time, and writing it on DAC
  if (modType < adcResolution / modAmount)
//      dacWrite(25, int((127 * wave[int(256 * freq / sampleRate * i) % 256])*envelope + 128));
    Serial.println(int((127 * wave[int(256 * freq / sampleRate * i) % 256])*envelope + 128));
  // no modulation
  else if (modType < 2 * adcResolution / modAmount)
//      dacWrite(25, int((127 - beta + (beta * sine[int(256 * modFreq / sampleRate * i) % 256]))*wave[int(256 * freq * i / sampleRate) % 256]*envelope) + 128);
    Serial.println(int((127 - beta + (beta * sine[int(256 * modFreq / sampleRate * i) % 256]))*wave[int(256 * freq * i / sampleRate) % 256]*envelope) + 128);
  // AM synthesis
  else
//      dacWrite(25, int(127 * wave[abs(int((256 * freq / sampleRate * i + int(beta * sine[int(256 * modFreq / sampleRate * i) % 256])))) % 256])*envelope + 128);
    Serial.println(int(127 * wave[abs(int((256 * freq / sampleRate * i + int(beta * sine[int(256 * modFreq / sampleRate * i) % 256])))) % 256])*envelope + 128);
  // FM synthesis
}

void setBPM() {
  tempBPM = int((analogRead(BPMPin)/25)) + 1;
  if (tempBPM > BPM + 5 || tempBPM < BPM - 5)
    BPM = tempBPM;
}

void setModFreq() {
  tempModFreq = int(analogRead(modFreqPin)/4);
  if (tempModFreq > modFreq + 20 || tempModFreq < modFreq - 20)
    modFreq = tempModFreq;
}

void setup()
{
  Serial.begin(115200);
  selectWave(wave, analogRead(wavePin));
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 25, true);
  timerAlarmEnable(timer);
  tft.init();

  tft.fillRect(0, 40, 240, 3, TFT_BLACK);
  tft.fillRect(0, 80, 240, 3, TFT_BLACK);
  tft.fillRect(0, 120, 240, 3, TFT_BLACK);
  tft.fillRect(0, 160, 240, 3, TFT_BLACK);
  tft.fillRect(0, 200, 240, 3, TFT_BLACK);
  tft.fillRect(0, 240, 240, 3, TFT_BLACK);
  tft.fillRect(0, 280, 240, 3, TFT_BLACK);

  
  tft.fillRect(120, 30, 120, 20, TFT_BLACK);
  tft.fillRect(120, 70, 120, 20, TFT_BLACK);
  tft.fillRect(120, 150, 120, 20, TFT_BLACK);
  tft.fillRect(120, 190, 120, 20, TFT_BLACK);
  tft.fillRect(120, 230, 120, 20, TFT_BLACK);
}


void loop()
{
  if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
    calcEnvelope();
    play();
    totalInterruptCounter++;
    i++;
    if (totalInterruptCounter % 500 == 0) attTime = (analogRead(attackPin) + 10) * 50;
    if ((totalInterruptCounter + 1) % 500 == 0) susTime = (analogRead(sustainPin) + 10) * 50;
    if ((totalInterruptCounter + 2) % 500 == 0) relTime = (analogRead(releasePin) + 10) * 50;
    if ((totalInterruptCounter + 3) % 500 == 0) octave = analogRead(frequencyPin)/683 + 1;
    if ((totalInterruptCounter + 4) % 500 == 0) octaveFreq = baseFreq * octave;
    if ((totalInterruptCounter + 5) % 500 == 0) selectWave(wave, analogRead(wavePin));
    if ((totalInterruptCounter + 6) % 500 == 0) modType = analogRead(modPin);
    if ((totalInterruptCounter + 7) % 500 == 0) beta = analogRead(betaPin) / 64;
    if ((totalInterruptCounter + 8) % 500 == 0) modFreq = analogRead(modFreqPin)/4;
    if ((totalInterruptCounter + 9) % 500 == 0) BPM = analogRead(BPMPin)/25;
    if ((totalInterruptCounter + 10) % 500 == 0) chooseArpeggio(analogRead(arpPin));
    if ((totalInterruptCounter + 11) % 500 == 0) touchScreen();
    if ((totalInterruptCounter + 12) % 500 == 0) touchFreq = octaveFreq * touchScreenMultiplier;
    if (totalInterruptCounter % int(600000 / BPM) == 0) arpeggiator(); 
    if (BPM < 20) freq = touchFreq;
  }  
}
