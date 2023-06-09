bool boolSwitch = false;

String createTruth(bool argBool, String argString, int argInt, float argFloat) {
  String boolVal;
  // Verifica se o argumento é true ou false
  if(argBool == true) {
    // Caso seja verdadeiro, retorna:
    boolVal = " eh verdadeiro";
    // Verifica se o argumento float é menor que 50 e maior ou igual a zero
    if(argFloat >= 0 && argFloat < 50) {
      // Caso seja menor que 50, retorna:
      boolVal = " poderia ser verdadeiro";
    }
  }
  // Caso não entre na condição acima, verifica se entra na de baixo
  else {
    boolVal = " eh falso";
    // Verifica se o argumento float é menor que 50 e maior ou igual a zero
    if(argFloat >= 0 && argFloat < 50) {
      // Caso seja menor que 50, retorna:
      boolVal = " poderia ser falso";
    }
  }
  // Cria uma mensagem com os argumentos
  String message = argString + boolVal + " Com " + String(argFloat, 0) + "% de confianca, calculado em uma velocidade de " + String(argInt) + "Km/h\n";
  // Retorna a mensagem criada
  return message;
} 

void setup() {
  // Dá inicio a comunicação Serial
  Serial.begin(9600);
}

void loop() {
  // Imprime uma mensagem para o usuário
  Serial.println("Declare algo, se 'TRUE' ou 'FALSE', e o nivel de confianca (Ex.: 'Dogs > Cats, true, 95')");
  // Enquanto boolSwitch for false, faça:
  while (boolSwitch == false) {
    // Verifica se existem dados disponíveis na Serial
    if (Serial.available() > 0) {
      // Cria uma String com todos os dados
      String wholeString = Serial.readStringUntil('\n');
      // Encontra o primeiro índice da vírgula
      int firstComma = wholeString.indexOf(", ");
      // Cria uma String apenas com a declaração
      String statement = wholeString.substring(0, firstComma);
      // Encontra o segundo índice da vírgula
      int secondComma = wholeString.indexOf(", ", firstComma + 1);
      // Cria um bool com o valor da declaração
      bool truthValue = wholeString.substring(firstComma + 2, secondComma).equalsIgnoreCase("true");
      // Cria um float com o valor de confiança
      float confidence = wholeString.substring(secondComma + 2).toFloat();
      // Imprime a mensagem criada com os argumentos
      Serial.println(createTruth(truthValue, statement, 100, confidence));
      // Interrompe o while para pedir outra declaração pelo println	
      break;
    }
  }
}
