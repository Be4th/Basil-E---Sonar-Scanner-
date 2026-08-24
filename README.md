BasilESonarradar

A sonar-style scanner that sweeps a servo-driven ultrasonic sensor 180° back and
forth, measuring distance to nearby objects and giving real-time visual + audio
feedback based on range.

Originally built as my final project for the ROBONYX course on Skool. I customized
the distance ranges and added a "lock-on" close-range response — modifications
beyond the original assignment.

 How It Works
- A servo sweeps the ultrasonic sensor from 0° to 180° and back, continuously.
- Distance is measured by the ultrasonic sensor and split into three zones:
  - Green (≥ 100 cm): Clear — sweep continues as usual, no sound.
  - Yellow (15–99 cm): Object detected — LED displays yellow (red + green
    channels on), buzzer gives a short beep each pass.
  - Red (< 15 cm): Object very close — LED turns red, buzzer holds on for
    1 second ("lock-on"), then the sweep resumes.

Note on the demo video: the room it was filmed in has most surfaces sitting in
the 15–99 cm yellow range, so the sensor reads yellow/beeping for most of the clip.
The red "lock-on" state only triggers when an object (my hand) enters within 15 cm
directly in front of the sensor.

 Pin Reference
- Ultrasonic sensor — Echo → 7, Trig → 8
- Servo → 11
- Buzzer → 10
- RGB LED — R → 4, G → 5, B → 3

Demo: [YouTube Short](https://youtube.com/shorts/8Tmxnm5-BZQ)
Photos: <img width="952" height="1270" alt="image" src="https://github.com/user-attachments/assets/37c4c6d4-7837-4f56-80bf-a0123c46b101" /><img width="952" height="1270" alt="image" src="https://github.com/user-attachments/assets/3717497c-d6dd-4e2e-95a5-d879f1fd5aee" />


Files: `BasilESonarradar.ino`

 What I Learned
- Coordinating a continuous servo sweep with real-time distance polling
- Structuring range-based state logic (green/yellow/red zones) cleanly in code
- Working within hardware limitations — active vs. passive buzzer changes what
  feedback is possible (no `tone()` without a passive buzzer)
- Debugging real hardware behavior vs. expected behavior (e.g. why a "quiet"
  room isn't necessarily out of range)

 Possible Next Steps
- Add a Tinkercad simulation so others can test the logic without hardware
- Swap to a passive buzzer for distinct tones per zone
- Log distance readings over time to visualize sweep coverage
