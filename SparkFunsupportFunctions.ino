// Support functions.

void  playForward_z(int freq, int duration){
  boardB.run(FWD, freq);
  delay(duration);
  boardB.softStop();
  while (boardA.busyCheck());
}
 
void playBack_z(int freq, int duration){
   boardB.run(REV, freq);
  delay(duration);
  boardB.softStop();
  while (boardA.busyCheck());
}

void playleft(int freq, int duration){
   boardC.run(FWD, freq);
  delay(duration);
  boardC.softStop();
  while (boardA.busyCheck());
}
void playright (int freq, int duration){
   boardC.run(REV, freq);
  delay(duration);
  boardC.softStop();
  while (boardA.busyCheck());
}

void playup(int freq, int duration){
  boardD.run(FWD, freq);
  delay(duration);
  boardD.softStop();
  while (boardA.busyCheck());
}
void playfwd(int freq, int duration){
  boardE.run(REV, freq);
  delay(duration);
  boardE.softStop();
  while (boardA.busyCheck());
}

// This is the configuration function for the three dSPIN parts. Read the inline
//  comments for more info.
void dSPINConfig(void)
{
  boardA.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations;
                                    //  second paramter ignored.
  boardA.configStepMode(STEP_FS);   // 0 microsteps per step
  boardA.setMaxSpeed(10000);        // 10000 steps/s max
  boardA.setFullSpeed(10000);       // microstep below 10000 steps/s
  boardA.setAcc(10000);             // accelerate at 10000 steps/s/s
  boardA.setDec(10000);
  boardA.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  boardA.setOCThreshold(OC_750mA);  // OC threshold 750mA
  boardA.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  boardA.setOCShutdown(OC_SD_DISABLE); // don't shutdown on OC
  boardA.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  boardA.setSwitchMode(SW_USER);    // Switch is not hard stop
  boardA.setOscMode(INT_16MHZ_OSCOUT_16MHZ); // for boardA, we want 16MHz
                                    //  internal osc, 16MHz out. boardB and
                                    //  boardC will be the same in all respects
                                    //  but this, as they will bring in and
                                    //  output the clock to keep them
                                    //  all in phase.
  boardA.setAccKVAL(255);           // We'll tinker with these later, if needed.
  boardA.setDecKVAL(255);
  boardA.setRunKVAL(255);
  boardA.setHoldKVAL(32);           // This controls the holding current; keep it low.

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  boardB.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations;
                                    //  second paramter ignored.
  boardB.configStepMode(STEP_FS);   // 0 microsteps per step
  boardB.setMaxSpeed(10000);        // 10000 steps/s max
  boardB.setFullSpeed(10000);       // microstep below 10000 steps/s
  boardB.setAcc(10000);             // accelerate at 10000 steps/s/s
  boardB.setDec(10000);
  boardB.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  boardB.setOCThreshold(OC_750mA);  // OC threshold 750mA
  boardB.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  boardB.setOCShutdown(OC_SD_DISABLE); // don't shutdown on OC
  boardB.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  boardB.setSwitchMode(SW_USER);    // Switch is not hard stop
  boardB.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for boardA, we want 16MHz
                                    //  internal osc, 16MHz out. boardB and
                                    //  boardC will be the same in all respects
                                    //  but this, as they will bring in and
                                    //  output the clock to keep them
                                    //  all in phase.
  boardB.setAccKVAL(255);           // We'll tinker with these later, if needed.
  boardB.setDecKVAL(255);
  boardB.setRunKVAL(255);
  boardB.setHoldKVAL(32);           // This controls the holding current; keep it low.
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  boardC.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations;
                                    //  second paramter ignored.
  boardC.configStepMode(STEP_FS);   // 0 microsteps per step
  boardC.setMaxSpeed(10000);        // 10000 steps/s max
  boardC.setFullSpeed(10000);       // microstep below 10000 steps/s
  boardC.setAcc(10000);             // accelerate at 10000 steps/s/s
  boardC.setDec(10000);
  boardC.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  boardC.setOCThreshold(OC_750mA);  // OC threshold 750mA
  boardC.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  boardC.setOCShutdown(OC_SD_DISABLE); // don't shutdown on OC
  boardC.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  boardC.setSwitchMode(SW_USER);    // Switch is not hard stop
  boardC.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for boardA, we want 16MHz
                                    //  internal osc, 16MHz out. boardB and
                                    //  boardC will be the same in all respects
                                    //  but this, as they will bring in and
                                    //  output the clock to keep them
                                    //  all in phase.
  boardC.setAccKVAL(255);           // We'll tinker with these later, if needed.
  boardC.setDecKVAL(255);
  boardC.setRunKVAL(255);
  boardC.setHoldKVAL(32);           // This controls the holding current; keep it low.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  boardD.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations;
                                    //  second paramter ignored.
  boardD.configStepMode(STEP_FS);   // 0 microsteps per step
  boardD.setMaxSpeed(10000);        // 10000 steps/s max
  boardD.setFullSpeed(10000);       // microstep below 10000 steps/s
  boardD.setAcc(10000);             // accelerate at 10000 steps/s/s
  boardD.setDec(10000);
  boardD.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  boardD.setOCThreshold(OC_750mA);  // OC threshold 750mA
  boardD.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  boardD.setOCShutdown(OC_SD_DISABLE); // don't shutdown on OC
  boardD.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  boardD.setSwitchMode(SW_USER);    // Switch is not hard stop
  boardD.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for boardA, we want 16MHz
                                    //  internal osc, 16MHz out. boardB and
                                    //  boardC will be the same in all respects
                                    //  but this, as they will bring in and
                                    //  output the clock to keep them
                                    //  all in phase.
  boardD.setAccKVAL(255);           // We'll tinker with these later, if needed.
  boardD.setDecKVAL(255);
  boardD.setRunKVAL(255);
  boardD.setHoldKVAL(32);           // This controls the holding current; keep it low.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  boardE.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations;
                                    //  second paramter ignored.
  boardE.configStepMode(STEP_FS);   // 0 microsteps per step
  boardE.setMaxSpeed(10000);        // 10000 steps/s max
  boardE.setFullSpeed(10000);       // microstep below 10000 steps/s
  boardE.setAcc(10000);             // accelerate at 10000 steps/s/s
  boardE.setDec(10000);
  boardE.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  boardE.setOCThreshold(OC_750mA);  // OC threshold 750mA
  boardE.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  boardE.setOCShutdown(OC_SD_DISABLE); // don't shutdown on OC
  boardE.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  boardE.setSwitchMode(SW_USER);    // Switch is not hard stop
  boardE.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for boardA, we want 16MHz
                                    //  internal osc, 16MHz out. boardB and
                                    //  boardC will be the same in all respects
                                    //  but this, as they will bring in and
                                    //  output the clock to keep them
                                    //  all in phase.
  boardE.setAccKVAL(255);           // We'll tinker with these later, if needed.
  boardE.setDecKVAL(255);
  boardE.setRunKVAL(255);
  boardE.setHoldKVAL(32);           // This controls the holding current; keep it low.
}
  
