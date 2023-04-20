bool boolSwitch = false;

String createTruth(bool argBool, String argString, int argInt, float argFloat) {
  String boolVal;
  if(argBool == true) {
    boolVal = " eh verdadeiro";
    if(argFloat < 50) {
      boolVal = " poderia ser verdadeiro";
    }
  }
  else {
    boolVal = " eh falso";
    if(argFloat < 50) {
      boolVal = " poderia ser falso";
    }
  }
  String message = argString + boolVal + " com " + String(argFloat, 2) + "% de confianca, calculado em uma velocidade de " + String(argInt) + "Km/h";
  boolSwitch = true;
  return message;
} 

void setup() {
  Serial.begin(9600);
  Serial.println("Declare algo, e se eh 'TRUE' ou 'FALSE', e o nivel de confianca (Ex.: 'Dogs > Cats, true, 95')");
}

void loop() {
  while (boolSwitch == false) {
    if (Serial.available() > 0) {
      String wholeString = Serial.readStringUntil('\n');
      int firstComma = wholeString.indexOf(", ");
      String statement = wholeString.substring(0, firstComma);
      int secondComma = wholeString.indexOf(", ", firstComma + 1);
      bool truthValue = wholeString.substring(firstComma + 2, secondComma).equalsIgnoreCase("true");
      float confidence = wholeString.substring(secondComma + 2).toFloat();
      Serial.println(createTruth(truthValue, statement, 100, confidence));
    }
  }
}
